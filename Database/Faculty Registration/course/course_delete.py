from tkinter import messagebox
import ttkbootstrap as ttk
import pymysql as sql
from course import course_check
import common as common
from common import course_id2type

course_del_items = {}
del_result_frame = []
detail_button_list = []
delete_button_list = []
frame_check = None


def fresh(self):
    create_check_del_course(self)


def delete_course(self, course_id):
    # 弹窗并确认是否删除
    if not messagebox.askyesno("确认", "确认删除这篇课程？"):
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
        cursor.callproc("delete_course", (course_id,))
        db.commit()
    except sql.Error as e:
        db.rollback()
        db.close()
        print("删除失败：" + str(e))
        exit(-1)
    db.close()
    messagebox.showinfo("成功", "删除成功")
    # 刷新页面
    create_check_del_course(self)


def create_check_del_course(self):
    check_result, check_result_simple = course_check.check_course(course_del_items)
    create_del_result_frame(self, check_result_simple, check_result)


def create_del_result_frame(self, check_result_simple, check_result):
    for frame in del_result_frame:
        frame.destroy()
    del_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_course_check_result = ttk.Frame(frame_check, width=800, height=50)
        frame_course_check_result.pack(side='top', anchor='w')
        del_result_frame.append(frame_course_check_result)
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
        # 删除按钮
        button_course_delete = ttk.Button(frame_course_check_result, text="删除", width=5, style='danger',
                                         command=lambda arg3=check_result[i][1]: delete_course(self, arg3))
        button_course_delete.grid(row=0, column=5, padx=2)
        delete_button_list.append((button_course_delete, i))


def create_frame_course_delete(self):
    global frame_check, course_del_items
    canvas_course_del = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_check = ttk.Frame(canvas_course_del, width=800, height=1200)
    self.frame_list["frame_course_delete"] = canvas_course_del
    frame_check.pack(side='top', anchor='n')
    canvas_course_del.create_window(820, 0, anchor='n', window=frame_check)

    frame_course_check_label = course_check.create_basic_info_frame(self, canvas_course_del, course_del_items,
                                                                    create_check_del_course, frame_check,
                                                                    "课程信息删除")
    ttk.Label(frame_course_check_label, text="", font=("宋体", 10), width=10).grid(row=0, column=4, padx=2)
