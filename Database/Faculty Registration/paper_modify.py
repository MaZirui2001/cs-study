import tkinter as tk
from tkinter import messagebox
import pymysql as sql
import pandas as pd
import paper_common as common
from paper_common import type_map, level_map, id2type, id2level

paper_mod_items = {}
paper_check_items = {}
check_result_simple = []
check_result = []
mod_result_frame = []
detail_button_list = []
modify_button_list = []

frame_paper_author_list = []
author_num_view = 0
paper_add_items = {}
author_info = []


def modify_paper_info(origin_paper_id, message_parent):
    # 总体思路：先删除原来的数据，再插入新的数据
    # 获取输入的论文信息
    paper_id = paper_add_items['paper_id'].get()
    paper_name = paper_add_items['paper_name'].get()
    paper_source = paper_add_items['paper_source'].get()
    paper_date = paper_add_items['paper_date'].get()
    paper_type = type_map[paper_add_items['paper_type'].get()]
    paper_level = level_map[paper_add_items['paper_level'].get()]
    author_id_list = []
    author_name_list = []
    author_rank_list = []
    author_is_communicate_list = []
    for i in range(author_num_view):
        author_id_list.append(author_info[i]['id'].get())
        author_name_list.append(author_info[i]['name'].get())
        author_rank_list.append(author_info[i]['rank'].get())
        author_is_communicate_list.append(author_info[i]['comm'].get())
    # 论文编号不能为空
    if paper_id == '':
        tk.messagebox.showerror(title='错误', message='论文编号不能为空！', parent=message_parent)
        return
    # 转换为int类型，转换失败则报错
    else:
        try:
            paper_id = int(paper_id)
        except ValueError:
            tk.messagebox.showerror(title='错误', message='论文编号必须为整数！', parent=message_parent)
            return
    # 论文名称不能为空
    if paper_name == '':
        tk.messagebox.showerror(title='错误', message='论文名称不能为空！', parent=message_parent)
        return
    # 论文来源不能为空
    if paper_source == '':
        tk.messagebox.showerror(title='错误', message='发表来源不能为空！', parent=message_parent)
        return
    # 论文发表日期需要合法，且需要可以转换为datetime类型
    if paper_date == '':
        tk.messagebox.showerror(title='错误', message='发表日期不能为空！', parent=message_parent)
        return
    else:
        try:
            paper_date = pd.to_datetime(paper_date).date()
        except ValueError:
            tk.messagebox.showerror(title='错误', message='发表日期不合法！', parent=message_parent)
            return
    # 检查作者列表是否有空值
    listnum = author_num_view
    temp_id_list = []
    temp_name_list = []
    temp_rank_list = []
    temp_is_communicate_list = []
    for i in range(author_num_view):
        if author_id_list[i] == '' or author_name_list[i] == '' or author_rank_list[i] == '':
            listnum -= 1
        else:
            temp_id_list.append(author_id_list[i])
            temp_name_list.append(author_name_list[i])
            temp_rank_list.append(author_rank_list[i])
            temp_is_communicate_list.append(author_is_communicate_list[i])
    if listnum == 0:
        tk.messagebox.showerror(title='错误', message='作者列表不能全为不完整的信息！', parent=message_parent)
        return
    author_id_list = temp_id_list
    author_name_list = temp_name_list
    author_rank_list = temp_rank_list
    author_is_communicate_list = temp_is_communicate_list
    # 检查作者编号是否合法
    for i in range(listnum):
        try:
            author_id_list[i] = int(author_id_list[i])
            if author_id_list[i] <= 0:
                raise ValueError
        except ValueError:
            tk.messagebox.showerror(title='错误', message='作者编号必须为正整数！', parent=message_parent)
            return
    # 检查作者排名是否合法
    # 检查是否有相同的作者编号
    for i in range(listnum):
        for j in range(i + 1, listnum):
            try:
                author_id_list[i] = int(author_id_list[i])
                if author_id_list[i] <= 0:
                    raise ValueError
            except ValueError:
                tk.messagebox.showerror(title='错误', message='作者编号必须为正整数！', parent=message_parent)
                return
            if author_id_list[i] == author_id_list[j]:
                tk.messagebox.showerror(title='错误', message='作者编号不能相同！', parent=message_parent)
                return
    # 检查是否有相同的排名
    for i in range(listnum):
        for j in range(i + 1, listnum):
            if author_rank_list[i] == author_rank_list[j]:
                tk.messagebox.showerror(title='错误', message='作者排名不能相同！', parent=message_parent)
                return
    # 检查是否有超过一个的通讯作者
    communicate_num = 0
    for i in range(listnum):
        if author_is_communicate_list[i] == 1:
            communicate_num += 1
    if communicate_num > 1:
        tk.messagebox.showerror(title='错误', message='通讯作者只能有一个！', parent=message_parent)
        return
    # 通过基本检查，开始删除原有记录
    # 对话框：确认提交修改
    if not tk.messagebox.askyesno(title='确认', message='确认提交修改？', parent=message_parent):
        return
    # 删除论文记录
    delete_id = origin_paper_id
    # 打开数据库连接
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
    # 调用删除存储过程，同时插入
    try:
        cursor.callproc('delete_paper', (delete_id,))
        cursor.callproc('insert_paper', (paper_id, paper_name, paper_source, paper_date, paper_type, paper_level))
        for i in range(listnum):
            cursor.callproc('insert_teacher_paper',
                            (author_id_list[i], author_name_list[i], paper_id, author_rank_list[i],
                             author_is_communicate_list[i]))
        db.commit()
    except sql.Error as e:
        tk.messagebox.showerror(title='错误', message='修改失败！\n' + str(e.args[1]), parent=message_parent)
        db.rollback()
        db.close()
        return
    # 关闭数据库连接
    db.close()
    # 提示修改成功
    tk.messagebox.showinfo(title='提示', message='修改成功！', parent=message_parent)


