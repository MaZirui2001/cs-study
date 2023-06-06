import tkinter as tk
from tkinter import messagebox
import pymysql as sql
import pandas as pd
import paper_common as common
from paper_common import id2type, id2level

paper_check_items = {}
check_result_frame = []
detail_button_list = []


def generate_check_sql(check_items):
    # 获取输入的论文信息
    paper_name = check_items["paper_name"].get()
    paper_id = check_items["paper_id"].get()
    author_name = check_items["author_name"].get()
    author_id = check_items["author_id"].get()
    paper_source = check_items["paper_source"].get()
    paper_date = check_items["publish_time"].get()
    # 使用sql语句，先将paper表、public_paper表、teacher表连接起来
    # 一旦有一个条件不为空，就将其加入sql语句中
    sql_sentence = "select distinct paper.id  from paper \
        join public_paper pp on paper.id = pp.paper_id \
        join teacher on pp.teacher_id = teacher.id "
    t = ()
    if paper_name != "" or paper_id != "" or author_name != "" or author_id != "":
        sql_sentence += "where "
    if paper_name != "":
        sql_sentence += "paper.name = %s"
        t = t + (paper_name,)
    if paper_id != "":
        # 检查paper_id是否为正整数
        try:
            paper_id = int(paper_id)
            if paper_id <= 0:
                raise ValueError
        except ValueError:
            messagebox.showerror("错误", "论文编号必须为正整数")
            return
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "paper.id = %s"
        t = t + (paper_id,)
    if author_name != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "teacher.name = %s"
        t = t + (author_name,)
    if author_id != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "teacher.id = %s"
        t = t + (author_id,)
    if paper_source != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "paper.public_source = %s"
        t = t + (paper_source,)

    if paper_date != "":
        # 检查paper_date是否为日期
        try:
            paper_date = pd.to_datetime(paper_date).date()
        except ValueError:
            messagebox.showerror("错误", "日期格式错误")
            return
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "paper.public_date = %s"
        t = t + (paper_date,)
    sql_sentence += " order by paper.id;"
    return sql_sentence, t


def check_paper():
    sql_sentence, t = generate_check_sql(paper_check_items)
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
    sql_sentence = "select paper.name, paper.id, paper.public_source, paper.public_date, paper.type, paper.level, \
    teacher.name, teacher.id, pp.ranking, pp.is_corresponding_author from paper \
    join public_paper pp on paper.id = pp.paper_id \
    join teacher on pp.teacher_id = teacher.id where paper.id = %s order by paper.id;"
    for i in range(len(data)):
        # 对每一个论文编号，查询其详细信息
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
        for j in range(6):
            check_result[i].append(result[i][0][j])
        check_result[i].append([])
        for j in range(len(result[i])):
            check_result[i][6].append([result[i][j][6], result[i][j][7], result[i][j][8], result[i][j][9]])

    # 按照排名对每一篇文章的作者进行排序
    for i in range(len(check_result)):
        check_result[i][6].sort(key=lambda x: x[2])

    # 显示简短信息
    check_result_simple = []
    for i in range(len(check_result)):
        check_result_simple.append(
            (check_result[i][0], check_result[i][6][0][0], check_result[i][3], check_result[i][2]))
    # create_check_result_frame(self, frame_paper_check)
    return check_result, check_result_simple


def create_check_result(self, frame_paper_check):
    check_result, check_result_simple = check_paper()
    create_check_result_frame(self, frame_paper_check, check_result_simple, check_result)


def create_detail_check_top(self, check_item):
    print("ok")
    top = tk.Toplevel(self.root, width=400, height=400)
    top.title("论文详情")
    top.geometry("400x400")
    top.resizable(False, False)
    # 30号字体靠左显示论文名称
    label_paper_name = tk.Label(top, text=check_item[0], font=("宋体", 20), anchor='w')
    label_paper_name.pack(side='top', anchor='w')

    # 15号字体靠左显示论文编号
    label_paper_id = tk.Label(top, text="论文编号：" + str(check_item[1]), font=("宋体", 10), anchor='w')
    label_paper_id.pack(side='top', anchor='w')

    # 15号字体靠左显示论文来源
    label_paper_source = tk.Label(top, text="论文来源：" + str(check_item[2]), font=("宋体", 10), anchor='w')
    label_paper_source.pack(side='top', anchor='w')

    # 15号字体靠左显示论文发表时间
    label_paper_publish_time = tk.Label(top, text="发表时间：" + str(check_item[3]), font=("宋体", 10),
                                        anchor='w')
    label_paper_publish_time.pack(side='top', anchor='w')

    # 10号字体靠左显示论文类型
    label_paper_type = tk.Label(top, text="论文类型：" + id2type[int(check_item[4])], font=("宋体", 10),
                                anchor='w')
    label_paper_type.pack(side='top', anchor='w')

    # 10号字体靠左显示论文等级
    label_paper_level = tk.Label(top, text="论文等级：" + id2level[int(check_item[5])], font=("宋体", 10),
                                 anchor='w')
    label_paper_level.pack(side='top', anchor='w')

    # 10号字体靠左显示所有论文作者
    for i in range(len(check_item[6])):
        string_info = "论文作者" + str(i + 1) + ": " + str(check_item[6][i][0])
        string_info += "（"
        string_info += "工号：" + str(check_item[6][i][1])
        if check_item[6][i][3] == 1:
            string_info += ", "
            string_info += "通讯作者"
        string_info += "）"
        label_paper_author = tk.Label(top, text=string_info,
                                      font=("宋体", 10), anchor='w')
        label_paper_author.pack(side='top', anchor='w')


