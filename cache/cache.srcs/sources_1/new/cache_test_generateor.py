verilog_head = '''
`timescale 1ns / 1ps
module cache_tb();

localparam INDEX_WIDTH          = %d;
localparam WORD_OFFSET_WIDTH    = %d;
localparam TOTAL_WORD_NUM       = 4 * (1 << INDEX_WIDTH) * (1 << (WORD_OFFSET_WIDTH));

// icache test
reg [31:0] addr_rom [TOTAL_WORD_NUM];
reg [31:0] data_ram [TOTAL_WORD_NUM];
reg [31:0] test_index = 0;
reg clk = 1'b1, rstn = 1'b0;

initial #5 rstn = 1'b1; 
always #1 clk = ~clk;

// generate addr_rom
initial begin
'''
verilog_mid = '''
end
initial begin
'''
verilog_tail = '''
end
// for icache 
reg             i_rvalid = 1;
wire            i_rready;
wire    [31:0]  i_raddr;
wire    [31:0]  i_rdata;
wire            i_rvalid_axi;
wire            i_rready_axi;
// icache && arbiter 
wire    [31:0]  i_raddr_axi;
wire    [31:0]  i_rdata_axi;
wire            i_rlast_axi;
wire    [2:0]   i_rsize_axi;
wire    [7:0]   i_rlen_axi;
// icache_debug
reg             i_rvalid_ff;
reg     [31:0]  i_raddr_ff;
reg             error_reg;
reg             i_pass_reg;
wire    [31:0]  i_correct_data;

// for dcache
wire    [31:0]  d_addr;
wire            d_rvalid;
wire            d_rready;
wire    [31:0]  d_rdata;
wire            d_wvalid;
wire            d_wready;
wire    [31:0]  d_wdata;
wire    [3:0]   d_wstrb;
// dcache && arbiter
wire            d_rvalid_axi;
wire            d_rready_axi;
wire    [31:0]  d_raddr_axi;
wire    [31:0]  d_rdata_axi;
wire            d_rlast_axi;
wire    [2:0]   d_rsize_axi;
wire    [7:0]   d_rlen_axi;
wire            d_wvalid_axi;
wire            d_wready_axi;
wire    [31:0]  d_waddr_axi;
wire    [31:0]  d_wdata_axi;
wire    [3:0]   d_wstrb_axi;
wire            d_wlast_axi;
wire    [2:0]   d_wsize_axi;
wire    [7:0]   d_wlen_axi;
wire            d_bvalid_axi;
wire            d_bready_axi;

// arbiter with main mem
wire    [31:0]  araddr;
wire            arvalid;
wire            arready;
wire    [7:0]   arlen;
wire    [2:0]   arsize;
wire    [1:0]   arburst;
wire    [31:0]  rdata;
wire    [1:0]   rresp;
wire            rvalid;
wire            rready;
wire            rlast;
wire    [31:0]  awaddr;
wire            awvalid;
wire            awready;
wire    [7:0]   awlen;
wire    [2:0]   awsize;
wire    [1:0]   awburst;
wire    [31:0]  wdata;
wire    [3:0]   wstrb;
wire            wvalid;
wire            wready;
wire            wlast;
wire    [1:0]   bresp;
wire            bvalid;
wire            bready;

assign i_raddr = addr_rom[test_index];
assign i_correct_data = data_ram[i_raddr_ff >> 2];
// simulate IF1-IF2 register i_rvalid_ff && i_raddr_ff
always @(posedge clk) begin
    if(!rstn) begin
        i_rvalid_ff <= 0;
        i_raddr_ff <= 0;
    end
    else if(!(i_rvalid && !i_rready))begin
        i_rvalid_ff <= i_rvalid;
        i_raddr_ff <= i_raddr;
    end
end

// update test_index
always @(posedge clk) begin
    if(!rstn) begin
        test_index <= 0;
        i_pass_reg <= 0;
    end
    else if (test_index >= (TOTAL_WORD_NUM-1)) begin
        test_index <= (TOTAL_WORD_NUM-1);
        i_pass_reg <= 1;
    end
    else if(!(i_rvalid_ff && !i_rready) && !error_reg) begin
        test_index <= test_index + 1;
    end
end
// update error 
always @(posedge clk) begin
    if(!rstn) begin
        error_reg <= 0;
    end
    else if(error_reg) begin
        error_reg <= 1;
    end
    else if(i_rvalid_ff && i_rready) begin
        error_reg <= !(i_rdata  == i_correct_data);
    end
end

icache #(
  .INDEX_WIDTH          (INDEX_WIDTH),
  .WORD_OFFSET_WIDTH    (WORD_OFFSET_WIDTH)
)
icache_dut (
    .clk      (clk ),
    .rstn     (rstn ),
    .rvalid   (i_rvalid ),
    .rready   (i_rready ),
    .raddr    (i_raddr ),
    .rdata    (i_rdata ),

    .i_rvalid (i_rvalid_axi ),
    .i_rready (i_rready_axi ),
    .i_raddr  (i_raddr_axi ),
    .i_rdata  (i_rdata_axi ),
    .i_rlast  (i_rlast_axi ),
    .i_rsize  (i_rsize_axi ),
    .i_rlen   (i_rlen_axi)
);
dcache #(
    .INDEX_WIDTH        (INDEX_WIDTH ),
    .WORD_OFFSET_WIDTH  (WORD_OFFSET_WIDTH )
)
dcache_dut (
  .clk      (clk ),
  .rstn     (rstn ),
  .addr     (d_addr ),
  .rvalid   (d_rvalid ),
  .rready   (d_rready ),
  .rdata    (d_rdata ),
  .wvalid   (d_wvalid ),
  .wready   (d_wready ),
  .wdata    (d_wdata ),
  .wstrb    (d_wstrb ),
  .d_rvalid (d_rvalid_axi ),
  .d_rready (d_rready_axi ),
  .d_raddr  (d_raddr_axi ),
  .d_rdata  (d_rdata_axi ),
  .d_rlast  (d_rlast_axi ),
  .d_rsize  (d_rsize_axi ),
  .d_rlen   (d_rlen_axi ),
  .d_wvalid (d_wvalid_axi ),
  .d_wready (d_wready_axi ),
  .d_waddr  (d_waddr_axi ),
  .d_wdata  (d_wdata_axi ),
  .d_wstrb  (d_wstrb_axi ),
  .d_wlast  (d_wlast_axi ),
  .d_wsize  (d_wsize_axi ),
  .d_wlen   (d_wlen_axi ),
  .d_bvalid (d_bvalid_axi ),
  .d_bready (d_bready_axi )
);

axi_arbiter 
axi_arbiter_dut (
  .clk      (clk ),
  .rstn     (rstn ),
  .i_rvalid (i_rvalid_axi ),
  .i_rready (i_rready_axi ),
  .i_raddr  (i_raddr_axi ),
  .i_rdata  (i_rdata_axi ),
  .i_rlast  (i_rlast_axi ),
  .i_rsize  (i_rsize_axi ),
  .i_rlen   (i_rlen_axi ),
  .d_rvalid (d_rvalid_axi ),
  .d_rready (d_rready_axi ),
  .d_raddr  (d_raddr_axi ),
  .d_rdata  (d_rdata_axi ),
  .d_rlast  (d_rlast_axi ),
  .d_rsize  (d_rsize_axi ),
  .d_rlen   (d_rlen_axi ),
  .d_wvalid (d_wvalid_axi ),
  .d_wready (d_wready_axi ),
  .d_waddr  (d_waddr_axi ),
  .d_wdata  (d_wdata_axi ),
  .d_wstrb  (d_wstrb_axi ),
  .d_wlast  (d_wlast_axi ),
  .d_wsize  (d_wsize_axi ),
  .d_wlen   (d_wlen_axi ),
  .d_bvalid (d_bvalid_axi ),
  .d_bready (d_bready_axi ),
  .araddr   (araddr ),
  .arvalid  (arvalid ),
  .arready  (arready ),
  .arlen    (arlen ),
  .arsize   (arsize ),
  .arburst  (arburst ),
  .rdata    (rdata ),
  .rresp    (rresp ),
  .rvalid   (rvalid ),
  .rready   (rready ),
  .rlast    (rlast ),
  .awaddr   (awaddr ),
  .awvalid  (awvalid ),
  .awready  (awready ),
  .awlen    (awlen ),
  .awsize   (awsize ),
  .awburst  (awburst ),
  .wdata    (wdata ),
  .wstrb    (wstrb ),
  .wvalid   (wvalid ),
  .wready   (wready ),
  .wlast    (wlast ),
  .bresp    (bresp ),
  .bvalid   (bvalid ),
  .bready   (bready)
);
main_memory main_mem(
    .s_aclk         (clk ),
    .s_aresetn      (rstn ),
    .s_axi_araddr   (araddr ),
    .s_axi_arburst  (arburst ),
    .s_axi_arid     (4'b0),
    .s_axi_arlen    (arlen ),
    .s_axi_arready  (arready ),
    .s_axi_arsize   (arsize ),
    .s_axi_arvalid  (arvalid ),
    .s_axi_awaddr   (awaddr ),
    .s_axi_awburst  (awburst ),
    .s_axi_awid     (4'b0),
    .s_axi_awlen    (awlen ),
    .s_axi_awready  (awready ),
    .s_axi_awsize   (awsize ),
    .s_axi_awvalid  (awvalid ),
    .s_axi_bid      (),
    .s_axi_bready   (bready ),
    .s_axi_bresp    (bresp ),
    .s_axi_bvalid   (bvalid ),
    .s_axi_rdata    (rdata ),
    .s_axi_rid      (),
    .s_axi_rlast    (rlast ),
    .s_axi_rready   (rready ),
    .s_axi_rresp    (rresp ),
    .s_axi_rvalid   (rvalid ),
    .s_axi_wdata    (wdata ),
    .s_axi_wlast    (wlast ),
    .s_axi_wready   (wready ),
    .s_axi_wstrb    (wstrb ),
    .s_axi_wvalid   (wvalid )
);
endmodule
'''

