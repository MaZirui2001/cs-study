`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/29/2022 12:36:33 AM
// Design Name: 
// Module Name: timer_top
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


module timer_top(
    input           clk,
    input           rstn,
    input   [15:0]  tc,
    input           st,
    output          td,
    output  [7:0]   an,
    output  [6:0]   seg,
    output  [15:0]  input_time
    );  
    wire [15:0] q;
    assign input_time = tc;
    timer  inst_timer (
        .clk  (clk), 
        .rstn (rstn), 
        .tc   (tc), 
        .st   (st), 
        .q    (q), 
        .td   (td)
    );
    DIS inst_DIS (
        .clk  (clk), 
        .rstn (rstn), 
        .din  ({16'b0, q}), 
        .an   (an), 
        .seg  (seg)
    );


endmodule
