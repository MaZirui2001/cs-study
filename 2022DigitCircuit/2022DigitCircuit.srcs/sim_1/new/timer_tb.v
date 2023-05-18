`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/29/2022 01:44:54 PM
// Design Name: 
// Module Name: timer_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module timer_tb(

    );
    reg clk, rstn, st;
    reg [15:0] tc;
    wire td;
    wire [7:0] an;
    wire [6:0] seg;
    wire [15:0] input_time;
    initial begin
        clk = 0; 
        forever #1 clk =  ~clk;
    end
    initial begin
        rstn = 0;
        #4 rstn = 1;
    end
    initial begin
        tc = 8888;
        st = 0;
        #10 st = 1;
    end
    LabH4_2  inst_LabH4_2 (
            .st   (st),
            .clk  (clk),
            .rstn (rstn),
            .tc   (tc),
            .td   (td),
            .cn   (seg),
            .an   (an)
        );


endmodule
