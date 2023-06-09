import tkinter as tk
from tkinter import messagebox
import ttkbootstrap as ttk
import pymysql as sql
from project import proj_check
import common as common
from common import proj_id2type

proj_del_items = {}
proj_check_items = {}
del_result_frame = []
detail_button_list = []
delete_button_list = []
frame_check = None


def fresh(self):
    create_check_del_proj(self)


def delete_proj(self, proj_id):
    # 弹窗并确认是否删除
    if not messagebox.askyesno("确认", "确认删除这篇项目？"):
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
        cursor.callproc("delete_project", (proj_id,))
        db.commit()
    except sql.Error as e:
        db.rollback()
        db.close()
        print("删除失败：" + str(e))
        exit(-1)
    db.close()
    messagebox.showinfo("成功", "删除成功")
    # 刷新页面
    create_check_del_proj(self)


def create_check_del_proj(self):
    check_result, check_result_simple = proj_check.check_proj(proj_del_items)
    create_del_result_frame(self, check_result_simple, check_result)


def create_del_result_frame(self, check_result_simple, check_result):
    for frame in del_result_frame:
        frame.destroy()
    del_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_proj_check_result = ttk.Frame(frame_check, width=800, height=50)
        frame_proj_check_result.pack(side='top', anchor='w')
        del_result_frame.append(frame_proj_check_result)
        # 显示四栏：项目名称、最高员工、发表时间、项目来源, 用Text组件, 每一个后面跟一个详情按钮和一个删除按钮
        # 项目名称
        common.create_text(frame_proj_check_result, str(check_result_simple[i][0]), 1, 0, 18)
        # 最高员工
        common.create_text(frame_proj_check_result, str(check_result_simple[i][1]), 1, 1, 18)
        # 发表时间
        common.create_text(frame_proj_check_result, str(check_result_simple[i][2]), 1, 2, 18)
        # 项目来源
        common.create_text(frame_proj_check_result, proj_id2type[int(check_result_simple[i][3])], 1, 3, 18)
        # 详情按钮
        button_proj_detail = ttk.Button(frame_proj_check_result, text="详情", width=5, style='success',
                                        command=lambda arg2=check_result[i]: proj_check.create_detail_check_top(self,
                                                                                                                arg2))
        button_proj_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_proj_detail, i))
        # 删除按钮
        button_proj_delete = ttk.Button(frame_proj_check_result, text="删除", width=5, style='danger',
                                        command=lambda arg3=check_result[i][1]: delete_proj(self, arg3))
        button_proj_delete.grid(row=0, column=5, padx=2)
        delete_button_list.append((button_proj_delete, i))


def create_frame_proj_delete(self):
    global frame_check, proj_del_items
    canvas_proj_del = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_check = ttk.Frame(canvas_proj_del, width=800, height=1200)
    self.frame_list["frame_proj_delete"] = canvas_proj_del
    frame_check.pack(side='top', anchor='n')
    canvas_proj_del.create_window(820, 0, anchor='n', window=frame_check)

    frame_proj_check_label = proj_check.create_basic_info_frame(self, canvas_proj_del, proj_del_items,
                                                                create_check_del_proj, frame_check, "项目信息删除")
    ttk.Label(frame_proj_check_label, text="", font=("宋体", 10), width=10).grid(row=0, column=4, padx=2)
