# Write your MySQL query statement below
select s.product_id , s.year 
as first_year , s.quantity , s.price
from Sales s 
join (
    select product_id , min(year) 
    as first_year
    from Sales
    group by product_id
) f
on s.product_id = f.product_id
AND s.year = f.first_year;