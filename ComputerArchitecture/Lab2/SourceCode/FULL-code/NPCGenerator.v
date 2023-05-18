`timescale 1ns / 1ps
//  功能说明
    //  根据跳转信号，决定执行的下一条指令地址
    //  debug端口用于simulation时批量写入数据，可以忽略
// 输入
    // PC                指令地址（PC + 4, 而非PC）
    // jal_target        jal跳转地址
    // jalr_target       jalr跳转地址
    // br_target         br跳转地址
    // jal               jal == 1时，有jal跳转
    // jalr              jalr == 1时，有jalr跳转
    // br                br == 1时，有br跳转
// 输出
    // NPC               下一条执行的指令地址
// 实验要求  
    // 实现NPC_Generator

module NPC_Generator(
    input clk, //new
    input is_br_EX, flushF, bubbleE,// new
    input wire [31:0] PC, jal_target, jalr_target, br_target,
    input wire [31:0] PC_IF, PC_EX, NPC_EX, // new
    input wire jal, jalr, br,
    output reg [31:0] NPC,
    output reg pre_fail
    );
    localparam  BTB_SET = 64;
    localparam  BTB_SET_WIDTH = $clog2(BTB_SET);
    localparam  BTB_TAG_WIDTH = 32 - BTB_SET_WIDTH;
    // BTB data table
    reg [31:0]              btb_predict_pc [0:BTB_SET-1];
    // BTB tag table
    reg [BTB_TAG_WIDTH-1:0] btb_branch_tag [0:BTB_SET-1];
    // BTB valid table
    reg                     btb_valid [0:BTB_SET-1];
    // BTB history table
    reg                     btb_history [0:BTB_SET-1];
    // statistic
    reg [63:0] total_br;
    reg [63:0] success_pre;
    always @(posedge clk) begin
        if(flushF) begin
            total_br <= 0;
            success_pre <= 0;
        end
        else if(is_br_EX && !bubbleE) begin
            total_br <= total_br + 1;
            if(!pre_fail) success_pre <= success_pre + 1;
        end
    end
    wire [BTB_SET_WIDTH-1:0] btb_rindex, btb_windex;
    wire [BTB_TAG_WIDTH-1:0] btb_rtag, btb_wtag;
    wire btb_rhit;
    always @(*) begin
        if(is_br_EX) begin
            if(br) begin
                pre_fail = NPC_EX != br_target;
            end
            else begin
                pre_fail = NPC_EX != PC_EX + 4;
            end
        end
        else begin
            pre_fail = 0;
        end
    end

    // read table
    assign btb_rindex = PC_IF[BTB_SET_WIDTH-1:0];
    assign btb_rtag = PC_IF[31:BTB_SET_WIDTH];
    assign btb_rhit = btb_valid[btb_rindex] && (btb_branch_tag[btb_rindex] == btb_rtag);
    // write table
    assign btb_windex = PC_EX[BTB_SET_WIDTH-1:0];
    assign btb_wtag = PC_EX[31:BTB_SET_WIDTH];
    integer i;
    always @(posedge clk) begin
        if(flushF) begin
            for (i = 0; i < BTB_SET; i = i + 1) begin
                btb_valid[i]        = 0;
                btb_branch_tag[i]   = 0;
                btb_predict_pc[i]   = 0;
                btb_history[i]      = 0;
            end
        end
        else if(is_br_EX) begin
            btb_branch_tag[btb_windex]     <= btb_wtag;
            btb_predict_pc[btb_windex]     <= br_target;
            btb_valid[btb_windex]          <= 1'b1;
            btb_history[btb_windex]        <= br;
        end
    end
    // BHT
    localparam BHT_SET = 4096;
    localparam  BHT_SET_WIDTH = $clog2(BHT_SET);
    localparam  BHT_TAG_WIDTH = 32 - BHT_SET_WIDTH;
    // state machine
    reg [1:0] bht_state [0:BHT_SET-1];
    wire [BHT_SET_WIDTH-1:0] bht_rindex, bht_windex;
    wire bht_rhit;
    assign bht_rindex = PC_IF[BHT_SET_WIDTH-1:0];
    assign bht_windex = PC_EX[BHT_SET_WIDTH-1:0];
    assign bht_rhit = bht_state[bht_rindex][1];
    always @(*) begin
        if(pre_fail) begin
            if(br) NPC = br_target;
            else NPC = PC_EX + 4;
        end
        else if(jalr) begin
            NPC = jalr_target;
        end
        else if(jal) begin
            NPC = jal_target;
        end
        else if(btb_rhit && btb_history[btb_rindex] && bht_rhit) begin
            NPC = btb_predict_pc[btb_rindex];
        end
        else begin
            NPC = PC;
        end
    end
    always @(posedge clk) begin
        if(flushF) begin
            for (i = 0; i < BHT_SET; i = i + 1) begin
                bht_state[i] = 2'b01;
            end
        end
        else if(is_br_EX) begin
            if(br) bht_state[bht_windex] <= bht_state[bht_windex] == 2'b11 ? 2'b11 : bht_state[bht_windex] + 1'b1;
            else bht_state[bht_windex] <= bht_state[bht_windex] == 2'b00 ? 2'b00 : bht_state[bht_windex] - 1'b1; 
        end
    end
    // TODO: Complete this module
//@BEGIN
    // always @ (*)
    // begin
    //     if (br == 1)
    //     begin
    //         NPC = br_target;
    //     end
    //     else if (jalr == 1)
    //     begin
    //         NPC = jalr_target;
    //     end
    //     else if (jal == 1)
    //     begin
    //         NPC = jal_target;
    //     end
    //     else 
    //     begin
    //         NPC = PC;
    //     end
    // end

//@END
endmodule