`timescale 1ns / 1ps

module PU#(
    parameter 
    HEN = 200,
    VEN = 150
)(
    input               clk,
    input               rstn,
    input               draw,
    input               up,
    input               left,
    input               down,
    input               right,
    input       [3:0]   pred,
    input       [3:0]   pgreen,
    input       [3:0]   pblue,
    output reg [14:0]   vram_waddr,
    output     [11:0]   vram_wdata,
    output              vram_we
    );
    wire up_stb, left_stb, down_stb, right_stb;
    wire up_edge, left_edge, down_edge, right_edge;
    wire up_in, left_in, down_in, right_in;
    wire up_con, left_con, down_con, right_con;
    DB #(.N(100000), .W(4)) btn_DB (
        .clk         (clk), 
        .rstn        (rstn),
        .din         ({up, left, down, right}), 
        .stable_dout ({up_stb, left_stb, down_stb, right_stb})
    );
    PS #(.W(4)) btn_PS (
        .clk (clk), 
        .s   ({up_stb, left_stb, down_stb, right_stb}), 
        .p   ({up_edge, left_edge, down_edge, right_edge})
    );
    reg  [25:0] count;
    reg btn_in;
    always @(posedge clk) begin
        if(~rstn) count <= 0;
        else if(count == 1000000) count <= 0;
        else count <= count  + 1;
        btn_in <= (count == 1000000);
    end
    DB #(.N(20000000), .W(4)) btn_con_click (
        .clk         (clk), 
        .rstn        (rstn),
        .din         ({up_stb, left_stb, down_stb, right_stb}), 
        .stable_dout ({up_con, left_con, down_con, right_con})
    );
    assign up_in = up_con ? btn_in : up_edge;
    assign left_in = left_con ? btn_in : left_edge;
    assign down_in = down_con ? btn_in : down_edge;
    assign right_in = right_con ? btn_in : right_edge;

    always @(posedge clk) begin
        if(~rstn) vram_waddr <= VEN * HEN / 2;
        else begin
            if(up_in) begin
                vram_waddr <= (vram_waddr < HEN) ? vram_waddr : (vram_waddr - HEN); 
            end
            else if(left_in) begin
                vram_waddr <= vram_waddr - 1;
            end
            else if(down_in) begin
                vram_waddr <= (vram_waddr + HEN < HEN * VEN) ? (vram_waddr + HEN) : vram_waddr;
            end
            else if(right_in) begin
                vram_waddr <= vram_waddr + 1;
            end
        end
    end
    assign vram_we = draw;
    assign vram_wdata = {pred, pgreen, pblue};
endmodule
