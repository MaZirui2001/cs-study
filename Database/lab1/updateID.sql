use library;

-- 设计一个存储过程 updateReaderID,实现对读者表的 ID 的修改
drop procedure if exists updateReaderID;
delimiter //
create procedure updateReaderID(in oldID char(8), in newID char(8))
begin
    -- check if the new ID is already in the table
    select count(*) into @count from Reader where ID = newID;
    if @count > 0 then
        signal sqlstate '45000'
            set message_text = 'The new ID is already in the table';
    end if;

    -- check if the old ID is already in the table
    select count(*) into @count from Reader where ID = oldID;
    if @count = 0 then
        signal sqlstate '45000'
            set message_text = 'The old ID is not in the table';
    end if;

    start transaction;
    update Borrow set Reader_ID = newID where Reader_ID = oldID;
    update Reserve set Reader_ID = newID where Reader_ID = oldID;
    update Reader set ID = newID where ID = oldID;
    commit;
end;
delimiter ;






