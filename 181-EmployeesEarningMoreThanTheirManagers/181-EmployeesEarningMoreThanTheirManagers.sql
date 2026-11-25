-- Last updated: 11/25/2026, 3:48:25 PM
# Write your MySQL query statement below
SELECT e1.name as Employee
FROM
Employee e1 JOIN Employee e2
ON e1.managerId = e2.id
AND e1.salary > e2.salary