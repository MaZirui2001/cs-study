
// `define FIFO
module cache #(
    parameter  LINE_ADDR_LEN = 3, // line内地址长度，决定了每个line具有2^3个word
    parameter  SET_ADDR_LEN  = 3, // 组地址长度，决定了一共有2^3=8组
    parameter  TAG_ADDR_LEN  = 6, // tag长度
    parameter  WAY_CNT       = 4  // 组相连度，决定了每组中有多少路line，这里是直接映射型cache，因此该参数没用到
)(
    input  clk, rst,
    output miss,               // 对CPU发出的miss信号
    input  [31:0] addr,        // 读写请求地址
    input  rd_req,             // 读请求信号
    output reg [31:0] rd_data, // 读出的数据，一次读一个word
    input  wr_req,             // 写请求信号
    input  [31:0] wr_data      // 要写入的数据，一次写一个word
);

localparam MEM_ADDR_LEN    = TAG_ADDR_LEN + SET_ADDR_LEN ; // 计算主存地址长度 MEM_ADDR_LEN，主存大小=2^MEM_ADDR_LEN个line
localparam UNUSED_ADDR_LEN = 32 - TAG_ADDR_LEN - SET_ADDR_LEN - LINE_ADDR_LEN - 2 ;       // 计算未使用的地址的长度

localparam LINE_SIZE       = 1 << LINE_ADDR_LEN  ;         // 计算 line 中 word 的数量，即 2^LINE_ADDR_LEN 个word 每 line
localparam SET_SIZE        = 1 << SET_ADDR_LEN   ;         // 计算一共有多少组，即 2^SET_ADDR_LEN 个组
localparam WAY_WIDTH       = $clog2(WAY_CNT)     ;

reg [            31:0] cache_mem    [WAY_CNT][SET_SIZE][LINE_SIZE]; // WAY_CNT个way，每个way有SET_SIZE个line，每个line有LINE_SIZE个word
reg [TAG_ADDR_LEN-1:0] cache_tags   [WAY_CNT][SET_SIZE];            // WAY_CNT个way，每个way有SET_SIZE个TAG
reg                    valid        [WAY_CNT][SET_SIZE];            // WAY_CNT个way，每个way有SET_SIZE个valid(有效位)
reg                    dirty        [WAY_CNT][SET_SIZE];            // WAY_CNT个way，每个way有SET_SIZE个dirty(脏位)

wire [              2-1:0]   word_addr;                   // 将输入地址addr拆分成这5个部分
wire [  LINE_ADDR_LEN-1:0]   line_addr;
wire [   SET_ADDR_LEN-1:0]    set_addr;
wire [   TAG_ADDR_LEN-1:0]    tag_addr;
wire [UNUSED_ADDR_LEN-1:0] unused_addr;

enum  {IDLE, SWAP_OUT, SWAP_IN, SWAP_IN_OK} cache_stat;    // cache 状态机的状态定义
                                                           // IDLE代表就绪，SWAP_OUT代表正在换出，SWAP_IN代表正在换入，SWAP_IN_OK代表换入后进行一周期的写入cache操作。

reg  [   SET_ADDR_LEN-1:0] mem_rd_set_addr = 0;
reg  [   TAG_ADDR_LEN-1:0] mem_rd_tag_addr = 0;
wire [   MEM_ADDR_LEN-1:0] mem_rd_addr = {mem_rd_tag_addr, mem_rd_set_addr};
reg  [   MEM_ADDR_LEN-1:0] mem_wr_addr = 0;

reg  [31:0] mem_wr_line [LINE_SIZE];
wire [31:0] mem_rd_line [LINE_SIZE];

wire mem_gnt;      // 主存响应读写的握手信号
reg [63:0] total_times = 0;
reg [63:0] hit_times = 0;
assign {unused_addr, tag_addr, set_addr, line_addr, word_addr} = addr;  // 拆分 32bit ADDR

wire cache_hit;
reg [WAY_CNT-1:0] hit;
always @(*) begin                     // 判断 输入的address 是否在 cache 中命中
    hit = 0;
    for(integer i = 0; i < WAY_CNT; i++) begin
        if(valid[i][set_addr] && cache_tags[i][set_addr] == tag_addr) begin
            hit[i] = 1'b1;
        end
    end
