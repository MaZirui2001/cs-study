`timescale 1ns / 1ps

module FSM_mealy_1101(
    input               clk,
    input               rstn,
    input               din,
    output reg [2:0]    crt,
    output reg          is_1101
    );
    localparam
        S0 = 3'h0,
        S1 = 3'h1,
        S2 = 3'h2,
        S3 = 3'h3;
    reg [2:0] nxt;
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
            S0_out;
            if(din)     nxt = S1;
            else        nxt = S0;
        end
        S1: begin
            S1_out;
            if(din)     nxt = S2;
            else        nxt = S0;
        end
        S2: begin
            S2_out;
            if(din)     nxt = S2;
            else        nxt = S3;
        end
        S3: begin
            S3_out;
            if(din)     nxt = S1;
            else        nxt = S0;
        end
        default: begin
            S0_out;
                        nxt = S0;
        end
        endcase
    end

    task S0_out;
        is_1101 = 1'b0;
    endtask
    task S1_out;
        is_1101 = 1'b0;
    endtask
    task S2_out;
        is_1101 = 1'b0;
    endtask 
    task S3_out;
        is_1101 = din;
    endtask
endmodule
