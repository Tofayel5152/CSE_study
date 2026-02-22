-- CREATE DATABASE mysql1;
-- USE mysql1;

-- CREATE TABLE student (
--     id INT AUTO_INCREMENT PRIMARY KEY,
--     name VARCHAR(20) NOT NULL,
--     email VARCHAR(100) UNIQUE NOT NULL,
--     gender ENUM('MALE','FEMALE'),
--     dob DATE,
--     create_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
-- );

-- RENAME TABLE student TO students;
-- ALTER TABLE students ADD COLUMN phone INT;
-- -- Note: The next line will cause the one after it to fail.
-- ALTER TABLE students DROP COLUMN phone;
-- ALTER TABLE students MODIFY COLUMN phone VARCHAR(20);