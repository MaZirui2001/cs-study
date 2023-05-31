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
                      where name = paper_name
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
    in paper_id int,
    in ranking int,
    in is_corresponding_author bool
)
begin
    # 检查教师是否存在
    if not exists(select * from teacher where id = teacher_id) then
        signal sqlstate '45001' set message_text = '教师不存在';
    end if;
    # 检查论文是否存在
    if not exists(select * from paper where id = paper_id) then
        signal sqlstate '45002' set message_text = '论文不存在';
    end if;
    # 检查教师排名不能重复
    if exists(select * from public_paper where public_paper.teacher_id = teacher_id and public_paper.ranking = ranking) then
        signal sqlstate '45003' set message_text = '教师排名重复';
    end if;
    # 检查论文只能有一个通讯作者
    if is_corresponding_author and exists(select * from public_paper where public_paper.paper_id = paper_id and public_paper.is_corresponding_author = 1) then
        signal sqlstate '45004' set message_text = '论文已有通讯作者';
    end if;
    # 通过检查，插入教师-论文关系
    insert into public_paper values (teacher_id, paper_id, ranking, is_corresponding_author);
end //