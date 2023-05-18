`timescale 1ns / 1ps


module painter(
    input           clk,
    input           rstn,
    input           draw,
    input           up,
    input           left,
    input           right,
    input           down,
    input   [3:0]   pred,
    input   [3:0]   pgreen,
    input   [3:0]   pblue,
    output  [3:0]   red,
    output  [3:0]   green,
    output  [3:0]   blue,
    output          hs,
    output          vs
    );
    wire pclk;
    wire [14:0] vram_waddr, vram_raddr;
    wire [11:0] vram_wdata, vram_rdata;
    wire vram_we;
    clk_wiz clk_50MHz(
        .clk_in1    (clk),
        .reset      (~rstn),
        .clk_out1   (pclk)
    );
    PU PU_dut (
        .clk          (pclk ),
        .rstn         (rstn ),
        .draw         (draw ),
        .up           (up ),
        .left         (left ),
        .down         (down ),
        .right        (right ),
        .pred         (pred ),
        .pgreen       (pgreen ),
        .pblue        (pblue ),
        .vram_waddr   (vram_waddr ),
        .vram_wdata   (vram_wdata ),
        .vram_we      (vram_we)
    );
    vram vram_dut(
        .clka       (pclk),
        .addra      (vram_waddr),
        .dina       (vram_wdata),
        .wea        (vram_we),
        .addrb      (vram_raddr),
        .clkb       (pclk),
        .doutb      (vram_rdata)
    );
    DU DU_dut (
        .clk          (pclk ),
        .rstn         (rstn ),
        .vram_rdata   (vram_rdata),
        .vram_waddr   (vram_waddr),
        .vram_wdata   (vram_wdata),
        .vram_raddr   (vram_raddr),
        .hs           (hs ),
        .vs           (vs ),
        .rgb          ({red, green, blue})
    );
  
  
    
endmodule
