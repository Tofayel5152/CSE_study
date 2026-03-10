/*Draw a simple ER Diagram based on these requirements:

. Entity 1: Student (Attributes: ID, Name, Department, DOB,)
. Entity 2: Course (Attributes: CourseID, CourseName, Credits)
· Relationship: A Student Enrolls in a Course.

Now, translate your drawing into a database:
1. ALTER the Students table to add a column named Email (Varchar
50)
2. ALTER the Courses table to change the column name CName to
Course Title.
3. INSERT 10 students into the Students table.|
4. INSERT 3 courses into the Courses table (e.g., DBMS, Python,
Networking).
5. The Manual Link: Use ALTER to add a column Enrolled_CID to the
Students table.
6. Create dummy tables. Apply the following on these dummy tables.
7. UPDATE/INSERT: Assign a CourseID to each student in that new
column.
8. DELETE the student record with RollNo = 2.
9. TRUNCATE the Courss table.
10. ALTER the Students table to DROP the Email column you created
earlier
11. DROP the entire Students table.
 */

-- 1=>
            CREATE DATABASE C243236;
            USE C243236;

            CREATE TABLE students (
            id INT AUTO_INCREMENT PRIMARY KEY,
            name VARCHAR (20) NOT NULL,
            department VARCHAR(30) NOT NULL,
            dob DATE
            );

            ALTER TABLE students ADD COLUMN email VARCHAR(100) UNIQUE NOT NULL;

-- 2=>
            USE C243236;

            CREATE TABLE course (
            courseID INT AUTO_INCREMENT PRIMARY KEY,
            CName VARCHAR(20) NOT NULL,
            creadits INT NOT NULL
            );

            ALTER TABLE course RENAME COLUMN CName TO Course_Title;

-- 3=>
            USE C243236;

            INSERT INTO students (id, name, department, dob, email)
            VALUES
            (1, 'Aarav Sharma', 'Computer Science', '2002-05-14', 'aarav.sharma@example.com'),
            (2, 'Priya Mehta', 'Electrical Engineering', '2001-11-22', 'priya.mehta@example.com'),
            (3, 'Rohan Patel', 'Mechanical Engineering', '2003-02-10', 'rohan.patel@example.com'),
            (4, 'Sneha Reddy', 'Civil Engineering', '2002-08-19', 'sneha.reddy@example.com'),
            (5, 'Karan Verma', 'Information Technology', '2001-12-05', 'karan.verma@example.com'),
            (6, 'Ananya Gupta', 'Electronics', '2004-03-27', 'ananya.gupta@example.com'),
            (7, 'Vikram Singh', 'Biotechnology', '2002-07-09', 'vikram.singh@example.com'),
            (8, 'Neha Kapoor', 'Chemical Engineering', '2001-09-30', 'neha.kapoor@example.com'),
            (9, 'Aditya Nair', 'Data Science', '2003-01-18', 'aditya.nair@example.com'),
            (10, 'Ishita Bose', 'Mathematics', '2002-04-25', 'ishita.bose@example.com');

-- 4=>
            USE C243236;

            INSERT INTO course (courseID,Course_Title,creadits)
            VALUES
            (1, 'DBMS', 4),
            (2, 'Python', 3),
            (3, 'Networking', 3);
            

-- 5=>
            USE C243236;

            ALTER TABLE students ADD COLUMN Enrolled_CID INT;

-- 6=>
            USE C243236;

            CREATE TABLE dummy_students (
            id INT AUTO_INCREMENT PRIMARY KEY,
            name VARCHAR(20) NOT NULL,
            department VARCHAR(30) NOT NULL,
            dob DATE,
            email VARCHAR(100) UNIQUE NOT NULL,
            Enrolled_CID INT
            );

            CREATE TABLE dummy_course (
            courseID INT AUTO_INCREMENT PRIMARY KEY,
            Course_Title VARCHAR(20) NOT NULL,
            creadits INT NOT NULL
            );

-- 7=>
            USE C243236;

            INSERT INTO dummy_students (id, name, department, dob, email, Enrolled_CID)
            VALUES
            (1, 'Aarav Sharma', 'Computer Science', '2002-05-14', 'aarav.sharma@example.com', 1),
            (2, 'Priya Mehta', 'Electrical Engineering', '2001-11-22', 'priya.mehta@example.com', 1),
            (3, 'Rohan Patel', 'Mechanical Engineering', '2003-02-10', 'rohan.patel@example.com', 1),
            (4, 'Sneha Reddy', 'Civil Engineering', '2002-08-19', 'sneha.reddy@example.com', 1),
            (5, 'Karan Verma', 'Information Technology', '2001-12-05', 'karan.verma@example.com', 1),
            (6, 'Ananya Gupta', 'Electronics', '2004-03-27', 'ananya.gupta@example.com', 1),
            (7, 'Vikram Singh', 'Biotechnology', '2002-07-09', 'vikram.singh@example.com', 1),
            (8, 'Neha Kapoor', 'Chemical Engineering', '2001-09-30', 'neha.kapoor@example.com', 2),
            (9, 'Aditya Nair', 'Data Science', '2003-01-18', 'aditya.nair@example.com', 3),
            (10, 'Ishita Bose', 'Mathematics', '2002-04-25', 'ishita.bose@example.com', 3);

-- 8=>
            USE C243236;

            DELETE FROM dummy_students WHERE id = 2;

-- 9=>
            USE C243236;

            TRUNCATE TABLE dummy_course;

-- 10=>
            USE C243236;

            ALTER TABLE dummy_students DROP COLUMN email;

-- 11=>
            USE C243236;

            DROP TABLE dummy_students;

