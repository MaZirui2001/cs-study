`timescale 1ns / 1ps


module encode_booth#(
    parameter W = 16
)(
    input              y1,
    input              y2,
    input              y3,
    input      [W-1:0] din,
    output reg [W-1:0] dout
    );
    always @(*) begin
        case({y3, y2, y1})
        3'd0, 3'd7: dout = 0;
        3'd1, 3'd2: dout = din;
        3'd3: dout = {din[W-2:0], 1'b0};
        3'd4: dout = -{din[W-2:0], 1'b0};
        3'd5, 3'd6: dout = -din;
        endcase
    end
endmodule
