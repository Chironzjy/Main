SELECT Employee.emp_id,Employee.emp_name,Employee.emp_salary,Department.dept_name
FROM Employee LEFT OUTER JOIN Department
ON Employee.dept_id=Department.dept_id
WHERE (Employee.dept_id,Employee.salary) IN 
   	(SELECT dept_id,MAX(emp_salary)
	FROM Employee
	WHERE dept_id IS NOT NULL
	GROUP BY dept_id)
ORDER BY Department.dept_name; 