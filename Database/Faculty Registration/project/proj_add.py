import tkinter as tk
from tkinter import messagebox
import ttkbootstrap as ttk
import pymysql as sql
import pandas as pd
import common
from common import proj_type_map, proj_id2type

frame_proj_teacher_list = []
teacher_num_view = 0
proj_add_items = {}
teacher_info = []


def fresh(self):
    pass


def insert_info_get_and_check(paper_add_items_local, teacher_num, teacher_info_local, message_parent):
    project_id = paper_add_items_local["proj_id"].get().strip()
    proj_name = paper_add_items_local["proj_name"].get().strip()
    proj_source = paper_add_items_local["proj_source"].get().strip()
    proj_type = proj_type_map[paper_add_items_local["proj_type"].get().strip()]
    proj_expend = paper_add_items_local["proj_expend"].get().strip()
    proj_start = paper_add_items_local["proj_start"].get().strip()
    proj_end = paper_add_items_local["proj_end"].get().strip()
    teacher_id_list = []
    teacher_name_list = []
    teacher_rank_list = []
    teacher_expend_list = []
    for i in range(teacher_num):
        teacher_id_list.append(teacher_info_local[i]['id'].get().strip())
        teacher_name_list.append(teacher_info_local[i]['name'].get().strip())
        teacher_rank_list.append(teacher_info_local[i]['rank'].get().strip())
        teacher_expend_list.append(teacher_info_local[i]['expend'].get().strip())

    # 项目编号不能为空
    if project_id == '':
        tk.messagebox.showerror(title='错误', message='项目编号不能为空！', parent=message_parent)
        return None
    # 项目名称不能为空
    if proj_name == '':
        tk.messagebox.showerror(title='错误', message='项目名称不能为空！', parent=message_parent)
        return None
    # 项目来源不能为空
    if proj_source == '':
        tk.messagebox.showerror(title='错误', message='项目来源不能为空！', parent=message_parent)
        return None
    # 项目总经费需要为钱的形式
    if proj_expend == '':
        tk.messagebox.showerror(title='错误', message='项目经费不能为空！', parent=message_parent)
        return None
    else:
        try:
            loc = proj_expend.find('.')
            if len(proj_expend) - loc > 3 and loc != -1:
                tk.messagebox.showerror(title='错误', message='项目经费不合法！', parent=message_parent)
                return None
            proj_expend = float(proj_expend)
        except ValueError:
            tk.messagebox.showerror(title='错误', message='项目经费不合法！', parent=message_parent)
            return None
    # 项目发表日期需要合法，且需要可以转换为datetime类型
    if proj_start == '':
        tk.messagebox.showerror(title='错误', message='项目开始日期不能为空！', parent=message_parent)
        return None
    else:
        try:
            proj_start = pd.to_datetime(proj_start).year
        except ValueError:
            tk.messagebox.showerror(title='错误', message='项目开始日期不合法！', parent=message_parent)
            return None
    if proj_end == '':
        tk.messagebox.showerror(title='错误', message='项目结束日期不能为空！', parent=message_parent)
        return None
    else:
        try:
            proj_end = pd.to_datetime(proj_end).year
        except ValueError:
            tk.messagebox.showerror(title='错误', message='项目结束日期不合法！', parent=message_parent)
            return None
    if proj_start > proj_end:
        tk.messagebox.showerror(title='错误', message='项目开始日期不能晚于结束日期！', parent=message_parent)
        return None
    # 检查员工列表是否有空值
    listnum = teacher_num
    temp_id_list = []
    temp_name_list = []
    temp_rank_list = []
    temp_expend = []
    for i in range(teacher_num):
        if teacher_id_list[i] == '' or teacher_name_list[i] == '' or teacher_rank_list[i] == '':
            listnum -= 1
        else:
            temp_id_list.append(teacher_id_list[i])
            temp_name_list.append(teacher_name_list[i])
            temp_rank_list.append(teacher_rank_list[i])
            temp_expend.append(teacher_expend_list[i])
    if listnum == 0:
        tk.messagebox.showerror(title='错误', message='员工列表不能全为不完整的信息！', parent=message_parent)
        return None
    teacher_id_list = temp_id_list
    teacher_name_list = temp_name_list
    teacher_rank_list = temp_rank_list
    teacher_expend_list = temp_expend
    # 检查是否有相同的员工编号
    for i in range(listnum):
        for j in range(i + 1, listnum):
            if teacher_id_list[i] == teacher_id_list[j]:
                tk.messagebox.showerror(title='错误', message='员工编号不能相同！', parent=message_parent)
                return None
    # 检查员工经费是否为钱的形式
    for i in range(listnum):
        try:
            loc = teacher_expend_list[i].find('.')
            if len(teacher_expend_list[i]) - loc > 3 and loc != -1:
                tk.messagebox.showerror(title='错误', message='员工经费小数点后最多两位！', parent=message_parent)
                return None
            teacher_expend_list[i] = float(teacher_expend_list[i])
            if teacher_expend_list[i] < 0:
                tk.messagebox.showerror(title='错误', message='员工经费不能为负数！', parent=message_parent)
                return None
        except ValueError:
            tk.messagebox.showerror(title='错误', message='员工经费不合法！', parent=message_parent)
            return None
    # 检查排名必须为正整数
    for i in range(listnum):
        try:
            teacher_rank_list[i] = int(teacher_rank_list[i])
            if teacher_rank_list[i] <= 0:
                tk.messagebox.showerror(title='错误', message='员工排名必须为正整数！', parent=message_parent)
                return None
        except ValueError:
            tk.messagebox.showerror(title='错误', message='员工排名不合法！', parent=message_parent)
            return None
    # 检查是否有相同的排名
    for i in range(listnum):
        for j in range(i + 1, listnum):
            if teacher_rank_list[i] == teacher_rank_list[j]:
                tk.messagebox.showerror(title='错误', message='员工排名不能相同！', parent=message_parent)
                return None
    # 检查总经费是否等于各经费之和
    total_expend = proj_expend
    for i in range(listnum):
        total_expend -= teacher_expend_list[i]
    if abs(total_expend) > 1e-6:
        tk.messagebox.showerror(title='错误', message='总经费必须等于各个员工经费之和！', parent=message_parent)
        return None

    return listnum, project_id, proj_name, proj_source, proj_type, proj_expend, proj_start, proj_end, teacher_id_list, \
        teacher_name_list, teacher_rank_list, teacher_expend_list


