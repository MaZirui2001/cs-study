import pymysql
import tkinter as tk


def create_frame_paper_add(self):
    frame_paper_add = tk.Frame(self.root, width=800, height=600)
    self.frame_list["frame_paper_add"] = frame_paper_add
    # 创建label
    label_paper_name = tk.Label(frame_paper_add, text="论文信息插入", font=("SimHei", 20))
    label_paper_name.pack(side='top', anchor='n')
    # 创建输入框, 获取输入的论文信息
    frame_paper_info = tk.Frame(frame_paper_add, width=200, height=600)
    frame_paper_info.pack(side='top', anchor='n')
    # 论文编号
    frame_paper_id = tk.Frame(frame_paper_info, width=800, height=50)
    label_paper_id = tk.Label(frame_paper_id, text="论文编号", font=("SimHei", 15))
    label_paper_id.pack(side='left', anchor='center')
    entry_paper_id = tk.Entry(frame_paper_id, width=50)
    entry_paper_id.pack(side='left', anchor='center')
    frame_paper_id.pack(side='top', anchor='w')
    # 论文名称
    frame_paper_name = tk.Frame(frame_paper_info, width=800, height=50)
    label_paper_name = tk.Label(frame_paper_name, text="论文名称", font=("SimHei", 15))
    label_paper_name.pack(side='left', anchor='center')
    entry_paper_name = tk.Entry(frame_paper_name, width=50)
    entry_paper_name.pack(side='left', anchor='center')
    frame_paper_name.pack(side='top', anchor='w')
    # 论文来源
    frame_paper_source = tk.Frame(frame_paper_info, width=800, height=50)
    label_paper_source = tk.Label(frame_paper_source, text="论文来源", font=("SimHei", 15))
    label_paper_source.pack(side='left', anchor='center')
    entry_paper_source = tk.Entry(frame_paper_source, width=50)
    entry_paper_source.pack(side='left', anchor='center')
    frame_paper_source.pack(side='top', anchor='w')
    # 论文发表日期
    frame_paper_date = tk.Frame(frame_paper_info, width=800, height=50)
    label_paper_date = tk.Label(frame_paper_date, text="发表日期", font=("SimHei", 15))
    label_paper_date.pack(side='left', anchor='center')
    entry_paper_date = tk.Entry(frame_paper_date, width=50)
    entry_paper_date.pack(side='left', anchor='center')
    frame_paper_date.pack(side='top', anchor='w')
    # 论文类型，下拉菜单
    frame_paper_type = tk.Frame(frame_paper_info, width=800, height=50)
    label_paper_type = tk.Label(frame_paper_type, text="论文类型", font=("SimHei", 15))
    label_paper_type.pack(side='left', anchor='center')
    var_paper_type = tk.StringVar()
    var_paper_type.set("full-paper")
    option_paper_type = tk.OptionMenu(frame_paper_type, var_paper_type, "full-paper", "short-paper", "poster-paper",
                                      "demo-paper")
    option_paper_type.pack(side='left', anchor='center')
    frame_paper_type.pack(side='top', anchor='w')
    # 论文级别， 下拉菜单
    frame_paper_level = tk.Frame(frame_paper_info, width=800, height=50)
    label_paper_level = tk.Label(frame_paper_level, text="论文级别", font=("SimHei", 15))
    label_paper_level.pack(side='left', anchor='center')
    var_paper_level = tk.StringVar()
    var_paper_level.set("CCF-A")
    option_paper_level = tk.OptionMenu(frame_paper_level, var_paper_level, "CCF-A", "CCF-B", "CCF-C", "中文 CCF-A",
                                       "中文 CCF-B", "无级别")
    option_paper_level.pack(side='left', anchor='center')
    frame_paper_level.pack(side='top', anchor='w')
    # 论文作者信息：作者编号、作者姓名、作者排名、是否为通讯作者
    # 作者可能有多个，默认显示一个，点击按钮添加新的作者信息或删除新的对话框
    frame_paper_author = tk.Frame(frame_paper_info, width=800, height=50)
    label_paper_author = tk.Label(frame_paper_author, text="论文作者", font=("SimHei", 15))
    label_paper_author.pack(side='left', anchor='center')
    frame_paper_author.pack(side='top', anchor='w')
    # 作者编号
    frame_author_id = tk.Frame(frame_paper_info, width=800, height=50)
    label_author_id = tk.Label(frame_author_id, text="作者编号", font=("SimHei", 15))
    label_author_id.pack(side='left', anchor='center')
    entry_author_id = tk.Entry(frame_author_id, width=50)
    entry_author_id.pack(side='left', anchor='center')
    frame_author_id.pack(side='top', anchor='w')
    # 作者姓名
    frame_author_name = tk.Frame(frame_paper_info, width=800, height=50)
    label_author_name = tk.Label(frame_author_name, text="作者姓名", font=("SimHei", 15))
    label_author_name.pack(side='left', anchor='center')
    entry_author_name = tk.Entry(frame_author_name, width=50)
    entry_author_name.pack(side='left', anchor='center')
    frame_author_name.pack(side='top', anchor='w')
    # 作者排名
    frame_author_rank = tk.Frame(frame_paper_info, width=800, height=50)
    label_author_rank = tk.Label(frame_author_rank, text="作者排名", font=("SimHei", 15))
    label_author_rank.pack(side='left', anchor='center')
    entry_author_rank = tk.Entry(frame_author_rank, width=50)
    entry_author_rank.pack(side='left', anchor='center')
    frame_author_rank.pack(side='top', anchor='w')
    # 是否为通讯作者
    frame_author_is_communicate = tk.Frame(frame_paper_info, width=800, height=50)
    label_author_is_communicate = tk.Label(frame_author_is_communicate, text="是否为通讯作者", font=("SimHei", 15))
    label_author_is_communicate.pack(side='left', anchor='center')
    var_author_is_communicate = tk.StringVar()
    var_author_is_communicate.set("否")
    option_author_is_communicate = tk.OptionMenu(frame_author_is_communicate, var_author_is_communicate, "是", "否")
    option_author_is_communicate.pack(side='left', anchor='center')
    frame_author_is_communicate.pack(side='top', anchor='w')
    
