import tkinter as tk

type_map = {'full-paper': 1, 'short-paper': 2, 'poster-paper': 3, 'demo-paper': 4}
level_map = {'CCF-A': 1, 'CCF-B': 2, 'CCF-C': 3, '中文 CCF-A': 4, '中文 CCF-B': 5, '无级别': 6}

id2type = ['none', 'full-paper', 'short-paper', 'poster-paper', 'demo-paper']
id2level = ['none', 'CCF-A', 'CCF-B', 'CCF-C', '中文 CCF-A', '中文 CCF-B', '无级别']
id2id_name = ['none', '博士后', '助教', '讲师', '副教授', '特任教授', '教授', '助理研究员', '特任副研究员', '副研究员',
              '特任研究员', '研究员']
id2gender = ['none', '男', '女']

def create_label_and_entry(frame_base, label_text, entry_default_text):
    frame = tk.Frame(frame_base, height=50, width=800, bg='white')
    label = tk.Label(frame, text=label_text, font=("宋体", 10))
    label.pack(side='left', anchor='center')
    entry = tk.Entry(frame, width=50)
    entry.insert(0, entry_default_text)
    entry.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return entry


def create_label_and_entry2(frame_base, label1_text, entry1_default_text, label2_text, entry2_default_text):
    frame = tk.Frame(frame_base, height=50, width=800)
    label1 = tk.Label(frame, text=label1_text, font=("宋体", 10))
    label1.pack(side='left', anchor='center')
    entry1 = tk.Entry(frame, width=20)
    entry1.insert(0, entry1_default_text)
    entry1.pack(side='left', anchor='center')
    label2 = tk.Label(frame, text=label2_text, font=("宋体", 10))
    label2.pack(side='left', anchor='center')
    entry2 = tk.Entry(frame, width=20)
    entry2.insert(0, entry2_default_text)
    entry2.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return entry1, entry2

def create_label_with_button2(frame_base, label_text, button_text1, command1, button_text2, command2):
    frame = tk.Frame(frame_base, width=800, height=50)
    label = tk.Label(frame, text=label_text, font=("宋体", 10))
    label.pack(side='left', anchor='center')
    button1 = tk.Button(frame, text=button_text1, font=("宋体", 10), command=command1)
    button1.pack(side='left', anchor='center')
    button2 = tk.Button(frame, text=button_text2, font=("宋体", 10), command=command2)
    button2.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')


def create_label_and_entry_with_checkbutton(frame_base, label_entry_text, entry_default_text, checkbutton_text,
                                            check_button_default_choice):
    frame = tk.Frame(frame_base, width=800, height=50)
    label = tk.Label(frame, text=label_entry_text, font=("宋体", 10))
    label.pack(side='left', anchor='center')
    entry = tk.Entry(frame, width=20)
    entry.insert(0, entry_default_text)
    entry.pack(side='left', anchor='center')

    var = tk.IntVar()
    var.set(check_button_default_choice)
    check_button = tk.Checkbutton(frame, text=checkbutton_text, variable=var)
    check_button.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return entry, var


def create_option_menu(frame_base, label_text, default_option, option_list):
    frame = tk.Frame(frame_base, width=800, height=50)
    label = tk.Label(frame, text=label_text, font=("宋体", 10))
    label.pack(side='left', anchor='center')
    var = tk.StringVar()
    var.set(default_option)
    option_menu = tk.OptionMenu(frame, var, *option_list)
    option_menu.pack(side='left', anchor='center')
    frame.pack(side='top', anchor='w')
    return var


def create_scrollbar(canvas_base):
    sb = tk.Scrollbar(canvas_base, orient='vertical', command=canvas_base.yview)
    sb.pack(side='right', fill='y')
    canvas_base.configure(yscrollcommand=sb.set)