def insert_proj_info(message_parent):
    global frame_proj_teacher_list, teacher_num_view, proj_add_items, teacher_info
    temp = insert_info_get_and_check(proj_add_items, teacher_num_view, teacher_info, message_parent)
    if temp is None:
        return
    listnum, project_id, proj_name, proj_source, proj_type, proj_expend, proj_start, proj_end, \
        teacher_id_list, teacher_name_list, teacher_rank_list, teacher_expend_list = temp
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
    # 插入项目信息
    cursor = db.cursor()
    val = (project_id, proj_name, proj_source, proj_type, proj_expend, proj_start, proj_end)
    # 执行sql语句，插入项目信息并捕捉异常编号
    try:
        cursor.callproc('insert_project', val)
        for i in range(listnum):
            cursor.callproc('insert_teacher_project',
                            (teacher_id_list[i], teacher_name_list[i], project_id, teacher_rank_list[i],
                             teacher_expend_list[i]))
        db.commit()
    except sql.Error as e:
        db.rollback()
        tk.messagebox.showerror(title='错误', message=e.args[1])
        return
    db.close()
    # 提示插入成功， 需要点击确认
    tk.messagebox.showinfo(title='成功', message='插入成功！')


def create_frame_project_teacher(frame_project_info):
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
        frame_project_teacher, "员工" + str(teacher_num_view) + "编号", "", "员工" + str(teacher_num_view) + "排名", "")

    # 输入员工姓名和是否为通讯员工
    entry_project_teacher_name, entry_project_expenditure = common.create_label_and_entry2(
        frame_project_teacher, "员工" + str(teacher_num_view) + "姓名", "", "员工" + str(teacher_num_view) + "经费", "")

    frame_project_teacher.pack(side='top', anchor='n')
    frame_proj_teacher_list.append(frame_project_teacher)

    teacher_info.append(
        {'id': entry_project_teacher_id, 'name': entry_project_teacher_name, 'rank': entry_project_teacher_rank,
         'expend': entry_project_expenditure})


