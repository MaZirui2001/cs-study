import tkinter as tk
from tkinter import messagebox
import pymysql as sql
import pandas as pd
import paper_common as common
from paper_common import type_map, level_map

frame_paper_author_list = []
author_num_view = 0
paper_add_items = {}
author_info = []

def insert_paper_info():
    global frame_paper_author_list, author_num_view, paper_add_items, author_info
    paper_id = paper_add_items["paper_id"].get()
    paper_name = paper_add_items["paper_name"].get()
    paper_source = paper_add_items["paper_source"].get()
    paper_date = paper_add_items["paper_date"].get()
    paper_type = type_map[paper_add_items["paper_type"].get()]
    paper_level = level_map[paper_add_items["paper_level"].get()]
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
        tk.messagebox.showerror(title='错误', message='论文编号不能为空！')
        return
    # 转换为int类型，转换失败则报错
    else:
        try:
            paper_id = int(paper_id)
        except ValueError:
            tk.messagebox.showerror(title='错误', message='论文编号必须为整数！')
            return
    # 论文名称不能为空
    if paper_name == '':
        tk.messagebox.showerror(title='错误', message='论文名称不能为空！')
        return
    # 论文来源不能为空
    if paper_source == '':
        tk.messagebox.showerror(title='错误', message='发表来源不能为空！')
        return
    # 论文发表日期需要合法，且需要可以转换为datetime类型
    if paper_date == '':
        tk.messagebox.showerror(title='错误', message='发表日期不能为空！')
        return
    else:
        try:
            paper_date = pd.to_datetime(paper_date).date()
        except ValueError:
            tk.messagebox.showerror(title='错误', message='发表日期不合法！')
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
        tk.messagebox.showerror(title='错误', message='作者列表不能全为不完整的信息！')
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
            tk.messagebox.showerror(title='错误', message='作者编号必须为正整数！')
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
                tk.messagebox.showerror(title='错误', message='作者编号必须为正整数！')
                return
            if author_id_list[i] == author_id_list[j]:
                tk.messagebox.showerror(title='错误', message='作者编号不能相同！')
                return
    # 检查是否有相同的排名
    for i in range(listnum):
        for j in range(i + 1, listnum):
            if author_rank_list[i] == author_rank_list[j]:
                tk.messagebox.showerror(title='错误', message='作者排名不能相同！')
                return
    # 检查是否有超过一个的通讯作者
    communicate_num = 0
    for i in range(listnum):
        if author_is_communicate_list[i] == 1:
            communicate_num += 1
    if communicate_num > 1:
        tk.messagebox.showerror(title='错误', message='通讯作者只能有一个！')
        return
    # 通过基本检查，开始插入数据
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
        print(e)
        exit(-1)
    # 插入论文信息
    cursor = db.cursor()
    val = (paper_id, paper_name, paper_source, paper_date, paper_type, paper_level)
    # 执行sql语句，插入论文信息并捕捉异常编号
    try:
        cursor.callproc('insert_paper', val)
        for i in range(listnum):
            cursor.callproc('insert_teacher_paper',
                            (author_id_list[i], author_name_list[i], paper_id, author_rank_list[i],
                             author_is_communicate_list[i]))
        db.commit()
    except sql.Error as e:
        db.rollback()
        tk.messagebox.showerror(title='错误', message=e.args[1])
        return
    db.close()


def create_frame_paper_author(frame_paper_info):
    global frame_paper_author_list, author_num_view
    if author_num_view >= 15:
        return
    if len(frame_paper_author_list) > author_num_view:
        frame_paper_author_list[author_num_view].pack(side='top', anchor='n')
        author_num_view += 1
        return
    frame_paper_author = tk.Frame(frame_paper_info, width=800, height=50)
    author_num_view += 1

    # 输入作者编号和排名
    entry_paper_author_id, entry_paper_author_rank = common.create_label_and_entry2(frame_paper_author, "作者" + str(
        author_num_view) + "编号", "", "作者" + str(author_num_view) + "排名", "")

    # 输入作者姓名和是否为通讯作者
    entry_paper_author_name, var_paper_author_is_communicate = common.create_label_and_entry_with_checkbutton(
        frame_paper_author, "作者" + str(author_num_view) + "姓名", "", "是否为通讯作者", 0)

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


def create_frame_paper_add(self):
    canvas_paper_add = tk.Canvas(self.root, width=800, height=1200, scrollregion=(0, 0, 1200, 800))
    frame_paper_add = tk.Frame(canvas_paper_add, width=800, height=1200)
    frame_paper_add.pack(side='top', anchor='n')
    canvas_paper_add.create_window(400, 0, anchor='n', window=frame_paper_add)
    self.frame_list["frame_paper_add"] = canvas_paper_add

    # 创建滚动条
    common.create_scrollbar(canvas_paper_add)

    # 创建label
    label_paper_name = tk.Label(frame_paper_add, text="论文信息登记", font=("宋体", 15))
    label_paper_name.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的论文信息
    frame_paper_info = tk.Frame(frame_paper_add, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')

    # 创建提交按钮
    button_paper_submit = tk.Button(frame_paper_info, text="提交", font=("宋体", 10), command=insert_paper_info)
    button_paper_submit.pack(side='top', anchor='e')

    # 论文编号
    paper_add_items["paper_id"] = common.create_label_and_entry(frame_paper_info, "论文编号", "")

    # 论文名称
    paper_add_items["paper_name"] = common.create_label_and_entry(frame_paper_info, "论文名称", "")

    # 论文来源
    paper_add_items["paper_source"] = common.create_label_and_entry(frame_paper_info, "论文来源", "")

    # 论文发表日期
    paper_add_items["paper_date"] = common.create_label_and_entry(frame_paper_info, "发表日期", "")

    # 论文类型，下拉菜单
    types = ["full-paper", "short-paper", "poster-paper", "demo-paper"]
    paper_add_items["paper_type"] = common.create_option_menu(frame_paper_info, "论文类型", types[0], types)

    # 论文级别， 下拉菜单
    levels = ["CCF-A", "CCF-B", "CCF-C", "中文 CCF-A", "中文 CCF-B", "无级别"]
    paper_add_items["paper_level"] = common.create_option_menu(frame_paper_info, "论文级别", levels[0], levels)

    # 论文作者信息：作者编号、作者姓名、作者排名、是否为通讯作者
    # 作者可能有多个，默认显示一个，点击按钮添加新的作者信息或删除新的对话框
    common.create_label_with_button2(frame_paper_info, "论文作者", "添加作者",
                                     lambda: create_frame_paper_author(frame_paper_info), "删除作者",
                                     lambda: delete_frame_paper_author())
    # 创建初始一个frame
    create_frame_paper_author(frame_paper_info)