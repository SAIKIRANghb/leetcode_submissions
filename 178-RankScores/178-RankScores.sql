-- Last updated: 11/25/2026, 3:48:30 PM
# Write your MySQL query statement below
SELECT score, 
DENSE_RANK() OVER (ORDER BY score DESC) AS "Rank"
FROM Scores