def delete_frame_project_teacher():
    global frame_proj_teacher_list, teacher_num_view
    if teacher_num_view <= 1:
        return
    frame_proj_teacher_list[teacher_num_view - 1].pack_forget()
    teacher_num_view -= 1


def create_basic_info(self, canvas_proj, frame_proj, proj_items, check_items):
    # 创建滚动条
    common.create_scrollbar(canvas_proj)

    # 创建label
    label_proj_name = ttk.Label(frame_proj, text="项目信息登记", font=("微软雅黑", 15, "bold"))
    label_proj_name.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的项目信息
    frame_proj_info = ttk.Frame(frame_proj, width=200, height=600)
    frame_proj_info.pack(side='top', anchor='n')

    # 创建提交按钮
    button_proj_submit = ttk.Button(frame_proj_info, text="提交", style='success')
    button_proj_submit.pack(side='top', anchor='e')

    # 项目编号
    print (check_items)
    proj_items["proj_id"] = common.create_label_and_entry(frame_proj_info, "项目编号", check_items[1])

    # 项目名称
    proj_items["proj_name"] = common.create_label_and_entry(frame_proj_info, "项目名称", check_items[0])

    # 项目来源
    proj_items["proj_source"] = common.create_label_and_entry(frame_proj_info, "项目来源", check_items[2])

    # 项目经费
    proj_items["proj_expend"] = common.create_label_and_entry(frame_proj_info, "项目经费", check_items[4])

    # 项目开始年份
    proj_items["proj_start"] = common.create_label_and_entry(frame_proj_info, "开始年份", check_items[5])

    # 项目结束年份
    proj_items["proj_end"] = common.create_label_and_entry(frame_proj_info, "结束年份", check_items[6])

    # 项目类型，下拉菜单
    types = ['none', '国家级', '省部级', '市厅级', '企业合作项目', '其他']
    proj_items["proj_type"] = common.create_option_menu(frame_proj_info, "项目类型",
                                                        proj_id2type[int(check_items[3])], types)
    return frame_proj_info, button_proj_submit


def create_frame_proj_add(self):
    canvas_proj_add = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_proj_add = ttk.Frame(canvas_proj_add, width=800, height=1200)
    frame_proj_add.pack(side='top', anchor='n')
    canvas_proj_add.create_window(820, 0, anchor='n', window=frame_proj_add)
    self.frame_list["frame_proj_add"] = canvas_proj_add

    frame_proj_info, button_submit = create_basic_info(self, canvas_proj_add, frame_proj_add, proj_add_items,
                                        ["", "", "", 1, "", "", "", ""])
    button_submit.config(command=lambda: insert_proj_info(self.root))
    # 项目员工信息：员工编号、员工姓名、员工排名、是否为通讯员工
    # 员工可能有多个，默认显示一个，点击按钮添加新的员工信息或删除新的对话框
    common.create_label_with_button2(frame_proj_info, "项目员工", "添加员工",
                                     lambda: create_frame_project_teacher(frame_proj_info), "删除员工",
                                     lambda: delete_frame_project_teacher())
    # 创建初始一个frame
    create_frame_project_teacher(frame_proj_info)
