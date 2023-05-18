`timescale 1ns / 1ps

module SQD(
    input             clk,
    input             rstn,
    input             x,
    output            yl,
    output            yr,
    output      [2:0] sl,
    output      [4:0] sr,
    output reg  [7:0] rx
    );
    FSM_mealy_1101 FSM_mealy(
        .clk        (clk), 
        .rstn       (rstn), 
        .din        (x), 
        .crt        (sl), 
        .is_1101    (yl)
    );
    FSM_moore_1101 FSM_moore(
        .clk        (clk), 
        .rstn       (rstn), 
        .din        (x), 
        .crt        (sr), 
        .is_1101    (yr)
    );
    always @(posedge clk or negedge rstn) begin
        if(!rstn) begin
            rx <= 0;
        end 
        else begin
            rx <= {rx[6:0], x};
        end
    end


endmodule
