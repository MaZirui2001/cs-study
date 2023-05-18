`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2022 09:33:43 AM
// Design Name: 
// Module Name: sort_matrix
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


module sort_matrix#(
    parameter AW = 5,
    parameter DW = 16
    )(
    input               clk,
    input               we,
    input   [AW-1:0]    waddr,
    input   [AW-1:0]    raddr,
    input   [DW-1:0]    wdata,
    output  [DW-1:0]    rdata,
    input               sort_en,
    input               sort_loc
    );
    reg [DW-1:0] sort_matrix [0:(1<<AW)-1];
    assign rdata = sort_matrix[raddr];

    integer i;
    always @(posedge clk) begin
        if(we) sort_matrix[waddr] <=  wdata;
        
        else if(sort_en) begin
            if(sort_loc) begin
                for(i = 0; i < 31; i = i + 2) begin
                    if(sort_matrix[i] > sort_matrix[i+1]) begin
                        sort_matrix[i]   <= sort_matrix[i+1];
                        sort_matrix[i+1] <= sort_matrix[i];
                    end
                end
            end

            else begin
                for(i = 1; i < 31; i = i + 2) begin
                    if(sort_matrix[i] > sort_matrix[i+1]) begin
                        sort_matrix[i]   <= sort_matrix[i+1];
                        sort_matrix[i+1] <= sort_matrix[i];
                    end
                end
            end

        end
    end
endmodule
