`timescale 1ns / 1ps


module register#(
    parameter W = 8
    )(
    input               clk,
    input               rstn,
    input       [W-1:0] din,
    input                we,
    output reg  [W-1:0] dout
    );
    always @(posedge clk) begin
        if(!rstn) dout <= 0;
        else if(we) dout <= din;
    end
endmodule
