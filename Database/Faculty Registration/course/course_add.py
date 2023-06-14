import tkinter as tk
from tkinter import messagebox
import ttkbootstrap as ttk
import pymysql as sql
import pandas as pd
import common
from common import course_type_map, course_semester_map, course_id2type

frame_course_teacher_list = []
teacher_num_view = 0
course_add_items = {}
teacher_info = []


def fresh(self):
    pass


def insert_info_get_and_check(course_add_items_local, teacher_num, teacher_info_local, message_parent):
    course_id = course_add_items_local["course_id"].get().strip()
    course_name = course_add_items_local["course_name"].get().strip()
    course_type = course_type_map[course_add_items_local["course_type"].get().strip()]
    course_hour = course_add_items_local["course_hour"].get().strip()
    teacher_id_list = []
    teacher_name_list = []
    teacher_year_list = []
    teacher_seme_list = []
    teacher_hour_list = []
    for i in range(teacher_num):
        teacher_id_list.append(teacher_info_local[i]['id'].get().strip())
        teacher_name_list.append(teacher_info_local[i]['name'].get().strip())
        teacher_year_list.append(teacher_info_local[i]['year'].get().strip())
        teacher_seme_list.append(teacher_info_local[i]['seme'].get().strip())
        teacher_hour_list.append(teacher_info_local[i]['hour'].get().strip())

    # 课程编号不能为空
    if course_id == '':
        tk.messagebox.showerror(title='错误', message='课程编号不能为空！', parent=message_parent)
        return None
    course_id = str(course_id)
    # 课程名称不能为空
    if course_name == '':
        tk.messagebox.showerror(title='错误', message='课程名称不能为空！', parent=message_parent)
        return None
    # 课程总学时需要合法
    if course_hour == '':
        tk.messagebox.showerror(title='错误', message='课程总学时不能为空！', parent=message_parent)
        return None
    else:
        try:
            course_hour = int(course_hour)
            if course_hour <= 0:
                raise ValueError
        except ValueError:
            tk.messagebox.showerror(title='错误', message='课程总学时必须为正整数！', parent=message_parent)
            return None
    # 检查员工列表是否有空值
    listnum = teacher_num
    temp_id_list = []
    temp_name_list = []
    temp_year_list = []
    temp_seme_list = []
    temp_hour_list = []
    for i in range(teacher_num):
        if teacher_id_list[i] == '' or teacher_name_list[i] == '' or teacher_hour_list[i] == '' \
                or teacher_year_list[i] == '':
            listnum -= 1
        else:
            temp_id_list.append(teacher_id_list[i])
            temp_name_list.append(teacher_name_list[i])
            temp_year_list.append(teacher_year_list[i])
            temp_seme_list.append(teacher_seme_list[i])
            temp_hour_list.append(teacher_hour_list[i])
    if listnum == 0:
        tk.messagebox.showerror(title='错误', message='教师列表不能全为不完整的信息！', parent=message_parent)
        return None
    teacher_id_list = temp_id_list
    teacher_name_list = temp_name_list
    teacher_year_list = temp_year_list
    teacher_seme_list = temp_seme_list
    teacher_hour_list = temp_hour_list

    # 检查开课年份应该是年份
    for i in range(listnum):
        try:
            teacher_year_list[i] = pd.to_datetime(teacher_year_list[i]).year
        except ValueError:
            tk.messagebox.showerror(title='错误', message='开课年份不合法！', parent=message_parent)
            return None
    # 检查教师学时应该为正整数
    for i in range(listnum):
        try:
            teacher_hour_list[i] = int(teacher_hour_list[i])
            if teacher_hour_list[i] <= 0:
                raise ValueError
        except ValueError:
            tk.messagebox.showerror(title='错误', message='教师承担学时必须为正整数！', parent=message_parent)
            return None
    # 检查一门课程每个学期的所有教师的学时总和应该等于课程总学时
    time_list = {}
    for i in range(listnum):
        key = str(teacher_year_list[i]) + '年' + teacher_seme_list[i]
        if key in time_list:
            time_list[key] += teacher_hour_list[i]
        else:
            time_list[key] = teacher_hour_list[i]
    for item in time_list:
        if time_list[item] != course_hour:
            tk.messagebox.showerror(title='错误', message='开课年份为' + item + '的教师学时总和不等于课程总学时！',
                                    parent=message_parent)
            return None

    return listnum, course_id, course_name, course_hour, course_type, teacher_id_list, \
        teacher_name_list, teacher_year_list, teacher_seme_list, teacher_hour_list


