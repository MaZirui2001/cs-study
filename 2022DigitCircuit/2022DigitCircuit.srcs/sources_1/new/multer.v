`timescale 1ns / 1ps

module multer(
    input         clk,
    input         rstn,
    input   [7:0] a,
    input   [7:0] b,
    output  [15:0] result
    );
    wire [7:0] s1, s2;
    wire [15:0] product;
    register#(8) input_reg1(
        .clk        (clk),
        .rstn       (rstn),
        .we         (1),
        .din        (a),
        .dout       (s1)
    );
    register#(8) input_reg2(
        .clk        (clk),
        .rstn       (rstn),
        .we         (1),
        .din        (b),
        .dout       (s2)
    );
    mul_btree mul1(
        .s1         (s1),
        .s2         (s2),
        .product    (product)
    );
    mul_wallce mul2(
        .s1         (s1),
        .s2         (s2),
        .product    (product)
    );
    mul_booth_wallce mul3(
        .s1         (s1),
        .s2         (s2),
        .product    (product)
    );
    mul_lookup mul4(
        .s1         (s1),
        .s2         (s2),
        .product    (product)
    );
    assign product = s1 * s2;
    register#(16) output_reg(
        .clk        (clk),
        .rstn       (rstn),
        .we         (1),
        .din        (product),
        .dout       (result)
    );
    
    
endmodule
