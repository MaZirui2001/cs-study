# Lab 2 RV32I Core设计

## 实验目的

+ 掌握五级流水线CPU的设计方法
+ 熟悉RISC-V的指令集和数据通路，了解其设计背后的思想
+ 进一步提高使用verilog编码和调试的能力，学会使用仿真（Simulation）调试

## 实验概要

本实验需要你基于助教给出的RV32I Core的Verilog代码框架，**补全缺失的模块**，以实现具有五级流水功能的RISC-V CPU，并通过给定的测试样例。代码框架已经提供了大部分的代码，你只需要完成部分数据通路、控制单元等模块的设计即可。

实验安排与说明：

+ 本次实验为**3周**，总共分**为3个阶段**进行验收，每周完成1个阶段。阶段2的测试如果能通过，默认阶段1已完成。阶段3的CSR指令需另行测试。如果不能完成整个实验，最后按完成阶段给分。实验结束后一周内需要提交实验报告
+ 本次实验验收只要求仿真（Simulation）结果正确，不要求综合和烧板子
+ 实验工具：Vivado；实验方式：Vivado 自带的波形仿真

## 实验内容

实验分为3个阶段进行，每个阶段依次单独验收。

### 阶段1验收要求

+ 自己手写合适的测试用汇编代码，通过提供的工具生成.inst 和.data 文件，用于初始化指令和数据的Block Memory，或者直接手写二进制测试代码
+ 测试用的指令流中需要包含的指令包括 SLLI、SRLI、SRAI、ADD、SUB、SLL、SLT、SLTU、XOR、SRL、SRA、OR、AND、ADDI、SLTI、SLTIU、XORI、ORI、ANDI、LUI、AUIPC
+ 测试例（汇编和对应的.inst .data）可以用其他同学提供的，但是需要自己知道对应的指令逻辑，需要能清楚的向助教表达这个测试例如何验证 CPU 功能正确，即正确运行后寄存器值应该是多少
+ CPU 执行后，各寄存器值符合预期
+ 此时**不需要处理数据相关**。可以令 Harzard 模块始终输出 stall、flush 恒为 0，forward恒为不转发，每两条指令之间间隔四条空指令  

### 阶段2验收要求

+ 我们提供了 1testAll.data、1testAll.inst、2testAll.data、2testAll.data、3testAll.data、3testAll.inst 三个测试样例的.inst 和.data 文件，用于初始化指令和数据的 Block Memory。
+ 对于任意一个测试样例，CPU 开始执行后 3 号寄存器的值会从 2 一直累增，该数字正在进行第多少项测试，执行结束后 3 号寄存器值变为 1
+ CPU 执行后，各寄存器值符合预期。阶段2二的测试如果能通过，默认阶段1已完成。
+ 测试用的指令流中，除了阶段一的测试指令，还需要包含的指令包括 JALR、LB、LH、LW、LBU、LHU、SB、SH、SW、BEQ、BNE、BLT、BLTU、BGE、BGEU、JAL
+ 此时**需要处理数据相关**，实现 Harzard 模块内部逻辑

### 阶段3验收要求

+ 自己手写合适的测试用汇编代码，通过提供的工具生成.inst 和.data 文件，用于初始化指令和数据的Block Memory。或者使用Simulation目录下提供的CSRtest文件，执行结束后 3 号寄存器值变为 1。
+ 在我们给的代码框架上添加你设计好的 CSR 数据通路（前两个阶段不用管，部分CSR数据通路已给出，需要补全模块内部代码，当然你也可以重新设计自己的数据通路）
+ 测试用的指令流中需要包含的指令包括: CSRRW、CSRRS、CSRRC、CSRRWI、CSRRSI、CSRRCI
+ CPU 执行后，各寄存器值符合预期
+ 阶段二已经处理好数据相关，这里不再特别考察。 

## 实验参考

### 代码框架

+ 三个目录Simulation、SourceCode、TestDataTools分别包含了仿真文件及测试数据、源代码、测试数据生成工具
+ 由于Vivado的编辑器存在中文编码问题，推荐在VSCode环境下开发代码。
+ 源代码均有注释，说明了模块功能、接口作用、是否需要补全，请参考注释完成RV32I Core
+ 阶段二的测试可以参考General Register的3号寄存器，它的值代表执行到第几个test，全部测试通过，3号寄存器的值最终变为1

### 使用方式

+ 以Vivado开发为例，新建工程，将[SourceCode/PART-code](SourceCode/PART-code)的代码导入，Simulation文件夹下的testBench.v作为仿真文件导入，并将testBench.v设置为Simulation的Top文件。之后直接进行仿真即可，会自动将.inst和.data的文件加载进Instruction Cache和Data Cache，并开始执行。
+ testBench.v定义的四个宏：`DataCacheContentLoadPath, InstCacheContentLoadPath, DataCacheContentSavePath, InstCacheContentSavePath `，分别是Data Cache、Instruction Cache的写入文件路径，及Data Cache、Instruction Cache导出内容路径，请根据需要自行修改。
+ TestDataTools的工具使用说明，请参考文件夹的[Readme](TestDataTools/README.md)文档

## 实验报告

+ 总结自己在三个阶段所做的工作
+ 总结自己在实验中遇到的问题，实验收获，写代码和写报告花费的时间
+ 提出改进实验的意见

## 评分标准

+ 代码部分占80%，具体分为：
  + 完成阶段1可获得30%
  + 完成阶段2可获得30%
  + 完成阶段3可获得20%
+ 报告部分占20%