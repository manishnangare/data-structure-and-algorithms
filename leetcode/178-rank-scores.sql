# Write your MySQL query statement below

select C.score, B.r as "rank"
from Scores as C
inner join (select A.score, row_number() over (order by A.score desc) as r
from Scores as A
group by A.score) as B
on B.score = C.score
order by C.score desc

