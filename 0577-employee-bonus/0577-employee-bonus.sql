# Write your MySQL query statement below

SELECT Employee.name as name, Bonus.bonus as bonus
FROM Employee
LEFT JOIN Bonus
ON Employee.empID = Bonus.empId
WHERE bonus IS NULL OR bonus < 1000