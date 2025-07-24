# Write your MySQL query statement below
select p.id,p.movie,p.description,p.rating
from Cinema as p
where p.id%2=1 and p.description != 'boring'
order by p.rating DESC;