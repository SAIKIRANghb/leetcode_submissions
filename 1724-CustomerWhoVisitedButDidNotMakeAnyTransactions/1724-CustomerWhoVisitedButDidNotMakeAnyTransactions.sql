-- Last updated: 11/25/2026, 3:43:27 PM
# Write your MySQL query statement below
select customer_id,COUNT(*) as count_no_trans from  Visits where visit_id not in(Select visit_id from Transactions) group by customer_id order by count_no_trans;  