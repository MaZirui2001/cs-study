`timescale 1ns / 1ps

module LCA#(
    parameter W = 16
    )(
    input   [W-1:0] s1,
    input   [W-1:0] s2,
    input           cin,
    output  [W-1:0] sum,
    output          cout
    );
    wire [W-1:0] p, g;
    wire [W:0] c;
    assign c[0] = cin;
    assign p = s1 ^ s2;
    assign g = s1 & s2;
    genvar i;
    for(i = 0; i < W; i = i + 1) begin
        assign c[i+1] = g[i] | (p[i] & c[i]);
    end
    
    assign cout = c[W];
    assign sum = p ^ c[W-1:0];
endmodule
