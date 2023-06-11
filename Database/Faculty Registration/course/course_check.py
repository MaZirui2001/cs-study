import ttkbootstrap as ttk
import pymysql as sql
import common as common
from common import course_id2type, course_semester_map

course_check_items = {}
check_result_frame = []
detail_button_list = []
frame_check = None


def fresh(self):
    create_check_result(self)


def generate_check_sql(check_items):
    # 获取输入的论文信息
    course_name = check_items["course_name"].get()
    course_id = check_items["course_id"].get()
    course_year = check_items["course_year"].get()
    course_semester = check_items["course_semester"].get()
    teacher_name = check_items["teacher_name"].get()
    teacher_id = check_items["teacher_id"].get()
    # 一旦有一个条件不为空，就将其加入sql语句中
    sql_sentence = "select distinct course.id  from course \
        join teach_course tc on course.id = tc.course_id \
        join teacher on tc.teacher_id = teacher.id "
    t = ()
    if course_name != "" or course_id != "" or teacher_name != "" or teacher_id != "" or course_year != "" \
            or course_semester != '不限':
        sql_sentence += "where "
    if course_name != "":
        sql_sentence += "course.name = %s"
        t = t + (course_name,)
    if course_id != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "course.id = %s"
        t = t + (course_id,)
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
    if course_year != "":
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "tc.year = %s"
        t = t + (course_year,)
    if course_semester != '不限':
        if not sql_sentence.endswith("where "):
            sql_sentence += " and "
        sql_sentence += "tc.semester = %s"
        t = t + (course_semester_map[course_semester],)

    sql_sentence += " order by course.id;"
    return sql_sentence, t


def check_course(check_items):
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
    sql_sentence = "select course.name, course.id, course.type, course.credit_hour, " \
                   "teacher.name, teacher.id, tc.year, tc.semester, tc.undertake_hour " \
                   "from course join teach_course tc on course.id = tc.course_id " \
                   "join teacher on tc.teacher_id = teacher.id where course.id = %s order by course.id;"
    for i in range(len(data)):
        # 对每一个课程编号，查询其详细信息
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
    # 处理数据
    check_result = []
    for i in range(len(result)):
        check_result.append([])
        for j in range(4):
            check_result[i].append(result[i][0][j])
        check_result[i].append({})
        for j in range(len(result[i])):
            # key: year + semester
            key = str(result[i][j][6]) + ' ' + str(result[i][j][7])
            if key in check_result[i][4].keys():
                check_result[i][4][key].append((result[i][j][4], result[i][j][5], result[i][j][8]))
            else:
                check_result[i][4][key] = [(result[i][j][4], result[i][j][5], result[i][j][8])]
    # 显示简短信息
    check_result_simple = []
    for i in range(len(check_result)):
        check_result_simple.append(
            (check_result[i][1], check_result[i][0], check_result[i][3], check_result[i][2]))
    return check_result, check_result_simple


def create_check_result(self):
    check_result, check_result_simple = check_course(course_check_items)
    create_check_result_frame(self, check_result_simple, check_result)


def create_detail_check_top(self, check_item):
    top = ttk.Toplevel(self.root, minsize=(800, 800))
    top.title("课程详情")
    self.root.attributes("-disabled", True)
    top.protocol("WM_DELETE_WINDOW", lambda: common.close_window(self.root, top))
    # 30号字体靠左显示课程名称
    label_course_name = ttk.Label(top, text=check_item[0], font=("宋体", 20, "bold"), anchor='w')
    label_course_name.pack(side='top', anchor='w', pady=20)

    # 15号字体靠左显示课程编号
    label_course_id = ttk.Label(top, text="课程编号：" + str(check_item[1]), font=("宋体", 10), anchor='w')
    label_course_id.pack(side='top', anchor='w', pady=10)

    # 15号字体靠左显示课程学时
    label_course_source = ttk.Label(top, text="课程学时：" + str(check_item[3]), font=("宋体", 10), anchor='w')
    label_course_source.pack(side='top', anchor='w', pady=10)
    # 10号字体靠左显示课程性质
    # print(check_item[2])
    label_course_type = ttk.Label(top, text="课程类型：" + course_id2type[int(check_item[2])], font=("宋体", 10),
                                  anchor='w')
    label_course_type.pack(side='top', anchor='w', pady=10)

    # 10号字体靠左显示所有学期的所有课程教师
    for key in check_item[4].keys():
        string_info = key.split(' ')[0] + '年' + common.course_id2semester[int(key.split(' ')[1])]
        ttk.Label(top, text=string_info, font=("宋体", 10, 'bold'), anchor='w').pack(side='top', anchor='w', pady=5)
        for i in range(len(check_item[4][key])):
            string_info = '课程教师' + str(i + 1) + ": " + check_item[4][key][i][0] + '（'
            string_info += '工号: ' + str(check_item[4][key][i][1]) + ' '
            string_info += '承担学时: ' + str(check_item[4][key][i][2]) + '）'
            label_course_teacher = ttk.Label(top, text=string_info, font=("宋体", 10), anchor='w')
            label_course_teacher.pack(side='top', anchor='w', pady=5)


