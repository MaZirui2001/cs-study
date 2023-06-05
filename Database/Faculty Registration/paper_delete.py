import tkinter as tk
from tkinter import messagebox
import pymysql as sql
import pandas as pd

paper_del_items = {}
paper_check_items = {}
check_result_simple = []
check_result = []
del_result_frame = []
detail_button_list = []
delete_button_list = []

id2type = ['none', 'full-paper', 'short-paper', 'poster-paper', 'demo-paper']
id2level = ['none', 'CCF-A', 'CCF-B', 'CCF-C', '中文 CCF-A', '中文 CCF-B', '无级别']
id2id_name = ['none', '博士后', '助教', '讲师', '副教授', '特任教授', '教授', '助理研究员', '特任副研究员', '副研究员',
              '特任研究员', '研究员']
id2gender = ['none', '男', '女']


def delete_paper(self, frame_paper_check, paper_id):
    # 弹窗并确认是否删除
    if not messagebox.askyesno("确认", "确认删除这篇论文？"):
        return

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
    # 调用删除存储过程
    try:
        cursor.callproc("delete_paper", (paper_id,))
        db.commit()
    except sql.Error as e:
        db.rollback()
        db.close()
        print("删除失败：" + str(e))
        exit(-1)
    db.close()
    messagebox.showinfo("成功", "删除成功")
    # 刷新页面
    check_del_paper(self, frame_paper_check)


def check_del_paper(self, frame_paper_delete):
    paper_name = paper_del_items["paper_name"].get()
    paper_id = paper_del_items["paper_id"].get()
    author_name = paper_del_items["author_name"].get()
    author_id = paper_del_items["author_id"].get()
    paper_source = paper_del_items["paper_source"].get()
    paper_date = paper_del_items["publish_time"].get()
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
    print(sql_sentence)
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
    global check_result
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
    print(check_result)

    # 显示剪短信息
    global check_result_simple
    check_result_simple = []
    for i in range(len(check_result)):
        check_result_simple.append(
            (check_result[i][0], check_result[i][6][0][0], check_result[i][3], check_result[i][2]))
    create_del_result_frame(self, frame_paper_delete)


def create_del_result_frame(self, frame_paper_check):
    for frame in del_result_frame:
        frame.destroy()
    del_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=50)
        frame_paper_check_result.pack(side='top', anchor='w')
        del_result_frame.append(frame_paper_check_result)
        # 显示四栏：论文名称、最高作者、发表时间、论文来源, 用Text组件, 每一个后面跟一个详情按钮和一个删除按钮
        # 论文名称
        text_paper_name = tk.Text(frame_paper_check_result, width=20, height=2)
        text_paper_name.grid(row=0, column=0)
        text_paper_name.insert(1.0, str(check_result_simple[i][0]))
        text_paper_name.config(state='disabled')
        # 最高作者
        text_author = tk.Text(frame_paper_check_result, width=20, height=2)
        text_author.grid(row=0, column=1)
        text_author.insert(1.0, str(check_result_simple[i][1]))
        text_author.config(state='disabled')
        # 发表时间
        text_publish_time = tk.Text(frame_paper_check_result, width=20, height=2)
        text_publish_time.grid(row=0, column=2)
        text_publish_time.insert(1.0, str(check_result_simple[i][2]))
        text_publish_time.config(state='disabled')
        # 论文来源
        text_paper_source = tk.Text(frame_paper_check_result, width=20, height=2)
        text_paper_source.grid(row=0, column=3)
        text_paper_source.insert(1.0, str(check_result_simple[i][3]))
        text_paper_source.config(state='disabled')
        # 详情按钮
        button_paper_detail = tk.Button(frame_paper_check_result, text="详情", width=10, height=1,
                                        command=lambda arg1=self, arg2=i: create_detail_check_top(arg1, arg2))
        button_paper_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_paper_detail, i))
        # 删除按钮
        button_paper_delete = tk.Button(frame_paper_check_result, text="删除", width=10, height=1,
                                        command=lambda arg1=self, arg2=frame_paper_check, arg3=check_result[i][1]: delete_paper(arg1, arg2, arg3))
        button_paper_delete.grid(row=0, column=5, padx=2)
        delete_button_list.append((button_paper_delete, i))


