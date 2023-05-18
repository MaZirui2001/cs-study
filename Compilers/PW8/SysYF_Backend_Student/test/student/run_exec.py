#!/usr/bin/env python3
# 这是一个用于ARM评测的编译ARM汇编代码并实际执行的脚本框架，仅供参考，请根据需求自行修改；尤其是实际汇编、链接过程，
# 该脚本运行在树莓派平台上
import subprocess
import os

def dict_to_csv(lens: list, d: dict, filename = "./diff.tab"):
    with open(filename, mode="w") as file:
        keys = list(d.keys())
        for l, k in zip(lens, keys):
            f = "{" + f"0:{l}" + "}"
            print(f.format(k), file=file, end="")
        print(file=file)

        index = d["filename"]
        index = len(index)
        index = range(index)
        index = list(index)
        index.sort(key=lambda x: d["filename"][x])

        for i in index:
            for l, k in zip(lens, keys):
                f = "{" + f"0:{l}" + "}"
                print(f.format(str(d[k][i])), file=file, end="")
            print(file=file)


def dict_to_stdout(lens: list, d: dict):
    keys = list(d.keys())
    for l, k in zip(lens, keys):
        f = "{" + f"0:{l}" + "}"
        print(f.format(k), end="")
    print()

    index = d["filename"]
    index = len(index)
    index = range(index)
    index = list(index)
    index.sort(key=lambda x: d["filename"][x])

    for i in index:
        for l, k in zip(lens, keys):
            f = "{" + f"0:{l}" + "}"
            print(f.format(str(d[k][i])), end="")
        print()


class Func:
    def __init__(self):
        self.inst = []
        pass

    def set_name(self, name: str):
        self.name = name

    def set_time(self, time: int):
        self.time = time

    def add_inst(self, inst: str):
        self.inst.append(inst)

    def str_count(self):
        count = 0
        for i in self.inst:
            # save parttern for str
            if "    str r" in i:
                count += 1
        return count

def read_last_line(filepath):
    with open(filepath) as file:
        txt = file.readlines()
        lastline = txt[-1]
    return lastline

def read_file(filepath):
    txt = ""
    with open(filepath) as file:
        while True:
            line = file.readline()
            if line:
                txt += line
            else:
                break
    return txt


def parse_file(filepath):
    txt = read_file(filepath)
    txts = txt.split("@")
    funcs = []
    for txt in txts:
        if not txt.strip():
            continue
        func = Func()
        lines = txt.split("\n")
        func.set_name(lines[0][:lines[0].find(":")])
        func.set_time(int(lines[1][lines[1].find(":") + 2:]))
        for line in lines[2:]:
            func.add_inst(line)
        funcs.append(func)
    return funcs


def parse(baseline, optimized):
    bfuncs: list[Func] = parse_file(baseline)
    ofuncs: list[Func] = parse_file(optimized)

    bstr_count = 0
    ostr_count = 0
    times = ""
    for b, o in zip(bfuncs, ofuncs):
        bstr_count += b.str_count()
        ostr_count += o.str_count()
        if b.time != o.time:
            times += f"{b.name}: {b.time - o.time} "

    return bstr_count - ostr_count, times
def compare_result(result_file, standard_file):
    with open(standard_file) as standard:
        with open(result_file) as result:
            txt = standard.readlines()
            for line in txt:
                if line == "\n": 
                    break
                else:
                    if result.readline() != line :
                        print(result_file, ": result not matches!")
                        return False
    return True





