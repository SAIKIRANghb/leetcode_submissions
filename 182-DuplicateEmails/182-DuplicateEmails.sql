-- Last updated: 11/25/2026, 3:48:24 PM
# Write your MySQL query statement below
-- SELECT email
-- FROM Person
-- GROUP BY email
-- HAVING COUNT(*) > 1

WITH CTE AS (
    SELECT email, ROW_NUMBER() OVER(PARTITION BY email ORDER BY email) AS rnk
    FROM Person
)
SELECT DISTINCT email 
FROM CTE
WHERE rnk > 1