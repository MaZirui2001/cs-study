import tkinter as tk
import ttkbootstrap as ttk
from tkinter import messagebox
import pymysql as sql
import common as common
from paper import paper_check
from paper import paper_add

paper_mod_items = {}
paper_check_items = {}
mod_result_frame = []
detail_button_list = []
modify_button_list = []

frame_paper_author_list = []
author_num_view = 0
paper_add_items = {}
author_info = []

frame_paper_check = None


def fresh(self):
    check_modify_paper(self)


def modify_paper_info(self, origin_paper_id, message_parent):
    # 总体思路：先删除原来的数据，再插入新的数据
    # 获取输入的论文信息
    global paper_add_items, author_info, author_num_view
    temp = paper_add.insert_info_get_and_check(paper_add_items, author_num_view, author_info, message_parent)
    if temp is None:
        return
    listnum, paper_id, paper_name, paper_source, paper_date, paper_type, paper_level, \
        author_id_list, author_name_list, author_rank_list, \
        author_is_communicate_list = temp
    # print(paper_id)
    # print(listnum, paper_id, paper_name, paper_source, paper_date, paper_type, paper_level)
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
    check_modify_paper(self)


def create_frame_paper_author(frame_paper_info, paper_author):
    global frame_paper_author_list, author_num_view
    if author_num_view >= 10:
        return
    if len(frame_paper_author_list) > author_num_view:
        frame_paper_author_list[author_num_view].pack(side='top', anchor='n')
        author_num_view += 1
        return

    frame_paper_author = ttk.Frame(frame_paper_info, width=800, height=50)
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


def close_window(root, window):
    root.attributes("-disabled", False)
    window.destroy()


def create_modify_window(self, check_item):
    # 创建新窗口
    window_modify = ttk.Toplevel(self.root, minsize=(1600, 1200))
    window_modify.title("修改论文信息")
    window_modify.resizable(False, True)
    self.root.attributes("-disabled", True)
    window_modify.protocol("WM_DELETE_WINDOW", lambda: common.close_window(self.root, window_modify))
    # 获取当前论文信息
    paper_authors = check_item[6]

    canvas_paper_add = ttk.Canvas(window_modify, width=800, height=1200, scrollregion=(0, 0, 1200, 800))
    frame_paper_add = ttk.Frame(canvas_paper_add, width=800, height=1200)
    canvas_paper_add.pack(side='top', anchor='center', fill='both', expand=1)
    frame_paper_add.pack(side='top', anchor='n')
    canvas_paper_add.create_window(820, 0, anchor='n', window=frame_paper_add)

    frame_paper_info, button_submit = paper_add.create_basic_info(self, canvas_paper_add, frame_paper_add, paper_add_items, check_item)
    button_submit.config(command=lambda: modify_paper_info(self, check_item[1], window_modify))
    # 论文作者信息：作者编号、作者姓名、作者排名、是否为通讯作者
    # 作者可能有多个，默认显示一个，点击按钮添加新的作者信息或删除新的对话框
    common.create_label_with_button2(frame_paper_info, "论文作者", "添加作者",
                                     lambda: create_frame_paper_author(frame_paper_info, ["", "", "", 0]),
                                     "删除作者", lambda: delete_frame_paper_author())

    global author_num_view, frame_paper_author_list, author_info
    author_num_view = 0
    for frame in frame_paper_author_list:
        frame.pack_forget()
    frame_paper_author_list.clear()
    author_info.clear()
    for author in paper_authors:
        create_frame_paper_author(frame_paper_info, author)


def check_modify_paper(self):
    check_result, check_result_simple = paper_check.check_paper(paper_mod_items)
    create_modify_result_frame(self, check_result_simple, check_result)


def create_modify_result_frame(self, check_result_simple, check_result):
    for frame in mod_result_frame:
        frame.destroy()
    mod_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_paper_check_result = ttk.Frame(frame_paper_check, width=800, height=50)
        frame_paper_check_result.pack(side='top', anchor='w')
        mod_result_frame.append(frame_paper_check_result)
        # 显示四栏：论文名称、最高作者、发表时间、论文来源, 用Text组件, 每一个后面跟一个详情按钮和一个删除按钮
        # 论文名称
        common.create_text(frame_paper_check_result, str(check_result_simple[i][0]), 1, 0, 18)
        # 最高作者
        common.create_text(frame_paper_check_result, str(check_result_simple[i][1]), 1, 1, 18)
        # 发表时间
        common.create_text(frame_paper_check_result, str(check_result_simple[i][2]), 1, 2, 18)
        # 论文来源
        common.create_text(frame_paper_check_result, str(check_result_simple[i][3]), 1, 3, 18)
        # 详情按钮
        button_paper_detail = ttk.Button(frame_paper_check_result, text="详情", width=5, style='success',
                                         command=lambda arg2=check_result[i]: paper_check.create_detail_check_top(self,
                                                                                                                  arg2))
        button_paper_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_paper_detail, i))
        # 修改按钮
        button_paper_modify = ttk.Button(frame_paper_check_result, text="修改", width=5, style='warning',
                                         command=lambda arg1=self, arg2=check_result[i]:
                                         create_modify_window(arg1, arg2))
        button_paper_modify.grid(row=0, column=5, padx=2)
        modify_button_list.append((button_paper_modify, i))


def create_frame_paper_modify(self):
    canvas_paper_mod = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    global frame_paper_check
    frame_paper_check = ttk.Frame(canvas_paper_mod, width=800, height=1200)
    self.frame_list["frame_paper_modify"] = canvas_paper_mod
    frame_paper_check.pack(side='top', anchor='n')
    canvas_paper_mod.create_window(820, 0, anchor='n', window=frame_paper_check)
    frame_paper_check_label = paper_check.create_basic_info_frame(self, canvas_paper_mod, paper_mod_items,
                                                                  check_modify_paper, frame_paper_check, "论文信息修改",
                                                                  18)
    frame_paper_check_label.pack(side='top', anchor='n')