if __name__ == '__main__':
    # 已有优化得到的汇编代码的路径列表
    baseline_asm_list = []
    # baseline汇编对应的可执行程序路径列表
    baseline_exe_list = []
    # 加上你的优化得到的汇编代码的路径列表
    optimized_asm_list = []
    # 优化后汇编对应的可执行程序路径列表
    optimized_exe_list = []

    # 使用gcc编译上述所有汇编程序，得到可执行程序, 参照格式为 'gcc -march=armv7-a -g sylib.c {汇编程序路径} -o {输出可执行程序路径}'
    if not os.path.exists("./baseline_exe"):
        os.mkdir("./baseline_exe")
    if not os.path.exists("./optimized_exe"):
        os.mkdir("./optimized_exe")
    if not os.path.exists("./baseline_output"):
        os.mkdir("./baseline_output")
    if not os.path.exists("./optimized_output"):
        os.mkdir("./optimized_output")

    for file in os.listdir("./baseline_asm"):
        if file.endswith(".s"):
            baseline_asm_list.append(file)
            filename = file.split('.')
            baseline_exe_list.append(filename[0])
    for file in os.listdir("./optimized_asm"):
        if file.endswith(".s"):
            optimized_asm_list.append(file)
            filename = file.split('.')
            optimized_exe_list.append(filename[0])

    log_compare = {
        "filename": [],
        "mem_access_diff": [],
        "baseline_runtime": [],
        "optimized_runtime": [],
        "stack_time_shorter": []
    }

    lens_1 = [24, 20, 20, 20, 64]
    # lens_1 = [24, 20, 64]

    baseline_exe_list.sort()
    baseline_asm_list.sort()
    optimized_exe_list.sort()
    optimized_asm_list.sort()
    for baseline_exe in baseline_exe_list:
        name = os.path.splitext(baseline_exe)[0]
        baseline_path = os.path.join("./baseline_report", name + ".txt")
        optimized_path = os.path.join("./optimized_report", name + ".txt")
        str_count, time = parse(baseline_path, optimized_path)
        log_compare["filename"].append(name)
        log_compare["mem_access_diff"].append(str_count)
        log_compare["stack_time_shorter"].append(time)
    
    # dict_to_stdout(lens_1, log_compare)
    # exit()
    print("--------------------------compiling--------------------------")
    print("compiling asm to exe...")
    # 注意这里可能用到输入输出运行时文件，请放在该文件夹里
    gcc_compile_cmd = 'gcc -march=armv7-a -g sylib.c {} -o {}'

    for asm_file, exe_file in zip(baseline_asm_list, baseline_exe_list):
        code_path = os.path.join("./baseline_asm", asm_file)
        exe_path = os.path.join("./baseline_exe", exe_file)
        os.system(gcc_compile_cmd.format(code_path, exe_path))

    for asm_file, exe_file in zip(optimized_asm_list, optimized_exe_list):
        code_path = os.path.join("./optimized_asm", asm_file)
        exe_path = os.path.join("./optimized_exe", exe_file)
        os.system(gcc_compile_cmd.format(code_path, exe_path))
    print("compiling finish!")
    print("---------------------------running---------------------------")
    # 执行可执行程序，参照格式为 'cat  {输入文件名} | {可执行程序} > {输出文件路径}'
    # 注意所有的输入输出样例也一定要放在该目录下
    exe_cmd = 'cat {} | {} > {}'

    lens_2 = [24, 20, 16]

    log_baseline = {
        "filename": [],
        "return_value": [],
        "run_time": []
    }

    log_optimized = {
        "filename": [],
        "return_value": [],
        "run_time": []
    }

    for baseline_exe in baseline_exe_list:
        input_file = baseline_exe.split("_baseline")
        input_path = os.path.join("./input", input_file[0] + ".in")
        baseline_output_path = os.path.join("./baseline_output", baseline_exe + ".out")
        
        baseline_exe_path = os.path.join("./baseline_exe", baseline_exe)
        log_baseline["filename"].append(baseline_exe)
        result = subprocess.run(
            exe_cmd.format(input_path, baseline_exe_path, baseline_output_path),
            shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf-8'
        )
        log_baseline["return_value"].append(result.returncode)

    for optimized_exe in optimized_exe_list:
        input_file = optimized_exe.split("_optimized")
        input_path = os.path.join("./input", input_file[0] + ".in")
        optimized_output_path = os.path.join("./optimized_output", optimized_exe + ".out")
        optimized_exe_path = os.path.join("./optimized_exe", optimized_exe)
        log_optimized["filename"].append(optimized_exe)
        result = subprocess.run(
            exe_cmd.format(input_path, optimized_exe_path, optimized_output_path),
            shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf-8'
        )
        log_optimized["return_value"].append(result.returncode)




    for baseline_exe in baseline_exe_list:
        input_file = baseline_exe.split("_baseline")
        standard_path = os.path.join("./standard_result" , input_file[0] + '.out')
        baseline_output_path = os.path.join("./baseline_output", baseline_exe + ".out")
        txt = read_last_line(baseline_output_path)
        log_baseline['run_time'].append(txt)
        log_compare["baseline_runtime"].append(txt)
        f = "{" + f"0:{35}" + "}"
        print("running", f.format(baseline_exe + "_optimized..."), end = " ")
        if compare_result(baseline_output_path, standard_path):
            print('result matches')
            
    for optimized_exe in optimized_exe_list:
        input_file = optimized_exe.split("_optimized")
        standard_path = os.path.join("./standard_result" , input_file[0] + '.out')
        optimized_output_path = os.path.join("./optimized_output", optimized_exe + ".out")
        txt = read_last_line(optimized_output_path)
        log_optimized["run_time"].append(txt)
        log_compare["optimized_runtime"].append(txt)
        f = "{" + f"0:{35}" + "}"
        print("running", f.format(optimized_exe + "_optimized..."), end = " ")
        if compare_result(optimized_output_path, standard_path):
            print('result matches')

    dict_to_csv(lens_2, log_baseline, "./baseline_log.tab")
    dict_to_csv(lens_2, log_optimized, "./optimized_log.tab")
    print("-----------------------------------------------diffent table-----------------------------------------------")
    dict_to_stdout(lens_1, log_compare)
    dict_to_csv(lens_1, log_compare)
    # 解析你的输出结果，输出优化前后的对比效果
    # parse()