def create_check_result_frame(self, check_result_simple, check_result):
    for frame in check_result_frame:
        frame.destroy()
    check_result_frame.clear()
    for i in range(len(check_result_simple)):
        frame_course_check_result = ttk.Frame(frame_check, width=800, height=50)
        frame_course_check_result.pack(side='top', anchor='w')
        check_result_frame.append(frame_course_check_result)
        # 显示四栏：课程编号、课程名称、课程学时、课程类型, 用Text组件, 每一个后面跟一个详情按钮
        # 课程编号
        common.create_text(frame_course_check_result, str(check_result_simple[i][0]), 1, 0)
        # 课程名称
        common.create_text(frame_course_check_result, str(check_result_simple[i][1]), 1, 1)
        # 课程学时
        common.create_text(frame_course_check_result, str(check_result_simple[i][2]), 1, 2)
        # 课程类型
        common.create_text(frame_course_check_result, course_id2type[int(check_result_simple[i][3])], 1, 3)
        # 详情按钮
        button_course_detail = ttk.Button(frame_course_check_result, text="详情", width=5, style='success',
                                          command=lambda arg1=self, arg2=check_result[i]: create_detail_check_top(arg1,
                                                                                                                  arg2))
        button_course_detail.grid(row=0, column=4, padx=2)
        detail_button_list.append((button_course_detail, i))


def create_basic_info_frame(self, canvas_course, course_items, create_result, frame_course_check, name="课程信息查找"):
    # 创建滚动条
    common.create_scrollbar(canvas_course)

    # 创建label
    ttk.Label(frame_course_check, text=name, font=("微软雅黑", 15, 'bold')).pack(side='top', anchor='n')

    button_course_check = ttk.Button(frame_course_check, text="查询", width=10, style='success')
    button_course_check.pack(side='top', anchor='n')

    # 创建输入框, 获取输入的课程信息
    frame_course_info = ttk.Frame(frame_course_check, width=200, height=600)
    frame_course_info.pack(side='top', anchor='n')

    # 课程编号
    course_items["course_id"] = common.create_label_and_entry(frame_course_info, "课程编号", "")

    # 课程名称
    course_items["course_name"] = common.create_label_and_entry(frame_course_info, "课程名称", "")

    # 教师工号
    course_items["teacher_id"] = common.create_label_and_entry(frame_course_info, "教师编号", "")

    # 教师姓名
    course_items["teacher_name"] = common.create_label_and_entry(frame_course_info, "教师姓名", "")

    # 开课年份
    course_items["course_year"] = common.create_label_and_entry(frame_course_info, "开课年份", "")

    # 开课学期
    seme = ["none", "不限", "春季学期", "夏季学期", "秋季学期"]
    course_items["course_semester"] = common.create_option_menu(frame_course_info, "开课学期", seme[1], seme)

    # 创建查询结果显示框
    frame_course_check_result = ttk.Frame(frame_course_check, width=800, height=600)
    frame_course_check_result.pack(side='top', anchor='n')

    button_course_check.config(command=lambda: create_result(self))

    # 创建查询结果显示框label
    label_course_check_result = ttk.Label(frame_course_check_result, text="查询结果", font=("宋体", 15, 'bold'))
    label_course_check_result.pack(side='top', anchor='n', pady=20)

    frame_course_check_label = ttk.Frame(frame_course_check_result, width=800, height=50)
    frame_course_check_label.pack(side='top', anchor='n')

    ttk.Label(frame_course_check_label, text="课程编号", font=("宋体", 10), width=20).grid(row=0, column=0)
    ttk.Label(frame_course_check_label, text="课程名称", font=("宋体", 10), width=20).grid(row=0, column=1)
    ttk.Label(frame_course_check_label, text="课程学时", font=("宋体", 10), width=20).grid(row=0, column=2)
    ttk.Label(frame_course_check_label, text="课程类型", font=("宋体", 10), width=20).grid(row=0, column=3)
    return frame_course_check_label


def create_frame_course_check(self):
    global frame_check, course_check_items
    canvas_course_check = ttk.Canvas(self.root, width=1600, height=2400, scrollregion=(0, 0, 1600, 2400))
    frame_check = ttk.Frame(canvas_course_check, width=800, height=1200)

    self.frame_list["frame_course_check"] = canvas_course_check
    frame_check.pack(side='top', anchor='n')
    canvas_course_check.create_window(820, 0, anchor='n', window=frame_check)

    frame_course_check_label = create_basic_info_frame(self, canvas_course_check, course_check_items,
                                                       create_check_result, frame_check)
    ttk.Label(frame_course_check_label, text="", font=("宋体", 10), width=10).grid(row=0, column=4)
