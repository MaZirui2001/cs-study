`timescale 1ns / 1ps
module debounce_test(
    input           clk,
    input           rstn,
    input           x,
    input           sel,
    output  [7:0]   an,
    output  [6:0]   seg
    );
    wire stable_dout, dout, increase;
    wire [31:0] seg_num;
    DB inst_DB (
        .clk         (clk), 
        .rstn        (rstn),
        .din         (x), 
        .stable_dout (stable_dout)
    );
    assign dout = sel ? stable_dout : x;
    PS inst_PS (
        .clk (clk), 
        .s   (dout), 
        .p   (increase)
    );
    counter #(
        .WIDTH(32),
        .RST_VLU(32'h12345678)
    ) inst_counter (
        .clk   (clk),
        .rstn  (rstn),
        .pe    (0),
        .ce    (increase),
        .d     (0),
        .count (seg_num)
    );
    DIS inst_DIS (
        .clk  (clk), 
        .rstn (rstn), 
        .din  (seg_num), 
        .an   (an), 
        .seg  (seg)
    );
endmodule
