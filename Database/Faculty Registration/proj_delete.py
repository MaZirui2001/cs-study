import tkinter as tk
from tkinter import messagebox
import pymysql as sql
import proj_check
import common as common
from common import proj_id2type

proj_del_items = {}
proj_check_items = {}
del_result_frame = []
detail_button_list = []
delete_button_list = []
frame_proj_check = None


def fresh(self):
    check_del_proj(self)


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
    check_del_proj(self)


def check_del_proj(self):
    check_result, check_result_simple = proj_check.check_proj()
    create_del_result_frame(self, check_result_simple, check_result)


def create_del_result_frame(self, check_result_simple, check_result):
    for frame in del_result_frame:
        frame.destroy()
    del_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_proj_check_result = tk.Frame(frame_proj_check, width=800, height=50)
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
        button_proj_detail = tk.Button(frame_proj_check_result, text="详情", width=8, height=1,
                                       command=lambda arg2=check_result[i]: proj_check.create_detail_check_top(self,
                                                                                                               arg2))
        button_proj_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_proj_detail, i))
        # 删除按钮
        button_proj_delete = tk.Button(frame_proj_check_result, text="删除", width=8, height=1,
                                       command=lambda arg3=check_result[i][1]: delete_proj(self, arg3))
        button_proj_delete.grid(row=0, column=5, padx=2)
        delete_button_list.append((button_proj_delete, i))


def create_frame_proj_delete(self):
    canvas_proj_del = tk.Canvas(self.root, width=800, height=1200, scrollregion=(0, 0, 800, 1200))
    global frame_proj_check
    frame_proj_check = tk.Frame(canvas_proj_del, width=800, height=1200)
    self.frame_list["frame_proj_delete"] = canvas_proj_del
    frame_proj_check.pack(side='top', anchor='n')
    canvas_proj_del.create_window(400, 0, anchor='n', window=frame_proj_check)

    # 创建滚动条
    common.create_scrollbar(canvas_proj_del)

    # 创建label
    label_proj_name = tk.Label(frame_proj_check, text="项目信息删除", font=("宋体", 15))
    label_proj_name.pack(side='top', anchor='n')

    # 创建查询按钮
    button_proj_check = tk.Button(frame_proj_check, text="查询", width=10, height=1)
    button_proj_check.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的项目信息
    frame_proj_info = tk.Frame(frame_proj_check, width=200, height=600)
    frame_proj_info.pack(side='top', anchor='n')

    # 项目编号
    proj_del_items["proj_id"] = common.create_label_and_entry(frame_proj_info, "项目编号", "")

    # 项目名称
    proj_del_items["proj_name"] = common.create_label_and_entry(frame_proj_info, "项目名称", "")

    # 项目来源
    proj_del_items["proj_source"] = common.create_label_and_entry(frame_proj_info, "项目来源", "")

    # 员工编号
    proj_del_items["teacher_id"] = common.create_label_and_entry(frame_proj_info, "员工编号", "")

    # 员工姓名
    proj_del_items["teacher_name"] = common.create_label_and_entry(frame_proj_info, "员工姓名", "")

    # 创建查询结果显示框
    frame_proj_check_result = tk.Frame(frame_proj_check, width=800, height=600)
    frame_proj_check_result.pack(side='top', anchor='n')
    button_proj_check.config(
        command=lambda: check_del_proj(self))

    # 创建查询结果显示框label
    label_proj_check_result = tk.Label(frame_proj_check_result, text="查询结果", font=("宋体", 15))
    label_proj_check_result.pack(side='top', anchor='n')

    frame_proj_check_label = tk.Frame(frame_proj_check_result, width=800, height=50)
    tk.Label(frame_proj_check_label, text="项目名称", font=("宋体", 10), width=20, height=2).grid(row=0, column=0)
    tk.Label(frame_proj_check_label, text="最高员工", font=("宋体", 10), width=20, height=2).grid(row=0, column=1)
    tk.Label(frame_proj_check_label, text="项目来源", font=("宋体", 10), width=20, height=2).grid(row=0, column=2)
    tk.Label(frame_proj_check_label, text="项目类型", font=("宋体", 10), width=20, height=2).grid(row=0, column=3)
    tk.Label(frame_proj_check_label, text="", font=("宋体", 10), width=10, height=2).grid(row=0, column=4, padx=2)
    tk.Label(frame_proj_check_label, text="", font=("宋体", 10), width=10, height=2).grid(row=0, column=5, padx=2)
    frame_proj_check_label.pack(side='top', anchor='n')
