`timescale 1ns / 1ps

module mux2_1 #(
    parameter W = 4
)(
    input       [W-1:0] din1,
    input       [W-1:0] din2,
    input               sel,
    output reg  [W-1:0] dout
);
    always @(*) begin
        case(sel)
        1'b0: dout = din1;
        1'b1: dout = din2;
        endcase
    end
endmodule
