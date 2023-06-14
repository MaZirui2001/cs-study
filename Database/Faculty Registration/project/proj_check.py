import ttkbootstrap as ttk
import pymysql as sql
import common as common
from common import proj_id2type

proj_check_items = {}
check_result_frame = []
detail_button_list = []
frame_check = None


def fresh(self):
    create_check_result(self)


def generate_check_sql(check_items):
    # 获取输入的论文信息
    proj_name = check_items["proj_name"].get()
    proj_id = check_items["proj_id"].get()
    teacher_name = check_items["teacher_name"].get()
    teacher_id = check_items["teacher_id"].get()
    proj_source = check_items["proj_source"].get()
    # 一旦有一个条件不为空，就将其加入sql语句中
    sql_sentence = "select distinct project.id  from project \
        join undertake_project up on project.id = up.project_id \
        join teacher on up.teacher_id = teacher.id "
    t = ()
    if proj_name != "" or proj_id != "" or teacher_name != "" or teacher_id != "" or proj_source != "":
        sql_sentence += "where "
    if proj_name != "":
        sql_sentence += "project.name = %s"
        t = t + (proj_name,)
    if proj_id != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "project.id = %s"
        t = t + (proj_id,)
    if teacher_name != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "teacher.name = %s"
        t = t + (teacher_name,)
    if teacher_id != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "teacher.id = %s"
        t = t + (teacher_id,)
    if proj_source != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "project.source = %s"
        t = t + (proj_source,)

    sql_sentence += " order by project.id;"
    return sql_sentence, t


def check_proj(check_items):
    temp = generate_check_sql(check_items)
    if temp is None:
        return [], []
    sql_sentence, t = temp
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
    # 使用execute方法执行SQL语句
    try:
        cursor.execute(sql_sentence, t)
    except sql.Error as e:
        db.close()
        print("查询失败：" + str(e))
        exit(-1)
    # 使用fetchall()方法获取所有数据
    data = cursor.fetchall()
    data_detail = []
    sql_sentence = "select project.name, project.id, project.source, project.type, project.expenditure, " \
                   "project.start_year, project.end_year, teacher.name, teacher.id, up.ranking, up.expenditure " \
                   "from project join undertake_project up on project.id = up.project_id " \
                   "join teacher on up.teacher_id = teacher.id where project.id = %s order by project.id;"
    for i in range(len(data)):
        # 对每一个项目编号，查询其详细信息
        try:
            cursor.execute(sql_sentence, data[i][0])
        except sql.Error as e:
            db.close()
            print("查询失败：" + str(e))
            exit(-1)
        # 使用fetchall()方法获取所有数据
        data_detail.append(cursor.fetchall())
    # 关闭数据库连接
    db.close()

    # 将查询结果存入全局变量中
    result = data_detail
    # print(result)
    # 处理数据
    check_result = []
    for i in range(len(result)):
        check_result.append([])
        for j in range(7):
            check_result[i].append(result[i][0][j])
        check_result[i].append([])
        for j in range(len(result[i])):
            check_result[i][7].append([result[i][j][7], result[i][j][8], result[i][j][9], result[i][j][10]])

    # 按照排名对每一篇文章的作者进行排序
    for i in range(len(check_result)):
        check_result[i][7].sort(key=lambda x: x[2])

    # 显示简短信息
    check_result_simple = []
    for i in range(len(check_result)):
        check_result_simple.append(
            (check_result[i][0], check_result[i][7][0][0], check_result[i][2], check_result[i][3]))
    # create_check_result_frame(self, frame_paper_check)
    return check_result, check_result_simple


def create_check_result(self):
    check_result, check_result_simple = check_proj(proj_check_items)
    create_check_result_frame(self, check_result_simple, check_result)


def create_detail_check_top(self, check_item):
    top = ttk.Toplevel(self.root, minsize=(800, 800))
    top.title("项目详情")
    self.root.attributes("-disabled", True)
    top.protocol("WM_DELETE_WINDOW", lambda: common.close_window(self.root, top))
    # top.resizable(False, False)
    # 30号字体靠左显示项目名称
    label_proj_name = ttk.Label(top, text=check_item[0], font=("宋体", 20, "bold"), anchor='w')
    label_proj_name.pack(side='top', anchor='w', pady=20)

    # 15号字体靠左显示项目编号
    label_proj_id = ttk.Label(top, text="项目编号：" + str(check_item[1]), font=("宋体", 10), anchor='w')
    label_proj_id.pack(side='top', anchor='w', pady=10)

    # 15号字体靠左显示项目来源
    label_proj_source = ttk.Label(top, text="项目来源：" + str(check_item[2]), font=("宋体", 10), anchor='w')
    label_proj_source.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示项目类型
    label_proj_type = ttk.Label(top, text="项目类型：" + proj_id2type[check_item[3]], font=("宋体", 10),
                                anchor='w')
    label_proj_type.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示项目总经费
    label_proj_expend = ttk.Label(top, text="项目经费：" + str(check_item[4]), font=("宋体", 10),
                                  anchor='w')
    label_proj_expend.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示开始时间
    label_proj_start = ttk.Label(top, text="开始时间：" + str(check_item[5]), font=("宋体", 10),
                                 anchor='w')
    label_proj_start.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示结束时间
    label_proj_start = ttk.Label(top, text="结束时间：" + str(check_item[5]), font=("宋体", 10),
                                 anchor='w')
    label_proj_start.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示所有项目员工
    for i in range(len(check_item[7])):
        string_info = "项目员工" + str(check_item[7][i][2]) + ": " + str(check_item[7][i][0])
        string_info += "（"
        string_info += "工号：" + str(check_item[7][i][1])
        string_info += " 经费：" + str(check_item[7][i][3])
        string_info += "）"
        label_proj_author = ttk.Label(top, text=string_info,
                                      font=("宋体", 10), anchor='w')
        label_proj_author.pack(side='top', anchor='w')


