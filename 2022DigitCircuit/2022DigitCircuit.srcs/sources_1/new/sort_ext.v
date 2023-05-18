`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2022 09:59:52 AM
// Design Name: 
// Module Name: sort_ext
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


module sort_ext#(
    parameter AW = 5,
    parameter DW = 16
    )(
    input               clk,
    input               rstn,
    input               exe,
    input               delay_clear,
    output  [AW-1:0]    rf_raddr,
    input   [DW-1:0]    rf_rdata,
    output  [AW-1:0]    rf_waddr,
    output  [DW-1:0]    rf_wdata,
    output              rf_sort_we,
    output              busy,
    output  [15:0]      delay
    );
    wire load_finish, sort_finish, store_finish;
    wire load_en, sort_en, store_en, sort_loc;
    wire [AW-1:0] mt_raddr, mt_waddr, sort_counter;
    wire [DW-1:0] mt_wdata, mt_rdata;
    assign rf_raddr = mt_waddr;
    assign rf_waddr = mt_raddr;
    assign mt_wdata = rf_rdata;
    assign rf_wdata = mt_rdata;
    assign rf_sort_we = store_en;
    sort_FSM inst_sort_FSM
        (
            .clk          (clk),
            .rstn         (rstn),
            .exe          (exe),
            .load_finish  (load_finish),
            .sort_finish  (sort_finish),
            .store_finish (store_finish),
            .load_en      (load_en),
            .sort_en      (sort_en),
            .store_en     (store_en),
            .busy         (busy)
        );
    sort_matrix #(.AW(5), .DW(16)) inst_sort_matrix 
        (
            .clk      (clk),
            .we       (load_en),
            .waddr    (mt_waddr),
            .raddr    (mt_raddr),
            .wdata    (mt_wdata),
            .rdata    (mt_rdata),
            .sort_en  (sort_en),
            .sort_loc (sort_loc)
        );
    sort_counters #(
            .LD_ST_CLKNUM(31),
            .SORT_CLKNUM(31)
        ) inst_sort_counters (
            .clk           (clk),
            .rstn          (rstn),
            .load_en       (load_en),
            .sort_en       (sort_en),
            .store_en      (store_en),
            .load_finish   (load_finish),
            .sort_finish   (sort_finish),
            .store_finish  (store_finish),
            .load_counter  (mt_waddr),
            .store_counter (mt_raddr),
            .sort_counter  (sort_counter),
            .sort_loc      (sort_loc)
        );
    delay_count inst_delay_count (
        .clk   (clk), 
        .rstn  (rstn), 
        .busy  (busy), 
        .clear (delay_clear), 
        .delay (delay)
        );


endmodule
