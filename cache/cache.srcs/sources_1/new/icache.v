
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


module icache(
    input               clk,
    input               rstn,
    // from pipeline 
    input               rvalid,
    output reg          rready,
    input [31:0]        raddr,
    output reg [31:0]   rdata,
    // from AXI arbiter
    output reg          i_rvalid,
    input               i_rready,
    output reg [31:0]   i_raddr,
    input [31:0]        i_rdata,
    input               i_rlast,
    output [2:0]    i_rsize,
    output [7:0]    i_rlen
);
    /* request buffer : lock the read request addr */
    reg [31:0]  req_buf;
    reg req_buf_we;
    always @(posedge clk) begin
        if(!rstn) begin
            req_buf <= 0;
        end
        else if(req_buf_we) begin
            req_buf <= raddr;
        end
    end

    /* return buffer : cat the return data */
    reg [511:0] ret_buf;
    always @(posedge clk) begin
        if(!rstn) begin
            ret_buf <= 0;
        end
        else if(i_rvalid && i_rready) begin
            ret_buf <= {i_rdata, ret_buf[511:32]};
        end
    end

    /* 2-way data memory */
    wire [5:0] r_index, w_index;
    reg [1:0] mem_we;                  // [0]way0, [1]way1
    assign r_index = raddr[11:6];
    assign w_index = req_buf[11:6];
    wire [511:0] mem_rdata [0:1];       // [0]way0, [1]way1
    BRAM_common #(
      .DATA_WIDTH(512),
      .ADDR_WIDTH (6)
    ) data_mem0 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      (ret_buf),
      .we       (mem_we[0]),
      .dout     (mem_rdata[0])
    );
    BRAM_common #(
      .DATA_WIDTH(512),
      .ADDR_WIDTH (6)
    ) data_mem1 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      (ret_buf),
      .we       (mem_we[1]),
      .dout     (mem_rdata[1])
    );

    /* 2-way tagv memory */
    reg [1:0] tagv_we;           // [0]way0, [1]way1
    wire [19:0] w_tag;
    assign w_tag = req_buf[31:12];
    wire [20:0] tag_rdata [0:1]; // [0]way0, [1]way1
    BRAM_common #(
      .DATA_WIDTH(21),
      .ADDR_WIDTH (6)
    ) tagv_mem0 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      ({1'b1, w_tag}),
      .we       (tagv_we[0]),
      .dout     (tag_rdata[0])
    );
    BRAM_common #(
      .DATA_WIDTH(21),
      .ADDR_WIDTH (6)
    ) tagv_mem1 (
      .clk      (clk ),
      .raddr    (r_index),
      .waddr    (w_index),
      .din      ({1'b1, w_tag}),
      .we       (tagv_we[1]),
      .dout     (tag_rdata[1])
    );
    
    /* settings of miss request */
    assign i_rlen = 8'h10;
    assign i_rsize = 3'h4;

    /* hit */
    wire [1:0] hit;
    wire cache_hit;
    wire [19:0] tag;
    assign tag = req_buf[31:12];

    assign hit[0] = tag_rdata[0][19:0] == tag && tag_rdata[0][20];
    assign hit[1] = tag_rdata[1][19:0] == tag && tag_rdata[1][20];
    assign cache_hit = |hit;
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
                next_state = IDLE;
            end
            default: begin
                next_state = IDLE;
            end
        endcase
    end
    always @(*) begin
        i_raddr     = {req_buf[31:6], 6'b0};
        req_buf_we  = 0;
        i_rvalid    = 0;
        rready      = 0;
        tagv_we     = 0;
        mem_we      = 0;
        case(state)
        IDLE: begin
            req_buf_we  = 1;
        end
        LOOKUP: begin
            rready      = cache_hit;
            req_buf_we  = rvalid;
        end
        MISS: begin
            i_rvalid    = 1;
        end
        REFILL: begin
            tagv_we     = 1;
            mem_we      = 1;
            rready      = 1;
        end
        default:;
        endcase
    end

endmodule
