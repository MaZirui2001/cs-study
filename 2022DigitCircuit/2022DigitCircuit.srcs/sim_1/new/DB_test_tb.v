`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/28/2022 10:43:50 PM
// Design Name: 
// Module Name: DB_test_tb
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


module DB_test_tb(

    );
    reg clk,rstn, sel, x;
    wire[7:0] an;
    wire [6:0] seg;
    debounce_test inst_debounce_test (.clk(clk), .rstn(rstn), .x(x), .sel(sel), .an(an), .seg(seg));
    initial begin
        clk = 0;
        forever #1 clk = ~clk;
    end
    initial begin
        rstn = 0;
        #4 rstn = 1;
    end
    initial begin
        x = 1;
        sel = 1;
    end

endmodule
