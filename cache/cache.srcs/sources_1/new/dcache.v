`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/12 15:39:26
// Design Name: 
// Module Name: dcache
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


module dcache #(
    parameter INDEX_WIDTH       = 4,
    parameter WORD_OFFSET_WIDTH = 2
)(
    input                   clk,
    input                   rstn,
    /* from pipeline */
    input [31:0]            addr,
    // read
    input                   rvalid,
    output reg              rready,
    output [31:0]           rdata,
    //write
    input                   wvalid,
    output reg              wready,
    input [31:0]            wdata,
    input [3:0]             wstrb,

    /* from AXI arbiter */
    // read
    output reg              d_rvalid,
    input                   d_rready,
    output [31:0]           d_raddr,
    input [31:0]            d_rdata,
    input                   d_rlast,
    output [2:0]            d_rsize,
    output [7:0]            d_rlen,
    // write
    output reg              d_wvalid,
    input                   d_wready,
    output [31:0]           d_waddr,
    output [31:0]           d_wdata,
    output [3:0]            d_wstrb,
    output reg              d_wlast,
    output [2:0]            d_wsize,
    output [7:0]            d_wlen,

    // back
    input                   d_bvalid,
    output reg              d_bready
);
    localparam 
        BYTE_OFFSET_WIDTH   = WORD_OFFSET_WIDTH + 2,                // total offset bits
        TAG_WIDTH           = 32 - BYTE_OFFSET_WIDTH - INDEX_WIDTH, // tag bits
        SET_NUM             = 1 << INDEX_WIDTH,                     // block(set) number of one Road
        WORD_NUM            = 1 << WORD_OFFSET_WIDTH,               // words per block(set)
        BYTE_NUM            = 1 << BYTE_OFFSET_WIDTH,               // bytes per block(set)
        BIT_NUM             = BYTE_NUM << 3;                        // bits per block(set)                     

    // request buffer
    reg     [67:0]              req_buf;
    reg                         req_buf_we;
    wire    [31:0]              wdata_pipe, address;
    wire    [3:0]               wstrb_pipe;
    wire                        we_pipe;

    // return buffer
    reg     [BIT_NUM-1:0]       ret_buf;

    // data memory
    wire    [INDEX_WIDTH-1:0]   r_index, w_index;
    reg     [BYTE_NUM-1:0]      mem_we [0:1];
    wire    [BIT_NUM-1:0]       mem_rdata [0:1];
    reg     [BIT_NUM-1:0]       mem_wdata;

    // tagv memory
    reg     [1:0]               tagv_we;           
    wire    [TAG_WIDTH-1:0]     w_tag;
    wire    [TAG_WIDTH:0]       tag_rdata [0:1]; 

    // hit
    wire    [1:0]               hit;
    wire                        cache_hit;
    wire    [TAG_WIDTH-1:0]     tag;
    wire                        hit_way;

    // wdata control
    wire    [BIT_NUM-1:0]       wdata_pipe_512;
    wire    [BIT_NUM-1:0]       wstrb_pipe_512;
    reg                         wdata_from_pipe;

    // rdata control
    reg     [BIT_NUM-1:0]       rdata_512;
    reg                         data_from_mem;

    // LRU replace
    reg     [SET_NUM-1:0]       LRU;
    reg                         lru_update_by_hit;
    reg                         lru_update_by_refill;
    wire                        lru_sel;

    // dirty table
    reg     [SET_NUM-1:0]       dirty [0:1];
    reg                         dirty_clear [0:1];
    reg                         dirty_write [0:1];
    wire                        dirty_info;

    // write back buffer
    reg     [BIT_NUM-1:0]       wbuf;
    reg                         wbuf_we;

    // miss buffer
    reg     [31:0]              m_buf;
    reg                         mbuf_we;

    // communication between write fsm and main fsm
    reg                         wfsm_en, wfsm_reset, wrt_finish;

    // a counter for write back
    reg     [3:0]               write_counter;
    reg                         write_counter_reset, write_counter_en;

    // statistics
    reg     [63:0]              total_time;
    reg     [63:0]              total_hit;

    /* request buffer : lock the read request addr */
    // [31:0] addr, [63:32] wdata [67:64] wstrb
    always @(posedge clk) begin
        if(!rstn) begin
            req_buf <= 0;
        end
        else if(req_buf_we) begin
            req_buf <= {wstrb, wdata, addr};
        end
    end
    assign address      = req_buf[31:0];
    assign wdata_pipe   = req_buf[63:32];
    assign wstrb_pipe   = req_buf[67:64];
    assign we_pipe      = |wstrb_pipe;

    /* return buffer : cat the return data */
    always @(posedge clk) begin
        if(!rstn) begin
            ret_buf <= 0;
        end
        else if(d_rvalid && d_rready) begin
            ret_buf <= {d_rdata, ret_buf[BIT_NUM-1:32]};
        end
    end

    /* 2-way data memory */
    assign r_index = addr[BYTE_OFFSET_WIDTH+INDEX_WIDTH-1:BYTE_OFFSET_WIDTH];
    assign w_index = address[BYTE_OFFSET_WIDTH+INDEX_WIDTH-1:BYTE_OFFSET_WIDTH];

    BRAM_bytewrite #(
        .DATA_WIDTH   (BIT_NUM),
        .ADDR_WIDTH   (INDEX_WIDTH)
    )
    data_mem0 (
        .clk      (clk ),
        .raddr    (r_index),
        .waddr    (w_index),
        .din      (mem_wdata),
        .we       (mem_we[0]),
        .dout     (mem_rdata[0])
    );
    BRAM_bytewrite #(
        .DATA_WIDTH   (BIT_NUM),
        .ADDR_WIDTH   (INDEX_WIDTH)
    )
    data_mem1 (
        .clk      (clk ),
        .raddr    (r_index),
        .waddr    (w_index),
        .din      (mem_wdata),
        .we       (mem_we[1]),
        .dout     (mem_rdata[1])
    );

    /* 2-way tagv memory */
    assign w_tag = address[31:32-TAG_WIDTH];
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

    /* hit */
    assign tag          = address[31:32-TAG_WIDTH];
    assign hit[0]       = tag_rdata[0][TAG_WIDTH] && (tag_rdata[0][TAG_WIDTH-1:0] == tag);
    assign hit[1]       = tag_rdata[1][TAG_WIDTH] && (tag_rdata[1][TAG_WIDTH-1:0] == tag);
    assign cache_hit    = |hit;
    assign hit_way      = hit[0] ? 0 : 1;

    /* write control */
    assign wdata_pipe_512 = ({{(BIT_NUM-32){1'b0}}, wdata_pipe} << address[1:0]) << {address[BYTE_OFFSET_WIDTH-1:2], 5'b0};
    assign wstrb_pipe_512 = {
            {(BIT_NUM-32){1'b0}}, ({{8{wstrb_pipe[3]}}, {8{wstrb_pipe[2]}}, {8{wstrb_pipe[1]}}, {8{wstrb_pipe[0]}}})
        } << {address[BYTE_OFFSET_WIDTH-1:2], 5'b0};
    always @(*) begin
        if(wdata_from_pipe) begin
            mem_wdata = wdata_pipe_512;
        end
        else begin
            mem_wdata = ret_buf & ~wstrb_pipe_512 | wdata_pipe_512 & wstrb_pipe_512;
        end
    end

    /* read control */
    assign rdata = rdata_512[31:0];
    always @(*) begin
        if(data_from_mem) begin
            rdata_512 = (mem_rdata[0] & {BIT_NUM{hit[0]}} | mem_rdata[1] & {BIT_NUM{hit[1]}}) >> {address[BYTE_OFFSET_WIDTH-1:2], 5'b0};
        end
        else begin
            rdata_512 = ret_buf >> ({address[BYTE_OFFSET_WIDTH-1:2], 5'b0});
        end
    end

    /* LRU replace */
    always @(posedge clk) begin
        if(!rstn) begin
            LRU <= 0;
        end
        else if(lru_update_by_hit) begin
            LRU[w_index] <= hit_way;
        end
        else if(lru_update_by_refill) begin
            LRU[w_index] <= ~LRU[w_index];
        end
    end
    assign lru_sel = LRU[w_index];

    /* dirty table */
    assign dirty_info = dirty[lru_sel][w_index];
    always @(posedge clk) begin
        if(!rstn) begin
            dirty[0] <= 0;
        end
        else if(dirty_clear[0]) begin
            dirty[0][w_index] <= 0;
        end
        else if(dirty_write[0]) begin
            dirty[0][w_index] <= 1;
        end
    end
    always @(posedge clk) begin
        if(!rstn) begin
            dirty[1] <= 0;
        end
        else if(dirty_clear[1]) begin
            dirty[1][w_index] <= 0;
        end
        else if(dirty_write[1]) begin
            dirty[1][w_index] <= 1;
        end
    end

    /* write buffer */
    always @(posedge clk) begin
        if(!rstn) begin
            wbuf <= 0;
        end
        else if(wbuf_we) begin
            wbuf <= lru_sel ? mem_rdata[1] : mem_rdata[0];
        end
        else if(d_wvalid && d_wready) begin
            wbuf <= {32'b0, wbuf[BIT_NUM-1:32]};
        end
    end

    /* miss buffer */
    always @(posedge clk) begin
        if(!rstn) begin
            m_buf <= 0;
        end
        else if(mbuf_we) begin
            m_buf <= {
                (lru_sel ? tag_rdata[1][TAG_WIDTH-1:0] : tag_rdata[0][TAG_WIDTH-1:0]),  // writeback tag
                address[BYTE_OFFSET_WIDTH+INDEX_WIDTH-1:BYTE_OFFSET_WIDTH],             // writeback index
                {BYTE_OFFSET_WIDTH{1'b0}}
            };
        end
    end
    
    /* memory visit settings*/
    assign d_raddr  = {address[31:BYTE_OFFSET_WIDTH], {BYTE_OFFSET_WIDTH{1'b0}}};
    assign d_rsize  = 3'h2;
    assign d_rlen   = WORD_NUM - 1;
    assign d_waddr  = m_buf;
    assign d_wsize  = 3'h2;
    assign d_wlen   = WORD_NUM - 1;
    assign d_wdata  = wbuf[31:0];
    assign d_wstrb  = 4'b1111;

    /* main FSM */
    localparam 
        IDLE        = 3'd0,
        LOOKUP      = 3'd1,
        MISS        = 3'd2,
        REFILL      = 3'd3,
        WAIT_WRITE  = 3'd4;
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
            if(rvalid || wvalid) begin
                next_state = LOOKUP;
            end
            else begin
                next_state = IDLE;
            end
        end
        LOOKUP: begin
            if(cache_hit) begin
                next_state = (rvalid || wvalid) ? LOOKUP : IDLE;
            end
            else begin
                next_state = MISS;
            end
        end
        MISS: begin
            if(d_rvalid && d_rready && d_rlast) begin
                next_state = REFILL;
            end
            else begin
                next_state = MISS;
            end
        end
        REFILL: begin
            next_state = WAIT_WRITE;
        end
        WAIT_WRITE: begin
            if(wrt_finish) begin
                next_state = (rvalid || wvalid) ? LOOKUP : IDLE;
            end
            else begin
                next_state = WAIT_WRITE;
            end
        end
        default: begin
            next_state = IDLE;
        end
        endcase
    end
    always @(*) begin
        // default assignments
        req_buf_we           = 0;
        wbuf_we              = 0;
        mbuf_we              = 0;
        d_rvalid             = 0;
        wfsm_en              = 0;
        wfsm_reset           = 0;
        mem_we[0]            = 0;
        mem_we[1]            = 0;
        tagv_we[0]           = 0;
        tagv_we[1]           = 0;
        dirty_clear[0]       = 0;
        dirty_clear[1]       = 0;
        dirty_write[0]       = 0;
        dirty_write[1]       = 0;
        lru_update_by_hit    = 0;
        lru_update_by_refill = 0;
        rready               = 0;
        wready               = 0;
        data_from_mem        = 1;
        wdata_from_pipe      = 1;
        case(state)
        IDLE: begin
            req_buf_we = 1;
        end
        LOOKUP: begin
            if(cache_hit) begin
                mem_we[hit_way]         = {{(BYTE_NUM-4){1'b0}}, wstrb_pipe} << {address[BYTE_OFFSET_WIDTH-1:2], 2'b0};
                req_buf_we              = (rvalid || wvalid);
                dirty_write[hit_way]    = we_pipe;
                lru_update_by_hit       = 1;
                rready                  = !we_pipe;
                wready                  = we_pipe;
            end
            else begin
                wbuf_we = 1;
                mbuf_we = 1;
                wfsm_en = 1;
            end
        end
        MISS: begin
            d_rvalid = 1;
        end
        REFILL: begin
            tagv_we[lru_sel]        = 1;
            mem_we[lru_sel]         = -1;
            dirty_write[lru_sel]    = we_pipe;
            dirty_clear[lru_sel]    = !we_pipe;
            lru_update_by_refill    = 1;
            wdata_from_pipe         = 0;
        end
        WAIT_WRITE: begin
            wfsm_reset      = 1;
            rready          = wrt_finish & !we_pipe;
            wready          = wrt_finish & we_pipe;
            data_from_mem   = 0;
            req_buf_we      = wrt_finish & (rvalid || wvalid);
        end
        endcase
    end

    /* write fsm */
    localparam 
        INIT    = 3'd0,
        WRITE   = 3'd1,
        FINISH  = 3'd2;
    reg [2:0] wfsm_state, wfsm_next_state;
    /* counter of write back */
    always @(posedge clk) begin
        if(!rstn) begin
            write_counter <= 0;
        end
        else if(write_counter_reset) begin
            write_counter <= 0;
        end
        else if(write_counter_en) begin
            write_counter <= write_counter == WORD_NUM-1 ? WORD_NUM-1 : write_counter + 1;
        end
    end
    /* stage 1 */
    always @(posedge clk) begin
        if(!rstn) begin
            wfsm_state <= INIT;
        end
        else begin
            wfsm_state <= wfsm_next_state;
        end
    end
    /* stage 2 */
    always @(*) begin
        case(wfsm_state)
        INIT: begin
            if(wfsm_en) begin
                wfsm_next_state = dirty_info ? WRITE : FINISH;
            end
            else begin
                wfsm_next_state = INIT;
            end
        end
        WRITE: begin
            if(d_bvalid && d_bready) begin
                wfsm_next_state = FINISH;
            end
            else begin
                wfsm_next_state = WRITE;
            end
        end
        FINISH: begin
            if(wfsm_reset) begin
                wfsm_next_state = INIT;
            end
            else begin
                wfsm_next_state = FINISH;
            end
        end
        default: begin
            wfsm_next_state = INIT;
        end
        endcase
    end
    /* stage 3 */
    always @(*) begin
        wrt_finish          = 0;
        write_counter_reset = 0;
        write_counter_en    = 0;
        d_wvalid            = 0;
        d_wlast             = 0;
        d_bready            = 0;
        case(wfsm_state)
        INIT: begin
            write_counter_reset = 1;
        end
        WRITE: begin
            d_wvalid            = 1;
            d_wlast             = (write_counter == WORD_NUM-1);
            write_counter_en    = d_wready;
            d_bready            = 1;
        end
        FINISH: begin
            wrt_finish = 1;
        end
        endcase
    end
    always @(posedge clk) begin
        if(!rstn) begin
            total_time <= 0;
            total_hit <= 0;
        end
        else if(state == LOOKUP) begin
            total_hit <= total_hit + {63'b0, cache_hit};
            total_time <= total_time + 1;
        end
    end
endmodule
