import tkinter as tk
from tkinter import messagebox
import ttkbootstrap as ttk
import pymysql as sql
import common as common
from common import course_semester_map, course_id2semester, course_id2type
from course import course_check
from course import course_add

course_mod_items = {}
course_check_items = {}
mod_result_frame = []
detail_button_list = []
modify_button_list = []

frame_course_teacher_list = []
teacher_num_view = 0
course_add_items = {}
teacher_info = []

frame_check = None


def fresh(self):
    check_modify_course(self)


def modify_course_info(self, origin_course_id, message_parent):
    # 总体思路：先删除原来的数据，再插入新的数据
    # 获取输入的课程信息
    global course_add_items, teacher_info, teacher_num_view
    temp = course_add.insert_info_get_and_check(course_add_items, teacher_num_view, teacher_info, message_parent)
    if temp is None:
        return
    listnum, course_id, course_name, course_hour, course_type, teacher_id_list, \
        teacher_name_list, teacher_year_list, teacher_seme_list, teacher_hour_list = temp
    # print(listnum, course_id, course_name, course_source, course_date, course_type, course_level)
    # 通过基本检查，开始删除原有记录
    # 对话框：确认提交修改
    if not tk.messagebox.askyesno(title='确认', message='确认提交修改？', parent=message_parent):
        return
    # 删除课程记录
    delete_id = origin_course_id
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
    val = (course_id, course_name, course_hour, course_type)
    # 调用删除存储过程，同时插入
    try:
        cursor.callproc('delete_course', (delete_id,))
        cursor.callproc('insert_course', val)
        for i in range(listnum):
            cursor.callproc('insert_teacher_course',
                            (teacher_id_list[i], teacher_name_list[i], course_id, teacher_year_list[i],
                             course_semester_map[teacher_seme_list[i]], teacher_hour_list[i]))
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
    check_modify_course(self)


def create_frame_course_teacher(frame_course_info, course_teacher):
    global frame_course_teacher_list, teacher_num_view
    if teacher_num_view >= 15:
        return
    if len(frame_course_teacher_list) > teacher_num_view:
        frame_course_teacher_list[teacher_num_view].pack(side='top', anchor='n')
        teacher_num_view += 1
        return
    frame_course_teacher = ttk.Frame(frame_course_info, width=800, height=50)
    teacher_num_view += 1

    # 输入教师编号和承担学时
    entry_course_teacher_id, entry_course_teacher_hour = common.create_label_and_entry2(
        frame_course_teacher, "教师" + str(teacher_num_view) + "编号", course_teacher[1], "承担学时", course_teacher[2])

    # 输入教师姓名和开课年份
    entry_course_teacher_name, entry_course_year = common.create_label_and_entry2(
        frame_course_teacher, "教师" + str(teacher_num_view) + "姓名", course_teacher[0], "开课年份", course_teacher[3])
    # 输入开课学期
    seme = ['none', '春季学期', '夏季学期', '秋季学期']
    menu_course_teacher_seme = common.create_option_menu(frame_course_teacher, "开课学期",
                                                         course_id2semester[course_teacher[4]], seme)
    frame_course_teacher.pack(side='top', anchor='n')
    frame_course_teacher_list.append(frame_course_teacher)

    teacher_info.append(
        {'id': entry_course_teacher_id, 'name': entry_course_teacher_name, 'hour': entry_course_teacher_hour,
         'year': entry_course_year, 'seme': menu_course_teacher_seme})


def delete_frame_course_teacher():
    global frame_course_teacher_list, teacher_num_view
    if teacher_num_view <= 1:
        return
    frame_course_teacher_list[teacher_num_view - 1].pack_forget()
    teacher_num_view -= 1


