# Write your MySQL query statement below

select C.name as Department, A.name as Employee, A.salary as Salary
from Employee as A
inner join Department as C
    on C.id = A.departmentId
where A.salary = ( select max(B.salary) from Employee as B where B.departmentId = A.departmentId);