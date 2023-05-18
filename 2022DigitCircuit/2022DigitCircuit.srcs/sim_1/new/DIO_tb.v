`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2022 01:05:05 AM
// Design Name: 
// Module Name: DIO_tb
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


module DIO_tb(

    );
    reg clk, rstn;
    reg [15:0] x;
    reg del, pre, nxt;
    wire [7:0] an;
    wire [6:0] seg;
    initial begin
        rstn = 0;
        #10 rstn = 1;
        #10000000 rstn = 0;
    end
    initial begin
        clk = 0;
        forever #1 clk = ~clk;
    end
    initial begin
        x = 16'h8000;
        del = 0;
        nxt = 0;
        pre = 0;
    end
    DIO inst_DIO
        (
            .clk  (clk),
            .rstn (rstn),
            .x    (x),
            .del  (del),
            .pre  (pre),
            .nxt  (nxt),
            .an   (an),
            .seg  (seg)
        );

endmodule
