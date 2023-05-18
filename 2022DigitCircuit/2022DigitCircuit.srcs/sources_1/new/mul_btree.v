`timescale 1ns / 1ps

module mul_btree(
    input [7:0] s1,
    input [7:0] s2,
    output [15:0] product
    );
    wire [15:0] res1_1, res1_2, res1_3, res1_4;
    wire [15:0] res2_1, res2_2;
    LCA adder1_1(
        .s1     ({8'b0, s1}       & {16{s2[0]}}),
        .s2     ({7'b0, s1, 1'b0} & {16{s2[1]}}),
        .cin    (0),
        .sum    (res1_1),
        .cout   ()
    );
    LCA adder1_2(
        .s1     ({6'b0, s1, 2'b0} & {16{s2[2]}}),
        .s2     ({5'b0, s1, 3'b0} & {16{s2[3]}}),
        .cin    (0),
        .sum    (res1_2),
        .cout   ()
    );
    LCA adder1_3(
        .s1     ({4'b0, s1, 4'b0} & {16{s2[4]}}),
        .s2     ({3'b0, s1, 5'b0} & {16{s2[5]}}),
        .cin    (0),
        .sum    (res1_3),
        .cout   ()
    );
    LCA adder1_4(
        .s1     ({2'b0, s1, 6'b0} & {16{s2[6]}}),
        .s2     ({1'b0, s1, 7'b0} & {16{s2[7]}}),
        .cin    (0),
        .sum    (res1_4),
        .cout   ()
    );
    LCA adder2_1(
        .s1     (res1_1),
        .s2     (res1_2),
        .cin    (0),
        .sum    (res2_1),
        .cout   ()
    );
    LCA adder2_2(
        .s1     (res1_3),
        .s2     (res1_4),
        .cin    (0),
        .sum    (res2_2),
        .cout   ()
    );
    LCA adder3_1(
        .s1     (res2_1),
        .s2     (res2_2),
        .cin    (0),
        .sum    (product),
        .cout   ()
    );


endmodule
