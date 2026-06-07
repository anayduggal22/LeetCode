# Write your MySQL query statement below

SELECT name as Employee
FROM Employee as e
WHERE managerId IS NOT NULL 
AND salary > (
    SELECT salary 
    FROM Employee
    WHERE id = e.managerId
)