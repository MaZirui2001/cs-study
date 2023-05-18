`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2022 01:57:46 PM
// Design Name: 
// Module Name: SRT_tb
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


module SRT_tb(

    );
    reg clk, rstn;
    reg [15:0] x;
    reg del, pre, nxt, exe, delay_clear;
    wire busy;
    wire [15:0] delay;
    wire [6:0] seg;
    wire [7:0] an;
        SRT_DIO inst_SRT_DIO
        (
            .clk         (clk),
            .rstn        (rstn),
            .x           (x),
            .del         (del),
            .pre         (pre),
            .nxt         (nxt),
            .exe         (exe),
            .delay_clear (delay_clear),
            .busy        (busy),
            .delay       (delay),
            .an          (an),
            .seg         (seg)
        );
    initial begin
        clk = 0;
        forever #1 clk = ~clk;
    end
    initial begin
        rstn = 0;
        #10 rstn = 1;
    end
    initial begin
        x= 0;
        del = 0;
        pre = 0;
        nxt = 0;
        exe = 1;
        delay_clear = 0;
    end

endmodule
