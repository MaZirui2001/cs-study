import tkinter as tk
from tkinter import messagebox
import pymysql as sql
from paper import paper_check
import common as common

paper_del_items = {}
paper_check_items = {}
del_result_frame = []
detail_button_list = []
delete_button_list = []
frame_paper_check = None


def fresh(self):
    check_del_paper(self)


def delete_paper(self, paper_id):
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
    check_del_paper(self)


def check_del_paper(self):
    check_result, check_result_simple = paper_check.check_paper(paper_del_items)
    create_del_result_frame(self, check_result_simple, check_result)


def create_del_result_frame(self, check_result_simple, check_result):
    for frame in del_result_frame:
        frame.destroy()
    del_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=50)
        frame_paper_check_result.pack(side='top', anchor='w')
        del_result_frame.append(frame_paper_check_result)
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
        button_paper_detail = tk.Button(frame_paper_check_result, text="详情", width=8, height=1,
                                        command=lambda arg2=check_result[i]: paper_check.create_detail_check_top(self,
                                                                                                                 arg2))
        button_paper_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_paper_detail, i))
        # 删除按钮
        button_paper_delete = tk.Button(frame_paper_check_result, text="删除", width=8, height=1,
                                        command=lambda arg3=check_result[i][1]: delete_paper(self,
                                                                                             arg3))
        button_paper_delete.grid(row=0, column=5, padx=2)
        delete_button_list.append((button_paper_delete, i))


def create_frame_paper_delete(self):
    canvas_paper_del = tk.Canvas(self.root, width=800, height=1200, scrollregion=(0, 0, 800, 1200))
    global frame_paper_check
    frame_paper_check = tk.Frame(canvas_paper_del, width=800, height=1200)
    self.frame_list["frame_paper_delete"] = canvas_paper_del
    frame_paper_check.pack(side='top', anchor='n')
    canvas_paper_del.create_window(400, 0, anchor='n', window=frame_paper_check)

    # 创建滚动条
    common.create_scrollbar(canvas_paper_del)

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
    paper_del_items["paper_id"] = common.create_label_and_entry(frame_paper_info, "论文编号", "")

    # 论文名称
    paper_del_items["paper_name"] = common.create_label_and_entry(frame_paper_info, "论文名称", "")

    # 论文来源
    paper_del_items["paper_source"] = common.create_label_and_entry(frame_paper_info, "论文来源", "")

    # 论文发表日期
    paper_del_items["publish_time"] = common.create_label_and_entry(frame_paper_info, "发表日期", "")

    # 作者编号
    paper_del_items["author_id"] = common.create_label_and_entry(frame_paper_info, "作者编号", "")

    # 作者姓名
    paper_del_items["author_name"] = common.create_label_and_entry(frame_paper_info, "作者姓名", "")

    # 创建查询结果显示框
    frame_paper_check_result = tk.Frame(frame_paper_check, width=800, height=600)
    frame_paper_check_result.pack(side='top', anchor='n')
    button_paper_check.config(
        command=lambda: check_del_paper(self))

    # 创建查询结果显示框label
    label_paper_check_result = tk.Label(frame_paper_check_result, text="查询结果", font=("宋体", 15))
    label_paper_check_result.pack(side='top', anchor='n')

    frame_paper_check_label = tk.Frame(frame_paper_check_result, width=800, height=50)
    tk.Label(frame_paper_check_label, text="论文名称", font=("宋体", 10), width=20, height=2).grid(row=0, column=0)
    tk.Label(frame_paper_check_label, text="最高作者", font=("宋体", 10), width=20, height=2).grid(row=0, column=1)
    tk.Label(frame_paper_check_label, text="发表时间", font=("宋体", 10), width=20, height=2).grid(row=0, column=2)
    tk.Label(frame_paper_check_label, text="论文来源", font=("宋体", 10), width=20, height=2).grid(row=0, column=3)
    tk.Label(frame_paper_check_label, text="", font=("宋体", 10), width=10, height=2).grid(row=0, column=4, padx=2)
    tk.Label(frame_paper_check_label, text="", font=("宋体", 10), width=10, height=2).grid(row=0, column=5, padx=2)
    frame_paper_check_label.pack(side='top', anchor='n')