def create_check_result_frame(self, check_result_simple, check_result):
    for frame in check_result_frame:
        frame.destroy()
    check_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_proj_check_result = ttk.Frame(frame_check, width=800, height=50)
        frame_proj_check_result.pack(side='top', anchor='w')
        check_result_frame.append(frame_proj_check_result)
        # 显示四栏：项目名称、最高员工、项目级别、项目来源, 用Text组件, 每一个后面跟一个详情按钮
        # 项目名称
        common.create_text(frame_proj_check_result, str(check_result_simple[i][0]), 1, 0)
        # 最高员工
        common.create_text(frame_proj_check_result, str(check_result_simple[i][1]), 1, 1)
        # 项目来源
        common.create_text(frame_proj_check_result, str(check_result_simple[i][2]), 1, 2)
        # 项目类型
        common.create_text(frame_proj_check_result, proj_id2type[check_result_simple[i][3]], 1, 3)
        # 详情按钮
        button_proj_detail = ttk.Button(frame_proj_check_result, text="详情", width=5, style="success",
                                        command=lambda arg1=self, arg2=check_result[i]: create_detail_check_top(arg1,
                                                                                                                arg2))
        button_proj_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_proj_detail, i))


def create_basic_info_frame(self, canvas_proj, proj_items, create_result, frame_proj_check, name="项目信息查找"):
    # 创建滚动条
    common.create_scrollbar(canvas_proj)

    # 创建label
    ttk.Label(frame_proj_check, text=name, font=("微软雅黑", 15, 'bold')).pack(side='top', anchor='n')

    button_proj_check = ttk.Button(frame_proj_check, text="查询", width=10, style="success")
    button_proj_check.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的项目信息
    frame_proj_info = ttk.Frame(frame_proj_check, width=200, height=600)
    frame_proj_info.pack(side='top', anchor='n')

    # 项目编号
    proj_items["proj_id"] = common.create_label_and_entry(frame_proj_info, "项目编号", "")

    # 项目名称
    proj_items["proj_name"] = common.create_label_and_entry(frame_proj_info, "项目名称", "")

    # 项目来源
    proj_items["proj_source"] = common.create_label_and_entry(frame_proj_info, "项目来源", "")

    # 参与者编号
    proj_items["teacher_id"] = common.create_label_and_entry(frame_proj_info, "员工编号", "")

    # 参与者姓名
    proj_items["teacher_name"] = common.create_label_and_entry(frame_proj_info, "员工姓名", "")

    # 创建查询结果显示框
    frame_proj_check_result = ttk.Frame(frame_proj_check, width=800, height=600)
    frame_proj_check_result.pack(side='top', anchor='n')

    button_proj_check.config(command=lambda: create_result(self))

    # 创建查询结果显示框label
    label_proj_check_result = ttk.Label(frame_proj_check_result, text="查询结果", font=("宋体", 15, 'bold'))
    label_proj_check_result.pack(side='top', anchor='n', pady=20)

    frame_proj_check_label = ttk.Frame(frame_proj_check_result, width=800, height=50)
    frame_proj_check_label.pack(side='top', anchor='n')

    ttk.Label(frame_proj_check_label, text="项目名称", font=("宋体", 10), width=20).grid(row=0, column=0)
    ttk.Label(frame_proj_check_label, text="最高员工", font=("宋体", 10), width=20).grid(row=0, column=1)
    ttk.Label(frame_proj_check_label, text="项目来源", font=("宋体", 10), width=20).grid(row=0, column=2)
    ttk.Label(frame_proj_check_label, text="项目类型", font=("宋体", 10), width=20).grid(row=0, column=3)

    return frame_proj_check_label


def create_frame_proj_check(self):
    global frame_check, proj_check_items
    canvas_proj_check = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_check = ttk.Frame(canvas_proj_check, width=800, height=1200)
    self.frame_list["frame_proj_check"] = canvas_proj_check
    frame_check.pack(side='top', anchor='n')
    canvas_proj_check.create_window(820, 0, anchor='n', window=frame_check)

    frame_proj_check_label = create_basic_info_frame(self, canvas_proj_check, proj_check_items, create_check_result,
                                                     frame_check)
    ttk.Label(frame_proj_check_label, text="", font=("宋体", 10), width=10).grid(row=0, column=4)