end
assign cache_hit = |hit;             // 如果有任意一路命中，则cache_hit=1

// encode 
reg [WAY_WIDTH-1:0] encoder [1 << WAY_CNT];
initial begin
    integer j;
    for(integer i = 0; i < (1 << WAY_CNT); i++) begin
        j = $clog2(i);
        encoder[i] = j[WAY_WIDTH-1:0];
    end
end
wire [WAY_WIDTH-1:0] hit_way;
assign hit_way = encoder[hit];

wire [WAY_WIDTH-1:0] select_out;

`ifdef FIFO
// FIFO
reg [WAY_CNT * WAY_WIDTH - 1 : 0] fifo [SET_SIZE];
assign select_out = fifo[set_addr][WAY_WIDTH - 1 -: WAY_WIDTH];

`else
// LRU
reg [WAY_CNT * WAY_WIDTH - 1 : 0] lru [SET_SIZE];
assign select_out =  lru[set_addr][WAY_WIDTH - 1 -: WAY_WIDTH];

// update LRU
reg [WAY_CNT-1:0] lru_hit_loc;
always @(*) begin
    lru_hit_loc = 0;
    if(cache_stat == IDLE && cache_hit) begin
        for(integer i = 0; i < WAY_CNT; i++) begin
            lru_hit_loc[i] = (lru[set_addr][i * WAY_WIDTH +: WAY_WIDTH] == hit_way);
        end
    end
    else if(cache_stat == SWAP_IN_OK) begin
        for(integer i = 0; i < WAY_CNT; i++) begin
            lru_hit_loc[i] = (lru[mem_rd_set_addr][i * WAY_WIDTH +: WAY_WIDTH] == select_out);
        end
    end