def insert_paper_info(message_parent):
    global frame_course_teacher_list, teacher_num_view, course_add_items, teacher_info
    temp = insert_info_get_and_check(course_add_items, teacher_num_view, teacher_info, message_parent)
    if temp is None:
        return
    listnum, course_id, course_name, course_hour, course_type, teacher_id_list, \
        teacher_name_list, teacher_year_list, teacher_seme_list, teacher_hour_list = temp
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
    # 插入课程信息
    cursor = db.cursor()
    val = (course_id, course_name, course_hour, course_type)
    # 执行sql语句，插入课程信息并捕捉异常编号
    try:
        cursor.callproc('insert_course', val)
        for i in range(listnum):
            cursor.callproc('insert_teacher_course',
                            (teacher_id_list[i], teacher_name_list[i], course_id, teacher_year_list[i],
                             course_semester_map[teacher_seme_list[i]], teacher_hour_list[i]))
        db.commit()
    except sql.Error as e:
        db.rollback()
        tk.messagebox.showerror(title='错误', message=e.args[1])
        return
    db.close()
    # 提示插入成功， 需要点击确认
    tk.messagebox.showinfo(title='成功', message='插入成功！')


def create_frame_course_teacher(frame_course_info):
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
        frame_course_teacher, "教师" + str(teacher_num_view) + "编号", "", "承担学时", "")

    # 输入教师姓名和开课年份
    entry_course_teacher_name, entry_course_year = common.create_label_and_entry2(
        frame_course_teacher, "教师" + str(teacher_num_view) + "姓名", "", "开课年份", "")
    # 输入开课学期
    seme = ['none', '春季学期', '夏季学期', '秋季学期']
    menu_course_teacher_seme = common.create_option_menu(frame_course_teacher, "开课学期", seme[1], seme)
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


def create_basic_info(self, canvas_course_add, frame_course_add, course_items, check_item):
    # 创建滚动条
    common.create_scrollbar(canvas_course_add)

    # 创建label
    label_course_name = ttk.Label(frame_course_add, text="课程信息登记", font=("微软雅黑", 15, 'bold'))
    label_course_name.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的课程信息
    frame_course_info = ttk.Frame(frame_course_add, width=200, height=600)
    frame_course_info.pack(side='top', anchor='n')

    # 创建提交按钮
    button_course_submit = ttk.Button(frame_course_info, text="提交", style='success')

    button_course_submit.pack(side='top', anchor='e')

    # 课程编号

    course_items["course_id"] = common.create_label_and_entry(frame_course_info, "课程编号", check_item[1])

    # 课程名称
    course_items["course_name"] = common.create_label_and_entry(frame_course_info, "课程名称", check_item[0])

    # 课程学时
    course_items["course_hour"] = common.create_label_and_entry(frame_course_info, "课程学时", check_item[3])

    # 课程类型
    types = ['none', '本科生课程', '研究生课程']
    course_items["course_type"] = common.create_option_menu(frame_course_info, "课程类型",
                                                            course_id2type[int(check_item[2])], types)
    return frame_course_info, button_course_submit


def create_frame_course_add(self):
    canvas_course_add = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_course_add = ttk.Frame(canvas_course_add, width=800, height=1200)
    frame_course_add.pack(side='top', anchor='n')
    canvas_course_add.create_window(820, 0, anchor='n', window=frame_course_add)
    self.frame_list["frame_course_add"] = canvas_course_add
    frame_course_info, button_submit = create_basic_info(self, canvas_course_add, frame_course_add, course_add_items, ["", "", 1, ""])

    button_submit.config(command=lambda: insert_paper_info(self.root))
    # 课程员工信息：员工编号、员工姓名、员工排名、是否为通讯员工
    # 员工可能有多个，默认显示一个，点击按钮添加新的员工信息或删除新的对话框
    common.create_label_with_button2(frame_course_info, "课程教师", "添加教师",
                                     lambda: create_frame_course_teacher(frame_course_info), "删除教师",
                                     lambda: delete_frame_course_teacher())
    # 创建初始一个frame
    create_frame_course_teacher(frame_course_info)
