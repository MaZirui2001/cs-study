`timescale 1ns / 1ps
module lab1_tb();
    wire            f;
    wire      [3:0] d;
    wire      [9:0] y;
    wire      [6:0] yn;
    wire            dp;
    wire      [7:0] an;
    reg       [9:0] din;
    initial begin
        /* change switch for 10 times */
        din = 1;
        repeat(10) #1 din = din << 1; 
        /* add switch for 10 times */
        din = 1;
        repeat(10) #1 din = din | (din << 1);
    end
    coder coder_test (
        .e        (1'b1),
        .a        (din),
        .b        (4'b0),
        .f        (f),
        .d        (d),
        .y        (y),
        .yn       (yn),
        .dp       (dp),
        .an       (an)
    );
endmodule
