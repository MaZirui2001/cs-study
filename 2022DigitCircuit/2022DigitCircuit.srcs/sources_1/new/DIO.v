`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/02/2022 10:39:46 PM
// Design Name: 
// Module Name: DIO
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


module SRT_DIO(
    input           clk,
    input           rstn,
    input   [15:0]  x,
    input           del,
    input           pre,
    input           nxt,
    input           exe,
    input           delay_clear,
    output          busy,
    output  [15:0]  delay,
    output  [7:0]   an,
    output  [6:0]   seg
    );
    wire            del_stb, pre_stb, nxt_stb, exe_stb;
    wire            del_edge, pre_edge, nxt_edge, exe_edge;
    wire    [15:0]  x_stb, x_edge;
    wire    [3:0]   hd;
    wire    [4:0]   rf_raddr0, rf_waddr, rf_raddr1, rf_sort_waddr;
    wire            ar_we, dr_we, rf_we, rf_sort_we;
    wire    [1:0]   ar_in_sel, dr_in_sel;
    wire    [4:0]   ar_in_data;
    wire    [15:0]  dr_in_data, reg_wdata;
    wire    [15:0]  rf_rdata0, rf_wdata, rf_rdata1, rf_sort_wdata;
    wire            rf_waddr_sel, rf_wdata_sel, sort_start;

    DB #(.N(100000), .W(4)) btn_DB (
        .clk         (clk), 
        .rstn        (rstn),
        .din         ({del, pre, nxt, exe}), 
        .stable_dout ({del_stb, pre_stb, nxt_stb, exe_stb})
    );
    DB #(.N(1000000), .W(16)) sw_DB (
        .clk         (clk), 
        .rstn        (1'b1),
        .din         (x), 
        .stable_dout (x_stb)
    );
    PS #(.W(4)) btn_PS (
        .clk (clk), 
        .s   ({del_stb, pre_stb, nxt_stb, exe_stb}), 
        .p   ({del_edge, pre_edge, nxt_edge, exe_edge})
    );
    PS_double #(.W(16)) sw_PS (
        .clk (clk), 
        .s   (x_stb), 
        .p   (x_edge)
    );
    decoder16_4 inst_decoder16_4 (
        .clk  (clk),
        .din  (x_edge), 
        .dout (hd)
    );
    mux3_1 #(.W(5)) addr_in_mux (
        .din1 (rf_raddr0 + 5'b1), 
        .din2 (rf_raddr0 - 5'b1), 
        .din3 (0), 
        .sel  (ar_in_sel), 
        .dout (ar_in_data)
    );

    register #(.W(5)) addr_register (
        .clk  (clk), 
        .rstn (rstn), 
        .din  (ar_in_data), 
        .we   (ar_we), 
        .dout (rf_raddr0)
    );
     mux3_1 #(.W(16)) data_in_mux (
        .din1 ({4'b0, reg_wdata[15:4]}), 
        .din2 ({reg_wdata[11:0], hd}), 
        .din3 (rf_rdata0), 
        .sel  (dr_in_sel), 
        .dout (dr_in_data)
    );
    register #(.W(16)) data_register (
        .clk  (clk), 
        .rstn (rstn), 
        .din  (dr_in_data), 
        .we   (dr_we), 
        .dout (reg_wdata)
    );
    mux2_1 #(.W(5)) rf_waddr_mux (
        .din1 (rf_raddr0), 
        .din2 (rf_sort_waddr), 
        .sel  (rf_waddr_sel), 
        .dout (rf_waddr)
    );
    mux2_1 #(.W(16)) rf_wdata_mux (
        .din1 (reg_wdata), 
        .din2 (rf_sort_wdata), 
        .sel  (rf_wdata_sel), 
        .dout (rf_wdata)
    );
    regfile inst_regfile (
        .clk (clk),
        .ra0 (rf_raddr0),
        .ra1 (rf_raddr1),
        .rd0 (rf_rdata0),
        .rd1 (rf_rdata1),
        .wa  (rf_waddr),
        .wd  (rf_wdata),
        .we  (rf_we)
    );
    main_FSM_DIO inst_main_FSM_DIO
        (
            .clk          (clk),
            .rstn         (rstn),
            .x_edge       (|x_edge),
            .del_edge     (del_edge),
            .nxt_edge     (nxt_edge),
            .pre_edge     (pre_edge),
            .exe_edge     (exe_edge),
            .busy         (busy),
            .rf_sort_we   (rf_sort_we),
            .ar_in_sel    (ar_in_sel),
            .dr_in_sel    (dr_in_sel),
            .ar_we        (ar_we),
            .dr_we        (dr_we),
            .rf_we        (rf_we),
            .rf_waddr_sel (rf_waddr_sel),
            .rf_wdata_sel (rf_wdata_sel),
            .sort_start   (sort_start)
        );
    sort_ext #(.AW(5), .DW(16)) inst_sort_ext (
            .clk        (clk),
            .rstn       (rstn),
            .exe        (sort_start),
            .rf_raddr   (rf_raddr1),
            .rf_rdata   (rf_rdata1),
            .rf_waddr   (rf_sort_waddr),
            .rf_wdata   (rf_sort_wdata),
            .rf_sort_we (rf_sort_we),
            .busy       (busy),
            .delay      (delay),
            .delay_clear(delay_clear)
        );

    DIS inst_DIS (
        .clk  (clk), 
        .rstn (rstn), 
        .din  ({3'b0, rf_raddr0, 8'b0, reg_wdata}), 
        .an   (an), 
        .seg  (seg)
    );

endmodule