def create_detail_check_top(self, index):
    top = tk.Toplevel(self.root, width=400, height=400)
    top.title("论文详情")
    top.geometry("400x400")
    top.resizable(False, False)
    # 30号字体靠左显示论文名称
    label_paper_name = tk.Label(top, text=check_result[index][0], font=("宋体", 20), anchor='w')
    label_paper_name.pack(side='top', anchor='w')

    # 15号字体靠左显示论文编号
    label_paper_id = tk.Label(top, text="论文编号：" + str(check_result[index][1]), font=("宋体", 10), anchor='w')
    label_paper_id.pack(side='top', anchor='w')

    # 15号字体靠左显示论文来源
    label_paper_source = tk.Label(top, text="论文来源：" + str(check_result[index][2]), font=("宋体", 10), anchor='w')
    label_paper_source.pack(side='top', anchor='w')

    # 15号字体靠左显示论文发表时间
    label_paper_publish_time = tk.Label(top, text="发表时间：" + str(check_result[index][3]), font=("宋体", 10),
                                        anchor='w')
    label_paper_publish_time.pack(side='top', anchor='w')

    # 10号字体靠左显示论文类型
    label_paper_type = tk.Label(top, text="论文类型：" + id2type[int(check_result[index][4])], font=("宋体", 10),
                                anchor='w')
    label_paper_type.pack(side='top', anchor='w')

    # 10号字体靠左显示论文等级
    label_paper_level = tk.Label(top, text="论文等级：" + id2level[int(check_result[index][5])], font=("宋体", 10),
                                 anchor='w')
    label_paper_level.pack(side='top', anchor='w')

    # 10号字体靠左显示所有论文作者
    for i in range(len(check_result[index][6])):
        string_info = "论文作者" + str(i + 1) + ": " + str(check_result[index][6][i][0])
        string_info += "（"
        string_info += "工号：" + str(check_result[index][6][i][1])
        if check_result[index][6][i][3] == 1:
            string_info += ", "
            string_info += "通讯作者"
        string_info += "）"
        label_paper_author = tk.Label(top, text=string_info,
                                      font=("宋体", 10), anchor='w')
        label_paper_author.pack(side='top', anchor='w')


