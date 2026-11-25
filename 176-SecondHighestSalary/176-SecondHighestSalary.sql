-- Last updated: 11/25/2026, 3:48:33 PM
# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee)