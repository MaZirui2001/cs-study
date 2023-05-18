`timescale 1ns / 1ps

module timer#(
    parameter SCALE = 100000000
    // parameter SCALE = 100
    )(
    input           clk,
    input           rstn,
    input   [15:0]  tc,
    input           st,
    output  [15:0]  q,
    output reg      td
    );
    reg [27:0] time_rec;
    reg minus_flag;
    reg timing;
    wire st_stable;
    wire st_edge;
    counter #(
        .WIDTH(16),
        .RST_VLU(0)
    ) inst_counter (
        .clk   (clk),
        .rstn  (rstn),
        .pe    (st_edge),
        .ce    (minus_flag),
        .d     (tc),
        .count (q)
    );
    DB inst_DB (
        .clk         (clk), 
        .rstn        (rstn), 
        .din         (st), 
        .stable_dout (st_stable)
    );
    PS inst_PS (
        .clk (clk), 
        .s   (st_stable), 
        .p   (st_edge)
    );


    always @(posedge clk) begin
        if(~rstn) begin
             timing <= 0;
        end 
        else if(st_edge) begin
             timing <= 1;
        end
        else if(td) begin
            timing <= 0;
        end
    end

    always @(posedge clk) begin 
        if(~rstn) begin
             time_rec <= 0;
        end 
        else if (st_edge) begin
            time_rec <= 0;
        end
        else if(time_rec == (SCALE - 1)) begin
             time_rec <= 0;
        end
        else if(timing) begin
            time_rec <= time_rec + 1;
        end
        else begin
            time_rec <= 0;
        end
    end
    
    always @(posedge clk) begin
        minus_flag <= (time_rec  == (SCALE - 1));
    end

    always @(posedge clk) begin
        if(~rstn) begin
            td <= 1;
        end 
        else if(st_edge) begin
            td <= 0;
        end
        else begin
             td <= ~ (|q);
        end
    end


endmodule
