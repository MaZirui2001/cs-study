`timescale 1ns / 1ps
//  功能说明
    //  将Cache中Load的数据扩展成32位
// 输入
    // data              cache读出的数据
    // addr              字节地址
    // load_type         load的类型
// 输出
    // dealt_data        扩展完的数据
// 实验要求
    // 补全模块


`include "Parameters.v"

module DataExtend(
    input wire [31:0] data,
    input wire [1:0] addr,
    input wire [2:0] load_type,
    output reg [31:0] dealt_data
    );

    // TODO: Complete this module
    
    always @ (*)
    begin
        if (load_type == `LHU)
        begin
            case(addr)
                2'b00: dealt_data = {16'b0, data[15:0]};
                2'b10: dealt_data = {16'b0, data[31:16]};
                default : dealt_data = 32'b0;
            endcase
        end
        else if (load_type == `NOREGWRITE)
        begin
            dealt_data = data;
        end
        else if (load_type == `LH)
        begin
            case(addr)
                2'b00: dealt_data = {{16{data[15]}}, data[15:0]};
                2'b10: dealt_data = {{16{data[31]}}, data[31:16]};
                default : dealt_data = 32'b0;
            endcase
        end

        /* FIXME: Write your code here... */

        else
        begin
            dealt_data = 32'b0;
        end

    end

endmodule