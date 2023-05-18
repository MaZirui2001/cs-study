`timescale 1ns / 1ps
module counter #(
    parameter WIDTH = 16, 
              RST_VLU = 0
)(
    input                   clk, 
    input                   rstn, 
    input                   pe, 
    input                   ce, 
    input       [WIDTH-1:0] d,
    output reg  [WIDTH-1:0] count
);
    always @(posedge clk) begin
        if (!rstn)  count <= RST_VLU;
        else if (pe)  count <= d;
        else if (ce)  count <= count - 1; 
    end
endmodule

