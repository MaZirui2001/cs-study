`timescale 1ns / 1ps

module mul_booth_wallce(
    input [7:0] s1,
    input [7:0] s2,
    output [15:0] product
    );
    wire [15:0] code1, code2, code3, code4;
    wire [15:0] sum1, sum2;
    wire [15:0] c1, c2;
    encode_booth encoder1(
        .y1     (s2[5]),
        .y2     (s2[6]),
        .y3     (s2[7]),
        .din    ({8'b0, s1}),
        .dout   (code4)
    );
    encode_booth encoder2(
        .y1     (s2[3]),
        .y2     (s2[4]),
        .y3     (s2[5]),
        .din    ({8'b0, s1}),
        .dout   (code3)
    );
    encode_booth encoder3(
        .y1     (s2[1]),
        .y2     (s2[2]),
        .y3     (s2[3]),
        .din    ({8'b0, s1}),
        .dout   (code2)
    );
    encode_booth encoder4(
        .y1     (0),
        .y2     (s2[0]),
        .y3     (s2[1]),
        .din    ({8'b0, s1}),
        .dout   (code1)
    );
    carry_keep_adder adder1(
        .s1     (code1),
        .s2     ({code2[13:0], 2'b0}),
        .s3     ({code3[11:0], 4'b0}),
        .carry  (c1),
        .sum    (sum1)
    );
    carry_keep_adder adder2(
        .s1     ({code4[9:0], 6'b0}),
        .s2     (c1),
        .s3     (sum1),
        .carry  (c2),
        .sum    (sum2)
    );
    LCA adder_final(
        .s1     (c2),
        .s2     (sum2),
        .cin    (0),
        .sum    (product),
        .cout   ()
    );
endmodule