def create_frame_paper_delete(self):
    canvas_paper_del = tk.Canvas(self.root, width=800, height=1200, scrollregion=(0, 0, 800, 1200))
    frame_paper_check = tk.Frame(canvas_paper_del, width=800, height=1200)
    self.frame_list["frame_paper_delete"] = canvas_paper_del

    # 创建滚动条
    sb = tk.Scrollbar(canvas_paper_del, orient='vertical', command=canvas_paper_del.yview)
    sb.pack(side='right', fill='y')
    canvas_paper_del.configure(yscrollcommand=sb.set)
    frame_paper_check.pack(side='top', anchor='n')
    canvas_paper_del.create_window(400, 0, anchor='n', window=frame_paper_check)

    # 创建label
    label_paper_name = tk.Label(frame_paper_check, text="论文信息删除", font=("宋体", 15))
    label_paper_name.pack(side='top', anchor='n')
    # 创建查询按钮
    button_paper_check = tk.Button(frame_paper_check, text="查询", width=10, height=1)
    button_paper_check.pack(side='top', anchor='n')
    # 创建输入框, 获取输入的论文信息
    frame_paper_info = tk.Frame(frame_paper_check, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')

    # 论文编号
    # 创建论文编号frame并绑定
    frame_paper_id = tk.Frame(frame_paper_info, width=800, height=50)
    frame_paper_id.pack(side='top', anchor='w')
    # 创建论文编号label
    label_paper_id = tk.Label(frame_paper_id, text="论文编号", font=("宋体", 10))
    label_paper_id.pack(side='left', anchor='center')
    # 创建论文编号输入框
    entry_paper_id = tk.Entry(frame_paper_id, width=50)
    entry_paper_id.pack(side='left', anchor='center')
    paper_del_items["paper_id"] = entry_paper_id

    # 论文名称
    # 创建论文名称frame并绑定
    frame_paper_name = tk.Frame(frame_paper_info, width=800, height=50)
    frame_paper_name.pack(side='top', anchor='w')
    # 创建论文名称label
    label_paper_name = tk.Label(frame_paper_name, text="论文名称", font=("宋体", 10))
    label_paper_name.pack(side='left', anchor='center')
    # 创建论文名称输入框
    entry_paper_name = tk.Entry(frame_paper_name, width=50)
    entry_paper_name.pack(side='left', anchor='center')
    paper_del_items["paper_name"] = entry_paper_name

    # 论文来源
    # 创建论文来源frame并绑定
    frame_paper_source = tk.Frame(frame_paper_info, width=800, height=50)
    frame_paper_source.pack(side='top', anchor='w')
    # 创建论文来源label
    label_paper_source = tk.Label(frame_paper_source, text="论文来源", font=("宋体", 10))
    label_paper_source.pack(side='left', anchor='center')
    # 创建论文来源输入框
    entry_paper_source = tk.Entry(frame_paper_source, width=50)
    entry_paper_source.pack(side='left', anchor='center')
    paper_del_items["paper_source"] = entry_paper_source

    # 论文发表日期
    # 创建论文发表日期frame并绑定
    frame_publish_time = tk.Frame(frame_paper_info, width=800, height=50)
    frame_publish_time.pack(side='top', anchor='w')
    # 创建论文发表日期label
    label_publish_time = tk.Label(frame_publish_time, text="发表日期", font=("宋体", 10))
    label_publish_time.pack(side='left', anchor='center')
    # 创建论文发表日期输入框
    entry_publish_time = tk.Entry(frame_publish_time, width=50)
    entry_publish_time.pack(side='left', anchor='center')
    paper_del_items["publish_time"] = entry_publish_time

    # 作者编号
    # 创建作者编号frame并绑定
    frame_author_id = tk.Frame(frame_paper_info, width=800, height=50)
    frame_author_id.pack(side='top', anchor='w')
    # 创建作者编号label
    label_author_id = tk.Label(frame_author_id, text="作者编号", font=("宋体", 10))
    label_author_id.pack(side='left', anchor='center')
    # 创建作者编号输入框
    entry_author_id = tk.Entry(frame_author_id, width=50)
    entry_author_id.pack(side='left', anchor='center')
    paper_del_items["author_id"] = entry_author_id

    # 作者姓名
    # 创建作者姓名frame并绑定
    frame_author_name = tk.Frame(frame_paper_info, width=800, height=50)
    frame_author_name.pack(side='top', anchor='w')
    # 创建作者姓名label
    label_author_name = tk.Label(frame_author_name, text="作者姓名", font=("宋体", 10))
    label_author_name.pack(side='left', anchor='center')
    # 创建作者姓名输入框
    entry_author_name = tk.Entry(frame_author_name, width=50)
    entry_author_name.pack(side='left', anchor='center')
    paper_del_items["author_name"] = entry_author_name

    # 创建查询结果显示框
    frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=600)
    frame_paper_check_result.pack(side='top', anchor='n')
    button_paper_check.config(command=lambda arg1=self, arg2=frame_paper_check_result: check_del_paper(arg1, arg2))

    # 创建查询结果显示框label
    label_paper_check_result = tk.Label(frame_paper_check_result, text="查询结果", font=("宋体", 15))
    label_paper_check_result.pack(side='top', anchor='n')

    frame_paper_check_label = tk.Frame(frame_paper_check_result, width=800, height=50)
    label_paper_name = tk.Label(frame_paper_check_label, text="论文名称", font=("宋体", 10), width=20, height=2)
    label_paper_name.grid(row=0, column=0)
    label_paper_author = tk.Label(frame_paper_check_label, text="最高作者", font=("宋体", 10), width=20, height=2)
    label_paper_author.grid(row=0, column=1)
    label_paper_time = tk.Label(frame_paper_check_label, text="发表时间", font=("宋体", 10), width=20, height=2)
    label_paper_time.grid(row=0, column=2)
    label_paper_source = tk.Label(frame_paper_check_label, text="论文来源", font=("宋体", 10), width=20, height=2)
    label_paper_source.grid(row=0, column=3)
    label_none = tk.Label(frame_paper_check_label, text="", font=("宋体", 10), width=10, height=2)
    label_none.grid(row=0, column=4, padx=2)
    label_none2 = tk.Label(frame_paper_check_label, text="", font=("宋体", 10), width=10, height=2)
    label_none2.grid(row=0, column=5, padx=2)
    frame_paper_check_label.pack(side='top', anchor='n')
