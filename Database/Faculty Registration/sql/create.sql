# 如果数据库不存在，创建一个登记系统数据库
drop database if exists register_system;
create database register_system;
use register_system;

# 创建教师表
drop table if exists teacher;
create table teacher
(
    id     character(5),
    name   character(128) not null,
    gender int, # 1-男，2-女
    title  int, # 1-博士后，2-助教，3-讲师，4-副教授，5-特任教授，6-教授，
    # 7-助理研究员，8-特任副研究员，9-副研究员，10-特任研究员，11-研究员
    constraint teacher_pk primary key (id)
);
# 创建论文表
drop table if exists paper;
create table paper
(
    id            int,
    name          character(128) not null,
    public_source character(128) not null,
    public_date   date,
    type          int, # 1-full, 2-short, 3-poster, 4-demo
    level         int, # 1-CCF A, 2-CCF B, 3-CCF C, 4-中文CCF A, 5-中文CCF B, 6-无级别
    constraint paper_pk primary key (id)
);
# 创建项目表
drop table if exists project;
create table project
(
    id          character(128),
    name        character(128) not null,
    source      character(128) not null,
    type        int, # 1-国家级，2-省部级，3-市厅级，4-企业合作项目，5-其他
    expenditure float,
    start_year  int,
    end_year    int,
    constraint project_pk primary key (id)
);
# 创建课程表
drop table if exists course;
create table course
(
    id          character(128),
    name        character(128) not null,
    credit_hour int,
    type        int, # 1-本科生，2-研究生
    constraint course_pk primary key (id)
);

# 创建发表论文关系
drop table if exists publish_paper;
create table publish_paper
(
    teacher_id              char(5),
    paper_id                int,
    ranking                 int, # 1-第一作者，2-第二作者，3-第三作者，4-第四作者，5-第五作者
    is_corresponding_author bool, # 1-是，0-否
    constraint publish_paper_pk primary key (teacher_id, paper_id),
    constraint publish_paper_teacher_id_fk foreign key (teacher_id) references teacher (id),
    constraint publish_paper_paper_id_fk foreign key (paper_id) references paper (id)
);
# 创建承担项目关系
drop table if exists undertake_project;
create table undertake_project
(
    teacher_id  char(5),
    project_id  char(128),
    ranking     int, # 1-负责人，2-主要参与人，3-参与人
    expenditure float,
    constraint undertake_project_pk primary key (teacher_id, project_id),
    constraint undertake_project_teacher_id_fk foreign key (teacher_id) references teacher (id),
    constraint undertake_project_project_id_fk foreign key (project_id) references project (id)
);
# 创建主讲课程关系
drop table if exists teach_course;
create table teach_course
(
    teacher_id     char(5),
    course_id      char(128),
    year           int,
    semester       int, # 1-春季学期，2-夏季学期，3-秋季学期
    undertake_hour int,
    constraint teach_course_pk primary key (teacher_id, course_id, year, semester),
    constraint teach_course_teacher_id_fk foreign key (teacher_id) references teacher (id),
    constraint teach_course_course_id_fk foreign key (course_id) references course (id)
);