def create_modify_window(self, check_item):
    # 创建新窗口
    window_modify = ttk.Toplevel(self.root, minsize=(1600, 1200))
    window_modify.title("修改课程信息")
    self.root.attributes("-disabled", True)
    window_modify.protocol("WM_DELETE_WINDOW", lambda: common.close_window(self.root, window_modify))
    # window_modify.resizable(False, False)
    # 获取当前课程信息
    course_teachers = []
    for key in check_item[4].keys():
        for i in range(len(check_item[4][key])):
            course_teachers.append(check_item[4][key][i] + (int(key.split(" ")[0]), int(key.split(" ")[1])))

    canvas_course_add = ttk.Canvas(window_modify, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_course_add = ttk.Frame(canvas_course_add, width=800, height=1200)
    canvas_course_add.pack(side='top', anchor='center', fill='both', expand=1)
    frame_course_add.pack(side='top', anchor='n')
    canvas_course_add.create_window(820, 0, anchor='n', window=frame_course_add)

    frame_course_info, button_submit = course_add.create_basic_info(self, canvas_course_add, frame_course_add,
                                                                    course_add_items, check_item)
    button_submit.config(command=lambda: modify_course_info(self, check_item[1], window_modify))
    # 课程作者信息：作者编号、作者姓名、作者排名、是否为通讯作者
    # 作者可能有多个，默认显示一个，点击按钮添加新的作者信息或删除新的对话框
    common.create_label_with_button2(frame_course_info, "课程教师", "添加教师",
                                     lambda: create_frame_course_teacher(frame_course_info, ['', '', '', "", 1]),
                                     "删除教师", lambda: delete_frame_course_teacher())

    global teacher_num_view, frame_course_teacher_list, teacher_info
    teacher_num_view = 0
    for frame in frame_course_teacher_list:
        frame.pack_forget()
    frame_course_teacher_list.clear()
    teacher_info.clear()

    for teacher in course_teachers:
        create_frame_course_teacher(frame_course_info, teacher)


def check_modify_course(self):
    check_result, check_result_simple = course_check.check_course(course_mod_items)
    create_modify_result_frame(self, check_result_simple, check_result)


def create_modify_result_frame(self, check_result_simple, check_result):
    for frame in mod_result_frame:
        frame.destroy()
    mod_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_course_check_result = ttk.Frame(frame_check, width=800, height=50)
        frame_course_check_result.pack(side='top', anchor='w')
        mod_result_frame.append(frame_course_check_result)
        # 显示四栏：课程编号、课程名称、课程学时、课程类型, 用Text组件, 每一个后面跟一个详情按钮
        # 课程编号
        common.create_text(frame_course_check_result, str(check_result_simple[i][0]), 1, 0, 18)
        # 课程名称
        common.create_text(frame_course_check_result, str(check_result_simple[i][1]), 1, 1, 18)
        # 课程学时
        common.create_text(frame_course_check_result, str(check_result_simple[i][2]), 1, 2, 18)
        # 课程类型
        common.create_text(frame_course_check_result, course_id2type[int(check_result_simple[i][3])], 1, 3, 18)
        # 详情按钮
        button_course_detail = ttk.Button(frame_course_check_result, text="详情", width=5, style='success',
                                          command=lambda arg1=self, arg2=check_result[i]:
                                          course_check.create_detail_check_top(arg1, arg2))
        button_course_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_course_detail, i))
        # 修改按钮
        button_course_modify = ttk.Button(frame_course_check_result, text="修改", width=5, style='warning',
                                          command=lambda arg1=self, arg2=check_result[i]:
                                          create_modify_window(arg1, arg2))
        button_course_modify.grid(row=0, column=5, padx=2)
        modify_button_list.append((button_course_modify, i))


def create_frame_course_modify(self):
    canvas_course_mod = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    global frame_check
    frame_check = ttk.Frame(canvas_course_mod, width=800, height=1200)
    self.frame_list["frame_course_modify"] = canvas_course_mod
    frame_check.pack(side='top', anchor='n')
    canvas_course_mod.create_window(820, 0, anchor='n', window=frame_check)
    frame_course_check_label = course_check.create_basic_info_frame(self, canvas_course_mod, course_mod_items,
                                                                    check_modify_course, frame_check, "课程信息修改")
    ttk.Label(frame_course_check_label, text="", font=("宋体", 10), width=10).grid(row=0, column=4, padx=2)
    frame_course_check_label.pack(side='top', anchor='n')