def create_frame_paper_author(frame_paper_info, paper_author):
    global frame_paper_author_list, author_num_view
    if author_num_view >= 10:
        return
    if len(frame_paper_author_list) > author_num_view:
        frame_paper_author_list[author_num_view].pack(side='top', anchor='n')
        author_num_view += 1
        return

    frame_paper_author = tk.Frame(frame_paper_info, width=800, height=50)
    author_num_view += 1

    # 输入作者编号和排名
    entry_paper_author_id, entry_paper_author_rank = common.create_label_and_entry2(frame_paper_author, "作者" + str(
        author_num_view) + "编号", paper_author[1], "作者" + str(author_num_view) + "排名", paper_author[2])

    # 输入作者姓名和是否为通讯作者
    entry_paper_author_name, var_paper_author_is_communicate = common.create_label_and_entry_with_checkbutton(
        frame_paper_author, "作者" + str(author_num_view) + "姓名", paper_author[0], "是否为通讯作者", paper_author[3])

    frame_paper_author.pack(side='top', anchor='n')
    frame_paper_author_list.append(frame_paper_author)

    author_info.append({'id': entry_paper_author_id, 'name': entry_paper_author_name, 'rank': entry_paper_author_rank,
                        'comm': var_paper_author_is_communicate})


def delete_frame_paper_author():
    global frame_paper_author_list, author_num_view
    if author_num_view <= 1:
        return
    frame_paper_author_list[author_num_view - 1].pack_forget()
    author_num_view -= 1


