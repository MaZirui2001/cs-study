`timescale 1ns / 1ps

module mux2_1_tb(

    );
    reg [6:0] din1, din2;
    reg sel;
    wire [6:0] dout;
    mux2_1 mux2_1_sim(
        .din1       (din1),
        .din2       (din2),
        .sel        (sel),
        .dout       (dout)
    );
    initial begin
        din1 = 0;
        din2 = 7'd100;
        sel = 0;
        repeat(10) begin
            #1 din1 = din1 + 1;
            #2 din2 = din2 - 1;
            #3 sel = ~sel;
        end
    end
endmodule
