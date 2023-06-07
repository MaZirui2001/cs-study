import tkinter as tk
from tkinter import messagebox
import pymysql as sql
import common as common
from common import proj_type_map, proj_id2type

proj_check_items = {}
check_result_frame = []
detail_button_list = []


def generate_check_sql(check_items):
    # 获取输入的论文信息
    proj_name = check_items["proj_name"].get()
    proj_id = check_items["proj_id"].get()
    teacher_name = check_items["teacher_name"].get()
    teacher_id = check_items["teacher_id"].get()
    proj_source = check_items["proj_source"].get()
    # 一旦有一个条件不为空，就将其加入sql语句中
    sql_sentence = "select distinct project.id  from project \
        join undertake_project up on project.id = up.project_id \
        join teacher on up.teacher_id = teacher.id "
    t = ()
    if proj_name != "" or proj_id != "" or teacher_name != "" or teacher_id != "":
        sql_sentence += "where "
    if proj_name != "":
        sql_sentence += "project.name = %s"
        t = t + (proj_name,)
    if proj_id != "":
        # 检查proj_id是否为正整数
        try:
            proj_id = int(proj_id)
            if proj_id <= 0:
                raise ValueError
        except ValueError:
            messagebox.showerror("错误", "项目编号必须为正整数")
            return
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "project.id = %s"
        t = t + (proj_id,)
    if teacher_name != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "teacher.name = %s"
        t = t + (teacher_name,)
    if teacher_id != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "teacher.id = %s"
        t = t + (teacher_id,)
    if proj_source != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "project.source = %s"
        t = t + (proj_source,)

    sql_sentence += " order by project.id;"
    return sql_sentence, t


def check_proj():
    temp = generate_check_sql(proj_check_items)
    if temp is None:
        return
    sql_sentence, t = temp
    # 链接数据库
    try:
        db = sql.connect(
            host='localhost',
            port=3306,
            user='root',
            passwd='qweR12345',
            db='register_system',
            charset='utf8'
        )
    except sql.Error as e:
        print("连接数据库失败：" + str(e))
        exit(-1)
    # 使用cursor()方法获取操作游标
    cursor = db.cursor()
    # 使用execute方法执行SQL语句
    try:
        cursor.execute(sql_sentence, t)
    except sql.Error as e:
        db.close()
        print("查询失败：" + str(e))
        exit(-1)
    # 使用fetchall()方法获取所有数据
    data = cursor.fetchall()
    data_detail = []
    sql_sentence = "select project.name, project.id, project.source, project.type, project.expenditure, " \
                   "project.start_year, project.end_year, teacher.name, teacher.id, up.ranking, up.expenditure " \
                   "from project join undertake_project up on project.id = up.project_id " \
                   "join teacher on up.teacher_id = teacher.id where project.id = %s order by project.id;"
    for i in range(len(data)):
        # 对每一个项目编号，查询其详细信息
        try:
            cursor.execute(sql_sentence, data[i][0])
        except sql.Error as e:
            db.close()
            print("查询失败：" + str(e))
            exit(-1)
        # 使用fetchall()方法获取所有数据
        data_detail.append(cursor.fetchall())
    # 关闭数据库连接
    db.close()

    # 将查询结果存入全局变量中
    result = data_detail
    # 处理数据
    check_result = []
    for i in range(len(result)):
        check_result.append([])
        for j in range(7):
            check_result[i].append(result[i][0][j])
        check_result[i].append([])
        for j in range(len(result[i])):
            check_result[i][7].append([result[i][j][7], result[i][j][8], result[i][j][9], result[i][j][10]])

    # 按照排名对每一篇文章的作者进行排序
    for i in range(len(check_result)):
        check_result[i][7].sort(key=lambda x: x[2])

    # 显示简短信息
    check_result_simple = []
    for i in range(len(check_result)):
        check_result_simple.append(
            (check_result[i][0], check_result[i][7][0][0], check_result[i][2], check_result[i][3]))
    # create_check_result_frame(self, frame_paper_check)
    return check_result, check_result_simple


def create_check_result(self, frame_proj_check):
    check_result, check_result_simple = check_proj()
    print(check_result)
    create_check_result_frame(self, frame_proj_check, check_result_simple, check_result)


