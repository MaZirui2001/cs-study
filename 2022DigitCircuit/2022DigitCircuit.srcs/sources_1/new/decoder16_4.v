`timescale 1ns / 1ps


module decoder16_4(
    input               clk,
    input   [15:0]      din,
    output reg  [3:0]   dout
    );
    always @(posedge clk) begin
        case(din)
        16'h0001: dout <= 4'h0;
        16'h0002: dout <= 4'h1;
        16'h0004: dout <= 4'h2;
        16'h0008: dout <= 4'h3;
        16'h0010: dout <= 4'h4;
        16'h0020: dout <= 4'h5;
        16'h0040: dout <= 4'h6;
        16'h0080: dout <= 4'h7;
        16'h0100: dout <= 4'h8;
        16'h0200: dout <= 4'h9;
        16'h0400: dout <= 4'ha;
        16'h0800: dout <= 4'hb;
        16'h1000: dout <= 4'hc;
        16'h2000: dout <= 4'hd;
        16'h4000: dout <= 4'he;
        16'h8000: dout <= 4'hf;
        default:  dout <= dout;     
        endcase   
    end
endmodule
