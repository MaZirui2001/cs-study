`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/28/2022 09:17:00 PM
// Design Name: 
// Module Name: seg_decoder
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


module seg_decoder(
    input       [3:0] din,
    output reg  [6:0] digit_dout
    );
    always @(*) begin
        case(din)
        4'h0: digit_dout = 7'b0000001;
        4'h1: digit_dout = 7'b1001111;
        4'h2: digit_dout = 7'b0010010;
        4'h3: digit_dout = 7'b0000110;
        4'h4: digit_dout = 7'b1001100;
        4'h5: digit_dout = 7'b0100100;
        4'h6: digit_dout = 7'b0100000;
        4'h7: digit_dout = 7'b0001111;
        4'h8: digit_dout = 7'b0000000;
        4'h9: digit_dout = 7'b0000100;
        4'ha: digit_dout = 7'b0001000;
        4'hb: digit_dout = 7'b1100000;
        4'hc: digit_dout = 7'b0110001;
        4'hd: digit_dout = 7'b1000010;
        4'he: digit_dout = 7'b0110000;
        4'hf: digit_dout = 7'b0111000;
        endcase
    end

endmodule
