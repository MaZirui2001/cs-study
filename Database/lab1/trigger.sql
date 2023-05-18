use library;

-- 设计一个触发器，实现：当一本书被预约时, 自动将 Book 表中相应图书的status 修改为2，并增加 reserve_Times；
-- 当某本预约的书被借出时或者读者取消预约时, 自动减少 reserve_Times。
delimiter //
-- 当一本书被预约时, 自动将 Book 表中相应图书的status 修改为2，并增加 reserve_Times；
drop trigger if exists reserve_book;
create trigger reserve_book
    before insert
    on Reserve
    for each row
begin
    -- 不允许同一个人重复预约同一本书
    select count(*) into @reserve from Reserve where book_ID = new.book_id and reader_ID = new.reader_id;
    if @reserve != 0 then
        signal sqlstate '45000' set message_text = 'You have already reserved this book.';
    end if;
    -- 如果这本书被借出，那么status=1
    select count(*) into @borrow from Borrow where book_ID = new.book_id and return_date is null;
    if @borrow != 0 then
        update Book set status = 1 where ID = new.book_id;
    else
        update Book set status = 2 where ID = new.book_id;
    end if;

    update Book set reserve_Times = reserve_Times + 1 where ID = new.book_id;
end;

-- 当读者取消预约时, 自动减少 reserve_Times。
drop trigger if exists cancel_reserve;
create trigger cancel_reserve
    after delete
    on Reserve
    for each row
begin
    -- 如果这本书被借出，那么status=1
    select count(*) into @borrow from Borrow where book_ID = old.book_ID;
    select count(*) into @reserve from Reserve where book_ID = old.book_ID;
    update Book set reserve_Times = reserve_Times - 1 where ID = old.book_ID;
    update Book set status = 1 where ID = old.book_ID;
    if @borrow != 0 then
        update Book set status = 1 where ID = old.book_ID;
        -- 如果这本书还有预约，那么status=2
    elseif @reserve != 0 then
        update Book set status = 2 where ID = old.book_ID;
        -- 如果这本书没有预约，那么status=0
    else
        update Book set status = 0 where ID = old.book_ID;
    end if;
end;