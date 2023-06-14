import ttkbootstrap as ttk
from paper import paper_check, paper_modify, paper_delete, paper_add
from project import proj_modify, proj_add, proj_delete, proj_check
from course import course_check, course_add, course_delete, course_modify
from statistic import statistic
import os
from PIL import Image, ImageTk

img = None


class Root:
    def __init__(self):
        root = ttk.Window(minsize=(1600, 1080), resizable=(False, True))
        root.title("教学科研登记系统")
        root.resizable(False, False)

        self.root = root
        self.frame_list = {}
        self.frame_fresh_list = {}

    def __create_paper_choose_button(self, frame_name, type_="paper"):
        frame_button = ttk.Frame(self.frame_list[frame_name], height=100, width=800)
        button_return = ttk.Button(frame_button, text="返回", style="secondary-outline.TButton",
                                   command=lambda: self.switch_to_frame("frame_main"))
        button_return.grid(row=0, column=0, ipadx=10, ipady=10)
        button_add = ttk.Button(frame_button, text="添加", style="success-outline.TButton",
                                command=lambda: self.switch_to_frame("frame_" + type_ + "_add"))
        button_add.grid(row=0, column=1, ipadx=10, ipady=10)
        button_delete = ttk.Button(frame_button, text="删除", style="danger-outline.TButton",
                                   command=lambda: self.switch_to_frame("frame_" + type_ + "_delete"))
        button_delete.grid(row=0, column=2, ipadx=10, ipady=10)
        button_modify = ttk.Button(frame_button, text="修改", style="warning-outline.TButton",
                                   command=lambda: self.switch_to_frame("frame_" + type_ + "_modify"))
        button_modify.grid(row=0, column=3, ipadx=10, ipady=10)
        button_check = ttk.Button(frame_button, text="查询", style="info-outline.TButton",
                                  command=lambda: self.switch_to_frame("frame_" + type_ + "_check"))
        button_check.grid(row=0, column=4, ipadx=10, ipady=10)
        frame_button.pack(side='bottom', anchor='center')

    def fresh(self, name):
        pass

    def create_frame_paper_add(self):
        paper_add.create_frame_paper_add(self)
        self.frame_fresh_list["frame_paper_add"] = paper_add.fresh
        self.__create_paper_choose_button("frame_paper_add")

    def create_frame_paper_delete(self):
        paper_delete.create_frame_paper_delete(self)
        self.frame_fresh_list["frame_paper_delete"] = paper_delete.fresh
        self.__create_paper_choose_button("frame_paper_delete")

    def create_frame_paper_modify(self):
        paper_modify.create_frame_paper_modify(self)
        self.frame_fresh_list["frame_paper_modify"] = paper_modify.fresh
        self.__create_paper_choose_button("frame_paper_modify")

    def create_frame_paper_check(self):
        paper_check.create_frame_paper_check(self)
        self.frame_fresh_list["frame_paper_check"] = paper_check.fresh
        self.__create_paper_choose_button("frame_paper_check")

    def create_frame_proj_add(self):
        proj_add.create_frame_proj_add(self)
        self.frame_fresh_list["frame_proj_add"] = proj_add.fresh
        self.__create_paper_choose_button("frame_proj_add", "proj")

    def create_frame_proj_delete(self):
        proj_delete.create_frame_proj_delete(self)
        self.frame_fresh_list["frame_proj_delete"] = proj_delete.fresh
        self.__create_paper_choose_button("frame_proj_delete", "proj")

    def create_frame_proj_modify(self):
        proj_modify.create_frame_proj_modify(self)
        self.frame_fresh_list["frame_proj_modify"] = proj_modify.fresh
        self.__create_paper_choose_button("frame_proj_modify", "proj")

    def create_frame_proj_check(self):
        proj_check.create_frame_proj_check(self)
        self.frame_fresh_list["frame_proj_check"] = proj_check.fresh
        self.__create_paper_choose_button("frame_proj_check", "proj")

    def create_frame_course_add(self):
        course_add.create_frame_course_add(self)
        self.frame_fresh_list["frame_course_add"] = course_add.fresh
        self.__create_paper_choose_button("frame_course_add", "course")

    def create_frame_course_delete(self):
        course_delete.create_frame_course_delete(self)
        self.frame_fresh_list["frame_course_delete"] = course_delete.fresh
        self.__create_paper_choose_button("frame_course_delete", "course")

    def create_frame_course_modify(self):
        course_modify.create_frame_course_modify(self)
        self.frame_fresh_list["frame_course_modify"] = course_modify.fresh
        self.__create_paper_choose_button("frame_course_modify", "course")

    def create_frame_course_check(self):
        course_check.create_frame_course_check(self)
        self.frame_fresh_list["frame_course_check"] = course_check.fresh
        self.__create_paper_choose_button("frame_course_check", "course")

    def create_frame_statistic(self):
        statistic.create_stat_frame(self)
        self.frame_fresh_list["frame_statistic"] = statistic.fresh
        self.__create_paper_choose_button("frame_statistic", "stat")

    def create_frame_main(self):
        # 获取当前路径
        path = os.path.abspath('.')
        global img
        img = Image.open(path + '/img/003.jpg')
        img = ImageTk.PhotoImage(img)

        s = ttk.Style()
        s.theme_use('cosmo')
        canvas_main = ttk.Canvas(self.root, height=1200, width=1600)
        canvas_main.create_image(0, 0, anchor='nw', image=img)
        canvas_main.background = img

        frame_button = ttk.Frame(canvas_main, height=10, width=20)
        canvas_main.create_window(820, 0, anchor='n', window=frame_button)

        s.configure('TButton', font=('微软雅黑', 12, 'bold'))
        self.frame_list["frame_main"] = canvas_main
        self.frame_fresh_list["frame_main"] = self.fresh
        button_paper = ttk.Button(frame_button, text="登记论文发表情况", style='warning.TButton',
                                  command=lambda: self.switch_to_frame("frame_paper_check"), width=20)
        button_paper.pack(side='top', anchor='n')
        button_proj = ttk.Button(frame_button, text="登记项目情况", style='success.TButton',
                                 command=lambda: self.switch_to_frame("frame_proj_check"), width=20)
        button_proj.pack(side='top', anchor='n')
        button_teach = ttk.Button(frame_button, text="登记教学情况", style="primary.TButton",
                                  command=lambda: self.switch_to_frame("frame_course_check"), width=20)
        button_teach.pack(side='top', anchor='n')
        button_check = ttk.Button(frame_button, text="查询统计", style="danger.TButton",
                                  command=lambda: self.switch_to_frame("frame_statistic"), width=20)
        button_check.pack(side='top', anchor='n')
        frame_button.pack(side='bottom', anchor='center', pady=100)

    def switch_to_frame(self, frame_name):
        for frame in self.frame_list.values():
            frame.pack_forget()
        if frame_name.startswith("frame_stat"):
            frame_name = "frame_statistic"
        self.frame_list[frame_name].pack(side='top', anchor='center', fill='both', expand='yes')
        self.frame_fresh_list[frame_name](self)


def show():
    pass
