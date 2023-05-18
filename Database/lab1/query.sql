use library;

-- 1. 查询读者 Rose 借过的读书（包括已还和未还）的图书号、书名和借期；
select b.ID, b.name, w.borrow_Date
from Borrow w
         join Book b on w.book_ID = b.ID
         join Reader r on w.reader_ID = r.ID
where r.name = 'Rose';

-- 2. 查询从没有借过图书也从没有预约过图书的读者号和读者姓名；
select r.ID, r.name
from Reader r
where r.ID not in (select distinct reader_ID
                   from Borrow)
  and r.ID not in (select distinct reader_ID
                   from Reserve);

-- 3. 查询被借阅次数最多的作者（注意一个作者可能写了多本书）；
select b.author
from Book b
group by b.author
having SUM(b.borrow_Times)
order by SUM(b.borrow_Times) DESC
limit 1;

-- 4. 查询目前借阅未还的书名中包含“MySQL”的的图书号和书名；
select b.ID, b.name
from Book b
         join Borrow w on w.book_ID = b.ID
where b.name like '%MySQL%'
  and w.return_Date is null;

-- 5. 查询借阅图书数目超过 10 本的读者姓名；
select r.name
from Reader r
         join Borrow w on w.reader_ID = r.ID
group by r.ID
having count(*) > 10;

-- 6. 查询没有借阅过任何一本 John 所著的图书的读者号和姓名；
select re.ID, re.name
from Reader re
where re.ID not in (select r.ID
                    from Reader r
                             join Borrow w on w.reader_ID = r.ID
                             join Book b on w.book_ID = b.ID
                    where b.author = 'John');

-- 7.查询 2022 年借阅图书数目排名前 10 名的读者号、姓名以及借阅图书数；
select r.ID, r.name, count(*) as num
from Reader r
         join Borrow w on w.reader_ID = r.ID
where w.borrow_Date like '2022%'
group by r.ID
order by num DESC
limit 10;

-- 8.创建一个读者借书信息的视图,该视图包含读者号、姓名、所借图书号、图书名和借期；
-- 并使用该视图查询最近一年所有读者的读者号以及所借阅的不同图书数；
create view BorrowInfo as
select r.ID as reader_ID, r.name as reader_name, b.ID as book_ID, b.name as book_name, w.borrow_Date
from Reader r
         join Borrow w on r.ID = w.reader_ID
         join Book b on b.ID = w.book_ID;

select reader_ID, count(distinct book_ID) as num
from BorrowInfo
where borrow_Date >= DATE_SUB(CURDATE(), INTERVAL 1 YEAR)
group by reader_ID;
