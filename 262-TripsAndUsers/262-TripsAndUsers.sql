-- Last updated: 11/25/2026, 3:47:51 PM
# Write your MySQL query statement below
WITH CTE AS (
    SELECT users_id 
    FROM Users
    WHERE banned = 'Yes'
)

SELECT request_at AS Day,
ROUND(SUM(IF(status <> "completed", 1, 0)) / COUNT(Status) ,2) AS "Cancellation Rate"
FROM Trips
WHERE request_at BETWEEN "2013-10-01" AND "2013-10-03"
AND client_id NOT IN (
    SELECT users_id FROM CTE
) 
AND driver_id NOT IN (
    SELECT users_id FROM CTE
)
GROUP BY request_at