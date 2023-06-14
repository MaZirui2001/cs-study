import tkinter as tk
from tkinter import messagebox
import ttkbootstrap as ttk
import pymysql as sql
import common as common
from common import proj_id2type
from project import proj_check
from project import proj_add

proj_mod_items = {}
proj_check_items = {}
mod_result_frame = []
detail_button_list = []
modify_button_list = []

frame_proj_teacher_list = []
teacher_num_view = 0
proj_add_items = {}
teacher_info = []

frame_check = None


def fresh(self):
    check_modify_proj(self)


def modify_proj_info(self, origin_proj_id, message_parent):
    # 总体思路：先删除原来的数据，再插入新的数据
    # 获取输入的项目信息
    global proj_add_items, teacher_info, teacher_num_view
    temp = proj_add.insert_info_get_and_check(proj_add_items, teacher_num_view, teacher_info, message_parent)
    if temp is None:
        return
    listnum, proj_id, proj_name, proj_source, proj_type, proj_expend, proj_start, proj_end, \
        teacher_id_list, teacher_name_list, teacher_rank_list, teacher_expend_list = temp
    # 通过基本检查，开始删除原有记录
    # 对话框：确认提交修改
    if not tk.messagebox.askyesno(title='确认', message='确认提交修改？', parent=message_parent):
        return
    # 删除项目记录
    delete_id = origin_proj_id
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
    val = (proj_id, proj_name, proj_source, proj_type, proj_expend, proj_start, proj_end)
    # 调用删除存储过程，同时插入
    try:
        cursor.callproc('delete_project', (delete_id,))
        cursor.callproc('insert_project', val)
        for i in range(listnum):
            cursor.callproc('insert_teacher_project',
                            (teacher_id_list[i], teacher_name_list[i], proj_id, teacher_rank_list[i],
                             teacher_expend_list[i]))
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
    check_modify_proj(self)


def create_frame_proj_teacher(frame_project_info, proj_teacher):
    global frame_proj_teacher_list, teacher_num_view
    if teacher_num_view >= 15:
        return
    if len(frame_proj_teacher_list) > teacher_num_view:
        frame_proj_teacher_list[teacher_num_view].pack(side='top', anchor='n')
        teacher_num_view += 1
        return
    frame_project_teacher = ttk.Frame(frame_project_info, width=800, height=50)
    teacher_num_view += 1

    # 输入员工编号和排名
    entry_project_teacher_id, entry_project_teacher_rank = common.create_label_and_entry2(
        frame_project_teacher, "员工" + str(teacher_num_view) + "编号", proj_teacher[1],
                               "员工" + str(teacher_num_view) + "排名", proj_teacher[2])

    # 输入作者姓名和是否为通讯作者
    entry_project_teacher_name, entry_project_expenditure = common.create_label_and_entry2(
        frame_project_teacher, "员工" + str(teacher_num_view) + "姓名", proj_teacher[0],
                               "员工" + str(teacher_num_view) + "经费", proj_teacher[3])

    frame_project_teacher.pack(side='top', anchor='n')
    frame_proj_teacher_list.append(frame_project_teacher)

    teacher_info.append(
        {'id': entry_project_teacher_id, 'name': entry_project_teacher_name, 'rank': entry_project_teacher_rank,
         'expend': entry_project_expenditure})


def delete_frame_proj_teacher():
    global frame_proj_teacher_list, teacher_num_view
    if teacher_num_view <= 1:
        return
    frame_proj_teacher_list[teacher_num_view - 1].pack_forget()
    teacher_num_view -= 1
    return teacher_num_view


