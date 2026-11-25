-- Last updated: 11/25/2026, 3:48:17 PM
# Write your MySQL query statement below

-- SELECT d.name as Department, e.name as Employee, e.salary as Salary
-- FROM Employee e
-- JOIN Department d
-- ON e.departmentId = d.id
-- WHERE (e.name, e.departmentId, e.salary) IN (
--     SELECT name, departmentId, salary 
--     FROM (
--         SELECT name, departmentId, salary, DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS rnk 
--         FROM Employee
--     ) T WHERE rnk <= 3
-- )

WITH dept_rank AS (
    SELECT name as Employee, Salary, departmentId,
    DENSE_RANK() OVER (PARTITION BY DepartmentId ORDER BY Salary DESC) AS rnk
    FROM Employee
)

SELECT d.Name AS Department, r.Employee, r.Salary
FROM dept_rank AS r
JOIN Department AS d
ON r.DepartmentId = d.Id
WHERE r.rnk <= 3
ORDER BY d.name ASC, r.salary DESC;