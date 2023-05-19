
`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/10/2023 07:42:39 PM
// Design Name: 
// Module Name: icache
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module icache #(
    parameter INDEX_WIDTH       = 4,
    parameter WORD_OFFSET_WIDTH = 2
)(
    input               clk,
    input               rstn,
    // from pipeline 
    input               rvalid,
    output reg          rready,
    input [31:0]        raddr,
    output [31:0]       rdata,
    // from AXI arbiter
    output reg          i_rvalid,
    input               i_rready,
    output [31:0]       i_raddr,
    input [31:0]        i_rdata,
    input               i_rlast,
    output [2:0]        i_rsize,
    output [7:0]        i_rlen
);
    localparam 
        BYTE_OFFSET_WIDTH   = WORD_OFFSET_WIDTH + 2,
        TAG_WIDTH           = 32 - BYTE_OFFSET_WIDTH - INDEX_WIDTH,
        SET_NUM             = 1 << INDEX_WIDTH,
        WORD_NUM            = 1 << WORD_OFFSET_WIDTH,
        BYTE_NUM            = 1 << BYTE_OFFSET_WIDTH,
        BIT_NUM             = BYTE_NUM << 3;
    reg     [31:0]              req_buf;
    reg                         req_buf_we;

    reg     [BIT_NUM-1:0]       ret_buf;

    wire    [INDEX_WIDTH-1:0]   r_index, w_index;
    reg     [1:0]               mem_we;                
    wire    [BIT_NUM-1:0]       mem_rdata [0:1];     

    reg     [1:0]               tagv_we;          
    wire    [TAG_WIDTH-1:0]     w_tag;
    wire    [TAG_WIDTH:0]       tag_rdata [0:1]; 

    wire    [1:0]               hit;
    wire                        cache_hit;
    wire    [TAG_WIDTH-1:0]     tag;

    reg     [SET_NUM-1:0]       LRU;
    reg                         lru_update;

    reg     [BIT_NUM-1:0]       rdata_512;
    reg                         data_from_mem;

    /* request buffer : lock the read request addr */
    always @(posedge clk) begin
        if(!rstn) begin
            req_buf <= 0;
        end
        else if(req_buf_we) begin
            req_buf <= raddr;
        end
    end

    /* return buffer : cat the return data */
    always @(posedge clk) begin
        if(!rstn) begin
            ret_buf <= 0;
        end
        else if(i_rvalid && i_rready) begin
            ret_buf <= {i_rdata, ret_buf[BIT_NUM-1:32]};
        end
    end

    /* 2-way data memory */
    assign r_index = raddr[BYTE_OFFSET_WIDTH+INDEX_WIDTH-1:BYTE_OFFSET_WIDTH];
    assign w_index = req_buf[BYTE_OFFSET_WIDTH+INDEX_WIDTH-1:BYTE_OFFSET_WIDTH];

    BRAM_common #(
      .DATA_WIDTH(BIT_NUM),
      .ADDR_WIDTH (INDEX_WIDTH)
    ) data_mem0 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      (ret_buf),
      .we       (mem_we[0]),
      .dout     (mem_rdata[0])
    );
    BRAM_common #(
      .DATA_WIDTH(BIT_NUM),
      .ADDR_WIDTH (INDEX_WIDTH)
    ) data_mem1 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      (ret_buf),
      .we       (mem_we[1]),
      .dout     (mem_rdata[1])
    );

    /* 2-way tagv memory */
    assign w_tag = req_buf[31:32-TAG_WIDTH];
    BRAM_common #(
      .DATA_WIDTH(TAG_WIDTH+1),
      .ADDR_WIDTH (INDEX_WIDTH)
    ) tagv_mem0 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      ({1'b1, w_tag}),
      .we       (tagv_we[0]),
      .dout     (tag_rdata[0])
    );
    BRAM_common #(
      .DATA_WIDTH(TAG_WIDTH+1),
      .ADDR_WIDTH (INDEX_WIDTH)
    ) tagv_mem1 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      ({1'b1, w_tag}),
      .we       (tagv_we[1]),
      .dout     (tag_rdata[1])
    );
    
    /* settings of miss request */
    assign i_rlen   = WORD_NUM-1;
    assign i_rsize  = 3'h2;
    assign i_raddr  = {req_buf[31:BYTE_OFFSET_WIDTH], {BYTE_OFFSET_WIDTH{1'b0}}};

    /* hit */
    assign tag = req_buf[31:32-TAG_WIDTH];
    assign hit[0] = tag_rdata[0][TAG_WIDTH-1:0] == tag && tag_rdata[0][TAG_WIDTH];
    assign hit[1] = tag_rdata[1][TAG_WIDTH-1:0] == tag && tag_rdata[1][TAG_WIDTH];
    assign cache_hit = |hit;
    

    /* read control */
    assign rdata = rdata_512[31:0];
    always @(*) begin
        if(data_from_mem) begin
            rdata_512 = (mem_rdata[0] & {BIT_NUM{hit[0]}} | mem_rdata[1] & {BIT_NUM{hit[1]}}) >> {req_buf[BYTE_OFFSET_WIDTH-1:2], 5'b0};
        end
        else begin
            rdata_512 = ret_buf >> ({req_buf[BYTE_OFFSET_WIDTH-1:2], 5'b0});
        end
    end
    
    /* LRU */
    always @(posedge clk) begin
        if(!rstn) begin
            LRU <= 0;
        end
        else if(lru_update) begin
            LRU[w_index] <= cache_hit ? (hit[0] ? 0 : 1) : ~LRU[w_index];
        end
    end
    /* state machine */
    localparam [2:0] 
        IDLE    = 3'b000, 
        LOOKUP  = 3'b001,
        MISS    = 3'b010, 
        REFILL  = 3'b011;
    reg [2:0] state, next_state;
    always @(posedge clk) begin
        if(!rstn) begin
            state <= IDLE;
        end
        else begin
            state <= next_state;
        end
    end
    always @(*) begin
        case(state)
            IDLE: begin
                if(rvalid) begin
                    next_state = LOOKUP;
                end
                else begin
                    next_state = IDLE;
                end
            end
            LOOKUP: begin
                // hit 
                if(cache_hit) begin
                    next_state = rvalid ? LOOKUP : IDLE;
                end
                // miss
                else begin
                    next_state = MISS;
                end
            end
            MISS: begin
                if(i_rvalid && i_rready && i_rlast) begin
                    next_state = REFILL;
                end
                else begin
                    next_state = MISS;
                end
            end
            REFILL: begin
                next_state = rvalid ? LOOKUP : IDLE;
            end
            default: begin
                next_state = IDLE;
            end
        endcase
    end
    always @(*) begin
        
        req_buf_we      = 0;
        i_rvalid        = 0;
        rready          = 0;
        tagv_we         = 0;
        mem_we          = 0;
        lru_update      = 0;
        data_from_mem   = 1;
        case(state)
        IDLE: begin
            req_buf_we  = 1;
        end
        LOOKUP: begin
            if(cache_hit) begin
                rready = 1;
                req_buf_we = rvalid;
                lru_update = 1;
            end
        end
        MISS: begin
            i_rvalid    = 1;
        end
        REFILL: begin
            tagv_we         = LRU[w_index] ? 1 : 2;
            mem_we          = LRU[w_index] ? 1 : 2;
            rready          = 1;
            lru_update      = 1;
            req_buf_we      = rvalid;
            data_from_mem   = 0;
        end
        default:;
        endcase
    end

endmodule