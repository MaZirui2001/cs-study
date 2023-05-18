#!/usr/bin/env python3
# 这是一个用于ARM评测的生成ARM汇编代码的脚本框架，仅供参考，请根据需求自行修改
# 该脚本运行在希冀评测平台上
import os

levels = ["Easy", "Medium", "Hard"]

if __name__ == '__main__':
    # 通过已有优化，编译程序得到汇编代码的命令，格式为 './compiler {编译选项} {输入程序文件路径} -o {输出汇编文件路径}'
    baseline_asm_gen_cmd = '../../build/compiler -S {} -o {} > {}'
    # 加上你的优化，编译程序得到汇编代码的命令，格式为 './compiler {编译选项} {输入程序文件路径} -o {输出汇编文件路径}'
    optimized_asm_gen_cmd = '../../build/compiler -S -O2 {} -o {} > {}'
    if not os.path.exists("./baseline_asm"):
        os.mkdir("./baseline_asm")
    if not os.path.exists("./optimized_asm"):
        os.mkdir("./optimized_asm")

    if not os.path.exists("./baseline_report"):
        os.mkdir("./baseline_report")

    if not os.path.exists("./optimized_report"):
        os.mkdir("./optimized_report")
    for level in levels:
        # 收集所有的`../test/student`目录下的测试样例
        source_file_list = []
        for file in os.listdir(os.path.join('../Test', level)):
            if file.endswith('.sy'):
                source_file_list.append(file)

        # 执行编译生成汇编
        # 注意生成的汇编代码一定要放在`../test/student`目录下，只有该目录将被打包发送到树莓派上进行可执行程序生成和实际运行
        # 这里我们分别放在`../test/student/baseline`和`../test/student/optimized`目录下
        names = []
        for file in source_file_list:
            name = os.path.splitext(file)[0]
            names.append(name)

            code_path = os.path.join('../Test', level, file)
            baseline_path = os.path.join('./baseline_asm', name + '.s')
            optimized_path = os.path.join('./optimized_asm', name + '.s')
            baseline_report_path = os.path.join("./baseline_report", name + '.txt')
            optimized_report_path = os.path.join("./optimized_report", name + '.txt')

            os.system(baseline_asm_gen_cmd.format(code_path, baseline_path, baseline_report_path))
            os.system(optimized_asm_gen_cmd.format(code_path, optimized_path, optimized_report_path))
