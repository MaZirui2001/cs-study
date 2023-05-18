`timescale 1ns / 1ps
module mul_wallce(
    input   [ 7:0] s1,
    input   [ 7:0] s2,
    output  [15:0] product
    );
    wire[15:0] c1, c2, c3, c4, c5, c6;
    wire[15:0] sum1, sum2, sum3, sum4, sum5, sum6;
    carry_keep_adder adder1_1(
        .s1     ({8'b0, s1 & {8{s2[0]}}}),
        .s2     ({7'b0, s1 & {8{s2[1]}}, 1'b0}),
        .s3     ({6'b0, s1 & {8{s2[2]}}, 2'b0}),
        .carry  (c1),
        .sum    (sum1)
    );
    carry_keep_adder adder1_2(
        .s1     ({5'b0, s1 & {8{s2[3]}}, 3'b0}),
        .s2     ({4'b0, s1 & {8{s2[4]}}, 4'b0}),
        .s3     ({3'b0, s1 & {8{s2[5]}}, 5'b0}),
        .carry  (c2),
        .sum    (sum2)
    );
    carry_keep_adder adder2_1(
        .s1     (sum1),
        .s2     ({1'b0, s1 & {8{s2[7]}}, 7'b0}),
        .s3     ({2'b0, s1 & {8{s2[6]}}, 6'b0}),
        .carry  (c3),
        .sum    (sum3)
    );
    carry_keep_adder adder2_2(
        .s1     (c2),
        .s2     (sum2),
        .s3     (c1),
        .carry  (c4),
        .sum    (sum4)
    );
    carry_keep_adder adder3_1(
        .s1     (c3),
        .s2     (sum3),
        .s3     (c4),
        .carry  (c5),
        .sum    (sum5)
    );
    carry_keep_adder adder4_1(
        .s1     (c5),
        .s2     (sum5),
        .s3     (sum4),
        .carry  (c6),
        .sum    (sum6)
    );
    LCA adder_final(
        .s1     (c6),
        .s2     (sum6),
        .cin    (0),
        .sum    (product),
        .cout   ()
    );

endmodule