def create_detail_check_top(self, check_item):
    top = tk.Toplevel(self.root, width=400, height=400)
    top.title("项目详情")
    top.geometry("400x400")
    # top.resizable(False, False)
    # 30号字体靠左显示项目名称
    label_proj_name = tk.Label(top, text=check_item[0], font=("宋体", 20), anchor='w')
    label_proj_name.pack(side='top', anchor='w')

    # 15号字体靠左显示项目编号
    label_proj_id = tk.Label(top, text="项目编号：" + str(check_item[1]), font=("宋体", 10), anchor='w')
    label_proj_id.pack(side='top', anchor='w')

    # 15号字体靠左显示项目来源
    label_proj_source = tk.Label(top, text="项目来源：" + str(check_item[2]), font=("宋体", 10), anchor='w')
    label_proj_source.pack(side='top', anchor='w')

    # 10号字体靠左显示项目类型
    label_proj_type = tk.Label(top, text="项目类型：" + proj_id2type[check_item[3]], font=("宋体", 10),
                               anchor='w')
    label_proj_type.pack(side='top', anchor='w')

    # 10号字体靠左显示项目总经费
    label_proj_expend = tk.Label(top, text="项目经费：" + str(check_item[4]), font=("宋体", 10),
                                 anchor='w')
    label_proj_expend.pack(side='top', anchor='w')

    # 10号字体靠左显示开始时间
    label_proj_start = tk.Label(top, text="开始时间：" + str(check_item[5]), font=("宋体", 10),
                                anchor='w')
    label_proj_start.pack(side='top', anchor='w')

    # 10号字体靠左显示结束时间
    label_proj_start = tk.Label(top, text="结束时间：" + str(check_item[5]), font=("宋体", 10),
                                anchor='w')
    label_proj_start.pack(side='top', anchor='w')

    # 10号字体靠左显示所有项目员工
    for i in range(len(check_item[7])):
        string_info = "项目员工" + str(check_item[7][i][2]) + ": " + str(check_item[7][i][0])
        string_info += "（"
        string_info += "工号：" + str(check_item[7][i][1])
        string_info += "\t经费：" + str(check_item[7][i][3])
        string_info += "）"
        label_proj_author = tk.Label(top, text=string_info,
                                     font=("宋体", 10), anchor='w')
        label_proj_author.pack(side='top', anchor='w')


def create_check_result_frame(self, frame_proj_check, check_result_simple, check_result):
    for frame in check_result_frame:
        frame.destroy()
    check_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_proj_check_result = tk.Frame(frame_proj_check, width=800, height=50)
        frame_proj_check_result.pack(side='top', anchor='w')
        check_result_frame.append(frame_proj_check_result)
        # 显示四栏：项目名称、最高员工、开始时间、项目来源, 用Text组件, 每一个后面跟一个详情按钮
        # 项目名称
        common.create_text(frame_proj_check_result, str(check_result_simple[i][0]), 1, 0)
        # 最高员工
        common.create_text(frame_proj_check_result, str(check_result_simple[i][1]), 1, 1)
        # 项目类型
        common.create_text(frame_proj_check_result, str(check_result_simple[i][2]), 1, 2)
        # 项目来源
        common.create_text(frame_proj_check_result, str(check_result_simple[i][3]), 1, 3)
        # 详情按钮
        button_proj_detail = tk.Button(frame_proj_check_result, text="详情", width=10, height=1,
                                       command=lambda arg1=self, arg2=check_result[i]: create_detail_check_top(arg1,
                                                                                                               arg2))
        button_proj_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_proj_detail, i))


def create_frame_proj_check(self):
    canvas_proj_check = tk.Canvas(self.root, width=800, height=1200, scrollregion=(0, 0, 1200, 800))
    frame_proj_check = tk.Frame(canvas_proj_check, width=800, height=1200)
    self.frame_list["frame_proj_check"] = canvas_proj_check
    frame_proj_check.pack(side='top', anchor='n')
    canvas_proj_check.create_window(400, 0, anchor='n', window=frame_proj_check)

    # 创建滚动条
    common.create_scrollbar(canvas_proj_check)

    # 创建label
    tk.Label(frame_proj_check, text="项目信息查找", font=("宋体", 15)).pack(side='top', anchor='n')

    button_proj_check = tk.Button(frame_proj_check, text="查询", width=10, height=1)
    button_proj_check.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的项目信息
    frame_proj_info = tk.Frame(frame_proj_check, width=200, height=600)
    frame_proj_info.pack(side='top', anchor='n')

    # 项目编号
    proj_check_items["proj_id"] = common.create_label_and_entry(frame_proj_info, "项目编号", "")

    # 项目名称
    proj_check_items["proj_name"] = common.create_label_and_entry(frame_proj_info, "项目名称", "")

    # 项目来源
    proj_check_items["proj_source"] = common.create_label_and_entry(frame_proj_info, "项目来源", "")

    # 参与者编号
    proj_check_items["teacher_id"] = common.create_label_and_entry(frame_proj_info, "员工编号", "")

    # 参与者姓名
    proj_check_items["teacher_name"] = common.create_label_and_entry(frame_proj_info, "员工姓名", "")

    # 创建查询结果显示框
    frame_proj_check_result = tk.Frame(frame_proj_check, width=800, height=600)
    frame_proj_check_result.pack(side='top', anchor='n')

    button_proj_check.config(
        command=lambda: create_check_result(self, frame_proj_check_result))

    # 创建查询结果显示框label
    label_proj_check_result = tk.Label(frame_proj_check_result, text="查询结果", font=("宋体", 10))
    label_proj_check_result.pack(side='top', anchor='n')

    frame_proj_check_label = tk.Frame(frame_proj_check_result, width=800, height=50)
    frame_proj_check_label.pack(side='top', anchor='n')

    tk.Label(frame_proj_check_label, text="项目名称", font=("宋体", 10), width=20, height=2).grid(row=0, column=0)
    tk.Label(frame_proj_check_label, text="最高员工", font=("宋体", 10), width=20, height=2).grid(row=0, column=1)
    tk.Label(frame_proj_check_label, text="开始年份", font=("宋体", 10), width=20, height=2).grid(row=0, column=2)
    tk.Label(frame_proj_check_label, text="项目来源", font=("宋体", 10), width=20, height=2).grid(row=0, column=3)
    tk.Label(frame_proj_check_label, text="", font=("宋体", 10), width=12, height=2).grid(row=0, column=4)