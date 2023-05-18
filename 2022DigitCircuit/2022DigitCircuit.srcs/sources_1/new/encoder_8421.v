`timescale 1ns / 1ps
module encoder_8421(    
    input       [9:0] din,
    input             e,
    output reg  [3:0] dout,
    output reg        f
    );
    always @(*) begin
        f = 1'b1;
        if(!e) begin
            dout = 4'h0;
            f    = 1'b0;
        end
        else begin
            if     (din[9]) dout = 4'h9;
            else if(din[8]) dout = 4'h8;
            else if(din[7]) dout = 4'h7;
            else if(din[6]) dout = 4'h6;
            else if(din[5]) dout = 4'h5;
            else if(din[4]) dout = 4'h4;
            else if(din[3]) dout = 4'h3;
            else if(din[2]) dout = 4'h2;
            else if(din[1]) dout = 4'h1;
            else if(din[0]) dout = 4'h0;
            else begin
                dout = 4'h0;
                f    = 1'b0;
            end
        end
    end
endmodule
