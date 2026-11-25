-- Last updated: 11/25/2026, 3:48:27 PM
# Write your MySQL query statement below

-- WITH CTE AS (
--     SELECT num, 
--     lead(num, 1) over() num1,
--     lead(num, 2) over() num2
--     from logs
-- )

-- SELECT DISTINCT num ConsecutiveNums from CTE WHERE (num = num1) and (num = num2)

SELECT DISTINCT a.Num as ConsecutiveNums
FROM Logs a
JOIN Logs b
ON a.id = b.id+1 AND a.num = b.num
JOIN Logs c
ON b.id = c.id + 1 AND a.num = c.num