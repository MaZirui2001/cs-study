-- create library
drop
    database if exists library;
create
    database library;
use
    library;

-- create book table
create table Book
(
    ID            char(8) primary key,
    name          varchar(10) not null,
    author        varchar(10),
    price         float,
    status        int check ( status in (0, 1, 2, 3) ),
    borrow_Times  int,
    reserve_Times int default 0
);

-- create reader table
create table Reader
(
    ID      char(8) primary key,
    name    varchar(10),
    age     int check ( age >= 0 ),
    address varchar(20)
);

-- create borrow table
create table Borrow
(
    book_ID     char(8) references Book (ID),
    reader_ID   char(8) references Reader (ID),
    borrow_Date date,
    return_Date date,
    primary key (book_ID, reader_ID, borrow_Date),
    check ( return_Date >= borrow_Date )
);

-- create reserve table
create table Reserve
(
    book_ID      char(8) references Book (ID),
    reader_ID    char(8) references Reader (ID),
    reserve_Date date default (curdate()),
    take_Date    date,
    primary key (book_ID, reader_ID, reserve_Date),
    check ( take_Date >= reserve_Date )
);

