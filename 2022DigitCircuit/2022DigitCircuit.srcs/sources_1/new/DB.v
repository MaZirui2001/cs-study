`timescale 1ns / 1ps
module DB#(
    parameter N = 100000,
    parameter W = 1
    )(
    input               clk,
    input               rstn,
    input   [W-1:0]     din,
    output reg  [W-1:0] stable_dout
    );
    reg [24:0] count [0:W-1];
    // integer j;
    // initial begin
    //     for(j = 0; j < W; j = j + 1) begin
    //         count[j] = 0;
    //     end
    // end
    genvar i;
    for(i = 0; i < W; i = i + 1)begin
        always @(posedge clk) begin
            stable_dout[i] <= count[i] == N -1;
        end
        always @(posedge clk) begin
            if(~rstn) count[i] <= 0;
            else if(count[i] == N - 1) begin
                if(din[i]) count[i] <= count[i];
                else count[i]     <= 0;
            end
            else if(din[i]) count[i] <= count[i] + 1;
            else count[i]        <= 0;
        end
    end
    
endmodule
