`timescale 1ns / 1ps

module mul_tb(

    );
    reg [7:0] a, b;
    reg clk, rstn, en;
    wire [15:0] y;
    wire eq, ug, ul, sg, sl;
    mul_cmp mul_cmp_dut (
      .clk      (clk ),
      .rstn     (rstn ),
      .a        (a ),
      .b        (b ),
      .en       (en ),
      .y        (y ),
      .eq       (eq ),
      .ug       (ug ),
      .ul       (ul ),
      .sg       (sg ),
      .sl       (sl )
    );
    initial begin
        clk = 0;
        rstn = 1'b1;
        en = 1'b1;
        forever #1 clk = ~clk;
    end
    initial begin
        // a = 0;
        // repeat(256) begin
        //     b = 0;
        //     repeat(256) begin
        //         #2 a = a + 1;
        //     end
        //     b = b + 1;
        // end
        a = 8'd255;
        b = 8'd255;
    end

endmodule
