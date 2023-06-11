use register_system;
# 插入一个课程，检查教师是否存在
delimiter //
drop procedure if exists insert_course//
create procedure insert_course(
    in course_id char(128),
    in course_name char(128),
    in course_hour int,
    in course_type int
)
begin
    # 检查course是否存在
    if not exists(select * from course where id = course_id) then
        insert into course
        values (course_id, course_name, course_hour, course_type);
    else
        # 检查course其他信息是否一致
        if not exists(select *
                      from course
                      where id = course_id
                        and name = course_name
                        and type = course_type
                        and credit_hour = course_hour) then
            signal sqlstate '45200' set message_text = 'course已经存在，本次插入信息不一致';
        end if;
    end if;

end//

# 插入教师-课程关系
drop procedure if exists insert_teacher_course//
create procedure insert_teacher_course(
    in teacher_id char(5),
    in teacher_name char(128),
    in course_id char(128),
    in year int,
    in semester int,
    in undertake_hour int
)
insert_:
begin
    # 检查教师是否存在
    if not exists(select * from teacher where id = teacher_id) then
        signal sqlstate '45201' set message_text = '教师不存在';
    end if;
    # 检查教师姓名是否一致
    if not exists(select * from teacher where id = teacher_id and name = teacher_name) then
        signal sqlstate '45202' set message_text = '教师姓名不一致';
    end if;

    # 检查课程是否存在
    if not exists(select * from course where id = course_id) then
        signal sqlstate '45203' set message_text = '课程不存在';
    end if;

    # 若插入信息与存储信息一致，则不做任何操作
    if exists(select *
              from teach_course
              where teach_course.teacher_id = teacher_id
                and teach_course.course_id = course_id
                and teach_course.year = year
                and teach_course.semester = semester
                and teach_course.undertake_hour = undertake_hour) then
        leave insert_;
    end if;
    # 通过检查，插入教师-课程关系
    insert into teach_course values (teacher_id, course_id, year, semester, undertake_hour);
end //

# 删除一篇课程
drop procedure if exists delete_course//
create procedure delete_course(
    in course_id char(128)
)
begin
    # 检查课程是否存在
    if not exists(select * from course where id = course_id) then
        signal sqlstate '45007' set message_text = '课程不存在';
    end if;

    # 删除课程-教师关系
    delete from teach_course where course_id = teach_course.course_id;
    delete from course where id = course_id;
end //
