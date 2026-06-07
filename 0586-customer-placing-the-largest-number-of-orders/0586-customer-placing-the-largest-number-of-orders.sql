# Write your MySQL query statement below

SELECT customer_number 
FROM (
    SELECT customer_number,COUNT(customer_number) as cnt
    FROM Orders
    GROUP BY customer_number
    ORDER BY COUNT(customer_number) DESC
) as temp
LIMIT 1


