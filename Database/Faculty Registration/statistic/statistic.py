import tkinter as tk
from tkinter import messagebox
import ttkbootstrap as ttk
import common
import pymysql as sql
import pandas as pd
from common import paper_id2level, proj_id2type, course_id2semester, id2gender, id2id_name
import markdown

stat_items = {}


def fresh(self):
    pass


def statistic(items):
    teacher_id = items["teacher_id"].get()
    start_year = items["start_year"].get()
    end_year = items["end_year"].get()
    # 检查输入是否合法
    if teacher_id == '':
        tk.messagebox.showerror(title='错误', message='教师工号不能为空！')
        return None
    if start_year == '':
        tk.messagebox.showerror(title='错误', message='起始时间不能为空！')
        return None
    else:
        try:
            start_year = pd.to_datetime(start_year).year
        except ValueError:
            tk.messagebox.showerror(title='错误', message='起始时间输入不合法！')
            return None
    if end_year == '':
        try:
            end_year = pd.to_datetime(end_year).year
        except ValueError:
            tk.messagebox.showerror(title='错误', message='结束时间输入不合法！')
            return None
    try:
        start_year = int(start_year)
        end_year = int(end_year)
        if start_year > end_year:
            raise ValueError
    except ValueError:
        tk.messagebox.showerror(title='错误', message='时间输入不合法！')
        return None
    # 查询教师信息
    sql_info = "select teacher.id, teacher.name, teacher.gender, teacher.title from teacher where id = %s "
    var_info = (teacher_id,)

    # 查询教师教授课程信息
    sql_teach = "select c.id, c.name, tc.undertake_hour, tc.year, tc.semester " \
                "from course c join teach_course tc on c.id = tc.course_id " \
                "where tc.teacher_id = %s and tc.year >= %s and tc.year <= %s"
    var_teach = (teacher_id, start_year, end_year)

    # 查询教师发表论文情况
    sql_paper = "select p.name, p.public_source, p.public_date, p.level, pp.ranking, pp.is_corresponding_author " \
                "from paper p join publish_paper pp on p.id = pp.paper_id " \
                "where pp.teacher_id = %s and p.public_date >= %s and p.public_date <= %s"
    var = (teacher_id, str(start_year) + '-01-01', str(end_year) + '-12-31')

    # 查询教师项目情况
    sql_project = "select p.name, p.source, p.type, p.start_year, p.end_year, p.expenditure, up.expenditure " \
                  "from project p join undertake_project up on p.id = up.project_id " \
                  "where up.teacher_id = %s and p.start_year >= %s and p.end_year <= %s"
    var_project = (teacher_id, start_year, end_year)

    # 连接数据库
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
    # 使用cursor()方法获取操作游标
    cursor = db.cursor()
    # 查询教师信息
    try:
        cursor.execute(sql_info, var_info)
        teacher_info = cursor.fetchone()
    except sql.Error as e:
        print(e)
        db.close()
        exit(-1)
    try:
        cursor.execute(sql_teach, var_teach)
        teach_course = cursor.fetchall()
    except sql.Error as e:
        print(e)
        db.close()
        exit(-1)
    try:
        cursor.execute(sql_paper, var)
        public_paper = cursor.fetchall()
    except sql.Error as e:
        print(e)
        db.close()
        exit(-1)
    try:
        cursor.execute(sql_project, var_project)
        undertake_project = cursor.fetchall()
    except sql.Error as e:
        print(e)
        db.close()
        exit(-1)
    return teacher_info, teach_course, public_paper, undertake_project, start_year, end_year


def make_stat_markdown(teacher_info, teach_course, public_paper, undertake_project, start_year, end_year):
    stat = "# 教师教学科研工作统计（" + str(start_year) + "—" + str(end_year) + "）\n"
    stat += "## 教师基本信息\n"
    stat += "| 工号 | 姓名 | 性别 | 职称 |\n"
    stat += "| :----: | :----: | :----: | :----: |\n"
    stat += "| " + teacher_info[0] + " | " + teacher_info[1] + " | " + id2gender[teacher_info[2]] + " | " + id2id_name[
        teacher_info[3]] + " |\n"
    stat += "## 教学情况\n"
    stat += "| 课程号 | 课程名 | 主讲学时 | 授课年份 | 授课学期 |\n"
    stat += "| :----: | :----: | :----: | :----: | :----: |\n"
    for item in teach_course:
        stat += "| " + item[0] + " | " + item[1] + " | " + str(item[2]) + " | " + str(item[3]) + " | " + \
                course_id2semester[int(item[4])] + " | \n"
    stat += "## 发表论文情况\n"
    stat += "| 论文名 | 发表源 | 发表年份 | 级别 | 排名 | 是否通讯作者 |\n"
    stat += "| :----: | :----: | :----: | :----: | :----: | :----: |\n"
    for item in public_paper:
        stat += "| " + item[0] + " | " + item[1] + " | " + str(pd.to_datetime(item[2]).year) + " | " + paper_id2level[
            int(item[3])] + " | " + str(item[4]) + " | " + ('是' if int(item[5]) else '否') + " | \n"
    stat += "## 承担项目情况\n"
    stat += "| 项目名 | 项目来源 | 项目类型 | 项目时间 | 总经费 | 承担经费 |\n"
    stat += "| :----: | :----: | :----: | :----: | :----: | :----: |\n"
    for item in undertake_project:
        stat += "| " + item[0] + " | " + item[1] + " | " + proj_id2type[int(item[2])] + " | " + str(
            item[3]) + "—" + str(item[4]) + " | " + str(item[5]) + " | " + str(item[6]) + " |\n"
    with open("./stat.md", "w", encoding="utf-8") as f:
        f.write(stat)
    messagebox.showinfo("提示", "统计完成，结果已保存在stat.md中")


def statistic_cope(items):
    temp = statistic(items)
    if temp is None:
        return
    teacher_info, teach_course, public_paper, undertake_project, start_year, end_year = temp
    make_stat_markdown(teacher_info, teach_course, public_paper, undertake_project, start_year, end_year)


def create_stat_frame(self):
    canvas_stat = ttk.Canvas(self.root, width=1600, height=1200)
    frame_stat = ttk.Frame(canvas_stat, width=800, height=600)
    canvas_stat.create_window(820, 0, window=frame_stat, anchor='n')
    self.frame_list["frame_statistic"] = canvas_stat
    # 创建label
    ttk.Label(frame_stat, text="科研情况查询", font=("微软雅黑", 15, 'bold')).pack(side='top', anchor='n')
    button_paper_check = ttk.Button(frame_stat, text="导出", width=10, style='info')
    button_paper_check.pack(side='top', anchor='n')
    button_paper_check.config(command=lambda: statistic_cope(stat_items))

    # 创建输入框, 获取输入的信息
    frame_paper_info = ttk.Frame(frame_stat, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')

    # 论文编号
    stat_items["teacher_id"] = common.create_label_and_entry(frame_paper_info, "教师工号", "")

    # 论文名称
    stat_items["start_year"] = common.create_label_and_entry(frame_paper_info, "起始时间", "")

    # 论文来源
    stat_items["end_year"] = common.create_label_and_entry(frame_paper_info, "结束时间", "")
