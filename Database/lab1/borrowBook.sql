use library;

-- 设计一个存储过程 borrowBook, 当读者借书时调用该存储过程完成借书处理。
-- a) 同一天不允许同一个读者重复借阅同一本读书；
-- b) 如果该图书存在预约记录，而当前借阅者没有预约，则不允许借阅；
-- c) 一个读者最多只能借阅 3 本图书，意味着如果读者已经借阅了 3 本图书并且未归还则不允许再借书；
-- d) 如果借阅者已经预约了该图书，则允许借阅，但要求借阅完成后删除借阅者对该图书的预约记录；
-- e) 借阅成功后图书表中的 times 加 1；
-- f) 借阅成功后修改 status。
delimiter //
drop procedure if exists borrowBook;
create procedure borrowBook(in readerId char(8), in bookId char(8), in borrowDate date)
begin
    -- 检查读者是否存在
    select count(*) into @reader from Reader where ID = readerId;
    if @reader = 0 then
        signal sqlstate '45000' set message_text = 'Reader is not exist';
    end if;

    -- 检查图书是否存在
    select count(*) into @book from Book where ID = bookId;
    if @book = 0 then
        signal sqlstate '45000' set message_text = 'Book is not exist';
    end if;

    -- 检查图书是否为可借状态
    select count(*) into @borrow from Borrow where book_ID = bookId and return_Date is null;
    select count(*) into @others from Reserve where book_ID = bookId and take_Date is null and reader_ID != readerId;
    select count(*) into @mine from Reserve where book_ID = bookId and take_Date is null and reader_ID = readerId;
    if @borrow or (@mine = 0 and @others != 0) then
        signal sqlstate '45000' set message_text = 'Book is not available';
    end if;

    -- a) 同一天不允许同一个读者重复借阅同一本读书；
    select count(*)
    into @count
    from Borrow
    where book_ID = bookId
      and reader_ID = readerId
      and borrow_date = borrowDate;
    if @count > 0 then
        signal sqlstate '45000' set message_text = 'Reader has already borrowed this book today';
    end if;

    -- c) 一个读者最多只能借阅 3 本图书，意味着如果读者已经借阅了 3 本图书并且未归还则不允许再借书；
    select count(*) into @count from Borrow where reader_ID = readerId and return_Date is null;
    if @count >= 3 then
        signal sqlstate '45000' set message_text = 'Reader has borrowed 3 books';
    end if;

    -- b) 如果该图书存在预约记录，而当前借阅者没有预约，则不允许借阅；
    -- d) 如果借阅者已经预约了该图书，则允许借阅，但要求借阅完成后删除借阅者对该图书的预约记录；
    select count(*) into @count from Reserve where book_ID = bookId and reader_ID = readerId and take_Date is null;
    if @count = 0 then
        select count(*) into @count from Reserve where book_ID = bookId and take_Date is null;
        if @count > 0 then
            signal sqlstate '45000' set message_text = 'Reader has not reserved this book and it is reserved by others';
        end if;
    end if;

    -- 检查通过，可以借阅
    insert into Borrow(reader_ID, book_ID, borrow_Date) values (readerId, bookId, borrowDate);
    set @row = row_count();
    if @row = 0 then
        signal sqlstate '45000' set message_text = 'Failed to insert new borrowing record';
    end if;
    -- e) 借阅成功后图书表中的 times 加 1；
    -- f) 借阅成功后修改 status。
    update Book set borrow_Times = Book.borrow_Times + 1, status = 1 where ID = bookId;
    set @row = row_count();
    if @row = 0 then
        signal sqlstate '45000' set message_text = 'Failed to update borrow times and status';
    end if;
    delete from Reserve where book_ID = bookId and reader_ID = readerId and take_Date is null;

    -- 输出成功信息
    select 'Borrow successfully' as message;
end;
delimiter ;

