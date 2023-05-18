`timescale 1ns / 1ps

module decoder_8421(
    input       [3:0] din,
    output reg  [9:0] led_dout,
    output reg  [6:0] digit_dout
    );
    always @(*) begin
        case(din)
        4'h0: led_dout = 10'h001;
        4'h1: led_dout = 10'h002;
        4'h2: led_dout = 10'h004;
        4'h3: led_dout = 10'h008;
        4'h4: led_dout = 10'h010;
        4'h5: led_dout = 10'h020;
        4'h6: led_dout = 10'h040;
        4'h7: led_dout = 10'h080;
        4'h8: led_dout = 10'h100;
        4'h9: led_dout = 10'h200;
        default: led_dout = 10'h000;
        endcase
    end
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
        default: digit_dout = 7'b1111111;
        endcase
    end
endmodule
