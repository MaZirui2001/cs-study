`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/28/2022 08:55:37 PM
// Design Name: 
// Module Name: fre_div_tb
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


module fre_div_tb(

    );
    reg clk, rstn;
    reg [24:0] k;
    wire pclk;
    fre_div inst_fre_div (
        .clk(clk), 
        .rstn(rstn), 
        .k(k), 
        .pclk(pclk)
    );
    initial begin
        k = 5;
        clk = 0;
        forever #1 clk = ~clk;
    end
    initial begin
        rstn = 0;
        #4 rstn = 1;
    end

endmodule