def create_modify_window(self, index):
    # 创建新窗口
    window_modify = tk.Toplevel(self.root)
    window_modify.geometry("800x600")
    window_modify.title("修改论文信息")
    window_modify.resizable(False, False)
    # 获取当前论文信息
    paper_id = check_result[index][1]
    paper_name = check_result[index][0]
    paper_source = check_result[index][2]
    paper_date = check_result[index][3]
    paper_type = check_result[index][4]
    paper_level = check_result[index][5]
    paper_authors = check_result[index][6]

    canvas_paper_add = tk.Canvas(window_modify, width=800, height=1200, scrollregion=(0, 0, 1200, 800))
    frame_paper_add = tk.Frame(canvas_paper_add, width=800, height=1200)
    canvas_paper_add.pack(side='top', anchor='center', fill='both', expand=1)
    frame_paper_add.pack(side='top', anchor='n')
    canvas_paper_add.create_window(400, 0, anchor='n', window=frame_paper_add)

    # 创建滚动条
    common.create_scrollbar(canvas_paper_add)

    # 创建label
    label_paper_name = tk.Label(frame_paper_add, text="论文信息修改", font=("宋体", 15))
    label_paper_name.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的论文信息
    frame_paper_info = tk.Frame(frame_paper_add, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')

    # 创建提交按钮
    button_paper_submit = tk.Button(frame_paper_info, text="提交", font=("宋体", 10),
                                    command=lambda arg1=paper_id, arg2=window_modify: modify_paper_info(arg1, arg2))
    button_paper_submit.pack(side='top', anchor='e')

    # 论文编号
    paper_add_items["paper_id"] = common.create_label_and_entry(frame_paper_info, "论文编号", paper_id)

    # 论文名称
    paper_add_items["paper_name"] = common.create_label_and_entry(frame_paper_info, "论文名称", paper_name)

    # 论文来源
    paper_add_items["paper_source"] = common.create_label_and_entry(frame_paper_info, "论文来源", paper_source)

    # 论文发表日期
    paper_add_items["paper_date"] = common.create_label_and_entry(frame_paper_info, "发表日期", paper_date)

    # 论文类型，下拉菜单
    types = ["full-paper", "short-paper", "poster-paper", "demo-paper"]
    paper_add_items["paper_type"] = common.create_option_menu(frame_paper_info, "论文类型", types[paper_type], types)

    # 论文级别， 下拉菜单
    levels = ["CCF-A", "CCF-B", "CCF-C", "中文 CCF-A", "中文 CCF-B", "无级别"]
    paper_add_items["paper_level"] = common.create_option_menu(frame_paper_info, "论文级别", levels[paper_level],
                                                               levels)

    # 论文作者信息：作者编号、作者姓名、作者排名、是否为通讯作者
    # 作者可能有多个，默认显示一个，点击按钮添加新的作者信息或删除新的对话框
    common.create_label_with_button2(frame_paper_info, "论文作者", "添加作者",
                                     lambda: create_frame_paper_author(frame_paper_info, ["" for i in range(4)]),
                                     "删除作者", lambda: delete_frame_paper_author())
    for author in paper_authors:
        create_frame_paper_author(frame_paper_info, author)


def check_modify_paper(self, frame_paper_modify):
    paper_name = paper_mod_items["paper_name"].get()
    paper_id = paper_mod_items["paper_id"].get()
    author_name = paper_mod_items["author_name"].get()
    author_id = paper_mod_items["author_id"].get()
    paper_source = paper_mod_items["paper_source"].get()
    paper_date = paper_mod_items["publish_time"].get()
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
    create_modify_result_frame(self, frame_paper_modify)


def create_modify_result_frame(self, frame_paper_check):
    for frame in mod_result_frame:
        frame.destroy()
    mod_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=50)
        frame_paper_check_result.pack(side='top', anchor='w')
        mod_result_frame.append(frame_paper_check_result)
        # 显示四栏：论文名称、最高作者、发表时间、论文来源, 用Text组件, 每一个后面跟一个详情按钮和一个修改按钮
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
        # 修改按钮
        button_paper_modify = tk.Button(frame_paper_check_result, text="修改", width=10, height=1,
                                        command=lambda arg1=self, arg2=i: create_modify_window(arg1, arg2))
        button_paper_modify.grid(row=0, column=5, padx=2)
        modify_button_list.append((button_paper_modify, i))


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


def create_frame_paper_modify(self):
    canvas_paper_mod = tk.Canvas(self.root, width=800, height=1200, scrollregion=(0, 0, 800, 1200))
    frame_paper_check = tk.Frame(canvas_paper_mod, width=800, height=1200)
    self.frame_list["frame_paper_modify"] = canvas_paper_mod

    # 创建滚动条
    sb = tk.Scrollbar(canvas_paper_mod, orient='vertical', command=canvas_paper_mod.yview)
    sb.pack(side='right', fill='y')
    canvas_paper_mod.configure(yscrollcommand=sb.set)
    frame_paper_check.pack(side='top', anchor='n')
    canvas_paper_mod.create_window(400, 0, anchor='n', window=frame_paper_check)

    # 创建label
    label_paper_name = tk.Label(frame_paper_check, text="论文信息修改", font=("宋体", 15))
    label_paper_name.pack(side='top', anchor='n')

    # 创建查询按钮
    button_paper_check = tk.Button(frame_paper_check, text="查询", width=10, height=1)
    button_paper_check.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的论文信息
    frame_paper_info = tk.Frame(frame_paper_check, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')

    # 论文编号
    paper_mod_items["paper_id"] = common.create_label_and_entry(frame_paper_info, "论文编号", "")

    # 论文名称
    paper_mod_items["paper_name"] = common.create_label_and_entry(frame_paper_info, "论文名称", "")

    # 论文来源
    paper_mod_items["paper_source"] = common.create_label_and_entry(frame_paper_info, "论文来源", "")

    # 论文发表日期
    paper_mod_items["publish_time"] = common.create_label_and_entry(frame_paper_info, "发表日期", "")

    # 作者编号
    paper_mod_items["author_id"] = common.create_label_and_entry(frame_paper_info, "作者编号", "")

    # 作者姓名
    paper_mod_items["author_name"] = common.create_label_and_entry(frame_paper_info, "作者姓名", "")

    # 创建查询结果显示框
    frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=600)
    frame_paper_check_result.pack(side='top', anchor='n')
    button_paper_check.config(command=lambda arg1=self, arg2=frame_paper_check_result: check_modify_paper(arg1, arg2))

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
