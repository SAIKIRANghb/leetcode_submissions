-- Last updated: 11/25/2026, 3:44:52 PM
# Write your MySQL query statement below
-- SELECT player_id, MIN(event_date) as first_login 
-- FROM Activity
-- GROUP BY player_id

SELECT player_id, MIN(event_date) as first_login
FROM Activity
GROUP BY player_id
HAVING MIN(event_date)