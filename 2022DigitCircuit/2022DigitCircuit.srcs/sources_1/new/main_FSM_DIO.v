`timescale 1ns / 1ps

module main_FSM_DIO(
    input               clk,
    input               rstn,
    input               x_edge,
    input               del_edge,
    input               nxt_edge,
    input               pre_edge,
    input               exe_edge,
    input               busy,
    input               rf_sort_we,
    output reg  [1:0]   ar_in_sel,
    output reg  [1:0]   dr_in_sel,
    output reg          ar_we,
    output reg          dr_we,
    output reg          rf_we,
    output reg          sort_start,
    output reg          rf_waddr_sel,
    output reg          rf_wdata_sel

    );
    localparam
        IDLE      = 3'd0,
        DEL       = 3'd1,
        PRE       = 3'd2,
        NXT       = 3'd3,
        DIN       = 3'd4,
        UPDATE_DR = 3'd5,
        START_SORT= 3'd6,
        WAIT_SORT = 3'd7;

    localparam
        ADD1      = 2'b00,
        SUB1      = 2'b01,
        ZERO      = 2'b10;

    localparam
        BKSP      = 2'b00,
        APED      = 2'b01,
        CHCK      = 2'b10;

    localparam
        REG       = 1'b0,
        SORT      = 1'b1;


    reg [2:0] crt, nxt;
    always @(posedge clk) begin
        if(~rstn) crt <= IDLE;
        else crt <= nxt;
    end 

    always @(*) begin
        case(crt)
        IDLE: begin
            if(x_edge)          nxt = DIN;
            else if(del_edge)   nxt = DEL;
            else if(nxt_edge)   nxt = NXT;
            else if(pre_edge)   nxt = PRE;
            else if(exe_edge)   nxt = START_SORT;
            else                nxt = IDLE;
        end
        DEL:            nxt = IDLE;
        PRE:            nxt = UPDATE_DR;
        NXT:            nxt = UPDATE_DR;
        DIN:            nxt = IDLE;
        UPDATE_DR:      nxt = IDLE;
        START_SORT:     nxt = WAIT_SORT;
        WAIT_SORT: begin
            if(!busy)   nxt = UPDATE_DR;
            else        nxt = WAIT_SORT;
        end
        default:        nxt = IDLE;
        endcase
    end

    always @(posedge clk) begin
        if(~rstn) begin
            rf_we      <= 0;
            ar_we      <= 0;
            dr_we      <= 1;
            sort_start <= 0;
            dr_in_sel  <= CHCK;
        end
        else begin
            case(nxt)
            IDLE: begin
                rf_we        <= 0;
                ar_we        <= 0;
                dr_we        <= 0;
                sort_start      <= 0;
            end
            DEL: begin
                rf_we        <= 0;
                ar_we        <= 0;
                dr_we        <= 1;
                dr_in_sel    <= BKSP;
            end
            DIN: begin
                rf_we        <= 0;
                ar_we        <= 0;
                dr_we        <= 1;
                dr_in_sel    <= APED;
            end
            PRE: begin
                rf_we        <= 1;
                ar_we        <= 1;
                ar_in_sel    <= SUB1;
                rf_wdata_sel <= REG;
                rf_waddr_sel <= REG;
            end
            NXT: begin
                rf_we        <= 1;
                ar_we        <= 1;
                ar_in_sel    <= ADD1;
                rf_wdata_sel <= REG;
                rf_waddr_sel <= REG;
            end
            UPDATE_DR: begin
                rf_we        <= 0;
                ar_we        <= 0;
                dr_we        <= 1;
                dr_in_sel    <= CHCK;
            end
            START_SORT: begin
                rf_we <= 0;
                ar_we <= 0;
                dr_we <= 0;
                sort_start <= 1;
            end
            WAIT_SORT: begin
                rf_we <= rf_sort_we;
                ar_we <= 0;
                dr_we <= 0;
                sort_start <= 0;
                rf_wdata_sel <= SORT;
                rf_waddr_sel <= SORT;
            end
            default: begin
                rf_we        <= 0;
                ar_we        <= 0;
                dr_we        <= 0;
                sort_start  <= 0;
            end
            endcase
        end
    

    end
endmodule
