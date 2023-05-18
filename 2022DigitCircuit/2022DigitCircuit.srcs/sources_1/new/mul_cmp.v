`timescale 1ns / 1ps
module mul_cmp(
    input         clk,
    input         rstn,
    input   [7:0] a,
    input   [7:0] b,
    input         en,
    output [15:0] y,
    output        eq,
    output        ug,
    output        ul,
    output        sg,
    output        sl
    );
    wire [7:0] a_input, b_input;
    wire [15:0] my_product, their_product;
    wire eq_tmp, ug_tmp, ul_tmp, sg_tmp, sl_tmp;
    register#(8) a_reg(
        .clk        (clk),
        .rstn       (rstn),
        .din        (a),
        .we         (en),
        .dout       (a_input)
    );
    register#(8) b_reg(
        .clk        (clk),
        .rstn       (rstn),
        .din        (b),
        .we         (en),
        .dout       (b_input)
    );
    mul_wallce multer(
        .s1         (a_input),
        .s2         (b_input),
        .product    (my_product)
    );
    assign their_product = a_input * b_input;
    assign eq_tmp = (my_product == their_product);
    comparer cmper(
        .s1     (a_input),
        .s2     (b_input),
        .ug     (ug_tmp),
        .ul     (ul_tmp),
        .sg     (sg_tmp),
        .sl     (sl_tmp)
    );
    register#(16) y_reg(
        .clk        (clk),
        .rstn       (rstn),
        .din        (my_product),
        .we         (en),
        .dout       (y)
    );
    register#(5) cmp_reg(
        .clk        (clk),
        .rstn       (rstn),
        .din        ({eq_tmp, ug_tmp, ul_tmp, sg_tmp, sl_tmp}),
        .we         (en),
        .dout       ({eq, ug, ul, sg, sl})
    );


endmodule
