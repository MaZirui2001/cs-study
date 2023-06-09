use register_system;
# 插入一篇论文，检查教师是否存在
delimiter //
drop procedure if exists insert_paper//
create procedure insert_paper(
    in paper_id int,
    in paper_name char(128),
    in paper_public_source char(128),
    in paper_public_date date,
    in paper_type int,
    in paper_level int
)
begin
    # 检查paper是否存在
    if not exists(select * from paper where id = paper_id) then
        insert into paper
        values (paper_id, paper_name, paper_public_source, paper_public_date, paper_type, paper_level);
    else
        # 检查paper其他信息是否一致
        if not exists(select *
                      from paper
                      where id = paper_id
                        and name = paper_name
                        and public_source = paper_public_source
                        and public_date = paper_public_date
                        and type = paper_type
                        and level = paper_level) then
            signal sqlstate '45000' set message_text = 'paper已经存在，本次插入信息不一致';
        end if;
    end if;

end//

# 插入教师-论文关系
drop procedure if exists insert_teacher_paper//
create procedure insert_teacher_paper(
    in teacher_id char(5),
    in teacher_name char(128),
    in paper_id int,
    in ranking int,
    in is_corresponding_author bool
)
insert_:
begin
    # 检查教师是否存在
    if not exists(select * from teacher where id = teacher_id) then
        signal sqlstate '45001' set message_text = '教师不存在';
    end if;
    # 检查教师姓名是否一致
    if not exists(select * from teacher where id = teacher_id and name = teacher_name) then
        signal sqlstate '45002' set message_text = '教师姓名不一致';
    end if;
    # 检查教师是否已经在论文中,若插入信息已经存在，则不做任何操作
    if exists(select *
              from publish_paper
              where publish_paper.teacher_id = teacher_id and publish_paper.paper_id = paper_id) then
        # 若插入信息与存储信息一致，则不做任何操作
        if exists(select *
                  from publish_paper
                  where publish_paper.teacher_id = teacher_id
                    and publish_paper.paper_id = paper_id
                    and publish_paper.ranking = ranking
                    and publish_paper.is_corresponding_author = is_corresponding_author) then
            leave insert_;
        end if;
        signal sqlstate '45003' set message_text = '有教师已经在本论文中登记，且本次插入信息不一致';
    end if;
    # 检查论文是否存在
    if not exists(select * from paper where id = paper_id) then
        signal sqlstate '45004' set message_text = '论文不存在';
    end if;
    # 检查教师排名不能重复
    if exists(select * from publish_paper where paper_id = publish_paper.paper_id and publish_paper.ranking = ranking) then
        signal sqlstate '45005' set message_text = '教师排名重复';
    end if;
    # 检查论文只能有一个通讯作者
    if is_corresponding_author and exists(select *
                                          from publish_paper
                                          where publish_paper.paper_id = paper_id
                                            and publish_paper.is_corresponding_author = 1) then
        signal sqlstate '45006' set message_text = '论文已有通讯作者';
    end if;
    # 通过检查，插入教师-论文关系
    insert into publish_paper values (teacher_id, paper_id, ranking, is_corresponding_author);
end //

# 删除一篇论文
drop procedure if exists delete_paper//
create procedure delete_paper(
    in paper_id int
)
begin
    # 检查论文是否存在
    if not exists(select * from paper where id = paper_id) then
        signal sqlstate '45007' set message_text = '论文不存在';
    end if;

    # 删除论文-教师关系
    delete from publish_paper where paper_id = publish_paper.paper_id;
    delete from paper where id = paper_id;
end //
