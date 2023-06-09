`timescale 1ns / 1ps
//  功能说明
    //  立即数拓展，将指令中的立即数部分拓展为完整立即数
// 输入
    // Inst              指令的[31:7]
    // ImmType           立即数类型
// 输出
    // imm               补全的立即数
// 实验要求
    // 补全模块


`include "Parameters.v"   
module ImmExtend(
    input wire [31:7] inst,
    input wire [2:0] imm_type,
    output reg [31:0] imm
    );

    always@(*)
    begin
        case(imm_type)
            `ITYPE: imm = {{21{inst[31]}}, inst[30:20]};
            // TODO: complete left part
            // Parameters.v defines all immediate type

            /* FIXME: Write your code here... */

            default: imm = 32'b0;
        endcase
    end
endmodule
