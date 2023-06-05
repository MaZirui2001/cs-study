import tkinter as tk
import paper_check
import paper_add
import paper_delete
import paper_modify

class Root:
    def __init__(self):
        root = tk.Tk()
        root.geometry("800x600")
        root.title("教学科研登记系统")
        self.root = root
        self.frame_list = {}

    def __create_paper_choose_button(self, frame_paper_name):
        frame_button = tk.Frame(self.frame_list[frame_paper_name], height=100, width=800, bg='green')
        button_return = tk.Button(frame_button, text="返回",
                                  command=lambda: self.switch_to_frame("frame_main"))
        button_return.grid(row=0, column=0, ipadx=10, ipady=10)
        button_add = tk.Button(frame_button, text="添加",
                               command=lambda: self.switch_to_frame("frame_paper_add"))
        button_add.grid(row=0, column=1, ipadx=10, ipady=10)
        button_delete = tk.Button(frame_button, text="删除",
                                  command=lambda: self.switch_to_frame("frame_paper_delete"))
        button_delete.grid(row=0, column=2, ipadx=10, ipady=10)
        button_modify = tk.Button(frame_button, text="修改",
                                  command=lambda: self.switch_to_frame("frame_paper_modify"))
        button_modify.grid(row=0, column=3, ipadx=10, ipady=10)
        button_check = tk.Button(frame_button, text="查询",
                                 command=lambda: self.switch_to_frame("frame_paper_check"))
        button_check.grid(row=0, column=4, ipadx=10, ipady=10)
        frame_button.pack(side='bottom', anchor='center')

    def create_frame_paper_add(self):
        paper_add.create_frame_paper_add(self)
        self.__create_paper_choose_button("frame_paper_add")

    def create_frame_paper_delete(self):
        paper_delete.create_frame_paper_delete(self)
        self.__create_paper_choose_button("frame_paper_delete")

    def create_frame_paper_modify(self):
        paper_modify.create_frame_paper_modify(self)
        self.__create_paper_choose_button("frame_paper_modify")

    def create_frame_paper_check(self):
        paper_check.create_frame_paper_check(self)
        self.__create_paper_choose_button("frame_paper_check")

    def create_frame_main(self):
        frame_main = tk.Frame(self.root, height=600, width=800, bg='pink')
        frame_button = tk.Frame(frame_main, height=10, width=800, bg='white')
        self.frame_list["frame_main"] = frame_main
        button_paper = tk.Button(frame_button, text="登记论文发表情况",
                                 command=lambda: self.switch_to_frame("frame_paper_check"), height=5, width=20)
        button_paper.pack(side='left', anchor='center')
        button_proj = tk.Button(frame_button, text="登记项目情况", command=show, height=5, width=20)
        button_proj.pack(side='left', anchor='center')
        button_teach = tk.Button(frame_button, text="登记教学情况", command=show, height=5, width=20)
        button_teach.pack(side='left', anchor='center')
        button_check = tk.Button(frame_button, text="查询统计", command=show, height=5, width=20)
        button_check.pack(side='left', anchor='center')
        frame_button.pack(side='bottom', anchor='center')

    def switch_to_frame(self, frame_name):
        for frame in self.frame_list.values():
            frame.pack_forget()
        self.frame_list[frame_name].pack(side='top', anchor='center', fill='both', expand='yes')


def show():
    pass
