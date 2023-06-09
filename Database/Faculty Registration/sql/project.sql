use register_system;
# 插入一篇项目，检查教师是否存在
delimiter //
drop procedure if exists insert_project//
create procedure insert_project(
    in project_id char(128),
    in project_name char(128),
    in project_source char(128),
    in project_type int,
    in project_expenditure float,
    in project_start int,
    in project_end int
)
begin
    # 检查project是否存在
    if not exists(select * from project where id = project_id) then
        insert into project
        values (project_id, project_name, project_source, project_type, project_expenditure, project_start, project_end);
    else
        # 检查其他信息是否一致
        if not exists(select *
                      from project
                      where id = project_id
                        and name = project_name
                        and source = project_source
                        and expenditure = project_expenditure
                        and type = project_type
                        and start_year = project_start
                        and end_year = project_end
                      ) then
            signal sqlstate '45100' set message_text = '项目已经存在，本次插入信息不一致';
        end if;
    end if;

end//

# 插入教师-项目关系
drop procedure if exists insert_teacher_project//
create procedure insert_teacher_project(
    in teacher_id char(5),
    in teacher_name char(128),
    in project_id char(128),
    in ranking int,
    in expenditure float
)
insert_:
begin
    # 检查教师是否存在
    if not exists(select * from teacher where id = teacher_id) then
        signal sqlstate '45101' set message_text = '教师不存在';
    end if;
    # 检查教师姓名是否一致
    if not exists(select * from teacher where id = teacher_id and name = teacher_name) then
        signal sqlstate '45102' set message_text = '教师姓名不一致';
    end if;
    # 检查教师是否已经在项目中,若插入信息已经存在，则不做任何操作
    if exists(select *
              from undertake_project
              where undertake_project.teacher_id = teacher_id
                and undertake_project.project_id = project_id) then
        # 若插入信息与存储信息一致，则不做任何操作
        if exists(select *
                  from undertake_project
                  where undertake_project.teacher_id = teacher_id
                    and undertake_project.project_id = project_id
                    and undertake_project.ranking = ranking
                    and undertake_project.expenditure = expenditure) then
            leave insert_;
        end if;
        signal sqlstate '45103' set message_text = '有教师已经在本项目中登记，且本次插入信息不一致';
    end if;
    # 检查项目是否存在
    if not exists(select * from project where id = project_id) then
        signal sqlstate '45104' set message_text = '项目不存在';
    end if;
    # 检查教师排名不能重复
    if exists(select * from undertake_project where project_id = undertake_project.project_id and undertake_project.ranking = ranking) then
        signal sqlstate '45105' set message_text = '教师排名重复';
    end if;
    # 通过检查，插入教师-项目关系
    insert into undertake_project values (teacher_id, project_id, ranking, expenditure);
end //

# 删除一个项目
drop procedure if exists delete_project//
create procedure delete_project(
    in project_id char(128)
)
begin
    # 检查项目是否存在
    if not exists(select * from project where id = project_id) then
        signal sqlstate '45007' set message_text = '项目不存在';
    end if;

    # 删除项目-教师关系
    delete from undertake_project where project_id = undertake_project.project_id;
    delete from project where id = project_id;
end //