`timescale 1ns / 1ps
module regfile#(
    parameter AW = 5,
    parameter DW = 16
    )(
    input               clk,
    input   [AW-1:0]    ra0,
    input   [AW-1:0]    ra1,
    output  [DW-1:0]    rd0,
    output  [DW-1:0]    rd1,
    input   [AW-1:0]    wa,
    input   [DW-1:0]    wd,
    input               we
    );
    reg [DW-1:0] rf [0:(1 << AW)-1];
    integer i;
    // initial begin
    //     for(i = 0; i < (1 << AW); i = i + 1)begin
    //         rf[i] = (1 << AW) - i - 1;
    //     end
    // end
    assign rd0 = rf[ra0];
    assign rd1 = rf[ra1];
    always @(posedge clk) begin 
        if(we) rf[wa] <= wd;
    end
endmodule
