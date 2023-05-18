use library;
-- borrow book
call borrowBook('r1', 'b9', curdate());
call borrowBook('r2', 'b9', curdate());
call borrowBook('r3', 'b9', curdate());
call borrowBook('r4', 'b9', curdate());
call borrowBook('r22', 'b10', curdate());
call borrowBook('r21', 'b10', curdate());
call borrowBook('r20', 'b10', curdate());

call borrowBook('r10', 'b7', curdate());
call borrowBook('r10', 'b8', curdate());
call borrowBook('r10', 'b17', curdate());
call borrowBook('r10', 'b18', curdate());

-- return book
call returnBook('r1', 'b9', current_date());
call returnBook('r2', 'b9', current_date());
call returnBook('r20', 'b10', current_date());
call returnBook('r23', 'b11', current_date());

call updateReaderID('r21', 'r99');
call updateReaderID('r100', 'r22');
call updateReaderID('r21', 'r1');

insert into Reserve value('b9', 'r3', '2023-02-18', NULL);
insert into Reserve value('b9', 'r4', '2023-02-18', NULL);