def create_check_result_frame(self, frame_paper_check, check_result_simple, check_result):
    for frame in check_result_frame:
        frame.destroy()
    check_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=50)
        frame_paper_check_result.pack(side='top', anchor='w')
        check_result_frame.append(frame_paper_check_result)
        # 显示四栏：论文名称、最高作者、发表时间、论文来源, 用Text组件, 每一个后面跟一个详情按钮
        # 论文名称
        common.create_text(frame_paper_check_result, str(check_result_simple[i][0]), 1, 0)
        # 最高作者
        common.create_text(frame_paper_check_result, str(check_result_simple[i][1]), 1, 1)
        # 发表时间
        common.create_text(frame_paper_check_result, str(check_result_simple[i][2]), 1, 2)
        # 论文来源
        common.create_text(frame_paper_check_result, str(check_result_simple[i][3]), 1, 3)
        # 详情按钮
        button_paper_detail = tk.Button(frame_paper_check_result, text="详情", width=10, height=1,
                                        command=lambda arg1=self, arg2=check_result[i]: create_detail_check_top(arg1,
                                                                                                                arg2))
        button_paper_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_paper_detail, i))


def create_frame_paper_check(self):
    canvas_paper_check = tk.Canvas(self.root, width=800, height=1200, scrollregion=(0, 0, 1200, 800))
    frame_paper_check = tk.Frame(canvas_paper_check, width=800, height=1200)
    self.frame_list["frame_paper_check"] = canvas_paper_check
    frame_paper_check.pack(side='top', anchor='n')
    canvas_paper_check.create_window(400, 0, anchor='n', window=frame_paper_check)

    # 创建滚动条
    common.create_scrollbar(canvas_paper_check)

    # 创建label
    tk.Label(frame_paper_check, text="论文信息查找", font=("宋体", 15)).pack(side='top', anchor='n')

    button_paper_check = tk.Button(frame_paper_check, text="查询", width=10, height=1)
    button_paper_check.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的论文信息
    frame_paper_info = tk.Frame(frame_paper_check, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')

    # 论文编号
    paper_check_items["paper_id"] = common.create_label_and_entry(frame_paper_info, "论文编号", "")

    # 论文名称
    paper_check_items["paper_name"] = common.create_label_and_entry(frame_paper_info, "论文名称", "")

    # 论文来源
    paper_check_items["paper_source"] = common.create_label_and_entry(frame_paper_info, "论文来源", "")

    # 论文发表日期
    paper_check_items["publish_time"] = common.create_label_and_entry(frame_paper_info, "发表日期", "")

    # 作者编号
    paper_check_items["author_id"] = common.create_label_and_entry(frame_paper_info, "作者编号", "")

    # 作者姓名
    paper_check_items["author_name"] = common.create_label_and_entry(frame_paper_info, "作者姓名", "")

    # 创建查询结果显示框
    frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=600)
    frame_paper_check_result.pack(side='top', anchor='n')

    button_paper_check.config(
        command=lambda: create_check_result(self, frame_paper_check_result))

    # 创建查询结果显示框label
    label_paper_check_result = tk.Label(frame_paper_check_result, text="查询结果", font=("宋体", 10))
    label_paper_check_result.pack(side='top', anchor='n')

    frame_paper_check_label = tk.Frame(frame_paper_check_result, width=800, height=50)
    frame_paper_check_label.pack(side='top', anchor='n')

    tk.Label(frame_paper_check_label, text="论文名称", font=("宋体", 10), width=20, height=2).grid(row=0, column=0)
    tk.Label(frame_paper_check_label, text="作者之一", font=("宋体", 10), width=20, height=2).grid(row=0, column=1)
    tk.Label(frame_paper_check_label, text="发表时间", font=("宋体", 10), width=20, height=2).grid(row=0, column=2)
    tk.Label(frame_paper_check_label, text="论文来源", font=("宋体", 10), width=20, height=2).grid(row=0, column=3)
    tk.Label(frame_paper_check_label, text="", font=("宋体", 10), width=12, height=2).grid(row=0, column=4)
