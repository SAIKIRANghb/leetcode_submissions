-- Last updated: 11/25/2026, 3:48:19 PM
# Write your MySQL query statement below

SELECT d.name as Department, e.name as Employee, salary as Salary
FROM Employee e
JOIN Department d
ON e.departmentId = d.id
WHERE (departmentId, Salary) IN (
    SELECT departmentId, MAX(salary) AS Salary 
    FROM Employee
    GROUP BY departmentId
)
