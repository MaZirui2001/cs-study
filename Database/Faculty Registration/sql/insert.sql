use register_system;
insert into teacher values (1, '张信明', 1, 2);
insert into teacher values (2, '张俊霞', 1, 2);
insert into teacher values (3, '王海龙', 1, 2);
insert into teacher values (4, '李永坤', 1, 4);
insert into teacher values (5, '李永坤', 1, 4);

insert into teacher values (6, '金培权', 2, 4);
insert into teacher values (7, '安虹', 3, 4);

insert into paper values(1, 'ZB+tree：一种"ZNS"感知', '计算机研究与发展', '2003.1.1', 3, 1);
insert into publish_paper values('6', 1, 2, 1);
insert into publish_paper values('7', 1, 3, 0);
insert into paper values(2, '基于ZB+tree的\'高效索引技术\'', 'DAC', '2003.1.1', 3, 1);
insert into publish_paper values('6', 2, 2, 0);
insert into publish_paper values('1', 2, 3, 1);

insert into project values('PPPP111', '学习方法研究', '国家自然', 1, '5000', '1999', '2000');
insert into undertake_project values('6', 'PPPP111', 1, '3000');
insert into undertake_project values('5', 'PPPP111', 2, '2000');
insert into project values('PPPP222', '学习方法研究', '国家自然', 1, '6000', '1999', '2000');
insert into undertake_project values('6', 'PPPP222', 1, '3000');
insert into undertake_project values('3', 'PPPP222', 2, '3000');