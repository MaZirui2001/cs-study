`timescale 1ns / 1ps

module coder(
    input             e,
    input       [9:0] a,
    input       [3:0] b,
    output            f,
    output      [3:0] d,
    output      [9:0] y,
    output      [6:0] yn,
    output            dp,
    output      [7:0] an
    );
    assign dp = 1;
    assign an = 8'hfe;
    wire [3:0] code;
    
    encoder_8421 encoder(
        .din        (a),
        .e          (e),
        .dout       (d),
        .f          (f)
    );
    mux2_1 decoder_input_mux(
        .din1       (b),
        .din2       (d),
        .sel        (f),
        .dout       (code)
    );
    decoder_8421 decoder(
        .din        (code),
        .led_dout   (y),
        .digit_dout (yn)
    );
endmodule
