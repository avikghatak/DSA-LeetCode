# Write your MySQL query statement below
SELECT Department.name as Department, Employee.name as Employee, Employee.salary as Salary
FROM Employee JOIN Department 
WHERE Employee.departmentId = Department.id
AND (DepartmentId, Salary) IN(
        SELECT  DepartmentId, MAX(Salary) AS Salary
        FROM Employee
        GROUP BY DepartmentId
        );