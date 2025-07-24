# Write your MySQL query statement below
select p.product_id,ifnull(round((sum(p.price*q.units)/sum(q.units)),2),0)  as average_price
from Prices as p
left join UnitsSold as q
on p.product_id = q.product_id and q.purchase_date between p.start_date and p.end_date
group by p.product_id;