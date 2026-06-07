# Write your MySQL query statement below

SELECT Department.name AS Department, Employee.name AS Employee,
       Employee.salary AS Salary
FROM Employee
JOIN Department
ON Department.id = Employee.departmentId
WHERE Employee.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE Department.id = Employee.departmentId
);