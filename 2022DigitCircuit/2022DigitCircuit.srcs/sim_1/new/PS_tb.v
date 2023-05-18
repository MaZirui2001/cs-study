`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/27/2022 11:23:52 PM
// Design Name: 
// Module Name: PS_tb
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


module PS_tb(

    );
    reg clk;
    reg s;
    wire p;
    initial begin
        clk = 1;
        forever #1 clk = ~clk;
    end
    initial begin
        s = 0;
        #4 s = 1;
    end
    PS inst_PS (.clk(clk), .s(s), .p(p));

endmodule
