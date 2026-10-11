Microsoft Windows \[Version 10.0.26300.9550]

(c) Microsoft Corporation. All rights reserved.



C:\\Users\\aksha>mysql -u root -p

Enter password: \*\*\*\*\*\*\*\*\*

Welcome to the MySQL monitor.  Commands end with ; or \\g.

Your MySQL connection id is 24

Server version: 8.0.46 MySQL Community Server - GPL



Copyright (c) 2000, 2026, Oracle and/or its affiliates.



Oracle is a registered trademark of Oracle Corporation and/or its

affiliates. Other names may be trademarks of their respective

owners.



Type 'help;' or '\\h' for help. Type '\\c' to clear the current input statement.



mysql> create database Library;

Query OK, 1 row affected (0.08 sec)



mysql> show databases;

+--------------------+

| Database           |

+--------------------+

| aug26              |

| information\_schema |

| library            |

| mysql              |

| performance\_schema |

| sakila             |

| students           |

| sys                |

| world              |

+--------------------+

9 rows in set (0.06 sec)



mysql> use library'

ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near ''' at line 1

mysql> use library;

Database changed



**Q.1. Write the SQL command to create a table Authors with the following fields:**

&#x20;  **- author\_id (Primary Key, INT)**

&#x20;  **- name (VARCHAR(100))**

&#x20;  **- country (VARCHAR(50))**



mysql> create table Author(

&#x20;   -> author\_id int Primary Key ,

&#x20;   -> name VARCHAR(100),

&#x20;   -> country VARCHAR(50)

&#x20;   -> );

Query OK, 0 rows affected (0.12 sec)



**Q.2. Write the SQL command to create a table Books with the following fields:**

&#x20;  **- book\_id (Primary Key, INT)**

&#x20;  **- title (VARCHAR(150))**

&#x20;  **- author\_id (Foreign Key referencing Authors)**

&#x20;  **- published\_year (YEAR)**

&#x20;  **- available\_copies (INT)**



mysql> CREATE TABLE books (

&#x20;   ->     book\_id INT PRIMARY KEY,

&#x20;   ->     title VARCHAR(150),

&#x20;   ->     author\_id INT,

&#x20;   ->     published\_year INT,

&#x20;   ->     available\_copies INT,

&#x20;   ->     FOREIGN KEY (author\_id) REFERENCES Author(author\_id)

&#x20;   -> );

Query OK, 0 rows affected (0.12 sec)



**Q.3. Write the SQL command to create a table Members with:**

&#x20;  **- member\_id (Primary Key, INT)**

&#x20;  **- name (VARCHAR(100))**

&#x20;  **- email (VARCHAR(100), unique)**

&#x20;  **- phone (VARCHAR(15))**



mysql> create table members(

&#x20;   -> member\_id int primary key,

&#x20;   -> name varchar(100),

&#x20;   -> email varchar(100) unique,

&#x20;   -> phone varchar(15)

&#x20;   -> );

Query OK, 0 rows affected (0.05 sec)



**Q.4. Write the SQL command to create a table Borrow\_Records with:**

&#x20;  **- record\_id (Primary Key, INT)**

&#x20;  **- member\_id (Foreign Key referencing Members)**

&#x20;  **- book\_id (Foreign Key referencing Books)**

&#x20;  **- borrow\_date (DATE)**

&#x20;  **- return\_date (DATE)**



mysql> CREATE TABLE borrow\_records (

&#x20;   ->     record\_id INT PRIMARY KEY,

&#x20;   ->     member\_id INT,

&#x20;   ->     book\_id INT,

&#x20;   ->     borrow\_date DATE,

&#x20;   ->     return\_date DATE,

&#x20;   ->     FOREIGN KEY (member\_id) REFERENCES members(member\_id),

&#x20;   ->   FOREIGN KEY (book\_id) REFERENCES books(book\_id)

&#x20;   -> );

Query OK, 0 rows affected (0.05 sec)



mysql> select \*from author;

Empty set (0.04 sec)



mysql> desc author;

+-----------+--------------+------+-----+---------+-------+

| Field     | Type         | Null | Key | Default | Extra |

+-----------+--------------+------+-----+---------+-------+

| author\_id | int          | NO   | PRI | NULL    |       |

| name      | varchar(100) | YES  |     | NULL    |       |

| country   | varchar(50)  | YES  |     | NULL    |       |

+-----------+--------------+------+-----+---------+-------+

3 rows in set (0.03 sec)



**Q.5. Modify the Books table to add a column genre of type VARCHAR(50).**

**mysql> alter table books add genre varchar(50);**

**Query OK, 0 rows affected (0.17 sec)**

**Records: 0  Duplicates: 0  Warnings: 0**



mysql> desc books;

+------------------+--------------+------+-----+---------+-------+

| Field            | Type         | Null | Key | Default | Extra |

+------------------+--------------+------+-----+---------+-------+

| book\_id          | int          | NO   | PRI | NULL    |       |

| title            | varchar(150) | YES  |     | NULL    |       |

| author\_id        | int          | YES  | MUL | NULL    |       |

| published\_year   | int          | YES  |     | NULL    |       |

| available\_copies | int          | YES  |     | NULL    |       |

| genre            | varchar(50)  | YES  |     | NULL    |       |

+------------------+--------------+------+-----+---------+-------+

6 rows in set (0.01 sec)



**Q.6. Insert 3 records into the Authors table.**



mysql> INSERT INTO Author (author\_id, name, country) VALUES

&#x20;   -> (1, 'akshada', 'india'),

&#x20;   -> (2, 'akshay', 'india'),

&#x20;   -> (3, 'akash', 'india');

Query OK, 3 rows affected (0.01 sec)

Records: 3  Duplicates: 0  Warnings: 0



mysql> select \*from author;

+-----------+---------+---------+

| author\_id | name    | country |

+-----------+---------+---------+

|         1 | akshada | india   |

|         2 | akshay  | india   |

|         3 | akash   | india   |

+-----------+---------+---------+

3 rows in set (0.00 sec)



**Q.7. Insert 5 books into the Books table.**



mysql> INSERT INTO books (book\_id, title, author\_id, published\_year, available\_copies, genre) VALUES

&#x20;   -> (101, 'The Indian Renaissance', 1, 2022, 5, 'History'),

&#x20;   -> (102, 'Data Analytics Guide', 2, 2024, 3, 'Technology'),

&#x20;   -> (103, 'Echoes of the Past', 3, 2020, 2, 'Fiction'),

&#x20;   -> (104, 'SQL for Beginners', 2, 2025, 7, 'Technology'),

&#x20;   -> (105, 'The Silent Valley', 1, 2023, 4, 'Mystery');

Query OK, 5 rows affected (0.05 sec)

Records: 5  Duplicates: 0  Warnings: 0



mysql> desc books;

+------------------+--------------+------+-----+---------+-------+

| Field            | Type         | Null | Key | Default | Extra |

+------------------+--------------+------+-----+---------+-------+

| book\_id          | int          | NO   | PRI | NULL    |       |

| title            | varchar(150) | YES  |     | NULL    |       |

| author\_id        | int          | YES  | MUL | NULL    |       |

| published\_year   | int          | YES  |     | NULL    |       |

| available\_copies | int          | YES  |     | NULL    |       |

| genre            | varchar(50)  | YES  |     | NULL    |       |

+------------------+--------------+------+-----+---------+-------+

6 rows in set (0.04 sec)



mysql> select \*from books;

+---------+------------------------+-----------+----------------+------------------+------------+

| book\_id | title                  | author\_id | published\_year | available\_copies | genre      |

+---------+------------------------+-----------+----------------+------------------+------------+

|     101 | The Indian Renaissance |         1 |           2022 |                5 | History    |

|     102 | Data Analytics Guide   |         2 |           2024 |                3 | Technology |

|     103 | Echoes of the Past     |         3 |           2020 |                2 | Fiction    |

|     104 | SQL for Beginners      |         2 |           2025 |                7 | Technology |

|     105 | The Silent Valley      |         1 |           2023 |                4 | Mystery    |

+---------+------------------------+-----------+----------------+------------------+------------+

5 rows in set (0.00 sec)



mysql> use library;

Database changed

mysql> show tables;

+-------------------+

| Tables\_in\_library |

+-------------------+

| author            |

| books             |

| borrow\_records    |

| members           |

+-------------------+

4 rows in set (0.10 sec)



mysql> select \*from author;

+-----------+---------+---------+

| author\_id | name    | country |

+-----------+---------+---------+

|         1 | akshada | india   |

|         2 | akshay  | india   |

|         3 | akash   | india   |

+-----------+---------+---------+

3 rows in set (0.01 sec)



mysql> select \*from books;

+---------+------------------------+-----------+----------------+------------------+------------+

| book\_id | title                  | author\_id | published\_year | available\_copies | genre      |

+---------+------------------------+-----------+----------------+------------------+------------+

|     101 | The Indian Renaissance |         1 |           2022 |                5 | History    |

|     102 | Data Analytics Guide   |         2 |           2024 |                3 | Technology |

|     103 | Echoes of the Past     |         3 |           2020 |                2 | Fiction    |

|     104 | SQL for Beginners      |         2 |           2025 |                7 | Technology |

|     105 | The Silent Valley      |         1 |           2023 |                4 | Mystery    |

+---------+------------------------+-----------+----------------+------------------+------------+

5 rows in set (0.00 sec)



mysql> select \*from members;

Empty set (0.02 sec)



mysql> desc members;

+-----------+--------------+------+-----+---------+-------+

| Field     | Type         | Null | Key | Default | Extra |

+-----------+--------------+------+-----+---------+-------+

| member\_id | int          | NO   | PRI | NULL    |       |

| name      | varchar(100) | YES  |     | NULL    |       |

| email     | varchar(100) | YES  | UNI | NULL    |       |

| phone     | varchar(15)  | YES  |     | NULL    |       |

+-----------+--------------+------+-----+---------+-------+

4 rows in set (0.00 sec)



**8. Insert 3 members into the Members table.**



mysql> insert into members(member\_id,name,email,phone)values(1,'rahul','rahul@gamil.com',9999999999),

&#x20;   -> (2,'rani','rani@gmail.com',8888888888),

&#x20;   -> (3,'ram','ram@gmail.com',7777777777);

Query OK, 3 rows affected (0.01 sec)

Records: 3  Duplicates: 0  Warnings: 0



mysql> select \*from members;

+-----------+-------+-----------------+------------+

| member\_id | name  | email           | phone      |

+-----------+-------+-----------------+------------+

|         1 | rahul | rahul@gamil.com | 9999999999 |

|         2 | rani  | rani@gmail.com  | 8888888888 |

|         3 | ram   | ram@gmail.com   | 7777777777 |

+-----------+-------+-----------------+------------+

3 rows in set (0.00 sec)



**9. Insert 4 borrow records into the Borrow\_Records table.**



mysql> INSERT INTO borrow\_records (record\_id, member\_id, book\_id, borrow\_date, return\_date) VALUES

&#x20;   -> (1, 1, 105, '2026-09-08', '2026-10-10'),

&#x20;   -> (2, 3, 104, '2026-09-18', '2026-10-01'),

&#x20;   -> (3, 2, 102, '2026-07-08', '2026-08-10'),

&#x20;   -> (4, 1, 101, '2026-06-15', '2026-07-19');

Query OK, 4 rows affected (0.01 sec)

Records: 4  Duplicates: 0  Warnings: 0



mysql> select \*from borrow\_records;

+-----------+-----------+---------+-------------+-------------+

| record\_id | member\_id | book\_id | borrow\_date | return\_date |

+-----------+-----------+---------+-------------+-------------+

|         1 |         1 |     105 | 2026-09-08  | 2026-10-10  |

|         2 |         3 |     104 | 2026-09-18  | 2026-10-01  |

|         3 |         2 |     102 | 2026-07-08  | 2026-08-10  |

|         4 |         1 |     101 | 2026-06-15  | 2026-07-19  |

+-----------+-----------+---------+-------------+-------------+

4 rows in set (0.00 sec)



**10. Write an SQL query to select all books where published\_year is after 2022.**



mysql> select \*from books where published\_year >2022;

+---------+----------------------+-----------+----------------+------------------+------------+

| book\_id | title                | author\_id | published\_year | available\_copies | genre      |

+---------+----------------------+-----------+----------------+------------------+------------+

|     102 | Data Analytics Guide |         2 |           2024 |                3 | Technology |

|     104 | SQL for Beginners    |         2 |           2025 |                7 | Technology |

|     105 | The Silent Valley    |         1 |           2023 |                4 | Mystery    |

+---------+----------------------+-----------+----------------+------------------+------------+

3 rows in set (0.01 sec)



**11. Write a SQL query to create a foreign key \& primary key relationship between two tables.**



mysql> create table sample( id int primary key,

&#x20;   -> book\_id int,

&#x20;   -> foreign key(book\_id) references books(book\_id)

&#x20;   -> );

Query OK, 0 rows affected (0.13 sec)



mysql> select \*from sample;

Empty set (0.00 sec)



mysql> desc sample;

+---------+------+------+-----+---------+-------+

| Field   | Type | Null | Key | Default | Extra |

+---------+------+------+-----+---------+-------+

| id      | int  | NO   | PRI | NULL    |       |

| book\_id | int  | YES  | MUL | NULL    |       |

+---------+------+------+-----+---------+-------+

2 rows in set (0.01 sec)



**12. Write an SQL query to find all members who have borrowed the book with title 'SQL for Beginners'.**



mysql> SELECT m.member\_id, m.name, m.email

&#x20;   -> FROM members m

&#x20;   -> JOIN borrow\_records br ON m.member\_id = br.member\_id

&#x20;   -> JOIN books b ON br.book\_id = b.book\_id

&#x20;   -> WHERE title = 'SQL for Beginners';

+-----------+------+---------------+

| member\_id | name | email         |

+-----------+------+---------------+

|         3 | ram  | ram@gmail.com |

+-----------+------+---------------+

1 row in set (0.00 sec)



**13. Update the available\_copies column of a specific book (choose any book) by reducing it by 1 after it is borrowed.**



mysql> update books

&#x20;   -> set available\_copies =available\_copies-1

&#x20;   -> where book\_id=104;

Query OK, 1 row affected (0.01 sec)

Rows matched: 1  Changed: 1  Warnings: 0



mysql> select \*from books;

+---------+------------------------+-----------+----------------+------------------+------------+

| book\_id | title                  | author\_id | published\_year | available\_copies | genre      |

+---------+------------------------+-----------+----------------+------------------+------------+

|     101 | The Indian Renaissance |         1 |           2022 |                5 | History    |

|     102 | Data Analytics Guide   |         2 |           2024 |                3 | Technology |

|     103 | Echoes of the Past     |         3 |           2020 |                2 | Fiction    |

|     104 | SQL for Beginners      |         2 |           2025 |                6 | Technology |

|     105 | The Silent Valley      |         1 |           2023 |                4 | Mystery    |

+---------+------------------------+-----------+----------------+------------------+------------+

5 rows in set (0.00 sec)



**14. Delete a record from Members where member\_id = 3.**



mysql> delete from members

&#x20;   -> where member\_id=3;

Query OK, 1 row affected (0.01 sec)



mysql> select \*from members;

+-----------+-------+-----------------+------------+

| member\_id | name  | email           | phone      |

+-----------+-------+-----------------+------------+

|         1 | rahul | rahul@gamil.com | 9999999999 |

|         2 | rani  | rani@gmail.com  | 8888888888 |

+-----------+-------+-----------------+------------+

2 rows in set (0.00 sec)



**15. Update a Book name record from Book table  with id = 105.**



mysql> update books set title=' basics of java' where book\_id=105 ;

Query OK, 1 row affected (0.01 sec)

Rows matched: 1  Changed: 1  Warnings: 0



mysql> select \*from books;

+---------+------------------------+-----------+----------------+------------------+------------+

| book\_id | title                  | author\_id | published\_year | available\_copies | genre      |

+---------+------------------------+-----------+----------------+------------------+------------+

|     101 | The Indian Renaissance |         1 |           2022 |                5 | History    |

|     102 | Data Analytics Guide   |         2 |           2024 |                3 | Technology |

|     103 | Echoes of the Past     |         3 |           2020 |                2 | Fiction    |

|     104 | SQL for Beginners      |         2 |           2025 |                6 | Technology |

|     105 |  basics of java        |         1 |           2023 |                4 | Mystery    |

+---------+------------------------+-----------+----------------+------------------+------------+

5 rows in set (0.00 sec)



mysql> SELECT \* FROM books WHERE book\_id = 105;

+---------+-----------------+-----------+----------------+------------------+---------+

| book\_id | title           | author\_id | published\_year | available\_copies | genre   |

+---------+-----------------+-----------+----------------+------------------+---------+

|     105 |  basics of java |         1 |           2023 |                4 | Mystery |

+---------+-----------------+-----------+----------------+------------------+---------+

1 row in set (0.00 sec)



**16. Write an SQL query to list all books along with their authors' names.**



mysql> SELECT b.title, a.name AS author\_name

&#x20;   -> FROM books b

&#x20;   -> JOIN Author a ON b.author\_id = a.author\_id;

+------------------------+-------------+

| title                  | author\_name |

+------------------------+-------------+

| The Indian Renaissance | akshada     |

|  basics of java        | akshada     |

| Data Analytics Guide   | akshay      |

| SQL for Beginners      | akshay      |

| Echoes of the Past     | akash       |

+------------------------+-------------+

5 rows in set (0.01 sec)



**17. Write an SQL query to delete all books from the Books table where the published\_year is before 2022.**



mysql> DELETE FROM books

&#x20;   -> WHERE published\_year < 2022;

Query OK, 1 row affected (0.01 sec)



mysql> select \*from books;

+---------+------------------------+-----------+----------------+------------------+------------+

| book\_id | title                  | author\_id | published\_year | available\_copies | genre      |

+---------+------------------------+-----------+----------------+------------------+------------+

|     101 | The Indian Renaissance |         1 |           2022 |                5 | History    |

|     102 | Data Analytics Guide   |         2 |           2024 |                3 | Technology |

|     104 | SQL for Beginners      |         2 |           2025 |                6 | Technology |

|     105 |  basics of java        |         1 |           2023 |                4 | Mystery    |

+---------+------------------------+-----------+----------------+------------------+------------+

4 rows in set (0.00 sec)



**18. Write an SQL query to find all books that are never borrowed (i.e., no records in Borrow\_Records).**



mysql> SELECT b.book\_id, b.title

&#x20;   -> FROM books b

&#x20;   -> LEFT JOIN borrow\_records br ON b.book\_id = br.book\_id

&#x20;   -> WHERE br.book\_id IS NULL;

+---------+-------------------+

| book\_id | title             |

+---------+-------------------+

|     104 | SQL for Beginners |

+---------+-------------------+

1 row in set (0.00 sec)



**19. Write the SQL command to drop the Borrow\_Records table.**



mysql> drop table borrow\_records;

Query OK, 0 rows affected (0.10 sec)



mysql> show tables;

+-------------------+

| Tables\_in\_library |

+-------------------+

| author            |

| books             |

| members           |

| sample            |

+-------------------+

4 rows in set (0.00 sec)



