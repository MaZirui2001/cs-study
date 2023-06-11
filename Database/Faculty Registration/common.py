import tkinter as tk
import ttkbootstrap as ttk
paper_type_map = {'full-paper': 1, 'short-paper': 2, 'poster-paper': 3, 'demo-paper': 4}
paper_level_map = {'CCF-A': 1, 'CCF-B': 2, 'CCF-C': 3, '中文 CCF-A': 4, '中文 CCF-B': 5, '无级别': 6}
proj_type_map = {'国家级': 1, '省部级': 2, '市厅级': 3, '企业合作项目': 4, '其他': 5}
course_type_map = {'本科生课程': 1, '研究生课程': 2}
course_semester_map = {'春季学期': 1, '夏季学期': 2, '秋季学期': 3, '不限': ""}

paper_id2type = ['none', 'full-paper', 'short-paper', 'poster-paper', 'demo-paper']
paper_id2level = ['none', 'CCF-A', 'CCF-B', 'CCF-C', '中文 CCF-A', '中文 CCF-B', '无级别']
proj_id2type = ['none', '国家级', '省部级', '市厅级', '企业合作项目', '其他']
course_id2type = ['none', '本科生课程', '研究生课程']
course_id2semester = ['none', '春季学期', '夏季学期', '秋季学期']

id2id_name = ['none', '博士后', '助教', '讲师', '副教授', '特任教授', '教授', '助理研究员', '特任副研究员',
              '副研究员', '特任研究员', '研究员']
id2gender = ['none', '男', '女']


def create_label_and_entry(frame_base, label_text, entry_default_text):
    frame = ttk.Frame(frame_base, height=50, width=800)
    label = ttk.Label(frame, text=label_text, font=("微软雅黑", 10))
    label.pack(side='left', anchor='center')
    entry = ttk.Entry(frame, width=50)
    entry.insert(0, entry_default_text)
    entry.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return entry


def create_label_and_entry2(frame_base, label1_text, entry1_default_text, label2_text, entry2_default_text):
    frame = ttk.Frame(frame_base, height=50, width=800)
    label1 = ttk.Label(frame, text=label1_text, font=("微软雅黑", 10))
    label1.pack(side='left', anchor='center')
    entry1 = ttk.Entry(frame, width=20)
    entry1.insert(0, entry1_default_text)
    entry1.pack(side='left', anchor='center')
    label2 = ttk.Label(frame, text=label2_text, font=("微软雅黑", 10))
    label2.pack(side='left', anchor='center')
    entry2 = ttk.Entry(frame, width=20)
    entry2.insert(0, entry2_default_text)
    entry2.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return entry1, entry2


def create_label_with_button2(frame_base, label_text, button_text1, command1, button_text2, command2):
    s1 = ttk.Style()
    s1.configure('my.TButton', font=('微软雅黑', 8), background='white', foreground='black')
    frame = ttk.Frame(frame_base, width=800, height=50)
    label = ttk.Label(frame, text=label_text, font=("微软雅黑", 10))
    label.pack(side='left', anchor='center')
    button1 = ttk.Button(frame, text=button_text1,  style="my.TButton", command=command1)
    button1.pack(side='left', anchor='center')
    button2 = ttk.Button(frame, text=button_text2,  style="my.TButton", command=command2)
    button2.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')


def create_label_and_entry_with_checkbutton(frame_base, label_entry_text, entry_default_text, checkbutton_text,
                                            check_button_default_choice):
    frame = ttk.Frame(frame_base, width=800, height=50)
    label = ttk.Label(frame, text=label_entry_text, font=("微软雅黑", 10))
    label.pack(side='left', anchor='center')
    entry = ttk.Entry(frame, width=20)
    entry.insert(0, entry_default_text)
    entry.pack(side='left', anchor='center')

    var = ttk.IntVar()
    var.set(check_button_default_choice)
    check_button = ttk.Checkbutton(frame, text=checkbutton_text, variable=var)
    check_button.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return entry, var


def create_option_menu(frame_base, label_text, default_option, option_list):
    frame = ttk.Frame(frame_base, width=800, height=50)
    label = ttk.Label(frame, text=label_text, font=("微软雅黑", 10))
    label.pack(side='left', anchor='center')
    var = ttk.StringVar()

    option_menu = ttk.OptionMenu(frame, var, *option_list, style='primary-outline.TMenubutton')
    var.set(default_option)
    option_menu.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return var


def create_scrollbar(canvas_base):
    sb = ttk.Scrollbar(canvas_base, orient='vertical', command=canvas_base.yview)
    sb.pack(side='right', fill='y')
    canvas_base.configure(yscrollcommand=sb.set)


def create_text(frame_base, text, disable, column, width=20):
    text_frame = ttk.Text(frame_base, width=width, height=2, font=("微软雅黑", 8))
    text_frame.grid(row=0, column=column)
    text_frame.insert(1.0, str(text))
    if disable:
        text_frame.config(state='disabled')


def create_four_text(frame_base, text, disable, column, width=20):
    text_frame = ttk.Text(frame_base, width=width, height=4)
    text_frame.grid(row=0, column=column)
    text_frame.insert(1.0, str(text))
    if disable:
        text_frame.config(state='disabled')


def close_window(root, window):
    root.attributes("-disabled", False)
    window.destroy()
