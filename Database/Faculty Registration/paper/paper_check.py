import ttkbootstrap as ttk
from tkinter import messagebox
import pymysql as sql
import pandas as pd
import common as common
from common import paper_id2type, paper_id2level

paper_check_items = {}
check_result_frame = []
detail_button_list = []
frame_paper_check = None


def fresh(self):
    create_check_result(self)


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
        join publish_paper pp on paper.id = pp.paper_id \
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


def check_paper(check_items):
    temp = generate_check_sql(check_items)
    if temp is None:
        return [], []
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
    sql_sentence = "select paper.name, paper.id, paper.public_source, paper.public_date, paper.type, paper.level, \
    teacher.name, teacher.id, pp.ranking, pp.is_corresponding_author from paper \
    join publish_paper pp on paper.id = pp.paper_id \
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
    return check_result, check_result_simple


def create_check_result(self):
    check_result, check_result_simple = check_paper(paper_check_items)
    create_check_result_frame(self, check_result_simple, check_result)


def create_detail_check_top(self, check_item):
    top = ttk.Toplevel(self.root, minsize=(800, 800))
    top.title("论文详情")
    self.root.attributes("-disabled", True)
    top.protocol("WM_DELETE_WINDOW", lambda: common.close_window(self.root, top))
    # 30号字体靠左显示论文名称
    label_paper_name = ttk.Label(top, text=check_item[0], font=("宋体", 20, 'bold'), anchor='w')
    label_paper_name.pack(side='top', anchor='w', pady=20)

    # 15号字体靠左显示论文编号
    label_paper_id = ttk.Label(top, text="论文编号：" + str(check_item[1]), font=("宋体", 10), anchor='w')
    label_paper_id.pack(side='top', anchor='w', pady=10)

    # 15号字体靠左显示论文来源
    label_paper_source = ttk.Label(top, text="论文来源：" + str(check_item[2]), font=("宋体", 10), anchor='w')
    label_paper_source.pack(side='top', anchor='w', pady=10)

    # 15号字体靠左显示论文发表时间
    label_paper_publish_time = ttk.Label(top, text="发表时间：" + str(check_item[3]), font=("宋体", 10),
                                         anchor='w')
    label_paper_publish_time.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示论文类型
    label_paper_type = ttk.Label(top, text="论文类型：" + paper_id2type[int(check_item[4])], font=("宋体", 10),
                                 anchor='w')
    label_paper_type.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示论文等级
    label_paper_level = ttk.Label(top, text="论文等级：" + paper_id2level[int(check_item[5])], font=("宋体", 10),
                                  anchor='w')
    label_paper_level.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示所有论文作者
    for i in range(len(check_item[6])):
        string_info = "论文作者" + str(check_item[6][i][2]) + ": " + str(check_item[6][i][0])
        string_info += "（"
        string_info += "工号：" + str(check_item[6][i][1])
        if check_item[6][i][3] == 1:
            string_info += ", "
            string_info += "通讯作者"
        string_info += "）"
        label_paper_author = ttk.Label(top, text=string_info,
                                       font=("宋体", 10), anchor='w')
        label_paper_author.pack(side='top', anchor='w', pady=10)


def create_check_result_frame(self, check_result_simple, check_result):
    for frame in check_result_frame:
        frame.destroy()
    check_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_paper_check_result = ttk.Frame(frame_paper_check, width=1600, height=100)
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
        button_paper_detail = ttk.Button(frame_paper_check_result, text="详情", width=5, style="warning",
                                         command=lambda arg1=self, arg2=check_result[i]: create_detail_check_top(arg1,
                                                                                                                 arg2))
        button_paper_detail.grid(row=0, column=4, padx=10)
        detail_button_list.append((button_paper_detail, i))


def create_basic_info_frame(self, canvas_paper, paper_items, create_result, frame_check, name="论文信息查找", width=20):
    # 创建滚动条
    common.create_scrollbar(canvas_paper)

    # 创建label
    ttk.Label(frame_check, text=name, font=("微软雅黑", 15, 'bold')).pack(side='top', anchor='n', pady=5)

    button_paper_check = ttk.Button(frame_check, text="查询", width=10, style='success')
    button_paper_check.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的论文信息
    frame_paper_info = ttk.Frame(frame_check, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')

    # 论文编号
    paper_items["paper_id"] = common.create_label_and_entry(frame_paper_info, "论文编号", "")

    # 论文名称
    paper_items["paper_name"] = common.create_label_and_entry(frame_paper_info, "论文名称", "")

    # 论文来源
    paper_items["paper_source"] = common.create_label_and_entry(frame_paper_info, "论文来源", "")

    # 论文发表日期
    paper_items["publish_time"] = common.create_label_and_entry(frame_paper_info, "发表日期", "")

    # 作者编号
    paper_items["author_id"] = common.create_label_and_entry(frame_paper_info, "作者编号", "")

    # 作者姓名
    paper_items["author_name"] = common.create_label_and_entry(frame_paper_info, "作者姓名", "")

    # 创建查询结果显示框
    frame_paper_check_result = ttk.Frame(frame_check, width=1600, height=800)
    frame_paper_check_result.pack(side='top', anchor='n')

    button_paper_check.config(
        command=lambda: create_result(self))

    # 创建查询结果显示框label
    label_paper_check_result = ttk.Label(frame_paper_check_result, text="查询结果", font=("宋体", 15, 'bold'))
    label_paper_check_result.pack(side='top', anchor='n', pady=20)

    frame_paper_check_label = ttk.Frame(frame_paper_check_result, width=1600, height=800)
    frame_paper_check_label.pack(side='top', anchor='n')

    ttk.Label(frame_paper_check_label, text="论文名称", font=("宋体", 10), width=width).grid(row=0, column=0)
    ttk.Label(frame_paper_check_label, text="作者之一", font=("宋体", 10), width=width).grid(row=0, column=1)
    ttk.Label(frame_paper_check_label, text="发表时间", font=("宋体", 10), width=width).grid(row=0, column=2)
    ttk.Label(frame_paper_check_label, text="论文来源", font=("宋体", 10), width=width).grid(row=0, column=3)
    ttk.Label(frame_paper_check_label, text="", font=("宋体", 10), width=12).grid(row=0, column=4)

    return frame_paper_check_label


def create_frame_paper_check(self):
    canvas_paper_check = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    global frame_paper_check
    frame_paper_check = ttk.Frame(canvas_paper_check, width=1600, height=2400)
    self.frame_list["frame_paper_check"] = canvas_paper_check
    frame_paper_check.pack(side='top', anchor='n')
    canvas_paper_check.create_window(840, 0, anchor='n', window=frame_paper_check)

    create_basic_info_frame(self, canvas_paper_check, paper_check_items, create_check_result, frame_paper_check)
