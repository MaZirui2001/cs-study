`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2022 11:11:48 AM
// Design Name: 
// Module Name: delay_count
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


module delay_count(
    input               clk,
    input               rstn,
    input               busy,
    input               clear,
    output reg  [15:0]  delay
    );
    always @(posedge clk) begin
        if(~rstn) delay <= 0;
        else if(clear) delay <= 0;
        else if(busy) delay  <= delay + 1;
    end
endmodule