def create_modify_window(self, check_item):
    # 创建新窗口
    window_modify = ttk.Toplevel(self.root, minsize=(1600, 1200))
    window_modify.title("修改项目信息")
    window_modify.resizable(False, False)
    self.root.attributes("-disabled", True)
    window_modify.protocol("WM_DELETE_WINDOW", lambda: common.close_window(self.root, window_modify))
    # 获取当前项目信息
    proj_teachers = check_item[7]

    canvas_proj_add = ttk.Canvas(window_modify, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_proj_add = ttk.Frame(canvas_proj_add, width=800, height=1200)
    canvas_proj_add.pack(side='top', anchor='center', fill='both', expand=1)
    frame_proj_add.pack(side='top', anchor='n')
    canvas_proj_add.create_window(820, 0, anchor='n', window=frame_proj_add)

    frame_proj_info, button_submit = proj_add.create_basic_info(self, canvas_proj_add, frame_proj_add, proj_add_items, check_item)
    button_submit.config(command=lambda: modify_proj_info(self, check_item[1], window_modify))
    # 项目员工信息：员工编号、员工姓名、员工排名、是否为通讯员工
    # 员工可能有多个，默认显示一个，点击按钮添加新的员工信息或删除新的对话框
    common.create_label_with_button2(frame_proj_info, "项目员工", "添加员工",
                                     lambda: create_frame_proj_teacher(frame_proj_info, ["", "", "", ""]),
                                     "删除员工", lambda: delete_frame_proj_teacher())

    global teacher_num_view, frame_proj_teacher_list, teacher_info
    teacher_num_view = 0
    for frame in frame_proj_teacher_list:
        frame.pack_forget()
    frame_proj_teacher_list.clear()
    teacher_info.clear()
    for teacher in proj_teachers:
        create_frame_proj_teacher(frame_proj_info, teacher)


def check_modify_proj(self):
    check_result, check_result_simple = proj_check.check_proj(proj_mod_items)
    create_modify_result_frame(self, check_result_simple, check_result)


def create_modify_result_frame(self, check_result_simple, check_result):
    for frame in mod_result_frame:
        frame.destroy()
    mod_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_proj_check_result = ttk.Frame(frame_check, width=800, height=50)
        frame_proj_check_result.pack(side='top', anchor='w')
        mod_result_frame.append(frame_proj_check_result)
        # 显示四栏：项目名称、最高员工、发表时间、项目来源, 用Text组件, 每一个后面跟一个详情按钮和一个删除按钮
        # 项目名称
        common.create_text(frame_proj_check_result, str(check_result_simple[i][0]), 1, 0, 18)
        # 最高员工
        common.create_text(frame_proj_check_result, str(check_result_simple[i][1]), 1, 1, 18)
        # 项目来源
        common.create_text(frame_proj_check_result, str(check_result_simple[i][2]), 1, 2, 18)
        # 项目类型
        common.create_text(frame_proj_check_result, proj_id2type[int(check_result_simple[i][3])], 1, 3, 18)
        # 详情按钮
        button_proj_detail = ttk.Button(frame_proj_check_result, text="详情", width=5, style='success',
                                        command=lambda arg2=check_result[i]: proj_check.create_detail_check_top(self,
                                                                                                                arg2))
        button_proj_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_proj_detail, i))
        # 修改按钮
        button_proj_modify = ttk.Button(frame_proj_check_result, text="修改", width=5, style='warning',
                                        command=lambda arg1=self, arg2=check_result[i]:
                                        create_modify_window(arg1, arg2))
        button_proj_modify.grid(row=0, column=5, padx=2)
        modify_button_list.append((button_proj_modify, i))


def create_frame_proj_modify(self):
    canvas_proj_mod = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    global frame_check
    frame_check = ttk.Frame(canvas_proj_mod, width=800, height=1200)
    self.frame_list["frame_proj_modify"] = canvas_proj_mod
    frame_check.pack(side='top', anchor='n')
    canvas_proj_mod.create_window(820, 0, anchor='n', window=frame_check)

    frame_proj_check_label= proj_check.create_basic_info_frame(self, canvas_proj_mod, proj_mod_items,
                                                            check_modify_proj, frame_check, "项目信息修改")
    ttk.Label(frame_proj_check_label, text="", font=("宋体", 10), width=10).grid(row=0, column=4, padx=2)
    frame_proj_check_label.pack(side='top', anchor='n')
