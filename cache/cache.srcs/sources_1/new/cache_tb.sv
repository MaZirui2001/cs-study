
`timescale 1ns / 1ps
module cache_tb();

localparam INDEX_WIDTH          = 4;
localparam WORD_OFFSET_WIDTH    = 4;
localparam TOTAL_WORD_NUM       = 4 * (1 << INDEX_WIDTH) * (1 << (WORD_OFFSET_WIDTH));

// cache test
reg [31:0] addr_rom [TOTAL_WORD_NUM];
reg [31:0] data_ram [TOTAL_WORD_NUM];
reg [31:0] i_test_index = 0;
reg [31:0] d_test_index = 0;
reg clk = 1'b1, rstn = 1'b0;

initial #5 rstn = 1'b1; 
always #1 clk = ~clk;

// generate addr_rom
initial begin
    addr_rom[    0] = 'h000008fc; 	    data_ram[    0] = 'h00000000; 
    addr_rom[    1] = 'h00000c94; 	    data_ram[    1] = 'h00000001; 
    addr_rom[    2] = 'h00000ddc; 	    data_ram[    2] = 'h00000002; 
    addr_rom[    3] = 'h000008f4; 	    data_ram[    3] = 'h00000003; 
    addr_rom[    4] = 'h00000f48; 	    data_ram[    4] = 'h00000004; 
    addr_rom[    5] = 'h00000358; 	    data_ram[    5] = 'h00000005; 
    addr_rom[    6] = 'h00000e7c; 	    data_ram[    6] = 'h00000006; 
    addr_rom[    7] = 'h000008b0; 	    data_ram[    7] = 'h00000007; 
    addr_rom[    8] = 'h00000360; 	    data_ram[    8] = 'h00000008; 
    addr_rom[    9] = 'h00000c10; 	    data_ram[    9] = 'h00000009; 
    addr_rom[   10] = 'h00000618; 	    data_ram[   10] = 'h0000000a; 
    addr_rom[   11] = 'h00000c8c; 	    data_ram[   11] = 'h0000000b; 
    addr_rom[   12] = 'h00000004; 	    data_ram[   12] = 'h0000000c; 
    addr_rom[   13] = 'h00000b1c; 	    data_ram[   13] = 'h0000000d; 
    addr_rom[   14] = 'h000009e0; 	    data_ram[   14] = 'h0000000e; 
    addr_rom[   15] = 'h00000d1c; 	    data_ram[   15] = 'h0000000f; 
    addr_rom[   16] = 'h00000b50; 	    data_ram[   16] = 'h00000010; 
    addr_rom[   17] = 'h000003f4; 	    data_ram[   17] = 'h00000011; 
    addr_rom[   18] = 'h000000d0; 	    data_ram[   18] = 'h00000012; 
    addr_rom[   19] = 'h000009a0; 	    data_ram[   19] = 'h00000013; 
    addr_rom[   20] = 'h00000268; 	    data_ram[   20] = 'h00000014; 
    addr_rom[   21] = 'h0000003c; 	    data_ram[   21] = 'h00000015; 
    addr_rom[   22] = 'h00000310; 	    data_ram[   22] = 'h00000016; 
    addr_rom[   23] = 'h00000510; 	    data_ram[   23] = 'h00000017; 
    addr_rom[   24] = 'h0000084c; 	    data_ram[   24] = 'h00000018; 
    addr_rom[   25] = 'h00000220; 	    data_ram[   25] = 'h00000019; 
    addr_rom[   26] = 'h00000248; 	    data_ram[   26] = 'h0000001a; 
    addr_rom[   27] = 'h00000144; 	    data_ram[   27] = 'h0000001b; 
    addr_rom[   28] = 'h00000ad8; 	    data_ram[   28] = 'h0000001c; 
    addr_rom[   29] = 'h00000db8; 	    data_ram[   29] = 'h0000001d; 
    addr_rom[   30] = 'h0000041c; 	    data_ram[   30] = 'h0000001e; 
    addr_rom[   31] = 'h00000a04; 	    data_ram[   31] = 'h0000001f; 
    addr_rom[   32] = 'h0000046c; 	    data_ram[   32] = 'h00000020; 
    addr_rom[   33] = 'h00000ed4; 	    data_ram[   33] = 'h00000021; 
    addr_rom[   34] = 'h00000d80; 	    data_ram[   34] = 'h00000022; 
    addr_rom[   35] = 'h000007e4; 	    data_ram[   35] = 'h00000023; 
    addr_rom[   36] = 'h0000091c; 	    data_ram[   36] = 'h00000024; 
    addr_rom[   37] = 'h00000b78; 	    data_ram[   37] = 'h00000025; 
    addr_rom[   38] = 'h00000f5c; 	    data_ram[   38] = 'h00000026; 
    addr_rom[   39] = 'h00000bc0; 	    data_ram[   39] = 'h00000027; 
    addr_rom[   40] = 'h0000014c; 	    data_ram[   40] = 'h00000028; 
    addr_rom[   41] = 'h00000d9c; 	    data_ram[   41] = 'h00000029; 
    addr_rom[   42] = 'h0000031c; 	    data_ram[   42] = 'h0000002a; 
    addr_rom[   43] = 'h000003e8; 	    data_ram[   43] = 'h0000002b; 
    addr_rom[   44] = 'h000000cc; 	    data_ram[   44] = 'h0000002c; 
    addr_rom[   45] = 'h00000cd0; 	    data_ram[   45] = 'h0000002d; 
    addr_rom[   46] = 'h00000838; 	    data_ram[   46] = 'h0000002e; 
    addr_rom[   47] = 'h000001c0; 	    data_ram[   47] = 'h0000002f; 
    addr_rom[   48] = 'h000002dc; 	    data_ram[   48] = 'h00000030; 
    addr_rom[   49] = 'h00000394; 	    data_ram[   49] = 'h00000031; 
    addr_rom[   50] = 'h00000560; 	    data_ram[   50] = 'h00000032; 
    addr_rom[   51] = 'h000001a8; 	    data_ram[   51] = 'h00000033; 
    addr_rom[   52] = 'h000001dc; 	    data_ram[   52] = 'h00000034; 
    addr_rom[   53] = 'h00000fa8; 	    data_ram[   53] = 'h00000035; 
    addr_rom[   54] = 'h000007b4; 	    data_ram[   54] = 'h00000036; 
    addr_rom[   55] = 'h000008bc; 	    data_ram[   55] = 'h00000037; 
    addr_rom[   56] = 'h000003dc; 	    data_ram[   56] = 'h00000038; 
    addr_rom[   57] = 'h000004b0; 	    data_ram[   57] = 'h00000039; 
    addr_rom[   58] = 'h00000150; 	    data_ram[   58] = 'h0000003a; 
    addr_rom[   59] = 'h00000b24; 	    data_ram[   59] = 'h0000003b; 
    addr_rom[   60] = 'h00000c2c; 	    data_ram[   60] = 'h0000003c; 
    addr_rom[   61] = 'h00000ef4; 	    data_ram[   61] = 'h0000003d; 
    addr_rom[   62] = 'h00000858; 	    data_ram[   62] = 'h0000003e; 
    addr_rom[   63] = 'h00000a7c; 	    data_ram[   63] = 'h0000003f; 
    addr_rom[   64] = 'h00000528; 	    data_ram[   64] = 'h00000040; 
    addr_rom[   65] = 'h00000044; 	    data_ram[   65] = 'h00000041; 
    addr_rom[   66] = 'h00000b70; 	    data_ram[   66] = 'h00000042; 
    addr_rom[   67] = 'h00000d90; 	    data_ram[   67] = 'h00000043; 
    addr_rom[   68] = 'h00000244; 	    data_ram[   68] = 'h00000044; 
    addr_rom[   69] = 'h0000078c; 	    data_ram[   69] = 'h00000045; 
    addr_rom[   70] = 'h000004cc; 	    data_ram[   70] = 'h00000046; 
    addr_rom[   71] = 'h000005b0; 	    data_ram[   71] = 'h00000047; 
    addr_rom[   72] = 'h0000042c; 	    data_ram[   72] = 'h00000048; 
    addr_rom[   73] = 'h00000d98; 	    data_ram[   73] = 'h00000049; 
    addr_rom[   74] = 'h00000c54; 	    data_ram[   74] = 'h0000004a; 
    addr_rom[   75] = 'h00000720; 	    data_ram[   75] = 'h0000004b; 
    addr_rom[   76] = 'h00000368; 	    data_ram[   76] = 'h0000004c; 
    addr_rom[   77] = 'h00000c50; 	    data_ram[   77] = 'h0000004d; 
    addr_rom[   78] = 'h00000638; 	    data_ram[   78] = 'h0000004e; 
    addr_rom[   79] = 'h00000614; 	    data_ram[   79] = 'h0000004f; 
    addr_rom[   80] = 'h00000610; 	    data_ram[   80] = 'h00000050; 
    addr_rom[   81] = 'h00000164; 	    data_ram[   81] = 'h00000051; 
    addr_rom[   82] = 'h000003b4; 	    data_ram[   82] = 'h00000052; 
    addr_rom[   83] = 'h00000ebc; 	    data_ram[   83] = 'h00000053; 
    addr_rom[   84] = 'h00000974; 	    data_ram[   84] = 'h00000054; 
    addr_rom[   85] = 'h000007a4; 	    data_ram[   85] = 'h00000055; 
    addr_rom[   86] = 'h00000b74; 	    data_ram[   86] = 'h00000056; 
    addr_rom[   87] = 'h00000498; 	    data_ram[   87] = 'h00000057; 
    addr_rom[   88] = 'h000001e4; 	    data_ram[   88] = 'h00000058; 
    addr_rom[   89] = 'h00000408; 	    data_ram[   89] = 'h00000059; 
    addr_rom[   90] = 'h000006a8; 	    data_ram[   90] = 'h0000005a; 
    addr_rom[   91] = 'h000002c0; 	    data_ram[   91] = 'h0000005b; 
    addr_rom[   92] = 'h00000b08; 	    data_ram[   92] = 'h0000005c; 
    addr_rom[   93] = 'h00000e18; 	    data_ram[   93] = 'h0000005d; 
    addr_rom[   94] = 'h0000026c; 	    data_ram[   94] = 'h0000005e; 
    addr_rom[   95] = 'h00000b44; 	    data_ram[   95] = 'h0000005f; 
    addr_rom[   96] = 'h00000a58; 	    data_ram[   96] = 'h00000060; 
    addr_rom[   97] = 'h0000088c; 	    data_ram[   97] = 'h00000061; 
    addr_rom[   98] = 'h00000a98; 	    data_ram[   98] = 'h00000062; 
    addr_rom[   99] = 'h00000ff8; 	    data_ram[   99] = 'h00000063; 
    addr_rom[  100] = 'h000001ac; 	    data_ram[  100] = 'h00000064; 
    addr_rom[  101] = 'h00000410; 	    data_ram[  101] = 'h00000065; 
    addr_rom[  102] = 'h00000e34; 	    data_ram[  102] = 'h00000066; 
    addr_rom[  103] = 'h00000600; 	    data_ram[  103] = 'h00000067; 
    addr_rom[  104] = 'h000000d8; 	    data_ram[  104] = 'h00000068; 
    addr_rom[  105] = 'h00000e6c; 	    data_ram[  105] = 'h00000069; 
    addr_rom[  106] = 'h00000bdc; 	    data_ram[  106] = 'h0000006a; 
    addr_rom[  107] = 'h00000604; 	    data_ram[  107] = 'h0000006b; 
    addr_rom[  108] = 'h00000f9c; 	    data_ram[  108] = 'h0000006c; 
    addr_rom[  109] = 'h000007a0; 	    data_ram[  109] = 'h0000006d; 
    addr_rom[  110] = 'h00000420; 	    data_ram[  110] = 'h0000006e; 
    addr_rom[  111] = 'h00000458; 	    data_ram[  111] = 'h0000006f; 
    addr_rom[  112] = 'h00000700; 	    data_ram[  112] = 'h00000070; 
    addr_rom[  113] = 'h00000058; 	    data_ram[  113] = 'h00000071; 
    addr_rom[  114] = 'h000006a4; 	    data_ram[  114] = 'h00000072; 
    addr_rom[  115] = 'h000002fc; 	    data_ram[  115] = 'h00000073; 
    addr_rom[  116] = 'h000003b8; 	    data_ram[  116] = 'h00000074; 
    addr_rom[  117] = 'h00000ef0; 	    data_ram[  117] = 'h00000075; 
    addr_rom[  118] = 'h000007f0; 	    data_ram[  118] = 'h00000076; 
    addr_rom[  119] = 'h00000ec4; 	    data_ram[  119] = 'h00000077; 
    addr_rom[  120] = 'h000004d8; 	    data_ram[  120] = 'h00000078; 
    addr_rom[  121] = 'h000001a4; 	    data_ram[  121] = 'h00000079; 
    addr_rom[  122] = 'h00000378; 	    data_ram[  122] = 'h0000007a; 
    addr_rom[  123] = 'h000004fc; 	    data_ram[  123] = 'h0000007b; 
    addr_rom[  124] = 'h000007f8; 	    data_ram[  124] = 'h0000007c; 
    addr_rom[  125] = 'h00000a38; 	    data_ram[  125] = 'h0000007d; 
    addr_rom[  126] = 'h00000978; 	    data_ram[  126] = 'h0000007e; 
    addr_rom[  127] = 'h00000d58; 	    data_ram[  127] = 'h0000007f; 
    addr_rom[  128] = 'h0000048c; 	    data_ram[  128] = 'h00000080; 
    addr_rom[  129] = 'h000000c8; 	    data_ram[  129] = 'h00000081; 
    addr_rom[  130] = 'h00000744; 	    data_ram[  130] = 'h00000082; 
    addr_rom[  131] = 'h0000086c; 	    data_ram[  131] = 'h00000083; 
    addr_rom[  132] = 'h00000e40; 	    data_ram[  132] = 'h00000084; 
    addr_rom[  133] = 'h00000e20; 	    data_ram[  133] = 'h00000085; 
    addr_rom[  134] = 'h00000d2c; 	    data_ram[  134] = 'h00000086; 
    addr_rom[  135] = 'h00000c7c; 	    data_ram[  135] = 'h00000087; 
    addr_rom[  136] = 'h00000cc4; 	    data_ram[  136] = 'h00000088; 
    addr_rom[  137] = 'h00000f70; 	    data_ram[  137] = 'h00000089; 
    addr_rom[  138] = 'h0000094c; 	    data_ram[  138] = 'h0000008a; 
    addr_rom[  139] = 'h000008c4; 	    data_ram[  139] = 'h0000008b; 
    addr_rom[  140] = 'h00000de8; 	    data_ram[  140] = 'h0000008c; 
    addr_rom[  141] = 'h000000b4; 	    data_ram[  141] = 'h0000008d; 
    addr_rom[  142] = 'h00000b14; 	    data_ram[  142] = 'h0000008e; 
    addr_rom[  143] = 'h00000bec; 	    data_ram[  143] = 'h0000008f; 
    addr_rom[  144] = 'h00000e3c; 	    data_ram[  144] = 'h00000090; 
    addr_rom[  145] = 'h00000538; 	    data_ram[  145] = 'h00000091; 
    addr_rom[  146] = 'h000007f4; 	    data_ram[  146] = 'h00000092; 
    addr_rom[  147] = 'h00000264; 	    data_ram[  147] = 'h00000093; 
    addr_rom[  148] = 'h00000170; 	    data_ram[  148] = 'h00000094; 
    addr_rom[  149] = 'h00000b00; 	    data_ram[  149] = 'h00000095; 
    addr_rom[  150] = 'h00000078; 	    data_ram[  150] = 'h00000096; 
    addr_rom[  151] = 'h0000096c; 	    data_ram[  151] = 'h00000097; 
    addr_rom[  152] = 'h00000558; 	    data_ram[  152] = 'h00000098; 
    addr_rom[  153] = 'h00000c4c; 	    data_ram[  153] = 'h00000099; 
    addr_rom[  154] = 'h00000b04; 	    data_ram[  154] = 'h0000009a; 
    addr_rom[  155] = 'h00000a18; 	    data_ram[  155] = 'h0000009b; 
    addr_rom[  156] = 'h000007b0; 	    data_ram[  156] = 'h0000009c; 
    addr_rom[  157] = 'h00000130; 	    data_ram[  157] = 'h0000009d; 
    addr_rom[  158] = 'h00000474; 	    data_ram[  158] = 'h0000009e; 
    addr_rom[  159] = 'h00000b20; 	    data_ram[  159] = 'h0000009f; 
    addr_rom[  160] = 'h00000480; 	    data_ram[  160] = 'h000000a0; 
    addr_rom[  161] = 'h00000284; 	    data_ram[  161] = 'h000000a1; 
    addr_rom[  162] = 'h00000edc; 	    data_ram[  162] = 'h000000a2; 
    addr_rom[  163] = 'h000002b8; 	    data_ram[  163] = 'h000000a3; 
    addr_rom[  164] = 'h00000114; 	    data_ram[  164] = 'h000000a4; 
    addr_rom[  165] = 'h000006d8; 	    data_ram[  165] = 'h000000a5; 
    addr_rom[  166] = 'h000006c8; 	    data_ram[  166] = 'h000000a6; 
    addr_rom[  167] = 'h00000dac; 	    data_ram[  167] = 'h000000a7; 
    addr_rom[  168] = 'h00000348; 	    data_ram[  168] = 'h000000a8; 
    addr_rom[  169] = 'h000004f4; 	    data_ram[  169] = 'h000000a9; 
    addr_rom[  170] = 'h00000d8c; 	    data_ram[  170] = 'h000000aa; 
    addr_rom[  171] = 'h00000c40; 	    data_ram[  171] = 'h000000ab; 
    addr_rom[  172] = 'h0000011c; 	    data_ram[  172] = 'h000000ac; 
    addr_rom[  173] = 'h000008b4; 	    data_ram[  173] = 'h000000ad; 
    addr_rom[  174] = 'h00000548; 	    data_ram[  174] = 'h000000ae; 
    addr_rom[  175] = 'h00000fd8; 	    data_ram[  175] = 'h000000af; 
    addr_rom[  176] = 'h000008d4; 	    data_ram[  176] = 'h000000b0; 
    addr_rom[  177] = 'h00000808; 	    data_ram[  177] = 'h000000b1; 
    addr_rom[  178] = 'h00000344; 	    data_ram[  178] = 'h000000b2; 
    addr_rom[  179] = 'h0000065c; 	    data_ram[  179] = 'h000000b3; 
    addr_rom[  180] = 'h0000017c; 	    data_ram[  180] = 'h000000b4; 
    addr_rom[  181] = 'h00000f98; 	    data_ram[  181] = 'h000000b5; 
    addr_rom[  182] = 'h00000518; 	    data_ram[  182] = 'h000000b6; 
    addr_rom[  183] = 'h000003c0; 	    data_ram[  183] = 'h000000b7; 
    addr_rom[  184] = 'h00000e64; 	    data_ram[  184] = 'h000000b8; 
    addr_rom[  185] = 'h0000074c; 	    data_ram[  185] = 'h000000b9; 
    addr_rom[  186] = 'h00000020; 	    data_ram[  186] = 'h000000ba; 
    addr_rom[  187] = 'h00000aec; 	    data_ram[  187] = 'h000000bb; 
    addr_rom[  188] = 'h00000154; 	    data_ram[  188] = 'h000000bc; 
    addr_rom[  189] = 'h00000770; 	    data_ram[  189] = 'h000000bd; 
    addr_rom[  190] = 'h00000290; 	    data_ram[  190] = 'h000000be; 
    addr_rom[  191] = 'h00000460; 	    data_ram[  191] = 'h000000bf; 
    addr_rom[  192] = 'h000003cc; 	    data_ram[  192] = 'h000000c0; 
    addr_rom[  193] = 'h00000c1c; 	    data_ram[  193] = 'h000000c1; 
    addr_rom[  194] = 'h00000330; 	    data_ram[  194] = 'h000000c2; 
    addr_rom[  195] = 'h00000e98; 	    data_ram[  195] = 'h000000c3; 
    addr_rom[  196] = 'h00000aa4; 	    data_ram[  196] = 'h000000c4; 
    addr_rom[  197] = 'h000000e0; 	    data_ram[  197] = 'h000000c5; 
    addr_rom[  198] = 'h00000f20; 	    data_ram[  198] = 'h000000c6; 
    addr_rom[  199] = 'h00000880; 	    data_ram[  199] = 'h000000c7; 
    addr_rom[  200] = 'h00000e08; 	    data_ram[  200] = 'h000000c8; 
    addr_rom[  201] = 'h00000934; 	    data_ram[  201] = 'h000000c9; 
    addr_rom[  202] = 'h0000006c; 	    data_ram[  202] = 'h000000ca; 
    addr_rom[  203] = 'h00000c04; 	    data_ram[  203] = 'h000000cb; 
    addr_rom[  204] = 'h00000bc4; 	    data_ram[  204] = 'h000000cc; 
    addr_rom[  205] = 'h00000e9c; 	    data_ram[  205] = 'h000000cd; 
    addr_rom[  206] = 'h00000208; 	    data_ram[  206] = 'h000000ce; 
    addr_rom[  207] = 'h00000ed0; 	    data_ram[  207] = 'h000000cf; 
    addr_rom[  208] = 'h000005b4; 	    data_ram[  208] = 'h000000d0; 
    addr_rom[  209] = 'h00000428; 	    data_ram[  209] = 'h000000d1; 
    addr_rom[  210] = 'h00000a88; 	    data_ram[  210] = 'h000000d2; 
    addr_rom[  211] = 'h000005e4; 	    data_ram[  211] = 'h000000d3; 
    addr_rom[  212] = 'h00000490; 	    data_ram[  212] = 'h000000d4; 
    addr_rom[  213] = 'h00000d48; 	    data_ram[  213] = 'h000000d5; 
    addr_rom[  214] = 'h00000110; 	    data_ram[  214] = 'h000000d6; 
    addr_rom[  215] = 'h00000958; 	    data_ram[  215] = 'h000000d7; 
    addr_rom[  216] = 'h000009e8; 	    data_ram[  216] = 'h000000d8; 
    addr_rom[  217] = 'h00000f24; 	    data_ram[  217] = 'h000000d9; 
    addr_rom[  218] = 'h000002a8; 	    data_ram[  218] = 'h000000da; 
    addr_rom[  219] = 'h0000066c; 	    data_ram[  219] = 'h000000db; 
    addr_rom[  220] = 'h00000728; 	    data_ram[  220] = 'h000000dc; 
    addr_rom[  221] = 'h0000043c; 	    data_ram[  221] = 'h000000dd; 
    addr_rom[  222] = 'h00000764; 	    data_ram[  222] = 'h000000de; 
    addr_rom[  223] = 'h00000e84; 	    data_ram[  223] = 'h000000df; 
    addr_rom[  224] = 'h00000c24; 	    data_ram[  224] = 'h000000e0; 
    addr_rom[  225] = 'h00000c38; 	    data_ram[  225] = 'h000000e1; 
    addr_rom[  226] = 'h00000c30; 	    data_ram[  226] = 'h000000e2; 
    addr_rom[  227] = 'h00000a70; 	    data_ram[  227] = 'h000000e3; 
    addr_rom[  228] = 'h00000674; 	    data_ram[  228] = 'h000000e4; 
    addr_rom[  229] = 'h000002bc; 	    data_ram[  229] = 'h000000e5; 
    addr_rom[  230] = 'h00000584; 	    data_ram[  230] = 'h000000e6; 
    addr_rom[  231] = 'h00000e4c; 	    data_ram[  231] = 'h000000e7; 
    addr_rom[  232] = 'h00000288; 	    data_ram[  232] = 'h000000e8; 
    addr_rom[  233] = 'h00000d10; 	    data_ram[  233] = 'h000000e9; 
    addr_rom[  234] = 'h000007dc; 	    data_ram[  234] = 'h000000ea; 
    addr_rom[  235] = 'h0000029c; 	    data_ram[  235] = 'h000000eb; 
    addr_rom[  236] = 'h0000030c; 	    data_ram[  236] = 'h000000ec; 
    addr_rom[  237] = 'h00000ff4; 	    data_ram[  237] = 'h000000ed; 
    addr_rom[  238] = 'h00000fd4; 	    data_ram[  238] = 'h000000ee; 
    addr_rom[  239] = 'h00000eb0; 	    data_ram[  239] = 'h000000ef; 
    addr_rom[  240] = 'h00000218; 	    data_ram[  240] = 'h000000f0; 
    addr_rom[  241] = 'h0000023c; 	    data_ram[  241] = 'h000000f1; 
    addr_rom[  242] = 'h00000028; 	    data_ram[  242] = 'h000000f2; 
    addr_rom[  243] = 'h00000634; 	    data_ram[  243] = 'h000000f3; 
    addr_rom[  244] = 'h0000044c; 	    data_ram[  244] = 'h000000f4; 
    addr_rom[  245] = 'h000009cc; 	    data_ram[  245] = 'h000000f5; 
    addr_rom[  246] = 'h000009bc; 	    data_ram[  246] = 'h000000f6; 
    addr_rom[  247] = 'h00000694; 	    data_ram[  247] = 'h000000f7; 
    addr_rom[  248] = 'h00000300; 	    data_ram[  248] = 'h000000f8; 
    addr_rom[  249] = 'h00000c18; 	    data_ram[  249] = 'h000000f9; 
    addr_rom[  250] = 'h00000888; 	    data_ram[  250] = 'h000000fa; 
    addr_rom[  251] = 'h00000fdc; 	    data_ram[  251] = 'h000000fb; 
    addr_rom[  252] = 'h00000cd4; 	    data_ram[  252] = 'h000000fc; 
    addr_rom[  253] = 'h00000c00; 	    data_ram[  253] = 'h000000fd; 
    addr_rom[  254] = 'h00000eb8; 	    data_ram[  254] = 'h000000fe; 
    addr_rom[  255] = 'h00000dc8; 	    data_ram[  255] = 'h000000ff; 
    addr_rom[  256] = 'h000002ac; 	    data_ram[  256] = 'h00000100; 
    addr_rom[  257] = 'h0000097c; 	    data_ram[  257] = 'h00000101; 
    addr_rom[  258] = 'h00000d44; 	    data_ram[  258] = 'h00000102; 
    addr_rom[  259] = 'h00000298; 	    data_ram[  259] = 'h00000103; 
    addr_rom[  260] = 'h00000b6c; 	    data_ram[  260] = 'h00000104; 
    addr_rom[  261] = 'h00000988; 	    data_ram[  261] = 'h00000105; 
    addr_rom[  262] = 'h0000002c; 	    data_ram[  262] = 'h00000106; 
    addr_rom[  263] = 'h00000d5c; 	    data_ram[  263] = 'h00000107; 
    addr_rom[  264] = 'h00000550; 	    data_ram[  264] = 'h00000108; 
    addr_rom[  265] = 'h0000000c; 	    data_ram[  265] = 'h00000109; 
    addr_rom[  266] = 'h00000230; 	    data_ram[  266] = 'h0000010a; 
    addr_rom[  267] = 'h00000c9c; 	    data_ram[  267] = 'h0000010b; 
    addr_rom[  268] = 'h000000e8; 	    data_ram[  268] = 'h0000010c; 
    addr_rom[  269] = 'h00000074; 	    data_ram[  269] = 'h0000010d; 
    addr_rom[  270] = 'h00000204; 	    data_ram[  270] = 'h0000010e; 
    addr_rom[  271] = 'h00000570; 	    data_ram[  271] = 'h0000010f; 
    addr_rom[  272] = 'h0000035c; 	    data_ram[  272] = 'h00000110; 
    addr_rom[  273] = 'h000000b8; 	    data_ram[  273] = 'h00000111; 
    addr_rom[  274] = 'h000005fc; 	    data_ram[  274] = 'h00000112; 
    addr_rom[  275] = 'h00000018; 	    data_ram[  275] = 'h00000113; 
    addr_rom[  276] = 'h000001b8; 	    data_ram[  276] = 'h00000114; 
    addr_rom[  277] = 'h00000658; 	    data_ram[  277] = 'h00000115; 
    addr_rom[  278] = 'h00000380; 	    data_ram[  278] = 'h00000116; 
    addr_rom[  279] = 'h00000ad0; 	    data_ram[  279] = 'h00000117; 
    addr_rom[  280] = 'h00000868; 	    data_ram[  280] = 'h00000118; 
    addr_rom[  281] = 'h00000d0c; 	    data_ram[  281] = 'h00000119; 
    addr_rom[  282] = 'h00000b10; 	    data_ram[  282] = 'h0000011a; 
    addr_rom[  283] = 'h00000fe8; 	    data_ram[  283] = 'h0000011b; 
    addr_rom[  284] = 'h00000ce0; 	    data_ram[  284] = 'h0000011c; 
    addr_rom[  285] = 'h00000af0; 	    data_ram[  285] = 'h0000011d; 
    addr_rom[  286] = 'h000008f0; 	    data_ram[  286] = 'h0000011e; 
    addr_rom[  287] = 'h00000454; 	    data_ram[  287] = 'h0000011f; 
    addr_rom[  288] = 'h00000984; 	    data_ram[  288] = 'h00000120; 
    addr_rom[  289] = 'h00000328; 	    data_ram[  289] = 'h00000121; 
    addr_rom[  290] = 'h00000174; 	    data_ram[  290] = 'h00000122; 
    addr_rom[  291] = 'h000004ac; 	    data_ram[  291] = 'h00000123; 
    addr_rom[  292] = 'h0000012c; 	    data_ram[  292] = 'h00000124; 
    addr_rom[  293] = 'h00000664; 	    data_ram[  293] = 'h00000125; 
    addr_rom[  294] = 'h00000a30; 	    data_ram[  294] = 'h00000126; 
    addr_rom[  295] = 'h0000051c; 	    data_ram[  295] = 'h00000127; 
    addr_rom[  296] = 'h000006b8; 	    data_ram[  296] = 'h00000128; 
    addr_rom[  297] = 'h00000738; 	    data_ram[  297] = 'h00000129; 
    addr_rom[  298] = 'h000006f0; 	    data_ram[  298] = 'h0000012a; 
    addr_rom[  299] = 'h00000ffc; 	    data_ram[  299] = 'h0000012b; 
    addr_rom[  300] = 'h00000bcc; 	    data_ram[  300] = 'h0000012c; 
    addr_rom[  301] = 'h000006c4; 	    data_ram[  301] = 'h0000012d; 
    addr_rom[  302] = 'h00000874; 	    data_ram[  302] = 'h0000012e; 
    addr_rom[  303] = 'h000002d0; 	    data_ram[  303] = 'h0000012f; 
    addr_rom[  304] = 'h000005f8; 	    data_ram[  304] = 'h00000130; 
    addr_rom[  305] = 'h00000c20; 	    data_ram[  305] = 'h00000131; 
    addr_rom[  306] = 'h000005d0; 	    data_ram[  306] = 'h00000132; 
    addr_rom[  307] = 'h00000ca4; 	    data_ram[  307] = 'h00000133; 
    addr_rom[  308] = 'h00000f18; 	    data_ram[  308] = 'h00000134; 
    addr_rom[  309] = 'h00000fc4; 	    data_ram[  309] = 'h00000135; 
    addr_rom[  310] = 'h00000f74; 	    data_ram[  310] = 'h00000136; 
    addr_rom[  311] = 'h00000f8c; 	    data_ram[  311] = 'h00000137; 
    addr_rom[  312] = 'h0000076c; 	    data_ram[  312] = 'h00000138; 
    addr_rom[  313] = 'h00000778; 	    data_ram[  313] = 'h00000139; 
    addr_rom[  314] = 'h00000f84; 	    data_ram[  314] = 'h0000013a; 
    addr_rom[  315] = 'h00000fc8; 	    data_ram[  315] = 'h0000013b; 
    addr_rom[  316] = 'h00000ae4; 	    data_ram[  316] = 'h0000013c; 
    addr_rom[  317] = 'h00000c28; 	    data_ram[  317] = 'h0000013d; 
    addr_rom[  318] = 'h00000814; 	    data_ram[  318] = 'h0000013e; 
    addr_rom[  319] = 'h000009c8; 	    data_ram[  319] = 'h0000013f; 
    addr_rom[  320] = 'h00000dc4; 	    data_ram[  320] = 'h00000140; 
    addr_rom[  321] = 'h00000840; 	    data_ram[  321] = 'h00000141; 
    addr_rom[  322] = 'h0000047c; 	    data_ram[  322] = 'h00000142; 
    addr_rom[  323] = 'h00000c44; 	    data_ram[  323] = 'h00000143; 
    addr_rom[  324] = 'h00000ea4; 	    data_ram[  324] = 'h00000144; 
    addr_rom[  325] = 'h000003d8; 	    data_ram[  325] = 'h00000145; 
    addr_rom[  326] = 'h000005a4; 	    data_ram[  326] = 'h00000146; 
    addr_rom[  327] = 'h00000d50; 	    data_ram[  327] = 'h00000147; 
    addr_rom[  328] = 'h00000940; 	    data_ram[  328] = 'h00000148; 
    addr_rom[  329] = 'h00000c5c; 	    data_ram[  329] = 'h00000149; 
    addr_rom[  330] = 'h00000c6c; 	    data_ram[  330] = 'h0000014a; 
    addr_rom[  331] = 'h000009d4; 	    data_ram[  331] = 'h0000014b; 
    addr_rom[  332] = 'h000005c8; 	    data_ram[  332] = 'h0000014c; 
    addr_rom[  333] = 'h00000e78; 	    data_ram[  333] = 'h0000014d; 
    addr_rom[  334] = 'h000003b0; 	    data_ram[  334] = 'h0000014e; 
    addr_rom[  335] = 'h00000338; 	    data_ram[  335] = 'h0000014f; 
    addr_rom[  336] = 'h00000d3c; 	    data_ram[  336] = 'h00000150; 
    addr_rom[  337] = 'h00000f30; 	    data_ram[  337] = 'h00000151; 
    addr_rom[  338] = 'h00000608; 	    data_ram[  338] = 'h00000152; 
    addr_rom[  339] = 'h00000bf4; 	    data_ram[  339] = 'h00000153; 
    addr_rom[  340] = 'h00000da8; 	    data_ram[  340] = 'h00000154; 
    addr_rom[  341] = 'h00000468; 	    data_ram[  341] = 'h00000155; 
    addr_rom[  342] = 'h00000ac8; 	    data_ram[  342] = 'h00000156; 
    addr_rom[  343] = 'h00000140; 	    data_ram[  343] = 'h00000157; 
    addr_rom[  344] = 'h00000228; 	    data_ram[  344] = 'h00000158; 
    addr_rom[  345] = 'h0000063c; 	    data_ram[  345] = 'h00000159; 
    addr_rom[  346] = 'h0000072c; 	    data_ram[  346] = 'h0000015a; 
    addr_rom[  347] = 'h00000160; 	    data_ram[  347] = 'h0000015b; 
    addr_rom[  348] = 'h00000ee0; 	    data_ram[  348] = 'h0000015c; 
    addr_rom[  349] = 'h0000013c; 	    data_ram[  349] = 'h0000015d; 
    addr_rom[  350] = 'h00000ce4; 	    data_ram[  350] = 'h0000015e; 
    addr_rom[  351] = 'h000008d0; 	    data_ram[  351] = 'h0000015f; 
    addr_rom[  352] = 'h00000224; 	    data_ram[  352] = 'h00000160; 
    addr_rom[  353] = 'h00000f44; 	    data_ram[  353] = 'h00000161; 
    addr_rom[  354] = 'h00000c3c; 	    data_ram[  354] = 'h00000162; 
    addr_rom[  355] = 'h00000068; 	    data_ram[  355] = 'h00000163; 
    addr_rom[  356] = 'h00000828; 	    data_ram[  356] = 'h00000164; 
    addr_rom[  357] = 'h00000da0; 	    data_ram[  357] = 'h00000165; 
    addr_rom[  358] = 'h000003e0; 	    data_ram[  358] = 'h00000166; 
    addr_rom[  359] = 'h0000064c; 	    data_ram[  359] = 'h00000167; 
    addr_rom[  360] = 'h00000210; 	    data_ram[  360] = 'h00000168; 
    addr_rom[  361] = 'h00000650; 	    data_ram[  361] = 'h00000169; 
    addr_rom[  362] = 'h000003a0; 	    data_ram[  362] = 'h0000016a; 
    addr_rom[  363] = 'h000009e4; 	    data_ram[  363] = 'h0000016b; 
    addr_rom[  364] = 'h00000484; 	    data_ram[  364] = 'h0000016c; 
    addr_rom[  365] = 'h00000844; 	    data_ram[  365] = 'h0000016d; 
    addr_rom[  366] = 'h000000f0; 	    data_ram[  366] = 'h0000016e; 
    addr_rom[  367] = 'h00000ae8; 	    data_ram[  367] = 'h0000016f; 
    addr_rom[  368] = 'h00000cd8; 	    data_ram[  368] = 'h00000170; 
    addr_rom[  369] = 'h00000cbc; 	    data_ram[  369] = 'h00000171; 
    addr_rom[  370] = 'h00000918; 	    data_ram[  370] = 'h00000172; 
    addr_rom[  371] = 'h000000d4; 	    data_ram[  371] = 'h00000173; 
    addr_rom[  372] = 'h000001f0; 	    data_ram[  372] = 'h00000174; 
    addr_rom[  373] = 'h000005c4; 	    data_ram[  373] = 'h00000175; 
    addr_rom[  374] = 'h00000a44; 	    data_ram[  374] = 'h00000176; 
    addr_rom[  375] = 'h0000090c; 	    data_ram[  375] = 'h00000177; 
    addr_rom[  376] = 'h00000d60; 	    data_ram[  376] = 'h00000178; 
    addr_rom[  377] = 'h00000968; 	    data_ram[  377] = 'h00000179; 
    addr_rom[  378] = 'h00000a90; 	    data_ram[  378] = 'h0000017a; 
    addr_rom[  379] = 'h00000384; 	    data_ram[  379] = 'h0000017b; 
    addr_rom[  380] = 'h000006bc; 	    data_ram[  380] = 'h0000017c; 
    addr_rom[  381] = 'h000006e4; 	    data_ram[  381] = 'h0000017d; 
    addr_rom[  382] = 'h00000530; 	    data_ram[  382] = 'h0000017e; 
    addr_rom[  383] = 'h000000fc; 	    data_ram[  383] = 'h0000017f; 
    addr_rom[  384] = 'h00000b18; 	    data_ram[  384] = 'h00000180; 
    addr_rom[  385] = 'h00000954; 	    data_ram[  385] = 'h00000181; 
    addr_rom[  386] = 'h00000a14; 	    data_ram[  386] = 'h00000182; 
    addr_rom[  387] = 'h00000b64; 	    data_ram[  387] = 'h00000183; 
    addr_rom[  388] = 'h000007cc; 	    data_ram[  388] = 'h00000184; 
    addr_rom[  389] = 'h00000e70; 	    data_ram[  389] = 'h00000185; 
    addr_rom[  390] = 'h00000cc0; 	    data_ram[  390] = 'h00000186; 
    addr_rom[  391] = 'h000001b4; 	    data_ram[  391] = 'h00000187; 
    addr_rom[  392] = 'h00000758; 	    data_ram[  392] = 'h00000188; 
    addr_rom[  393] = 'h00000928; 	    data_ram[  393] = 'h00000189; 
    addr_rom[  394] = 'h00000a48; 	    data_ram[  394] = 'h0000018a; 
    addr_rom[  395] = 'h00000818; 	    data_ram[  395] = 'h0000018b; 
    addr_rom[  396] = 'h0000098c; 	    data_ram[  396] = 'h0000018c; 
    addr_rom[  397] = 'h000005b8; 	    data_ram[  397] = 'h0000018d; 
    addr_rom[  398] = 'h000005bc; 	    data_ram[  398] = 'h0000018e; 
    addr_rom[  399] = 'h0000087c; 	    data_ram[  399] = 'h0000018f; 
    addr_rom[  400] = 'h000008cc; 	    data_ram[  400] = 'h00000190; 
    addr_rom[  401] = 'h00000f50; 	    data_ram[  401] = 'h00000191; 
    addr_rom[  402] = 'h00000c74; 	    data_ram[  402] = 'h00000192; 
    addr_rom[  403] = 'h00000488; 	    data_ram[  403] = 'h00000193; 
    addr_rom[  404] = 'h0000062c; 	    data_ram[  404] = 'h00000194; 
    addr_rom[  405] = 'h00000b60; 	    data_ram[  405] = 'h00000195; 
    addr_rom[  406] = 'h00000a94; 	    data_ram[  406] = 'h00000196; 
    addr_rom[  407] = 'h0000052c; 	    data_ram[  407] = 'h00000197; 
    addr_rom[  408] = 'h00000a4c; 	    data_ram[  408] = 'h00000198; 
    addr_rom[  409] = 'h00000e74; 	    data_ram[  409] = 'h00000199; 
    addr_rom[  410] = 'h00000108; 	    data_ram[  410] = 'h0000019a; 
    addr_rom[  411] = 'h000009ac; 	    data_ram[  411] = 'h0000019b; 
    addr_rom[  412] = 'h000006dc; 	    data_ram[  412] = 'h0000019c; 
    addr_rom[  413] = 'h00000df0; 	    data_ram[  413] = 'h0000019d; 
    addr_rom[  414] = 'h00000734; 	    data_ram[  414] = 'h0000019e; 
    addr_rom[  415] = 'h00000eb4; 	    data_ram[  415] = 'h0000019f; 
    addr_rom[  416] = 'h00000eac; 	    data_ram[  416] = 'h000001a0; 
    addr_rom[  417] = 'h0000034c; 	    data_ram[  417] = 'h000001a1; 
    addr_rom[  418] = 'h00000334; 	    data_ram[  418] = 'h000001a2; 
    addr_rom[  419] = 'h00000754; 	    data_ram[  419] = 'h000001a3; 
    addr_rom[  420] = 'h00000254; 	    data_ram[  420] = 'h000001a4; 
    addr_rom[  421] = 'h00000c98; 	    data_ram[  421] = 'h000001a5; 
    addr_rom[  422] = 'h00000430; 	    data_ram[  422] = 'h000001a6; 
    addr_rom[  423] = 'h0000033c; 	    data_ram[  423] = 'h000001a7; 
    addr_rom[  424] = 'h00000e68; 	    data_ram[  424] = 'h000001a8; 
    addr_rom[  425] = 'h000005dc; 	    data_ram[  425] = 'h000001a9; 
    addr_rom[  426] = 'h00000db4; 	    data_ram[  426] = 'h000001aa; 
    addr_rom[  427] = 'h00000e60; 	    data_ram[  427] = 'h000001ab; 
    addr_rom[  428] = 'h00000438; 	    data_ram[  428] = 'h000001ac; 
    addr_rom[  429] = 'h00000ccc; 	    data_ram[  429] = 'h000001ad; 
    addr_rom[  430] = 'h000006f4; 	    data_ram[  430] = 'h000001ae; 
    addr_rom[  431] = 'h000009c0; 	    data_ram[  431] = 'h000001af; 
    addr_rom[  432] = 'h00000f60; 	    data_ram[  432] = 'h000001b0; 
    addr_rom[  433] = 'h00000f64; 	    data_ram[  433] = 'h000001b1; 
    addr_rom[  434] = 'h0000069c; 	    data_ram[  434] = 'h000001b2; 
    addr_rom[  435] = 'h00000748; 	    data_ram[  435] = 'h000001b3; 
    addr_rom[  436] = 'h00000abc; 	    data_ram[  436] = 'h000001b4; 
    addr_rom[  437] = 'h00000d78; 	    data_ram[  437] = 'h000001b5; 
    addr_rom[  438] = 'h00000e58; 	    data_ram[  438] = 'h000001b6; 
    addr_rom[  439] = 'h00000c34; 	    data_ram[  439] = 'h000001b7; 
    addr_rom[  440] = 'h00000a54; 	    data_ram[  440] = 'h000001b8; 
    addr_rom[  441] = 'h00000670; 	    data_ram[  441] = 'h000001b9; 
    addr_rom[  442] = 'h00000690; 	    data_ram[  442] = 'h000001ba; 
    addr_rom[  443] = 'h0000083c; 	    data_ram[  443] = 'h000001bb; 
    addr_rom[  444] = 'h000001b0; 	    data_ram[  444] = 'h000001bc; 
    addr_rom[  445] = 'h0000070c; 	    data_ram[  445] = 'h000001bd; 
    addr_rom[  446] = 'h00000dd0; 	    data_ram[  446] = 'h000001be; 
    addr_rom[  447] = 'h00000320; 	    data_ram[  447] = 'h000001bf; 
    addr_rom[  448] = 'h000008c8; 	    data_ram[  448] = 'h000001c0; 
    addr_rom[  449] = 'h00000b80; 	    data_ram[  449] = 'h000001c1; 
    addr_rom[  450] = 'h0000022c; 	    data_ram[  450] = 'h000001c2; 
    addr_rom[  451] = 'h00000578; 	    data_ram[  451] = 'h000001c3; 
    addr_rom[  452] = 'h00000470; 	    data_ram[  452] = 'h000001c4; 
    addr_rom[  453] = 'h00000034; 	    data_ram[  453] = 'h000001c5; 
    addr_rom[  454] = 'h00000e44; 	    data_ram[  454] = 'h000001c6; 
    addr_rom[  455] = 'h000003d4; 	    data_ram[  455] = 'h000001c7; 
    addr_rom[  456] = 'h00000684; 	    data_ram[  456] = 'h000001c8; 
    addr_rom[  457] = 'h00000a84; 	    data_ram[  457] = 'h000001c9; 
    addr_rom[  458] = 'h000004e0; 	    data_ram[  458] = 'h000001ca; 
    addr_rom[  459] = 'h000006e8; 	    data_ram[  459] = 'h000001cb; 
    addr_rom[  460] = 'h00000db0; 	    data_ram[  460] = 'h000001cc; 
    addr_rom[  461] = 'h00000e14; 	    data_ram[  461] = 'h000001cd; 
    addr_rom[  462] = 'h00000fa0; 	    data_ram[  462] = 'h000001ce; 
    addr_rom[  463] = 'h000006e0; 	    data_ram[  463] = 'h000001cf; 
    addr_rom[  464] = 'h000009f4; 	    data_ram[  464] = 'h000001d0; 
    addr_rom[  465] = 'h000009dc; 	    data_ram[  465] = 'h000001d1; 
    addr_rom[  466] = 'h000000f8; 	    data_ram[  466] = 'h000001d2; 
    addr_rom[  467] = 'h00000168; 	    data_ram[  467] = 'h000001d3; 
    addr_rom[  468] = 'h00000ec8; 	    data_ram[  468] = 'h000001d4; 
    addr_rom[  469] = 'h000009a4; 	    data_ram[  469] = 'h000001d5; 
    addr_rom[  470] = 'h00000794; 	    data_ram[  470] = 'h000001d6; 
    addr_rom[  471] = 'h000004ec; 	    data_ram[  471] = 'h000001d7; 
    addr_rom[  472] = 'h000009ec; 	    data_ram[  472] = 'h000001d8; 
    addr_rom[  473] = 'h0000080c; 	    data_ram[  473] = 'h000001d9; 
    addr_rom[  474] = 'h00000e88; 	    data_ram[  474] = 'h000001da; 
    addr_rom[  475] = 'h00000c68; 	    data_ram[  475] = 'h000001db; 
    addr_rom[  476] = 'h00000ad4; 	    data_ram[  476] = 'h000001dc; 
    addr_rom[  477] = 'h000007e0; 	    data_ram[  477] = 'h000001dd; 
    addr_rom[  478] = 'h000007bc; 	    data_ram[  478] = 'h000001de; 
    addr_rom[  479] = 'h00000ac4; 	    data_ram[  479] = 'h000001df; 
    addr_rom[  480] = 'h00000f80; 	    data_ram[  480] = 'h000001e0; 
    addr_rom[  481] = 'h00000400; 	    data_ram[  481] = 'h000001e1; 
    addr_rom[  482] = 'h00000d88; 	    data_ram[  482] = 'h000001e2; 
    addr_rom[  483] = 'h00000af4; 	    data_ram[  483] = 'h000001e3; 
    addr_rom[  484] = 'h00000f08; 	    data_ram[  484] = 'h000001e4; 
    addr_rom[  485] = 'h00000e5c; 	    data_ram[  485] = 'h000001e5; 
    addr_rom[  486] = 'h0000036c; 	    data_ram[  486] = 'h000001e6; 
    addr_rom[  487] = 'h00000f1c; 	    data_ram[  487] = 'h000001e7; 
    addr_rom[  488] = 'h00000b30; 	    data_ram[  488] = 'h000001e8; 
    addr_rom[  489] = 'h00000be0; 	    data_ram[  489] = 'h000001e9; 
    addr_rom[  490] = 'h000009b4; 	    data_ram[  490] = 'h000001ea; 
    addr_rom[  491] = 'h000008ec; 	    data_ram[  491] = 'h000001eb; 
    addr_rom[  492] = 'h00000cf8; 	    data_ram[  492] = 'h000001ec; 
    addr_rom[  493] = 'h00000060; 	    data_ram[  493] = 'h000001ed; 
    addr_rom[  494] = 'h00000178; 	    data_ram[  494] = 'h000001ee; 
    addr_rom[  495] = 'h0000079c; 	    data_ram[  495] = 'h000001ef; 
    addr_rom[  496] = 'h00000f00; 	    data_ram[  496] = 'h000001f0; 
    addr_rom[  497] = 'h000001ec; 	    data_ram[  497] = 'h000001f1; 
    addr_rom[  498] = 'h00000864; 	    data_ram[  498] = 'h000001f2; 
    addr_rom[  499] = 'h00000644; 	    data_ram[  499] = 'h000001f3; 
    addr_rom[  500] = 'h00000374; 	    data_ram[  500] = 'h000001f4; 
    addr_rom[  501] = 'h00000b48; 	    data_ram[  501] = 'h000001f5; 
    addr_rom[  502] = 'h00000b98; 	    data_ram[  502] = 'h000001f6; 
    addr_rom[  503] = 'h000004e8; 	    data_ram[  503] = 'h000001f7; 
    addr_rom[  504] = 'h000007c4; 	    data_ram[  504] = 'h000001f8; 
    addr_rom[  505] = 'h00000dfc; 	    data_ram[  505] = 'h000001f9; 
    addr_rom[  506] = 'h00000ca0; 	    data_ram[  506] = 'h000001fa; 
    addr_rom[  507] = 'h000004b4; 	    data_ram[  507] = 'h000001fb; 
    addr_rom[  508] = 'h00000cdc; 	    data_ram[  508] = 'h000001fc; 
    addr_rom[  509] = 'h00000854; 	    data_ram[  509] = 'h000001fd; 
    addr_rom[  510] = 'h00000cb4; 	    data_ram[  510] = 'h000001fe; 
    addr_rom[  511] = 'h000001cc; 	    data_ram[  511] = 'h000001ff; 
    addr_rom[  512] = 'h000007ac; 	    data_ram[  512] = 'h00000200; 
    addr_rom[  513] = 'h00000adc; 	    data_ram[  513] = 'h00000201; 
    addr_rom[  514] = 'h00000098; 	    data_ram[  514] = 'h00000202; 
    addr_rom[  515] = 'h000006b4; 	    data_ram[  515] = 'h00000203; 
    addr_rom[  516] = 'h00000c70; 	    data_ram[  516] = 'h00000204; 
    addr_rom[  517] = 'h00000e24; 	    data_ram[  517] = 'h00000205; 
    addr_rom[  518] = 'h000000a8; 	    data_ram[  518] = 'h00000206; 
    addr_rom[  519] = 'h000004c8; 	    data_ram[  519] = 'h00000207; 
    addr_rom[  520] = 'h000004d4; 	    data_ram[  520] = 'h00000208; 
    addr_rom[  521] = 'h00000188; 	    data_ram[  521] = 'h00000209; 
    addr_rom[  522] = 'h00000ed8; 	    data_ram[  522] = 'h0000020a; 
    addr_rom[  523] = 'h00000e28; 	    data_ram[  523] = 'h0000020b; 
    addr_rom[  524] = 'h00000830; 	    data_ram[  524] = 'h0000020c; 
    addr_rom[  525] = 'h00000274; 	    data_ram[  525] = 'h0000020d; 
    addr_rom[  526] = 'h000001d8; 	    data_ram[  526] = 'h0000020e; 
    addr_rom[  527] = 'h00000520; 	    data_ram[  527] = 'h0000020f; 
    addr_rom[  528] = 'h00000008; 	    data_ram[  528] = 'h00000210; 
    addr_rom[  529] = 'h000005cc; 	    data_ram[  529] = 'h00000211; 
    addr_rom[  530] = 'h000006f8; 	    data_ram[  530] = 'h00000212; 
    addr_rom[  531] = 'h00000444; 	    data_ram[  531] = 'h00000213; 
    addr_rom[  532] = 'h00000050; 	    data_ram[  532] = 'h00000214; 
    addr_rom[  533] = 'h00000d34; 	    data_ram[  533] = 'h00000215; 
    addr_rom[  534] = 'h00000fe0; 	    data_ram[  534] = 'h00000216; 
    addr_rom[  535] = 'h00000e8c; 	    data_ram[  535] = 'h00000217; 
    addr_rom[  536] = 'h00000fbc; 	    data_ram[  536] = 'h00000218; 
    addr_rom[  537] = 'h000002f0; 	    data_ram[  537] = 'h00000219; 
    addr_rom[  538] = 'h0000071c; 	    data_ram[  538] = 'h0000021a; 
    addr_rom[  539] = 'h0000092c; 	    data_ram[  539] = 'h0000021b; 
    addr_rom[  540] = 'h00000514; 	    data_ram[  540] = 'h0000021c; 
    addr_rom[  541] = 'h00000568; 	    data_ram[  541] = 'h0000021d; 
    addr_rom[  542] = 'h00000fb4; 	    data_ram[  542] = 'h0000021e; 
    addr_rom[  543] = 'h00000260; 	    data_ram[  543] = 'h0000021f; 
    addr_rom[  544] = 'h00000d70; 	    data_ram[  544] = 'h00000220; 
    addr_rom[  545] = 'h000000c0; 	    data_ram[  545] = 'h00000221; 
    addr_rom[  546] = 'h00000fac; 	    data_ram[  546] = 'h00000222; 
    addr_rom[  547] = 'h00000d68; 	    data_ram[  547] = 'h00000223; 
    addr_rom[  548] = 'h000002e0; 	    data_ram[  548] = 'h00000224; 
    addr_rom[  549] = 'h00000c60; 	    data_ram[  549] = 'h00000225; 
    addr_rom[  550] = 'h000000e4; 	    data_ram[  550] = 'h00000226; 
    addr_rom[  551] = 'h00000948; 	    data_ram[  551] = 'h00000227; 
    addr_rom[  552] = 'h00000ca8; 	    data_ram[  552] = 'h00000228; 
    addr_rom[  553] = 'h00000540; 	    data_ram[  553] = 'h00000229; 
    addr_rom[  554] = 'h000004a8; 	    data_ram[  554] = 'h0000022a; 
    addr_rom[  555] = 'h00000fd0; 	    data_ram[  555] = 'h0000022b; 
    addr_rom[  556] = 'h00000464; 	    data_ram[  556] = 'h0000022c; 
    addr_rom[  557] = 'h00000b58; 	    data_ram[  557] = 'h0000022d; 
    addr_rom[  558] = 'h000005a0; 	    data_ram[  558] = 'h0000022e; 
    addr_rom[  559] = 'h000003d0; 	    data_ram[  559] = 'h0000022f; 
    addr_rom[  560] = 'h00000cb0; 	    data_ram[  560] = 'h00000230; 
    addr_rom[  561] = 'h00000f38; 	    data_ram[  561] = 'h00000231; 
    addr_rom[  562] = 'h00000970; 	    data_ram[  562] = 'h00000232; 
    addr_rom[  563] = 'h000002c8; 	    data_ram[  563] = 'h00000233; 
    addr_rom[  564] = 'h0000067c; 	    data_ram[  564] = 'h00000234; 
    addr_rom[  565] = 'h00000894; 	    data_ram[  565] = 'h00000235; 
    addr_rom[  566] = 'h00000620; 	    data_ram[  566] = 'h00000236; 
    addr_rom[  567] = 'h00000780; 	    data_ram[  567] = 'h00000237; 
    addr_rom[  568] = 'h000007b8; 	    data_ram[  568] = 'h00000238; 
    addr_rom[  569] = 'h00000030; 	    data_ram[  569] = 'h00000239; 
    addr_rom[  570] = 'h00000dec; 	    data_ram[  570] = 'h0000023a; 
    addr_rom[  571] = 'h000000a4; 	    data_ram[  571] = 'h0000023b; 
    addr_rom[  572] = 'h00000a40; 	    data_ram[  572] = 'h0000023c; 
    addr_rom[  573] = 'h000008d8; 	    data_ram[  573] = 'h0000023d; 
    addr_rom[  574] = 'h00000c78; 	    data_ram[  574] = 'h0000023e; 
    addr_rom[  575] = 'h000004e4; 	    data_ram[  575] = 'h0000023f; 
    addr_rom[  576] = 'h00000efc; 	    data_ram[  576] = 'h00000240; 
    addr_rom[  577] = 'h000002d4; 	    data_ram[  577] = 'h00000241; 
    addr_rom[  578] = 'h00000e04; 	    data_ram[  578] = 'h00000242; 
    addr_rom[  579] = 'h000007d4; 	    data_ram[  579] = 'h00000243; 
    addr_rom[  580] = 'h00000b5c; 	    data_ram[  580] = 'h00000244; 
    addr_rom[  581] = 'h0000082c; 	    data_ram[  581] = 'h00000245; 
    addr_rom[  582] = 'h00000064; 	    data_ram[  582] = 'h00000246; 
    addr_rom[  583] = 'h00000100; 	    data_ram[  583] = 'h00000247; 
    addr_rom[  584] = 'h00000a68; 	    data_ram[  584] = 'h00000248; 
    addr_rom[  585] = 'h00000654; 	    data_ram[  585] = 'h00000249; 
    addr_rom[  586] = 'h00000920; 	    data_ram[  586] = 'h0000024a; 
    addr_rom[  587] = 'h00000f88; 	    data_ram[  587] = 'h0000024b; 
    addr_rom[  588] = 'h00000938; 	    data_ram[  588] = 'h0000024c; 
    addr_rom[  589] = 'h00000d38; 	    data_ram[  589] = 'h0000024d; 
    addr_rom[  590] = 'h00000824; 	    data_ram[  590] = 'h0000024e; 
    addr_rom[  591] = 'h00000cfc; 	    data_ram[  591] = 'h0000024f; 
    addr_rom[  592] = 'h00000340; 	    data_ram[  592] = 'h00000250; 
    addr_rom[  593] = 'h00000964; 	    data_ram[  593] = 'h00000251; 
    addr_rom[  594] = 'h000005a8; 	    data_ram[  594] = 'h00000252; 
    addr_rom[  595] = 'h0000056c; 	    data_ram[  595] = 'h00000253; 
    addr_rom[  596] = 'h00000580; 	    data_ram[  596] = 'h00000254; 
    addr_rom[  597] = 'h00000f90; 	    data_ram[  597] = 'h00000255; 
    addr_rom[  598] = 'h00000a10; 	    data_ram[  598] = 'h00000256; 
    addr_rom[  599] = 'h00000138; 	    data_ram[  599] = 'h00000257; 
    addr_rom[  600] = 'h000005e8; 	    data_ram[  600] = 'h00000258; 
    addr_rom[  601] = 'h00000418; 	    data_ram[  601] = 'h00000259; 
    addr_rom[  602] = 'h00000688; 	    data_ram[  602] = 'h0000025a; 
    addr_rom[  603] = 'h00000ab4; 	    data_ram[  603] = 'h0000025b; 
    addr_rom[  604] = 'h00000bb0; 	    data_ram[  604] = 'h0000025c; 
    addr_rom[  605] = 'h00000e0c; 	    data_ram[  605] = 'h0000025d; 
    addr_rom[  606] = 'h00000c90; 	    data_ram[  606] = 'h0000025e; 
    addr_rom[  607] = 'h00000b34; 	    data_ram[  607] = 'h0000025f; 
    addr_rom[  608] = 'h00000878; 	    data_ram[  608] = 'h00000260; 
    addr_rom[  609] = 'h00000908; 	    data_ram[  609] = 'h00000261; 
    addr_rom[  610] = 'h000002cc; 	    data_ram[  610] = 'h00000262; 
    addr_rom[  611] = 'h00000798; 	    data_ram[  611] = 'h00000263; 
    addr_rom[  612] = 'h000001d4; 	    data_ram[  612] = 'h00000264; 
    addr_rom[  613] = 'h00000404; 	    data_ram[  613] = 'h00000265; 
    addr_rom[  614] = 'h00000bbc; 	    data_ram[  614] = 'h00000266; 
    addr_rom[  615] = 'h00000884; 	    data_ram[  615] = 'h00000267; 
    addr_rom[  616] = 'h00000190; 	    data_ram[  616] = 'h00000268; 
    addr_rom[  617] = 'h00000898; 	    data_ram[  617] = 'h00000269; 
    addr_rom[  618] = 'h00000cb8; 	    data_ram[  618] = 'h0000026a; 
    addr_rom[  619] = 'h0000055c; 	    data_ram[  619] = 'h0000026b; 
    addr_rom[  620] = 'h00000fa4; 	    data_ram[  620] = 'h0000026c; 
    addr_rom[  621] = 'h000003ac; 	    data_ram[  621] = 'h0000026d; 
    addr_rom[  622] = 'h00000038; 	    data_ram[  622] = 'h0000026e; 
    addr_rom[  623] = 'h00000590; 	    data_ram[  623] = 'h0000026f; 
    addr_rom[  624] = 'h00000924; 	    data_ram[  624] = 'h00000270; 
    addr_rom[  625] = 'h000008c0; 	    data_ram[  625] = 'h00000271; 
    addr_rom[  626] = 'h00000054; 	    data_ram[  626] = 'h00000272; 
    addr_rom[  627] = 'h00000714; 	    data_ram[  627] = 'h00000273; 
    addr_rom[  628] = 'h00000f6c; 	    data_ram[  628] = 'h00000274; 
    addr_rom[  629] = 'h000001f8; 	    data_ram[  629] = 'h00000275; 
    addr_rom[  630] = 'h000005c0; 	    data_ram[  630] = 'h00000276; 
    addr_rom[  631] = 'h00000534; 	    data_ram[  631] = 'h00000277; 
    addr_rom[  632] = 'h000004dc; 	    data_ram[  632] = 'h00000278; 
    addr_rom[  633] = 'h00000350; 	    data_ram[  633] = 'h00000279; 
    addr_rom[  634] = 'h000006b0; 	    data_ram[  634] = 'h0000027a; 
    addr_rom[  635] = 'h0000016c; 	    data_ram[  635] = 'h0000027b; 
    addr_rom[  636] = 'h00000c48; 	    data_ram[  636] = 'h0000027c; 
    addr_rom[  637] = 'h0000021c; 	    data_ram[  637] = 'h0000027d; 
    addr_rom[  638] = 'h00000bb8; 	    data_ram[  638] = 'h0000027e; 
    addr_rom[  639] = 'h00000be8; 	    data_ram[  639] = 'h0000027f; 
    addr_rom[  640] = 'h000007c8; 	    data_ram[  640] = 'h00000280; 
    addr_rom[  641] = 'h0000015c; 	    data_ram[  641] = 'h00000281; 
    addr_rom[  642] = 'h00000d08; 	    data_ram[  642] = 'h00000282; 
    addr_rom[  643] = 'h000002a0; 	    data_ram[  643] = 'h00000283; 
    addr_rom[  644] = 'h000007d0; 	    data_ram[  644] = 'h00000284; 
    addr_rom[  645] = 'h00000998; 	    data_ram[  645] = 'h00000285; 
    addr_rom[  646] = 'h00000598; 	    data_ram[  646] = 'h00000286; 
    addr_rom[  647] = 'h00000b84; 	    data_ram[  647] = 'h00000287; 
    addr_rom[  648] = 'h00000f94; 	    data_ram[  648] = 'h00000288; 
    addr_rom[  649] = 'h00000d40; 	    data_ram[  649] = 'h00000289; 
    addr_rom[  650] = 'h00000e90; 	    data_ram[  650] = 'h0000028a; 
    addr_rom[  651] = 'h00000370; 	    data_ram[  651] = 'h0000028b; 
    addr_rom[  652] = 'h00000af8; 	    data_ram[  652] = 'h0000028c; 
    addr_rom[  653] = 'h00000564; 	    data_ram[  653] = 'h0000028d; 
    addr_rom[  654] = 'h0000009c; 	    data_ram[  654] = 'h0000028e; 
    addr_rom[  655] = 'h00000a6c; 	    data_ram[  655] = 'h0000028f; 
    addr_rom[  656] = 'h00000c08; 	    data_ram[  656] = 'h00000290; 
    addr_rom[  657] = 'h00000390; 	    data_ram[  657] = 'h00000291; 
    addr_rom[  658] = 'h00000724; 	    data_ram[  658] = 'h00000292; 
    addr_rom[  659] = 'h000006d0; 	    data_ram[  659] = 'h00000293; 
    addr_rom[  660] = 'h00000a34; 	    data_ram[  660] = 'h00000294; 
    addr_rom[  661] = 'h000000bc; 	    data_ram[  661] = 'h00000295; 
    addr_rom[  662] = 'h00000fc0; 	    data_ram[  662] = 'h00000296; 
    addr_rom[  663] = 'h0000050c; 	    data_ram[  663] = 'h00000297; 
    addr_rom[  664] = 'h00000ea0; 	    data_ram[  664] = 'h00000298; 
    addr_rom[  665] = 'h00000554; 	    data_ram[  665] = 'h00000299; 
    addr_rom[  666] = 'h0000025c; 	    data_ram[  666] = 'h0000029a; 
    addr_rom[  667] = 'h00000860; 	    data_ram[  667] = 'h0000029b; 
    addr_rom[  668] = 'h000008b8; 	    data_ram[  668] = 'h0000029c; 
    addr_rom[  669] = 'h000008a4; 	    data_ram[  669] = 'h0000029d; 
    addr_rom[  670] = 'h00000ef8; 	    data_ram[  670] = 'h0000029e; 
    addr_rom[  671] = 'h00000bd0; 	    data_ram[  671] = 'h0000029f; 
    addr_rom[  672] = 'h00000710; 	    data_ram[  672] = 'h000002a0; 
    addr_rom[  673] = 'h000002f8; 	    data_ram[  673] = 'h000002a1; 
    addr_rom[  674] = 'h00000dd4; 	    data_ram[  674] = 'h000002a2; 
    addr_rom[  675] = 'h00000544; 	    data_ram[  675] = 'h000002a3; 
    addr_rom[  676] = 'h00000200; 	    data_ram[  676] = 'h000002a4; 
    addr_rom[  677] = 'h00000ee8; 	    data_ram[  677] = 'h000002a5; 
    addr_rom[  678] = 'h00000630; 	    data_ram[  678] = 'h000002a6; 
    addr_rom[  679] = 'h00000088; 	    data_ram[  679] = 'h000002a7; 
    addr_rom[  680] = 'h00000a20; 	    data_ram[  680] = 'h000002a8; 
    addr_rom[  681] = 'h000003a8; 	    data_ram[  681] = 'h000002a9; 
    addr_rom[  682] = 'h000002d8; 	    data_ram[  682] = 'h000002aa; 
    addr_rom[  683] = 'h00000b3c; 	    data_ram[  683] = 'h000002ab; 
    addr_rom[  684] = 'h00000a2c; 	    data_ram[  684] = 'h000002ac; 
    addr_rom[  685] = 'h00000120; 	    data_ram[  685] = 'h000002ad; 
    addr_rom[  686] = 'h000001e0; 	    data_ram[  686] = 'h000002ae; 
    addr_rom[  687] = 'h00000a78; 	    data_ram[  687] = 'h000002af; 
    addr_rom[  688] = 'h00000238; 	    data_ram[  688] = 'h000002b0; 
    addr_rom[  689] = 'h00000364; 	    data_ram[  689] = 'h000002b1; 
    addr_rom[  690] = 'h000005f4; 	    data_ram[  690] = 'h000002b2; 
    addr_rom[  691] = 'h000003fc; 	    data_ram[  691] = 'h000002b3; 
    addr_rom[  692] = 'h0000037c; 	    data_ram[  692] = 'h000002b4; 
    addr_rom[  693] = 'h00000768; 	    data_ram[  693] = 'h000002b5; 
    addr_rom[  694] = 'h00000ff0; 	    data_ram[  694] = 'h000002b6; 
    addr_rom[  695] = 'h000005ec; 	    data_ram[  695] = 'h000002b7; 
    addr_rom[  696] = 'h00000d28; 	    data_ram[  696] = 'h000002b8; 
    addr_rom[  697] = 'h0000075c; 	    data_ram[  697] = 'h000002b9; 
    addr_rom[  698] = 'h00000450; 	    data_ram[  698] = 'h000002ba; 
    addr_rom[  699] = 'h0000059c; 	    data_ram[  699] = 'h000002bb; 
    addr_rom[  700] = 'h00000ecc; 	    data_ram[  700] = 'h000002bc; 
    addr_rom[  701] = 'h00000ee4; 	    data_ram[  701] = 'h000002bd; 
    addr_rom[  702] = 'h00000bf8; 	    data_ram[  702] = 'h000002be; 
    addr_rom[  703] = 'h00000c14; 	    data_ram[  703] = 'h000002bf; 
    addr_rom[  704] = 'h000003c4; 	    data_ram[  704] = 'h000002c0; 
    addr_rom[  705] = 'h00000198; 	    data_ram[  705] = 'h000002c1; 
    addr_rom[  706] = 'h000006c0; 	    data_ram[  706] = 'h000002c2; 
    addr_rom[  707] = 'h000000b0; 	    data_ram[  707] = 'h000002c3; 
    addr_rom[  708] = 'h000009d0; 	    data_ram[  708] = 'h000002c4; 
    addr_rom[  709] = 'h00000010; 	    data_ram[  709] = 'h000002c5; 
    addr_rom[  710] = 'h0000099c; 	    data_ram[  710] = 'h000002c6; 
    addr_rom[  711] = 'h00000b9c; 	    data_ram[  711] = 'h000002c7; 
    addr_rom[  712] = 'h00000d14; 	    data_ram[  712] = 'h000002c8; 
    addr_rom[  713] = 'h00000080; 	    data_ram[  713] = 'h000002c9; 
    addr_rom[  714] = 'h00000258; 	    data_ram[  714] = 'h000002ca; 
    addr_rom[  715] = 'h000009fc; 	    data_ram[  715] = 'h000002cb; 
    addr_rom[  716] = 'h00000fb0; 	    data_ram[  716] = 'h000002cc; 
    addr_rom[  717] = 'h0000018c; 	    data_ram[  717] = 'h000002cd; 
    addr_rom[  718] = 'h0000077c; 	    data_ram[  718] = 'h000002ce; 
    addr_rom[  719] = 'h00000c58; 	    data_ram[  719] = 'h000002cf; 
    addr_rom[  720] = 'h000000dc; 	    data_ram[  720] = 'h000002d0; 
    addr_rom[  721] = 'h00000ac0; 	    data_ram[  721] = 'h000002d1; 
    addr_rom[  722] = 'h00000b4c; 	    data_ram[  722] = 'h000002d2; 
    addr_rom[  723] = 'h000008e4; 	    data_ram[  723] = 'h000002d3; 
    addr_rom[  724] = 'h00000b0c; 	    data_ram[  724] = 'h000002d4; 
    addr_rom[  725] = 'h00000628; 	    data_ram[  725] = 'h000002d5; 
    addr_rom[  726] = 'h0000057c; 	    data_ram[  726] = 'h000002d6; 
    addr_rom[  727] = 'h00000a24; 	    data_ram[  727] = 'h000002d7; 
    addr_rom[  728] = 'h00000aa8; 	    data_ram[  728] = 'h000002d8; 
    addr_rom[  729] = 'h000003e4; 	    data_ram[  729] = 'h000002d9; 
    addr_rom[  730] = 'h000009b0; 	    data_ram[  730] = 'h000002da; 
    addr_rom[  731] = 'h00000134; 	    data_ram[  731] = 'h000002db; 
    addr_rom[  732] = 'h000003a4; 	    data_ram[  732] = 'h000002dc; 
    addr_rom[  733] = 'h0000001c; 	    data_ram[  733] = 'h000002dd; 
    addr_rom[  734] = 'h000008f8; 	    data_ram[  734] = 'h000002de; 
    addr_rom[  735] = 'h000000f4; 	    data_ram[  735] = 'h000002df; 
    addr_rom[  736] = 'h0000024c; 	    data_ram[  736] = 'h000002e0; 
    addr_rom[  737] = 'h0000019c; 	    data_ram[  737] = 'h000002e1; 
    addr_rom[  738] = 'h000007fc; 	    data_ram[  738] = 'h000002e2; 
    addr_rom[  739] = 'h00000c84; 	    data_ram[  739] = 'h000002e3; 
    addr_rom[  740] = 'h00000bf0; 	    data_ram[  740] = 'h000002e4; 
    addr_rom[  741] = 'h00000810; 	    data_ram[  741] = 'h000002e5; 
    addr_rom[  742] = 'h00000504; 	    data_ram[  742] = 'h000002e6; 
    addr_rom[  743] = 'h00000708; 	    data_ram[  743] = 'h000002e7; 
    addr_rom[  744] = 'h00000678; 	    data_ram[  744] = 'h000002e8; 
    addr_rom[  745] = 'h00000800; 	    data_ram[  745] = 'h000002e9; 
    addr_rom[  746] = 'h00000318; 	    data_ram[  746] = 'h000002ea; 
    addr_rom[  747] = 'h00000448; 	    data_ram[  747] = 'h000002eb; 
    addr_rom[  748] = 'h0000027c; 	    data_ram[  748] = 'h000002ec; 
    addr_rom[  749] = 'h00000848; 	    data_ram[  749] = 'h000002ed; 
    addr_rom[  750] = 'h00000a50; 	    data_ram[  750] = 'h000002ee; 
    addr_rom[  751] = 'h00000398; 	    data_ram[  751] = 'h000002ef; 
    addr_rom[  752] = 'h00000df4; 	    data_ram[  752] = 'h000002f0; 
    addr_rom[  753] = 'h0000005c; 	    data_ram[  753] = 'h000002f1; 
    addr_rom[  754] = 'h00000a80; 	    data_ram[  754] = 'h000002f2; 
    addr_rom[  755] = 'h00000b8c; 	    data_ram[  755] = 'h000002f3; 
    addr_rom[  756] = 'h000008dc; 	    data_ram[  756] = 'h000002f4; 
    addr_rom[  757] = 'h00000f0c; 	    data_ram[  757] = 'h000002f5; 
    addr_rom[  758] = 'h00000f40; 	    data_ram[  758] = 'h000002f6; 
    addr_rom[  759] = 'h00000850; 	    data_ram[  759] = 'h000002f7; 
    addr_rom[  760] = 'h00000c64; 	    data_ram[  760] = 'h000002f8; 
    addr_rom[  761] = 'h00000314; 	    data_ram[  761] = 'h000002f9; 
    addr_rom[  762] = 'h00000234; 	    data_ram[  762] = 'h000002fa; 
    addr_rom[  763] = 'h000004d0; 	    data_ram[  763] = 'h000002fb; 
    addr_rom[  764] = 'h00000834; 	    data_ram[  764] = 'h000002fc; 
    addr_rom[  765] = 'h00000118; 	    data_ram[  765] = 'h000002fd; 
    addr_rom[  766] = 'h0000058c; 	    data_ram[  766] = 'h000002fe; 
    addr_rom[  767] = 'h000009b8; 	    data_ram[  767] = 'h000002ff; 
    addr_rom[  768] = 'h00000b88; 	    data_ram[  768] = 'h00000300; 
    addr_rom[  769] = 'h00000de0; 	    data_ram[  769] = 'h00000301; 
    addr_rom[  770] = 'h00000c0c; 	    data_ram[  770] = 'h00000302; 
    addr_rom[  771] = 'h00000dc0; 	    data_ram[  771] = 'h00000303; 
    addr_rom[  772] = 'h000003bc; 	    data_ram[  772] = 'h00000304; 
    addr_rom[  773] = 'h000008e8; 	    data_ram[  773] = 'h00000305; 
    addr_rom[  774] = 'h00000084; 	    data_ram[  774] = 'h00000306; 
    addr_rom[  775] = 'h00000cc8; 	    data_ram[  775] = 'h00000307; 
    addr_rom[  776] = 'h00000e30; 	    data_ram[  776] = 'h00000308; 
    addr_rom[  777] = 'h00000ea8; 	    data_ram[  777] = 'h00000309; 
    addr_rom[  778] = 'h00000680; 	    data_ram[  778] = 'h0000030a; 
    addr_rom[  779] = 'h00000014; 	    data_ram[  779] = 'h0000030b; 
    addr_rom[  780] = 'h00000478; 	    data_ram[  780] = 'h0000030c; 
    addr_rom[  781] = 'h00000f28; 	    data_ram[  781] = 'h0000030d; 
    addr_rom[  782] = 'h00000698; 	    data_ram[  782] = 'h0000030e; 
    addr_rom[  783] = 'h00000104; 	    data_ram[  783] = 'h0000030f; 
    addr_rom[  784] = 'h0000040c; 	    data_ram[  784] = 'h00000310; 
    addr_rom[  785] = 'h0000081c; 	    data_ram[  785] = 'h00000311; 
    addr_rom[  786] = 'h000004f8; 	    data_ram[  786] = 'h00000312; 
    addr_rom[  787] = 'h00000f78; 	    data_ram[  787] = 'h00000313; 
    addr_rom[  788] = 'h00000e1c; 	    data_ram[  788] = 'h00000314; 
    addr_rom[  789] = 'h00000158; 	    data_ram[  789] = 'h00000315; 
    addr_rom[  790] = 'h000007e8; 	    data_ram[  790] = 'h00000316; 
    addr_rom[  791] = 'h00000b38; 	    data_ram[  791] = 'h00000317; 
    addr_rom[  792] = 'h00000d20; 	    data_ram[  792] = 'h00000318; 
    addr_rom[  793] = 'h00000dcc; 	    data_ram[  793] = 'h00000319; 
    addr_rom[  794] = 'h000001fc; 	    data_ram[  794] = 'h0000031a; 
    addr_rom[  795] = 'h0000045c; 	    data_ram[  795] = 'h0000031b; 
    addr_rom[  796] = 'h00000994; 	    data_ram[  796] = 'h0000031c; 
    addr_rom[  797] = 'h00000a9c; 	    data_ram[  797] = 'h0000031d; 
    addr_rom[  798] = 'h00000a08; 	    data_ram[  798] = 'h0000031e; 
    addr_rom[  799] = 'h00000990; 	    data_ram[  799] = 'h0000031f; 
    addr_rom[  800] = 'h00000f10; 	    data_ram[  800] = 'h00000320; 
    addr_rom[  801] = 'h00000588; 	    data_ram[  801] = 'h00000321; 
    addr_rom[  802] = 'h00000ec0; 	    data_ram[  802] = 'h00000322; 
    addr_rom[  803] = 'h00000090; 	    data_ram[  803] = 'h00000323; 
    addr_rom[  804] = 'h0000060c; 	    data_ram[  804] = 'h00000324; 
    addr_rom[  805] = 'h000005ac; 	    data_ram[  805] = 'h00000325; 
    addr_rom[  806] = 'h000005d4; 	    data_ram[  806] = 'h00000326; 
    addr_rom[  807] = 'h00000294; 	    data_ram[  807] = 'h00000327; 
    addr_rom[  808] = 'h0000004c; 	    data_ram[  808] = 'h00000328; 
    addr_rom[  809] = 'h00000c88; 	    data_ram[  809] = 'h00000329; 
    addr_rom[  810] = 'h00000d30; 	    data_ram[  810] = 'h0000032a; 
    addr_rom[  811] = 'h0000085c; 	    data_ram[  811] = 'h0000032b; 
    addr_rom[  812] = 'h00000de4; 	    data_ram[  812] = 'h0000032c; 
    addr_rom[  813] = 'h00000910; 	    data_ram[  813] = 'h0000032d; 
    addr_rom[  814] = 'h000001a0; 	    data_ram[  814] = 'h0000032e; 
    addr_rom[  815] = 'h00000a0c; 	    data_ram[  815] = 'h0000032f; 
    addr_rom[  816] = 'h0000054c; 	    data_ram[  816] = 'h00000330; 
    addr_rom[  817] = 'h000004b8; 	    data_ram[  817] = 'h00000331; 
    addr_rom[  818] = 'h00000500; 	    data_ram[  818] = 'h00000332; 
    addr_rom[  819] = 'h00000a60; 	    data_ram[  819] = 'h00000333; 
    addr_rom[  820] = 'h00000e38; 	    data_ram[  820] = 'h00000334; 
    addr_rom[  821] = 'h000006fc; 	    data_ram[  821] = 'h00000335; 
    addr_rom[  822] = 'h00000d94; 	    data_ram[  822] = 'h00000336; 
    addr_rom[  823] = 'h000002e4; 	    data_ram[  823] = 'h00000337; 
    addr_rom[  824] = 'h00000904; 	    data_ram[  824] = 'h00000338; 
    addr_rom[  825] = 'h0000093c; 	    data_ram[  825] = 'h00000339; 
    addr_rom[  826] = 'h000004a4; 	    data_ram[  826] = 'h0000033a; 
    addr_rom[  827] = 'h000005d8; 	    data_ram[  827] = 'h0000033b; 
    addr_rom[  828] = 'h000003ec; 	    data_ram[  828] = 'h0000033c; 
    addr_rom[  829] = 'h00000d04; 	    data_ram[  829] = 'h0000033d; 
    addr_rom[  830] = 'h00000e80; 	    data_ram[  830] = 'h0000033e; 
    addr_rom[  831] = 'h00000d24; 	    data_ram[  831] = 'h0000033f; 
    addr_rom[  832] = 'h00000be4; 	    data_ram[  832] = 'h00000340; 
    addr_rom[  833] = 'h00000070; 	    data_ram[  833] = 'h00000341; 
    addr_rom[  834] = 'h000007d8; 	    data_ram[  834] = 'h00000342; 
    addr_rom[  835] = 'h00000a74; 	    data_ram[  835] = 'h00000343; 
    addr_rom[  836] = 'h000006cc; 	    data_ram[  836] = 'h00000344; 
    addr_rom[  837] = 'h000002b4; 	    data_ram[  837] = 'h00000345; 
    addr_rom[  838] = 'h000003f0; 	    data_ram[  838] = 'h00000346; 
    addr_rom[  839] = 'h000001e8; 	    data_ram[  839] = 'h00000347; 
    addr_rom[  840] = 'h000004c0; 	    data_ram[  840] = 'h00000348; 
    addr_rom[  841] = 'h00000ab0; 	    data_ram[  841] = 'h00000349; 
    addr_rom[  842] = 'h00000fcc; 	    data_ram[  842] = 'h0000034a; 
    addr_rom[  843] = 'h00000cec; 	    data_ram[  843] = 'h0000034b; 
    addr_rom[  844] = 'h00000b54; 	    data_ram[  844] = 'h0000034c; 
    addr_rom[  845] = 'h000009f8; 	    data_ram[  845] = 'h0000034d; 
    addr_rom[  846] = 'h00000acc; 	    data_ram[  846] = 'h0000034e; 
    addr_rom[  847] = 'h000003c8; 	    data_ram[  847] = 'h0000034f; 
    addr_rom[  848] = 'h000000c4; 	    data_ram[  848] = 'h00000350; 
    addr_rom[  849] = 'h00000cf4; 	    data_ram[  849] = 'h00000351; 
    addr_rom[  850] = 'h000004c4; 	    data_ram[  850] = 'h00000352; 
    addr_rom[  851] = 'h00000ba8; 	    data_ram[  851] = 'h00000353; 
    addr_rom[  852] = 'h000006a0; 	    data_ram[  852] = 'h00000354; 
    addr_rom[  853] = 'h00000a1c; 	    data_ram[  853] = 'h00000355; 
    addr_rom[  854] = 'h00000f54; 	    data_ram[  854] = 'h00000356; 
    addr_rom[  855] = 'h00000ce8; 	    data_ram[  855] = 'h00000357; 
    addr_rom[  856] = 'h00000788; 	    data_ram[  856] = 'h00000358; 
    addr_rom[  857] = 'h00000730; 	    data_ram[  857] = 'h00000359; 
    addr_rom[  858] = 'h00000a00; 	    data_ram[  858] = 'h0000035a; 
    addr_rom[  859] = 'h00000bd8; 	    data_ram[  859] = 'h0000035b; 
    addr_rom[  860] = 'h00000280; 	    data_ram[  860] = 'h0000035c; 
    addr_rom[  861] = 'h00000240; 	    data_ram[  861] = 'h0000035d; 
    addr_rom[  862] = 'h00000d4c; 	    data_ram[  862] = 'h0000035e; 
    addr_rom[  863] = 'h00000980; 	    data_ram[  863] = 'h0000035f; 
    addr_rom[  864] = 'h00000f4c; 	    data_ram[  864] = 'h00000360; 
    addr_rom[  865] = 'h00000890; 	    data_ram[  865] = 'h00000361; 
    addr_rom[  866] = 'h000001d0; 	    data_ram[  866] = 'h00000362; 
    addr_rom[  867] = 'h00000a28; 	    data_ram[  867] = 'h00000363; 
    addr_rom[  868] = 'h00000bac; 	    data_ram[  868] = 'h00000364; 
    addr_rom[  869] = 'h00000c80; 	    data_ram[  869] = 'h00000365; 
    addr_rom[  870] = 'h0000007c; 	    data_ram[  870] = 'h00000366; 
    addr_rom[  871] = 'h00000250; 	    data_ram[  871] = 'h00000367; 
    addr_rom[  872] = 'h000008ac; 	    data_ram[  872] = 'h00000368; 
    addr_rom[  873] = 'h00000308; 	    data_ram[  873] = 'h00000369; 
    addr_rom[  874] = 'h000008a0; 	    data_ram[  874] = 'h0000036a; 
    addr_rom[  875] = 'h00000508; 	    data_ram[  875] = 'h0000036b; 
    addr_rom[  876] = 'h0000010c; 	    data_ram[  876] = 'h0000036c; 
    addr_rom[  877] = 'h00000ab8; 	    data_ram[  877] = 'h0000036d; 
    addr_rom[  878] = 'h000002a4; 	    data_ram[  878] = 'h0000036e; 
    addr_rom[  879] = 'h000002e8; 	    data_ram[  879] = 'h0000036f; 
    addr_rom[  880] = 'h00000704; 	    data_ram[  880] = 'h00000370; 
    addr_rom[  881] = 'h00000f68; 	    data_ram[  881] = 'h00000371; 
    addr_rom[  882] = 'h00000f3c; 	    data_ram[  882] = 'h00000372; 
    addr_rom[  883] = 'h00000184; 	    data_ram[  883] = 'h00000373; 
    addr_rom[  884] = 'h0000020c; 	    data_ram[  884] = 'h00000374; 
    addr_rom[  885] = 'h00000b2c; 	    data_ram[  885] = 'h00000375; 
    addr_rom[  886] = 'h000005f0; 	    data_ram[  886] = 'h00000376; 
    addr_rom[  887] = 'h00000afc; 	    data_ram[  887] = 'h00000377; 
    addr_rom[  888] = 'h00000fe4; 	    data_ram[  888] = 'h00000378; 
    addr_rom[  889] = 'h00000388; 	    data_ram[  889] = 'h00000379; 
    addr_rom[  890] = 'h00000124; 	    data_ram[  890] = 'h0000037a; 
    addr_rom[  891] = 'h000003f8; 	    data_ram[  891] = 'h0000037b; 
    addr_rom[  892] = 'h000004bc; 	    data_ram[  892] = 'h0000037c; 
    addr_rom[  893] = 'h0000038c; 	    data_ram[  893] = 'h0000037d; 
    addr_rom[  894] = 'h00000f14; 	    data_ram[  894] = 'h0000037e; 
    addr_rom[  895] = 'h00000e54; 	    data_ram[  895] = 'h0000037f; 
    addr_rom[  896] = 'h000006ec; 	    data_ram[  896] = 'h00000380; 
    addr_rom[  897] = 'h00000f04; 	    data_ram[  897] = 'h00000381; 
    addr_rom[  898] = 'h000002c4; 	    data_ram[  898] = 'h00000382; 
    addr_rom[  899] = 'h000004f0; 	    data_ram[  899] = 'h00000383; 
    addr_rom[  900] = 'h00000bd4; 	    data_ram[  900] = 'h00000384; 
    addr_rom[  901] = 'h00000dd8; 	    data_ram[  901] = 'h00000385; 
    addr_rom[  902] = 'h00000624; 	    data_ram[  902] = 'h00000386; 
    addr_rom[  903] = 'h00000760; 	    data_ram[  903] = 'h00000387; 
    addr_rom[  904] = 'h00000668; 	    data_ram[  904] = 'h00000388; 
    addr_rom[  905] = 'h00000b28; 	    data_ram[  905] = 'h00000389; 
    addr_rom[  906] = 'h00000b7c; 	    data_ram[  906] = 'h0000038a; 
    addr_rom[  907] = 'h00000524; 	    data_ram[  907] = 'h0000038b; 
    addr_rom[  908] = 'h00000d18; 	    data_ram[  908] = 'h0000038c; 
    addr_rom[  909] = 'h00000d84; 	    data_ram[  909] = 'h0000038d; 
    addr_rom[  910] = 'h00000b40; 	    data_ram[  910] = 'h0000038e; 
    addr_rom[  911] = 'h00000a5c; 	    data_ram[  911] = 'h0000038f; 
    addr_rom[  912] = 'h00000194; 	    data_ram[  912] = 'h00000390; 
    addr_rom[  913] = 'h00000354; 	    data_ram[  913] = 'h00000391; 
    addr_rom[  914] = 'h000009a8; 	    data_ram[  914] = 'h00000392; 
    addr_rom[  915] = 'h00000f7c; 	    data_ram[  915] = 'h00000393; 
    addr_rom[  916] = 'h00000128; 	    data_ram[  916] = 'h00000394; 
    addr_rom[  917] = 'h00000594; 	    data_ram[  917] = 'h00000395; 
    addr_rom[  918] = 'h00000dbc; 	    data_ram[  918] = 'h00000396; 
    addr_rom[  919] = 'h0000049c; 	    data_ram[  919] = 'h00000397; 
    addr_rom[  920] = 'h00000d74; 	    data_ram[  920] = 'h00000398; 
    addr_rom[  921] = 'h00000fec; 	    data_ram[  921] = 'h00000399; 
    addr_rom[  922] = 'h00000000; 	    data_ram[  922] = 'h0000039a; 
    addr_rom[  923] = 'h0000089c; 	    data_ram[  923] = 'h0000039b; 
    addr_rom[  924] = 'h00000aac; 	    data_ram[  924] = 'h0000039c; 
    addr_rom[  925] = 'h00000d00; 	    data_ram[  925] = 'h0000039d; 
    addr_rom[  926] = 'h00000b68; 	    data_ram[  926] = 'h0000039e; 
    addr_rom[  927] = 'h00000960; 	    data_ram[  927] = 'h0000039f; 
    addr_rom[  928] = 'h00000790; 	    data_ram[  928] = 'h000003a0; 
    addr_rom[  929] = 'h00000d6c; 	    data_ram[  929] = 'h000003a1; 
    addr_rom[  930] = 'h0000073c; 	    data_ram[  930] = 'h000003a2; 
    addr_rom[  931] = 'h0000039c; 	    data_ram[  931] = 'h000003a3; 
    addr_rom[  932] = 'h00000b90; 	    data_ram[  932] = 'h000003a4; 
    addr_rom[  933] = 'h00000ae0; 	    data_ram[  933] = 'h000003a5; 
    addr_rom[  934] = 'h0000008c; 	    data_ram[  934] = 'h000003a6; 
    addr_rom[  935] = 'h00000440; 	    data_ram[  935] = 'h000003a7; 
    addr_rom[  936] = 'h00000cac; 	    data_ram[  936] = 'h000003a8; 
    addr_rom[  937] = 'h000002ec; 	    data_ram[  937] = 'h000003a9; 
    addr_rom[  938] = 'h00000f34; 	    data_ram[  938] = 'h000003aa; 
    addr_rom[  939] = 'h000007a8; 	    data_ram[  939] = 'h000003ab; 
    addr_rom[  940] = 'h00000bc8; 	    data_ram[  940] = 'h000003ac; 
    addr_rom[  941] = 'h00000d64; 	    data_ram[  941] = 'h000003ad; 
    addr_rom[  942] = 'h00000950; 	    data_ram[  942] = 'h000003ae; 
    addr_rom[  943] = 'h00000f58; 	    data_ram[  943] = 'h000003af; 
    addr_rom[  944] = 'h000007ec; 	    data_ram[  944] = 'h000003b0; 
    addr_rom[  945] = 'h000001f4; 	    data_ram[  945] = 'h000003b1; 
    addr_rom[  946] = 'h000006ac; 	    data_ram[  946] = 'h000003b2; 
    addr_rom[  947] = 'h00000944; 	    data_ram[  947] = 'h000003b3; 
    addr_rom[  948] = 'h00000740; 	    data_ram[  948] = 'h000003b4; 
    addr_rom[  949] = 'h00000718; 	    data_ram[  949] = 'h000003b5; 
    addr_rom[  950] = 'h00000304; 	    data_ram[  950] = 'h000003b6; 
    addr_rom[  951] = 'h00000e48; 	    data_ram[  951] = 'h000003b7; 
    addr_rom[  952] = 'h00000214; 	    data_ram[  952] = 'h000003b8; 
    addr_rom[  953] = 'h000009c4; 	    data_ram[  953] = 'h000003b9; 
    addr_rom[  954] = 'h00000e00; 	    data_ram[  954] = 'h000003ba; 
    addr_rom[  955] = 'h00000d7c; 	    data_ram[  955] = 'h000003bb; 
    addr_rom[  956] = 'h00000b94; 	    data_ram[  956] = 'h000003bc; 
    addr_rom[  957] = 'h0000028c; 	    data_ram[  957] = 'h000003bd; 
    addr_rom[  958] = 'h00000024; 	    data_ram[  958] = 'h000003be; 
    addr_rom[  959] = 'h00000270; 	    data_ram[  959] = 'h000003bf; 
    addr_rom[  960] = 'h0000068c; 	    data_ram[  960] = 'h000003c0; 
    addr_rom[  961] = 'h00000e94; 	    data_ram[  961] = 'h000003c1; 
    addr_rom[  962] = 'h00000bb4; 	    data_ram[  962] = 'h000003c2; 
    addr_rom[  963] = 'h00000094; 	    data_ram[  963] = 'h000003c3; 
    addr_rom[  964] = 'h000002f4; 	    data_ram[  964] = 'h000003c4; 
    addr_rom[  965] = 'h0000053c; 	    data_ram[  965] = 'h000003c5; 
    addr_rom[  966] = 'h00000eec; 	    data_ram[  966] = 'h000003c6; 
    addr_rom[  967] = 'h00000aa0; 	    data_ram[  967] = 'h000003c7; 
    addr_rom[  968] = 'h000007c0; 	    data_ram[  968] = 'h000003c8; 
    addr_rom[  969] = 'h00000148; 	    data_ram[  969] = 'h000003c9; 
    addr_rom[  970] = 'h00000da4; 	    data_ram[  970] = 'h000003ca; 
    addr_rom[  971] = 'h000008a8; 	    data_ram[  971] = 'h000003cb; 
    addr_rom[  972] = 'h00000424; 	    data_ram[  972] = 'h000003cc; 
    addr_rom[  973] = 'h00000ba0; 	    data_ram[  973] = 'h000003cd; 
    addr_rom[  974] = 'h00000a64; 	    data_ram[  974] = 'h000003ce; 
    addr_rom[  975] = 'h000002b0; 	    data_ram[  975] = 'h000003cf; 
    addr_rom[  976] = 'h0000061c; 	    data_ram[  976] = 'h000003d0; 
    addr_rom[  977] = 'h00000f2c; 	    data_ram[  977] = 'h000003d1; 
    addr_rom[  978] = 'h000008e0; 	    data_ram[  978] = 'h000003d2; 
    addr_rom[  979] = 'h00000434; 	    data_ram[  979] = 'h000003d3; 
    addr_rom[  980] = 'h00000ba4; 	    data_ram[  980] = 'h000003d4; 
    addr_rom[  981] = 'h00000820; 	    data_ram[  981] = 'h000003d5; 
    addr_rom[  982] = 'h000005e0; 	    data_ram[  982] = 'h000003d6; 
    addr_rom[  983] = 'h00000e2c; 	    data_ram[  983] = 'h000003d7; 
    addr_rom[  984] = 'h00000660; 	    data_ram[  984] = 'h000003d8; 
    addr_rom[  985] = 'h000000ec; 	    data_ram[  985] = 'h000003d9; 
    addr_rom[  986] = 'h00000648; 	    data_ram[  986] = 'h000003da; 
    addr_rom[  987] = 'h00000494; 	    data_ram[  987] = 'h000003db; 
    addr_rom[  988] = 'h00000278; 	    data_ram[  988] = 'h000003dc; 
    addr_rom[  989] = 'h00000804; 	    data_ram[  989] = 'h000003dd; 
    addr_rom[  990] = 'h00000930; 	    data_ram[  990] = 'h000003de; 
    addr_rom[  991] = 'h00000180; 	    data_ram[  991] = 'h000003df; 
    addr_rom[  992] = 'h000004a0; 	    data_ram[  992] = 'h000003e0; 
    addr_rom[  993] = 'h00000914; 	    data_ram[  993] = 'h000003e1; 
    addr_rom[  994] = 'h00000fb8; 	    data_ram[  994] = 'h000003e2; 
    addr_rom[  995] = 'h00000784; 	    data_ram[  995] = 'h000003e3; 
    addr_rom[  996] = 'h000006d4; 	    data_ram[  996] = 'h000003e4; 
    addr_rom[  997] = 'h000009d8; 	    data_ram[  997] = 'h000003e5; 
    addr_rom[  998] = 'h00000bfc; 	    data_ram[  998] = 'h000003e6; 
    addr_rom[  999] = 'h000000a0; 	    data_ram[  999] = 'h000003e7; 
    addr_rom[ 1000] = 'h000001c8; 	    data_ram[ 1000] = 'h000003e8; 
    addr_rom[ 1001] = 'h00000e10; 	    data_ram[ 1001] = 'h000003e9; 
    addr_rom[ 1002] = 'h00000640; 	    data_ram[ 1002] = 'h000003ea; 
    addr_rom[ 1003] = 'h00000870; 	    data_ram[ 1003] = 'h000003eb; 
    addr_rom[ 1004] = 'h00000a8c; 	    data_ram[ 1004] = 'h000003ec; 
    addr_rom[ 1005] = 'h00000324; 	    data_ram[ 1005] = 'h000003ed; 
    addr_rom[ 1006] = 'h000009f0; 	    data_ram[ 1006] = 'h000003ee; 
    addr_rom[ 1007] = 'h00000750; 	    data_ram[ 1007] = 'h000003ef; 
    addr_rom[ 1008] = 'h000001c4; 	    data_ram[ 1008] = 'h000003f0; 
    addr_rom[ 1009] = 'h00000048; 	    data_ram[ 1009] = 'h000003f1; 
    addr_rom[ 1010] = 'h000000ac; 	    data_ram[ 1010] = 'h000003f2; 
    addr_rom[ 1011] = 'h00000900; 	    data_ram[ 1011] = 'h000003f3; 
    addr_rom[ 1012] = 'h0000095c; 	    data_ram[ 1012] = 'h000003f4; 
    addr_rom[ 1013] = 'h00000414; 	    data_ram[ 1013] = 'h000003f5; 
    addr_rom[ 1014] = 'h00000774; 	    data_ram[ 1014] = 'h000003f6; 
    addr_rom[ 1015] = 'h00000cf0; 	    data_ram[ 1015] = 'h000003f7; 
    addr_rom[ 1016] = 'h00000040; 	    data_ram[ 1016] = 'h000003f8; 
    addr_rom[ 1017] = 'h00000df8; 	    data_ram[ 1017] = 'h000003f9; 
    addr_rom[ 1018] = 'h00000e50; 	    data_ram[ 1018] = 'h000003fa; 
    addr_rom[ 1019] = 'h0000032c; 	    data_ram[ 1019] = 'h000003fb; 
    addr_rom[ 1020] = 'h00000d54; 	    data_ram[ 1020] = 'h000003fc; 
    addr_rom[ 1021] = 'h00000574; 	    data_ram[ 1021] = 'h000003fd; 
    addr_rom[ 1022] = 'h00000a3c; 	    data_ram[ 1022] = 'h000003fe; 
    addr_rom[ 1023] = 'h000001bc; 	    data_ram[ 1023] = 'h000003ff; 

end
// for icache 
wire            i_rvalid;
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
reg             i_error_reg;
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
// dcache_debug
reg             d_rvalid_ff;
reg     [31:0]  d_addr_ff;
reg             d_error_reg;
reg             d_pass_reg;
wire    [31:0]  d_correct_data;

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

assign i_raddr = addr_rom[i_test_index];
assign i_correct_data = data_ram[i_raddr_ff >> 2];
assign i_rvalid = 1'b1;
// simulate IF1-IF2 register i_rvalid_ff && i_raddr_ff
always @(posedge clk) begin
    if(!rstn) begin
        i_rvalid_ff <= 0;
        i_raddr_ff <= 0;
    end
    else if(!(i_rvalid_ff && !i_rready))begin
        i_rvalid_ff <= i_rvalid;
        i_raddr_ff <= i_raddr;
    end
end
// update i_test_index
always @(posedge clk) begin
    if(!rstn) begin
        i_test_index <= 0;
        i_pass_reg <= 0;
    end
    else if (i_test_index >= (TOTAL_WORD_NUM / 2)) begin
        i_test_index <= (TOTAL_WORD_NUM / 2);
        i_pass_reg <= 1;
    end
    else if(!(i_rvalid_ff && !i_rready) && !i_error_reg) begin
        i_test_index <= i_test_index + 1;
    end
end
// update i_error 
always @(posedge clk) begin
    if(!rstn) begin
        i_error_reg <= 0;
    end
    else if(i_error_reg) begin
        i_error_reg <= 1;
    end
    else if(i_rvalid_ff && i_rready) begin
        i_error_reg <= !(i_rdata  == i_correct_data);
    end
end

assign d_addr = addr_rom[d_test_index];
assign d_correct_data = data_ram[d_addr_ff >> 2];
assign d_rvalid = 1'b1;
assign d_wvalid = 1'b0;
assign d_wdata = 0;
assign d_wstrb = 0;
// simulate EX-MEM register
always @(posedge clk) begin
    if(!rstn) begin
        d_rvalid_ff <= 0;
        d_addr_ff <= 0;
    end
    else if(!(d_rvalid_ff && !d_rready))begin
        d_rvalid_ff <= d_rvalid;
        d_addr_ff <= d_addr;
    end
end
// update d_test_index
always @(posedge clk) begin
    if(!rstn) begin
        d_test_index <= TOTAL_WORD_NUM / 2;
        d_pass_reg <= 0;
    end
    else if (d_test_index >= (TOTAL_WORD_NUM-1)) begin
        d_test_index <= (TOTAL_WORD_NUM-1);
        d_pass_reg <= 1;
    end
    else if(!(d_rvalid_ff && !d_rready) && !d_error_reg) begin
        d_test_index <= d_test_index + 1;
    end
end
// update d_error 
always @(posedge clk) begin
    if(!rstn) begin
        d_error_reg <= 0;
    end
    else if(d_error_reg) begin
        d_error_reg <= 1;
    end
    else if(d_rvalid_ff && d_rready) begin
        d_error_reg <= !(d_rdata  == d_correct_data);
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

axi_arbiter axi_arbiter_dut (
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

