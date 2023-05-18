`timescale 1ns / 1ps
module mux3_1#(
    parameter W = 16
    )(
    input   [W-1:0]     din1,
    input   [W-1:0]     din2,
    input   [W-1:0]     din3,
    input   [1:0]       sel,
    output reg  [W-1:0] dout
    );
    always @(*) begin
        case(sel)
        2'b00: dout   = din1;
        2'b01: dout   = din2;
        2'b10: dout   = din3;
        default: dout = 0;
        endcase
    end
endmodule
