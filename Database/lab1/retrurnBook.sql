use library;

-- 设计一个存储过程 returnBook，当读者还书时调用该存储过程完成还书处理。
-- 检查该书是否已经被借出或已经归还
-- 检查该读者是否已经借过该书
-- 更新图书状态
-- 更新借阅记录

delimiter //
drop procedure if exists returnBook;
create procedure returnBook(in readerId char(8), in bookId char(8), in returnDate date)
begin
    -- 检查该书是否存在
    select count(*) into @count from Book where ID = bookId;
    if @count = 0 then
        signal sqlstate '45000' set message_text = 'This book does not exist.';
    end if;

    -- 检查该读者是否存在
    select count(*) into @count from Reader where ID = readerId;
    if @count = 0 then
        signal sqlstate '45000' set message_text = 'This reader does not exist.';
    end if;

    -- 检查该书是否已经被借出或已经归还
    select status into @status from Book where ID = bookId;
    if @status != 1 then
        signal sqlstate '45000' set message_text = 'This book is not borrowed or has been returned.';
    end if;

    -- 检查该读者是否已经借过该书
    select count(*) into @count from Borrow where bookId = book_ID and readerId = reader_ID;
    if @count = 0 then
        signal sqlstate '45000' set message_text = 'This reader has not borrowed this book.';
    end if;

    -- 更新借阅记录
    select count(*)
    into @count
    from Borrow
    where bookId = book_ID
      and readerId = reader_ID
      and return_Date is null
      and borrow_Date > returnDate;
    if @count != 0 then
        signal sqlstate '45000' set message_text = 'The return date is earlier than the borrow date.';
    end if;
    update Borrow set return_Date = returnDate where bookId = book_ID and readerId = reader_ID and return_Date is null;

    -- 更新图书状态
    select count(*) into @count from Reserve where book_ID = bookId and take_Date is null;
    if @count != 0 then
        update Book set status = 2 where ID = bookId;
    else
        update Book set status = 0 where ID = bookId;
    end if;

    -- 输出成功信息
    select 'Return book successfully.' as message;
end //

