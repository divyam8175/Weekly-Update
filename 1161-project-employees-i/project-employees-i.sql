# Write your MySQL query statement below
select p.project_id,round(sum(q.experience_years)/count(p.project_id),2)as average_years
from Project as p
left join Employee as q
on p.employee_id = q.employee_id
group by p.project_id;
