`timescale 1ns / 1ps
module sort_counters#(
    parameter LD_ST_CLKNUM = 31,
    parameter SORT_CLKNUM = 31
    )(
    input                                   clk,
    input                                   rstn,
    input                                   load_en,
    input                                   sort_en,
    input                                   store_en,
    output reg                              load_finish,
    output reg                              sort_finish,
    output reg                              store_finish,
    output reg  [$clog2(LD_ST_CLKNUM)-1:0]  load_counter, 
    output reg  [$clog2(LD_ST_CLKNUM)-1:0]  store_counter,
    output reg  [$clog2(SORT_CLKNUM)-1:0]   sort_counter,
    output                                  sort_loc
    );
    // reg [$clog2(LD_ST_CLKNUM)-1:0]  load_counter, store_counter;
    // reg [$clog2(SORT_CLKNUM)-1:0]   sort_counter;
    always @(posedge clk) begin
        if(~rstn) begin
            load_counter  <= LD_ST_CLKNUM;
            sort_counter  <= SORT_CLKNUM;
            store_counter <= LD_ST_CLKNUM;
        end
        else if(load_en) load_counter   <= load_counter - 1;
        else if(sort_en) sort_counter   <= sort_counter - 1;
        else if(store_en) store_counter <= store_counter - 1;
    end
    always @(*) begin 
        load_finish  = !(|load_counter);
        sort_finish  = !(|sort_counter);
        store_finish = !(|store_counter);
    end
    assign sort_loc = sort_counter[0];
endmodule
