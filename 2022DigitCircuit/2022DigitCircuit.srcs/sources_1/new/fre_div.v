`timescale 1ns / 1ps

module fre_div(
    input clk,
    input rstn,
    input [24:0] k,
    output reg pclk
    );
    wire [24:0] k_low = k + 1;
    wire [24:0] high = {1'b0, k[24:1]};
    wire [24:0] low = {1'b0, k_low[24:1]};
    reg [24:0] count;
    always @(posedge clk) begin
        if(!rstn) pclk <= 0;
        else if(count < low) pclk <= 0;
        else pclk <= 1;
    end

    always @(posedge clk) begin
        if(!rstn) count <= 0;
        else if(count == k - 1) count <= 0;
        else count <= count + 1;
    end
endmodule
