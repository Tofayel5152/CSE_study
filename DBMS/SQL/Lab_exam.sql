-- CREATE DATABASE labExam;
USE labExam;

CREATE TABLE student (
    sid INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    cg DOUBLE
);

INSERT INTO student (sid,name,cg) VALUES
(101,'A',3),
(102,'B',3.5),
(103,'C',4);

CREATE TABLE course (
    sid INT,
    cid VARCHAR(20),
    credit DOUBLE
);

INSERT INTO course (sid,cid,credit) VALUES
(101,'c-111',1.5),
(101,'c-112',0.75),
(102,'c-111',1.5),
(102,'c-113',3),
(104,'c-111',1.5);

-- Q1 (All info): 
SELECT * FROM Students;

-- Q2 (Name/CGPA):
SELECT Name, CGPA FROM Students;

-- Q3 (Alias):
SELECT Name, AdmissionDate AS Joining_Date FROM Students;

-- Q4 (Unique Departments):
SELECT DISTINCT Department FROM Students;

-- Q5 (CSE Dept):
SELECT * FROM Students WHERE Department = 'CSE';

-- Q6 (CGPA > 3.75):
SELECT * FROM Students WHERE CGPA > 3.75;

-- Q7 (Specific Depts): 
SELECT Name FROM Students WHERE Department IN ('EEE', 'Pharmacy');

-- Q8 (Date Range): 
SELECT * FROM Students WHERE AdmissionDate BETWEEN '2023-01-01' AND '2024-12-31';

-- Q9 (Starts with 'S'): 
SELECT * FROM Students WHERE Name LIKE 'S%';

-- Q10 (Sort CGPA): 
SELECT * FROM Students ORDER BY CGPA DESC;

-- Q11 (Sort BBA Alpha): 
SELECT * FROM Students WHERE Department = 'BBA' ORDER BY Name ASC;

-- Q12 (Top 3): 
SELECT * FROM Students ORDER BY CGPA DESC LIMIT 3;

-- Q13 (Complex Filter): 
SELECT Name, Department, CGPA FROM Students
WHERE Department = 'CSE' AND AdmissionDate > '2022-12-31'
ORDER BY CGPA DESC;

-- Q14 (Email check): 
SELECT * FROM Students WHERE Email LIKE '%@yahoo.com' OR Email LIKE '%@gmail.com';

-- Q15 (Avg CGPA): 
SELECT AVG(CGPA) FROM Students WHERE Department = 'CSE';

-- Q16 (High/Low): 
SELECT MAX(CGPA), MIN(CGPA) FROM Students WHERE Department = 'EEE';

-- Q17 (Count by Dept): 
SELECT Department, COUNT(*) AS Total_Students FROM Students GROUP BY Department;

-- Q18 (Having Clause):

SELECT Department FROM Students 
GROUP BY Department 
HAVING COUNT(*) > 10 AND AVG(CGPA) > 3.0;
-- Q19 (Filtered Avg): 
SELECT Department, AVG(CGPA) FROM Students WHERE CGPA >= 3.0 GROUP BY Department;

-- Q20 (Max < 3.5): 
SELECT Department FROM Students GROUP BY Department HAVING MAX(CGPA) < 3.5;

-- Q21 (Length): 
SELECT Name, LENGTH(Name) FROM Students;

-- Q22 (Concat): 
SELECT CONCAT(Name, ' - ', Department) AS Student_Info FROM Students;

-- Q23 (Datediff): 
SELECT Name, DATEDIFF(CURDATE(), AdmissionDate) AS Days_Passed FROM Students;

-- Q24 (Months): 
SELECT Name, TIMESTAMPDIFF(MONTH, AdmissionDate, CURDATE()) AS Months_Enrolled FROM Students;

-- Q25 (Round): 
SELECT Name, ROUND(CGPA, 1) FROM Students;

-- Q26 (Floor): 
SELECT Name, FLOOR(CGPA) FROM Students;

-- Q27 (Ceil): 
SELECT Name, CEIL(CGPA) FROM Students;

-- Q28 (IF Condition): 
SELECT Name, IF(CGPA >= 2.0, 'Pass', 'Fail') AS Result_Status FROM Students;



-- ANOTHER QUESTION: 
-- Students registered in "Database Systems": To get this data, we join the Student, Registration, and Course tables.
SELECT DISTINCT S.SID, S.Name, S.Dept
FROM Student S
JOIN Registration R ON S.SID = R.SID
JOIN Course C ON R.CID = C.CID
WHERE C.Title = 'Database Systems';

-- Students not registered in any course: This is best handled using a NOT IN subquery or a LEFT JOIN where the registration side is empty.

-- Option A (Using Subquery):
SELECT * FROM Student 
WHERE SID NOT IN (SELECT SID FROM Registration);

-- Option B (Using Join):
SELECT S.*
FROM Student S
LEFT JOIN Registration R ON S.SID = R.SID
WHERE R.SID IS NULL;

-- Faculty teaching courses taken by CSE students: This query requires a "chain" of joins to link the Faculty all the way to the Department of the Students they are teaching.
SELECT DISTINCT F.FID, F.Name
FROM Faculty F
JOIN Assigned A ON F.FID = A.FID
JOIN Registration R ON A.CID = R.CID
JOIN Student S ON R.SID = S.SID
WHERE S.Dept = 'CSE';