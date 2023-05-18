`timescale 1ns / 1ps

module comparer#(
    parameter W = 8
    )(
    input [W-1:0] s1,
    input [W-1:0] s2,
    output        ug,
    output        ul,
    output        sg,
    output        sl
    );
    wire [W:0] result;
    wire f;
    LCA#(W+1) comp(
        .s1     ({s1[W-1], s1}),
        .s2     (~{s2[W-1], s2}),
        .cin    (1'b1),
        .sum    (result),
        .cout   (f)
    );
    assign ug = f && result[W-1:0];
    assign ul = ~f && result[W-1:0];
    assign sl = result[W] && result[W-1:0];
    assign sg = ~result[W] && result[W-1:0];
endmodule
