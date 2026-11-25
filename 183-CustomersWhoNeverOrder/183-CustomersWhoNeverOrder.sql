-- Last updated: 11/25/2026, 3:48:21 PM
# Write your MySQL query statement below

## using joins
-- SELECT c.name AS Customers
-- FROM
-- Customers c
-- LEFT JOIN 
-- Orders o
-- ON c.id = o.customerId
-- WHERE o.customerId is NULL; 

##using subquery
SELECT name as Customers
FROM Customers C
WHERE C.id NOT IN (
    SELECT customerId
    FROM Orders
)