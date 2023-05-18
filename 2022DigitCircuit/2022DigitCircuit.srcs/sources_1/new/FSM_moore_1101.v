`timescale 1ns / 1ps

module FSM_moore_1101(
    input               clk,
    input               rstn,
    input               din,
    output reg [4:0]    crt,
    output reg          is_1101
    );
    localparam
        S0 = 5'h01,
        S1 = 5'h02,
        S2 = 5'h04,
        S3 = 5'h08,
        S4 = 5'h10;

    reg [4:0] nxt;
    initial begin
        crt = S0;
        nxt = S0;
    end

    always @(posedge clk or negedge rstn) begin
        if(!rstn)   crt <= S0;
        else        crt <= nxt;
    end

    always @(*) begin
        case(crt)
        S0: begin
            if(din)     nxt = S1;
            else        nxt = S0;
        end
        S1: begin
            if(din)     nxt = S2;
            else        nxt = S0;
        end
        S2: begin
            if(din)     nxt = S2;
            else        nxt = S3;
        end
        S3: begin
            if(din)     nxt = S4;
            else        nxt = S0;
        end
        S4: begin
            if(din)     nxt = S2;
            else        nxt = S0;
        end
        default:        nxt = S0;
        endcase 
    end

    always @(posedge clk) begin
        if(nxt == S4)   is_1101 <= 1'b1;
        else            is_1101 <= 1'b0;
    end
endmodule
