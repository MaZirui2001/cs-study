`timescale 1ns / 1ps
module carry_keep_adder#(
    parameter W = 16
    )(
    input   [W-1:0] s1,
    input   [W-1:0] s2,
    input   [W-1:0] s3,
    output  [W-1:0] carry,
    output  [W-1:0] sum
    );
    // genvar i;
    wire [W-1:0] c;
    // for(i = 0; i < W; i = i + 1) begin
    //     assign {c[i], sum[i]} = s1[i] + s2[i] + s3[i];
    // end
    // assign carry = {c[W-2:0], 1'b0};
    assign sum = s1 ^ s2 ^ s3;
    assign c = s1 & s2 | s1 & s3 | s2 & s3;
    assign carry = {c[W-2:0], 1'b0};
endmodule
