use register_system;
# 查询论文名字为kkk，论文编号为1，作者名字为aaa，教师编号为1的论文信息
select *
from paper
         left join public_paper pp on paper.id = pp.paper_id
         left join teacher on pp.teacher_id = teacher.

