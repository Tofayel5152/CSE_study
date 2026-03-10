/*
DBMS Lab Task-2:

Employee(id, name, dept, email, salary, joining_date):
| id  | name            | dept        | email                                               | salary | joining   |
| --- | --------------- | ----------- | --------------------------------------------------- | ------ | --------- |
| 101 | sahil           | cse         | [sahil@gmail.com](mailto:sahil@gmail.com)           | 70000  | 2/20/2022 |
| 102 | Alice Johnson   | Engineering | [alice.j@company.com](mailto:alice.j@company.com)   | 85000  | 2/20/2022 |
| 103 | Bob Smith       | Sales       | [bob.s@company.com](mailto:bob.s@company.com)       | 62000  | 2/20/2021 |
| 104 | Charlie Davis   | HR          | [charlie.d@yahoo.com](mailto:charlie.d@yahoo.com)   | 55000  | 2/20/2023 |
| 105 | Diana Prince    | Engineering | [diana.p@yahoo.com](mailto:diana.p@yahoo.com)       | 95000  | 2/20/2024 |
| 106 | Ethan Hunt      | Security    | [ethan.h@gmail.com](mailto:ethan.h@gmail.com)       | 75000  | 2/20/2025 |
| 107 | Fiona Gallagher | Marketing   | [fiona.g@gmail.com](mailto:fiona.g@gmail.com)       | 58000  | 2/20/2022 |
| 108 | George Miller   | Sales       | [george.m@company.com](mailto:george.m@company.com) | 61000  | 2/20/2020 |
| 109 | Hannah Abbott   | Engineering | [hannah.a@yahoo.com](mailto:hannah.a@yahoo.com)     | 88000  | 2/20/2020 |
| 110 | Ian Wright      | Support     | [ian.w@company.com](mailto:ian.w@company.com)       | 45000  | 2/20/2021 |
| 111 | Jenny Kim       | Marketing   | [jenny.k@ymail.com](mailto:jenny.k@ymail.com)       | 64000  | 2/20/2021 |
| 112 | Kevin Hart      | IT          | [kevin.h@company.com](mailto:kevin.h@company.com)   | 72000  | 2/20/2021 |
| 113 | Laura Palmer    | Finance     | [laura.p@company.com](mailto:laura.p@company.com)   | 78000  | 2/20/2022 |
| 114 | Mike Ross       | Legal       | [mike.r@company.com](mailto:mike.r@company.com)     | 92000  | 2/20/2023 |
| 115 | Nina Simone     | Creative    | [nina.s@company.com](mailto:nina.s@company.com)     | 70000  | 2/20/2021 |

1. Retrieve all information for every employee in the table.
2. Display only the Name and Salary of all employees.
3. Display the Name and HireDate, but change the column heading of HireDate to 'HireDate'.
4. Show a list of all unique Department names in the company (no duplicates).
5. List all details of employees working in the 'IT' department.
6. Find all employees who earn more than 75,000.
7. Retrieve the names of employees who work in either 'Sales' or 'HR'.
8. Find employees who were hired between '2022-01-01' and '2023-12-31'.
9. Find all employees whose names start with the letter 'M'.
10. List all employees sorted by their Salary from highest to lowest.
11. List all employees in the 'Finance' department, sorted by their Name alphabetically.
12. Find the top 3 highest-paid employees in the entire company.
13. Retrieve the Name, Department, and Salary of all 'IT' employees hired after 2021, sorted by Salary in descending order.
14. Find employees who have a yahoo or gmail account.

*/

-- 1=>
            CREATE DATABASE C243236;
            USE C243236;

            CREATE TABLE employee (
            id INT PRIMARY KEY,
            name VARCHAR(50) NOT NULL,
            dept VARCHAR(30) NOT NULL,
            email VARCHAR(100) UNIQUE,
            salary INT,
            joining_date DATE
            );

            INSERT INTO employee (id, name, dept, email, salary, joining_date) 
            VALUES 
            (101, 'sahil', 'cse', 'sahil@gmail.com', 70000, '2022-02-20'),
            (102, 'Alice Johnson', 'Engineering', 'alice.j@company.com', 85000, '2022-02-20'),
            (103, 'Bob Smith', 'Sales', 'bob.s@company.com', 62000, '2021-02-20'),
            (104, 'Charlie Davis', 'HR', 'charlie.d@yahoo.com', 55000, '2023-02-20'),
            (105, 'Diana Prince', 'Engineering', 'diana.p@yahoo.com', 95000, '2024-02-20'),
            (106, 'Ethan Hunt', 'Security', 'ethan.h@gmail.com', 75000, '2025-02-20'),
            (107, 'Fiona Gallagher', 'Marketing', 'fiona.g@gmail.com', 58000, '2022-02-20'),
            (108, 'George Miller', 'Sales', 'george.m@company.com', 61000, '2020-02-20'),
            (109, 'Hannah Abbott', 'Engineering', 'hannah.a@yahoo.com', 88000, '2020-02-20'),
            (110, 'Ian Wright', 'Support', 'ian.w@company.com', 45000, '2021-02-20'),
            (111, 'Jenny Kim', 'Marketing', 'jenny.k@ymail.com', 64000, '2021-02-20'),
            (112, 'Kevin Hart', 'IT', 'kevin.h@company.com', 72000, '2021-02-20'),
            (113, 'Laura Palmer', 'Finance', 'laura.p@company.com', 78000, '2022-02-20'),
            (114, 'Mike Ross', 'Legal', 'mike.r@company.com', 92000, '2023-02-20'),
            (115, 'Nina Simone', 'Creative', 'nina.s@company.com', 70000, '2021-02-20');

            SELECT * FROM employee;

-- 2=>
            USE C243236;
            SELECT name, salary FROM employee;

-- 3=>
            USE C243236;
            SELECT name, joining_date AS HireDate FROM employee;

-- 4=>
            USE C243236;
            SELECT DISTINCT dept FROM employee;

-- 5=>
            USE C243236;
            SELECT * FROM employee WHERE dept = 'IT';

-- 6=>
            USE C243236;
            SELECT * FROM employee WHERE salary > 75000;

-- 7=>
            USE C243236;
            SELECT name FROM employee WHERE dept IN ('Sales', 'HR');

-- 8=>
            USE C243236;
            SELECT * FROM employee WHERE joining_date BETWEEN '2022-01-01' AND '2023-12-31';

-- 9=>
            USE C243236;
            SELECT * FROM employee WHERE name LIKE 'M%';

-- 10=>
            USE C243236;
            SELECT * FROM employee ORDER BY salary DESC;

-- 11=>
            USE C243236;
            SELECT * FROM employee WHERE dept = 'Finance' ORDER BY name ASC;

-- 12=>
            USE C243236;
            SELECT * FROM employee ORDER BY salary DESC LIMIT 3;

-- 13=>
            USE C243236;
            SELECT name, dept, salary FROM employee 
            WHERE dept = 'IT' AND joining_date > '2021-12-31' 
            ORDER BY salary DESC;

-- 14=>
            USE C243236;
            SELECT * FROM employee 
            WHERE email LIKE '%@gmail.com' OR email LIKE '%@yahoo.com';