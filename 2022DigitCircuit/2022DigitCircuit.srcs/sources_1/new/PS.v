`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/27/2022 11:20:24 PM
// Design Name: 
// Module Name: PS
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


module PS#(
    parameter W = 1
    )(
    input               clk,
    input   [W-1:0]     s,
    output reg  [W-1:0] p
    );
    reg [W-1:0] s1, s2;
    always @(posedge clk) begin
        s1 <= s;
        s2 <= s1;
        p  <= s1 & ~s2;
    end
endmodule
