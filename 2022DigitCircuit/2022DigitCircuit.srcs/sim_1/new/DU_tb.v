`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/11/10 17:36:21
// Design Name: 
// Module Name: DU_tb
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


module DU_tb(

    );
    reg clk, rstn;
    wire vs, hs;
    wire [11:0] rgb;
    DU DU_dut (
      .clk (clk ),
      .rstn (rstn ),
      .hs (hs ),
      .vs (vs ),
      .rgb  ( rgb)
    );
    initial begin
      clk = 1;
      forever #1 clk = ~clk;
    end
    initial begin
      rstn = 0;
      #10 rstn =1;
    end
  
endmodule
