`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/28/2022 09:27:52 PM
// Design Name: 
// Module Name: DIS
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


module DIS(
    input           clk,
    input           rstn,
    input   [31:0]  din,
    output  [7:0]   an,
    output  [6:0]   seg
    );
    wire pclk;
    reg [7:0] count;
    wire [3:0] seg_din;
    fre_div inst_fre_div (
        .clk    (clk), 
        .rstn   (rstn), 
        .k      (25'd250000), 
        .pclk   (pclk)
    );
    seg_decoder inst_seg_decoder (
        .din        (seg_din), 
        .digit_dout (seg)
    );
    always @(posedge pclk or negedge rstn) begin
        if(~rstn) count <= 8'b00000001;
        else count <= {count[6:0], count[7]};
    end

    assign an = ~count;
    assign seg_din = din[ 3: 0] & {4{count[0]}}
                   | din[ 7: 4] & {4{count[1]}}
                   | din[11: 8] & {4{count[2]}}
                   | din[15:12] & {4{count[3]}}
                   | din[19:16] & {4{count[4]}}
                   | din[23:20] & {4{count[5]}}
                   | din[27:24] & {4{count[6]}}
                   | din[31:28] & {4{count[7]}};
endmodule