end
wire [WAY_WIDTH-1 : 0] lru_hit;
assign lru_hit = encoder[lru_hit_loc];
`endif



always @ (posedge clk or posedge rst) begin     // ?? cache ???
    if(rst) begin
        cache_stat <= IDLE;
        for(integer i = 0; i < WAY_CNT; i++) begin
            for(integer j = 0; j < SET_SIZE; j++) begin
                dirty[i][j] = 1'b0;
                valid[i][j] = 1'b0;
            end
        end
        for(integer k = 0; k < LINE_SIZE; k++)
            mem_wr_line[k] <= 0;
    `ifdef FIFO
        for(integer i = 0; i < SET_SIZE; i++) begin
            for(integer j = 0; j < WAY_CNT; j++) begin
                fifo[i][j * WAY_WIDTH +: WAY_WIDTH] <= j[WAY_WIDTH-1:0];
            end
        end
    `else
        for(integer i = 0; i < SET_SIZE; i++) begin
            for(integer j = 0; j < WAY_CNT; j++) begin
                lru[i][j * WAY_WIDTH +: WAY_WIDTH] <= j[WAY_WIDTH-1:0];
            end
        end
    `endif

        mem_wr_addr <= 0;
        {mem_rd_tag_addr, mem_rd_set_addr} <= 0;
        rd_data <= 0;
    end else begin
        case(cache_stat)
        IDLE:       begin
                        if(cache_hit) begin
                            if(rd_req) begin    // 如果cache命中，并且是读请求，
                                rd_data <= cache_mem[hit_way][set_addr][line_addr];   //则直接从cache中取出要读的数据
                                total_times <= total_times + 1;
                                hit_times <= hit_times + 1;
                            `ifndef FIFO
                                // 更新LRU：找到命中点，提到最高位，剩下的顺序补位
                                for(integer i = 0; i < (WAY_CNT - 1) * WAY_WIDTH; i = i + WAY_WIDTH) begin
                                    if(i >= lru_hit * WAY_WIDTH)begin
                                        lru[set_addr][i +: WAY_WIDTH] <= lru[set_addr][(i + WAY_WIDTH) +: WAY_WIDTH];
                                    end
                                end
                                lru[set_addr][WAY_CNT * WAY_WIDTH - 1 -: WAY_WIDTH] <= hit_way;
                            `endif
                            end else if(wr_req) begin // 如果cache命中，并且是写请求，
                                cache_mem[hit_way][set_addr][line_addr] <= wr_data;   // 则直接向cache中写入数据
                                dirty[hit_way][set_addr] <= 1'b1;                     // 写数据的同时置脏位
                                total_times <= total_times + 1;
                                hit_times <= hit_times + 1;
                            `ifndef FIFO
                                // 更新LRU：找到命中点，提到最高位，剩下的顺序补位
                                for(integer i = 0; i < (WAY_CNT - 1) * WAY_WIDTH; i = i + WAY_WIDTH) begin
                                    if(i >= lru_hit * WAY_WIDTH)begin
                                        lru[set_addr][i +: WAY_WIDTH] <= lru[set_addr][(i + WAY_WIDTH) +: WAY_WIDTH];
                                    end
                                end
                                lru[set_addr][WAY_CNT * WAY_WIDTH - 1 -: WAY_WIDTH] <= hit_way;
                            `endif
                            end
                        end else begin
                            if(wr_req | rd_req) begin   // 如果 cache 未命中，并且有读写请求，则需要进行换入
                                if(valid[select_out][set_addr] & dirty[select_out][set_addr]) begin    // 如果 要换入的cache line 本来有效，且脏，则需要先将它换出
                                    cache_stat  <= SWAP_OUT;
                                    mem_wr_addr <= {cache_tags[select_out][set_addr], set_addr};
                                    mem_wr_line <= cache_mem[select_out][set_addr];
                                end else begin                                   // 反之，不需要换出，直接换入
                                    cache_stat  <= SWAP_IN;
                                end
                                {mem_rd_tag_addr, mem_rd_set_addr} <= {tag_addr, set_addr};
                                total_times <= total_times + 1;
                            end
                        end
                    end
        SWAP_OUT:   begin
                        if(mem_gnt) begin           // 如果主存握手信号有效，说明换出成功，跳到下一状态
                            cache_stat <= SWAP_IN;
                        end
                    end
        SWAP_IN:    begin
                        if(mem_gnt) begin           // 如果主存握手信号有效，说明换入成功，跳到下一状态
                            cache_stat <= SWAP_IN_OK;
                        end
                    end
        SWAP_IN_OK: begin           // 上一个周期换入成功，这周期将主存读出的line写入cache，并更新tag，置高valid，置低dirty
                        for(integer i=0; i<LINE_SIZE; i++)  cache_mem[select_out][mem_rd_set_addr][i] <= mem_rd_line[i];
                        cache_tags[select_out][mem_rd_set_addr] <= mem_rd_tag_addr;
                        valid     [select_out][mem_rd_set_addr] <= 1'b1;
                        dirty     [select_out][mem_rd_set_addr] <= 1'b0;

                        // 更新换页策略：LRU把最后一个提到最前，FIFO把最后一个提到最前
                    `ifdef FIFO
                        fifo[mem_rd_set_addr] <= {select_out, fifo[mem_rd_set_addr][WAY_CNT * WAY_WIDTH - 1 : WAY_WIDTH]};
                    `else
                        lru[mem_rd_set_addr] <= {select_out, lru[mem_rd_set_addr][WAY_CNT * WAY_WIDTH - 1 : WAY_WIDTH]};
                    `endif
                        cache_stat <= IDLE;        // 回到就绪状态
                    end
        endcase
    end
end

wire mem_rd_req = (cache_stat == SWAP_IN );
wire mem_wr_req = (cache_stat == SWAP_OUT);
wire [   MEM_ADDR_LEN-1 :0] mem_addr = mem_rd_req ? mem_rd_addr : ( mem_wr_req ? mem_wr_addr : 0);

assign miss = (rd_req | wr_req) & ~(cache_hit && cache_stat==IDLE) ;     // 当 有读写请求时，如果cache不处于就绪(IDLE)状态，或者未命中，则miss=1

main_mem #(     // 主存，每次读写以line 为单位
    .LINE_ADDR_LEN  ( LINE_ADDR_LEN          ),
    .ADDR_LEN       ( MEM_ADDR_LEN           )
) main_mem_instance (
    .clk            ( clk                    ),
    .rst            ( rst                    ),
    .gnt            ( mem_gnt                ),
    .addr           ( mem_addr               ),
    .rd_req         ( mem_rd_req             ),
    .rd_line        ( mem_rd_line            ),
    .wr_req         ( mem_wr_req             ),
    .wr_line        ( mem_wr_line            )
);

endmodule





