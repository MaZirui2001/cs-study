import tkinter as tk
from tkinter import messagebox
import ttkbootstrap as ttk
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
        frame_paper_check_result = ttk.Frame(frame_paper_check, width=800, height=50)
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
        button_paper_detail = ttk.Button(frame_paper_check_result, text="详情", width=5, style="success",
                                         command=lambda arg2=check_result[i]: paper_check.create_detail_check_top(self,
                                                                                                                  arg2))
        button_paper_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_paper_detail, i))
        # # 删除按钮
        button_paper_delete = ttk.Button(frame_paper_check_result, text="删除", width=5, style="danger",
                                         command=lambda arg3=check_result[i][1]: delete_paper(self,
                                                                                              arg3))
        button_paper_delete.grid(row=0, column=5, padx=2)
        delete_button_list.append((button_paper_delete, i))


def create_frame_paper_delete(self):
    canvas_paper_del = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    global frame_paper_check
    frame_paper_check = ttk.Frame(canvas_paper_del, width=800, height=1200)
    self.frame_list["frame_paper_delete"] = canvas_paper_del
    frame_paper_check.pack(side='top', anchor='n')
    canvas_paper_del.create_window(820, 0, anchor='n', window=frame_paper_check)

    frame_paper_check_label = paper_check.create_basic_info_frame(self, canvas_paper_del, paper_del_items,
                                                                  check_del_paper, frame_paper_check,
                                                                  name="论文信息删除", width=18)
    # ttk.Label(frame_paper_check_label, text="", font=("宋体", 10), width=10).grid(row=0, column=5)
    frame_paper_check_label.pack(side='top', anchor='n')
