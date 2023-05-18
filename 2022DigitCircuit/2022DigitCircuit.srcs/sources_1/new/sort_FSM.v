`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
module sort_FSM(
    input       clk,
    input       rstn,
    input       exe,
    input       load_finish,
    input       sort_finish,
    input       store_finish,
    output reg  load_en,
    output reg  sort_en,
    output reg  store_en,
    output reg  busy
    );
    localparam
        IDLE = 2'b00,
        LOAD = 2'b01,
        SORT = 2'b10,
        STORE = 2'b11;
    reg [1:0] crt, nxt;
    always @(posedge clk) begin 
        if(~rstn) crt <= IDLE;
        else crt <= nxt;
    end
    always @(*) begin
        case(crt)
        IDLE: begin
            if(exe) nxt = LOAD;
            else nxt = IDLE;
        end
        LOAD: begin
            if(load_finish) nxt = SORT;
            else nxt = LOAD;
        end
        SORT: begin
            if(sort_finish) nxt = STORE;
            else nxt = SORT;
        end
        STORE: begin
            if(store_finish) nxt = IDLE;
            else nxt = STORE;
        end
        endcase
    end
    always @(posedge clk) begin
        if(~rstn) begin
            load_en <= 0;
            sort_en <= 0;
            store_en <= 0;
            busy <= 0;
        end
        else begin
            case(nxt) 
            IDLE: begin
                load_en <= 0;
                sort_en <= 0;
                store_en <= 0;
                busy <= 0;
            end
            LOAD: begin
                load_en <= 1;
                sort_en <= 0;
                store_en <= 0;
                busy <= 1;
            end
            SORT: begin
                load_en <= 0;
                sort_en <= 1;
                store_en <= 0;
                busy <= 1;
            end
            STORE: begin
                load_en <= 0;
                sort_en <= 0;
                store_en <= 1;
                busy <= 1;
            end
            default:;
            endcase
        end
    end

endmodule
