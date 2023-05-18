`timescale 1ns / 1ps

module DU#(
    parameter 
    HBP     = 64,
    HEN     = 800,
    HFP     = 56,
    HSW     = 120,
    HWID    = HBP + HEN + HFP + HSW,
    VBP     = 23,
    VEN     = 600,
    VFP     = 37,
    VSW     = 6,
    VWID    = VBP + VEN + VFP + VSW,

    XSCALE  = 200,
    YSCALE  = 150
)(
    input   clk,
    input   rstn,
    input  [11:0] vram_rdata,
    input [14:0] vram_waddr,
    input [11:0] vram_wdata,
    output [14:0] vram_raddr,

    output  hs,
    output  vs,
    output reg [11:0] rgb
); 
    reg [15:0] h_count, v_count;
    wire [15:0] vram_raddrx, vram_raddry;
    wire [13:0] vram_raddrx_real, vram_raddry_real;
    wire den;
    reg pointer_en;
    // hs
    always @(posedge clk) begin
        if(~rstn)                    h_count <= 0;
        else if(h_count == HWID - 1) h_count <= 0;
        else                         h_count <= h_count + 1;
    end
    assign hs = (h_count < HSW);

    // vs
    always @(posedge clk) begin
        if(~rstn)                     v_count <= 0;
        else if (h_count == HWID - 1) begin
            if(v_count == VWID - 1)   v_count <= 0;
            else                      v_count <= v_count + 1;
        end
    end
    assign vs = (v_count < VSW);

    assign den = (h_count >= HSW + HBP) && (h_count < HWID - HFP) 
                && (v_count >= VSW + VBP) && (v_count < VWID - VFP);

    assign vram_raddrx = {16{den}} & (h_count - (HSW + HBP));
    assign vram_raddry = {16{den}} & (v_count - (VSW + VBP));
    assign vram_raddrx_real = vram_raddrx[15:2];
    assign vram_raddry_real = vram_raddry[15:2];
    assign vram_raddr = {vram_raddry_real[11:0], 3'b0} 
                        + {vram_raddry_real[8:0], 6'b0} 
                        + {vram_raddry_real[7:0], 7'b0} 
                        + {1'b0, vram_raddrx_real};

    // pointer
    always @(posedge clk) begin
        if(~rstn) pointer_en <= 0;
        else pointer_en <= (vram_raddr == vram_waddr - 1)
                        || (vram_raddr == vram_waddr + 1)
                        || (vram_raddr == vram_waddr - XSCALE)
                        || (vram_raddr == vram_waddr + XSCALE);
        rgb <= {12{den}} & (pointer_en ? vram_wdata : vram_rdata);
    end

endmodule