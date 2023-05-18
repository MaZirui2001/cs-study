`timescale 1ns / 1ps
module mul_lookup(
    input   [7:0] s1,
    input   [7:0] s2,
    output  [15:0] product
    );
    reg [15:0] mem [0:65536];
    integer i, j;
    initial begin
        for(i = 0; i < 256; i = i + 1) begin
            for(j = 0; j < 256; j = j + 1) begin
                mem[{i[7:0], j[7:0]}] = i * j;
            end
        end
    end
    assign product = mem[{s1, s2}];
endmodule