import sys
from random import randint
from random import shuffle

if len(sys.argv) != 3:
    print('    Usage:\n        python generate_cache_tb.py [write words]')
    print('    Example:\n        python generate_cache_tb.py 6 4')
    print('    Tip: use this command to write to file:\n        python generate_cache_tb.py 6 4 > cache_tb.v')
else:
    try:
        INDEX = int( sys.argv[1] )
    except:
        print('    *** Error: parameter must be integer, not %s' % (sys.argv[1], ) )
        sys.exit(-1)
    try:
        WOFFSET = int( sys.argv[2] )
    except:
        print('    *** Error: parameter must be integer, not %s' % (sys.argv[2], ) )
        sys.exit(-1)
    
    verilog = verilog_head % (INDEX,WOFFSET,)
    addr_rom = [i << 2 for i in range(4 * (1 << INDEX) * (1 << WOFFSET))]
    shuffle(addr_rom)
    for i in range(4 * (1 << INDEX) * (1 << WOFFSET)):
        verilog += "    addr_rom[%5d] = 'h%08x; \n" % (i, addr_rom[i])
    verilog += verilog_mid
    
    data_ram = [i for i in range(4096)]
    for i in range(4 * (1 << INDEX) * (1 << WOFFSET)):
        verilog += "    data_ram[%5d] = 'h%08x; \n" % (i, data_ram[i])
    verilog += verilog_tail
    # make coe file
    coe = 'memory_initialization_radix=16;\nmemory_initialization_vector=\n'
    for i in range(4096):
        coe += '%08x\n' % (data_ram[i],)
    with open('memory.coe', 'w') as f:
        f.write(coe)
    
    print(verilog)



    
    
    