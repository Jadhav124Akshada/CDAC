Microsoft Windows \[Version 10.0.26300.9550]

(c) Microsoft Corporation. All rights reserved.



C:\\Users\\aksha>mysql -u root -p

Enter password: \*\*\*\*\*\*\*\*\*

Welcome to the MySQL monitor.  Commands end with ; or \\g.

Your MySQL connection id is 27

Server version: 8.0.46 MySQL Community Server - GPL



Copyright (c) 2000, 2026, Oracle and/or its affiliates.



Oracle is a registered trademark of Oracle Corporation and/or its

affiliates. Other names may be trademarks of their respective

owners.



Type 'help;' or '\\h' for help. Type '\\c' to clear the current input statement.





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

| techcorp\_db        |

| world              |

+--------------------+

10 rows in set (0.15 sec)



mysql> use techcorp\_db;

Database changed



**1.Write a Relational Algebra expression to perform Cartesian Product (Cross Join) between Emp and Dept tables.**



mysql> select e.emp\_name , d.dept\_name

&#x20;   -> from employees e

&#x20;   -> cross join departments d;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | finance                |

| akshada jadhav | information technology |

| akshada jadhav | human resources        |

| rahul sharma   | finance                |

| rahul sharma   | information technology |

| rahul sharma   | human resources        |

| priya patil    | finance                |

| priya patil    | information technology |

| priya patil    | human resources        |

| amit deshmukh  | finance                |

| amit deshmukh  | information technology |

| amit deshmukh  | human resources        |

| sneha more     | finance                |

| sneha more     | information technology |

| sneha more     | human resources        |

+----------------+------------------------+

15 rows in set (0.04 sec)



mysql> select \*from employees;

+--------+----------------+----------------------+----------+------------+---------+------------+

| emp\_id | emp\_name       | email                | salary   | hire\_date  | dept\_id | manager\_id |

+--------+----------------+----------------------+----------+------------+---------+------------+

|      1 | akshada jadhav | akshada@techcorp.com | 75000.00 | 2025-01-15 |       1 |       NULL |

|      2 | rahul sharma   | rahul@techcorp.com   | 55000.00 | 2025-03-20 |       2 |          1 |

|      3 | priya patil    | priya@techcorp.com   | 90000.00 | 2024-11-10 |       1 |          3 |

|      4 | amit deshmukh  | amit@techcorp.com    | 45000.00 | 2025-06-01 |       3 |          1 |

|      5 | sneha more     | sneha@techcorp.com   | 62000.00 | 2025-02-10 |       2 |          3 |

+--------+----------------+----------------------+----------+------------+---------+------------+

5 rows in set (0.01 sec)





mysql> INSERT INTO employees (emp\_name, email, salary, hire\_date, dept\_id, manager\_id)

&#x20;   -> VALUES

&#x20;   -> ('aditi sharma', 'aditi@example.com', 65000.00, '2023-05-20', 3, NULL),

&#x20;   -> ('amit verma', 'amit@example.com', 67000.00, '2023-04-10', 2, 2);

Query OK, 2 rows affected (0.08 sec)

Records: 2  Duplicates: 0  Warnings: 0



mysql> select e.emp\_name , d.dept\_name

&#x20;   -> from employees e

&#x20;   -> cross join departments d;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | finance                |

| akshada jadhav | information technology |

| akshada jadhav | human resources        |

| rahul sharma   | finance                |

| rahul sharma   | information technology |

| rahul sharma   | human resources        |

| priya patil    | finance                |

| priya patil    | information technology |

| priya patil    | human resources        |

| amit deshmukh  | finance                |

| amit deshmukh  | information technology |

| amit deshmukh  | human resources        |

| sneha more     | finance                |

| sneha more     | information technology |

| sneha more     | human resources        |

| aditi sharma   | finance                |

| aditi sharma   | information technology |

| aditi sharma   | human resources        |

| amit verma     | finance                |

| amit verma     | information technology |

| amit verma     | human resources        |

+----------------+------------------------+

21 rows in set (0.03 sec)





mysql> select \* from departments;

+---------+------------------------+-----------+

| dept\_id | dept\_name              | location  |

+---------+------------------------+-----------+

|       1 | human resources        | pune      |

|       2 | information technology | pune      |

|       3 | finance                | bangalore |

+---------+------------------------+-----------+

3 rows in set (0.01 sec)



mysql> insert into departments(dept\_name,location)values

&#x20;   -> (null,'nashik'),

&#x20;   -> ('marketing',null);

ERROR 1048 (23000): Column 'dept\_name' cannot be null

mysql> insert into departments(dept\_name,location)values

&#x20;   -> ('marketing',null);

Query OK, 1 row affected (0.03 sec)



mysql> select e.emp\_name , d.dept\_name

&#x20;   -> from employees e

&#x20;   -> cross join departments d;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | marketing              |

| akshada jadhav | finance                |

| akshada jadhav | information technology |

| akshada jadhav | human resources        |

| rahul sharma   | marketing              |

| rahul sharma   | finance                |

| rahul sharma   | information technology |

| rahul sharma   | human resources        |

| priya patil    | marketing              |

| priya patil    | finance                |

| priya patil    | information technology |

| priya patil    | human resources        |

| amit deshmukh  | marketing              |

| amit deshmukh  | finance                |

| amit deshmukh  | information technology |

| amit deshmukh  | human resources        |

| sneha more     | marketing              |

| sneha more     | finance                |

| sneha more     | information technology |

| sneha more     | human resources        |

| aditi sharma   | marketing              |

| aditi sharma   | finance                |

| aditi sharma   | information technology |

| aditi sharma   | human resources        |

| amit verma     | marketing              |

| amit verma     | finance                |

| amit verma     | information technology |

| amit verma     | human resources        |

+----------------+------------------------+

28 rows in set (0.00 sec)



**2.Write a SQL query to perform an INNER JOIN between Emp and Dept tables displaying EmpName and DeptName.**



mysql> select e.emp\_name,d.dept\_name

&#x20;   -> from employees e

&#x20;   -> inner join departments d on e.dept\_id=d.dept\_id;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | human resources        |

| priya patil    | human resources        |

| rahul sharma   | information technology |

| sneha more     | information technology |

| amit verma     | information technology |

| amit deshmukh  | finance                |

| aditi sharma   | finance                |

+----------------+------------------------+

7 rows in set (0.01 sec)





mysql> alter table departments modify dept\_name varchar(50) null;

Query OK, 0 rows affected (0.37 sec)

Records: 0  Duplicates: 0  Warnings: 0



mysql> insert into departments(dept\_name,location)values

&#x20;   -> (null,'nashik');

Query OK, 1 row affected (0.01 sec)



**3.Write a SQL query to perform a LEFT OUTER JOIN between Emp and Dept tables to display all employees along with their department information, including employees without a department.**



mysql> select e.emp\_name,d.dept\_name

&#x20;   -> from employees e

&#x20;   -> left join departments d on e.dept\_id=d.dept\_id;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | human resources        |

| rahul sharma   | information technology |

| priya patil    | human resources        |

| amit deshmukh  | finance                |

| sneha more     | information technology |

| aditi sharma   | finance                |

| amit verma     | information technology |

+----------------+------------------------+

7 rows in set (0.01 sec)



mysql> select\*from departments;

+---------+------------------------+-----------+

| dept\_id | dept\_name              | location  |

+---------+------------------------+-----------+

|       1 | human resources        | pune      |

|       2 | information technology | pune      |

|       3 | finance                | bangalore |

|       5 | marketing              | NULL      |

|       6 | NULL                   | nashik    |

+---------+------------------------+-----------+

5 rows in set (0.00 sec)



mysql> INSERT INTO employees (emp\_name, email, salary, hire\_date, dept\_id, manager\_id)

&#x20;   -> VALUES ('raj verma', 'raj@example.com', 77000.00, '2026-02-28', 6, 2);

Query OK, 1 row affected (0.01 sec)



mysql> select e.emp\_name,d.dept\_name

&#x20;   -> from employees e

&#x20;   -> left join departments d on e.dept\_id=d.dept\_id;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | human resources        |

| rahul sharma   | information technology |

| priya patil    | human resources        |

| amit deshmukh  | finance                |

| sneha more     | information technology |

| aditi sharma   | finance                |

| amit verma     | information technology |

| raj verma      | NULL                   |

+----------------+------------------------+

8 rows in set (0.01 sec)



**4.Write a SQL query to perform a RIGHT OUTER JOIN between Emp and Dept tables.**



mysql> select e.emp\_name,d.dept\_name

&#x20;   -> from employees e

&#x20;   -> right join departments d on e.dept\_id=d.dept\_id;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | human resources        |

| priya patil    | human resources        |

| rahul sharma   | information technology |

| sneha more     | information technology |

| amit verma     | information technology |

| amit deshmukh  | finance                |

| aditi sharma   | finance                |

| NULL           | marketing              |

| raj verma      | NULL                   |

+----------------+------------------------+

9 rows in set (0.00 sec)



**5.Write a SQL query to perform a NATURAL JOIN between Emp and Dept.**



mysql> select emp\_name,dept\_name

&#x20;   -> from employees

&#x20;   -> natural join departments;

+----------------+------------------------+

| emp\_name       | dept\_name              |

+----------------+------------------------+

| akshada jadhav | human resources        |

| rahul sharma   | information technology |

| priya patil    | human resources        |

| amit deshmukh  | finance                |

| sneha more     | information technology |

| aditi sharma   | finance                |

| amit verma     | information technology |

| raj verma      | NULL                   |

+----------------+------------------------+

8 rows in set (0.01 sec)



**6.Write a SQL query to perform a CROSS JOIN between Emp and Project table.**



mysql> create table project (

&#x20;   ->     project\_id int primary key auto\_increment,

&#x20;   ->     project\_name varchar(50) not null

&#x20;   -> );

Query OK, 0 rows affected (0.08 sec)



mysql> insert into project (project\_name) values

&#x20;   -> ('hr portal'),

&#x20;   -> ('data analytics');

Query OK, 2 rows affected (0.01 sec)

Records: 2  Duplicates: 0  Warnings: 0



mysql> select \* from employees cross join project;

+--------+----------------+----------------------+----------+------------+---------+------------+------------+----------------+

| emp\_id | emp\_name       | email                | salary   | hire\_date  | dept\_id | manager\_id | project\_id | project\_name   |

+--------+----------------+----------------------+----------+------------+---------+------------+------------+----------------+

|      1 | akshada jadhav | akshada@techcorp.com | 75000.00 | 2025-01-15 |       1 |       NULL |          2 | data analytics |

|      1 | akshada jadhav | akshada@techcorp.com | 75000.00 | 2025-01-15 |       1 |       NULL |          1 | hr portal      |

|      2 | rahul sharma   | rahul@techcorp.com   | 55000.00 | 2025-03-20 |       2 |          1 |          2 | data analytics |

|      2 | rahul sharma   | rahul@techcorp.com   | 55000.00 | 2025-03-20 |       2 |          1 |          1 | hr portal      |

|      3 | priya patil    | priya@techcorp.com   | 90000.00 | 2024-11-10 |       1 |          3 |          2 | data analytics |

|      3 | priya patil    | priya@techcorp.com   | 90000.00 | 2024-11-10 |       1 |          3 |          1 | hr portal      |

|      4 | amit deshmukh  | amit@techcorp.com    | 45000.00 | 2025-06-01 |       3 |          1 |          2 | data analytics |

|      4 | amit deshmukh  | amit@techcorp.com    | 45000.00 | 2025-06-01 |       3 |          1 |          1 | hr portal      |

|      5 | sneha more     | sneha@techcorp.com   | 62000.00 | 2025-02-10 |       2 |          3 |          2 | data analytics |

|      5 | sneha more     | sneha@techcorp.com   | 62000.00 | 2025-02-10 |       2 |          3 |          1 | hr portal      |

|      6 | aditi sharma   | aditi@example.com    | 65000.00 | 2023-05-20 |       3 |       NULL |          2 | data analytics |

|      6 | aditi sharma   | aditi@example.com    | 65000.00 | 2023-05-20 |       3 |       NULL |          1 | hr portal      |

|      7 | amit verma     | amit@example.com     | 67000.00 | 2023-04-10 |       2 |          2 |          2 | data analytics |

|      7 | amit verma     | amit@example.com     | 67000.00 | 2023-04-10 |       2 |          2 |          1 | hr portal      |

|      8 | raj verma      | raj@example.com      | 77000.00 | 2026-02-28 |       6 |          2 |          2 | data analytics |

|      8 | raj verma      | raj@example.com      | 77000.00 | 2026-02-28 |       6 |          2 |          1 | hr portal      |

+--------+----------------+----------------------+----------+------------+---------+------------+------------+----------------+

16 rows in set (0.01 sec)



**7.Write a SQL query to create a new table EmpBackup with the same structure as Emp but no data.**



mysql> create table EmpBackup like employees;

Query OK, 0 rows affected (0.12 sec)



**8.Write a SQL query to copy all data from Emp into EmpBackup table.**



mysql> create table EmpBackup as  select \*from employees;

ERROR 1050 (42S01): Table 'EmpBackup' already exists



mysql> create table Emp\_Backup as  select \*from employees;

Query OK, 8 rows affected (0.06 sec)

Records: 8  Duplicates: 0  Warnings: 0



mysql> select \*from Emp\_Backup;

+--------+----------------+----------------------+----------+------------+---------+------------+

| emp\_id | emp\_name       | email                | salary   | hire\_date  | dept\_id | manager\_id |

+--------+----------------+----------------------+----------+------------+---------+------------+

|      1 | akshada jadhav | akshada@techcorp.com | 75000.00 | 2025-01-15 |       1 |       NULL |

|      2 | rahul sharma   | rahul@techcorp.com   | 55000.00 | 2025-03-20 |       2 |          1 |

|      3 | priya patil    | priya@techcorp.com   | 90000.00 | 2024-11-10 |       1 |          3 |

|      4 | amit deshmukh  | amit@techcorp.com    | 45000.00 | 2025-06-01 |       3 |          1 |

|      5 | sneha more     | sneha@techcorp.com   | 62000.00 | 2025-02-10 |       2 |          3 |

|      6 | aditi sharma   | aditi@example.com    | 65000.00 | 2023-05-20 |       3 |       NULL |

|      7 | amit verma     | amit@example.com     | 67000.00 | 2023-04-10 |       2 |          2 |

|      8 | raj verma      | raj@example.com      | 77000.00 | 2026-02-28 |       6 |          2 |

+--------+----------------+----------------------+----------+------------+---------+------------+

8 rows in set (0.00 sec)



**9.Write a SQL query to create a new table ProjectArchive with the same structure and data as Project.**



mysql> create table ProjectArchive as  select \*from project;

Query OK, 2 rows affected (0.05 sec)

Records: 2  Duplicates: 0  Warnings: 0



mysql> select \*from ProjectArchive;

+------------+----------------+

| project\_id | project\_name   |

+------------+----------------+

|          1 | hr portal      |

|          2 | data analytics |

+------------+----------------+

2 rows in set (0.00 sec)



**10.Write a SQL query to create an AUTO\_INCREMENT sequence for EmpID in the Emp table during table creation.**



mysql> create table employee (

&#x20;   ->     empid int primary key auto\_increment,

&#x20;   ->     emp\_name varchar(50) not null,

&#x20;   ->     email varchar(50),

&#x20;   ->     salary decimal(10,2),

&#x20;   ->     hire\_date date

&#x20;   -> );

Query OK, 0 rows affected (0.06 sec)



**11.Write a SQL query using a subquery to find all employees whose salary is greater than the average salary of all employees.**



mysql> select emp\_name ,salary

&#x20;   -> from employees

&#x20;   -> where salary >(

&#x20;   -> select avg(salary)

&#x20;   -> from employees);

+----------------+----------+

| emp\_name       | salary   |

+----------------+----------+

| akshada jadhav | 75000.00 |

| priya patil    | 90000.00 |

| raj verma      | 77000.00 |

+----------------+----------+

3 rows in set (0.01 sec)



**12.Write a SQL query using a subquery in WHERE clause to find employees working in departments located in 'Mumbai'.**



mysql> select emp\_name ,dept\_id

&#x20;   -> from employees

&#x20;   -> where dept\_id in (

&#x20;   -> select dept\_id

&#x20;   -> from departments

&#x20;   -> where location in('mumbai'));

+---------------+---------+

| emp\_name      | dept\_id |

+---------------+---------+

| akshay jadhav |       8 |

+---------------+---------+

1 row in set (0.00 sec)



**13.Write a SQL query to display all departments where the number of employees is greater than 5, using a subquery.**



mysql> select dept\_id

&#x20;   -> from departments d

&#x20;   -> where (

&#x20;   ->     select count(\*)

&#x20;   ->     from employees e

&#x20;   ->     where e.dept\_id = d.dept\_id

&#x20;   -> ) > 5;

+---------+

| dept\_id |

+---------+

|       8 |

+---------+

1 row in set (0.01 sec)



mysql> select dept\_name

&#x20;   -> from departments d

&#x20;   -> where (

&#x20;   ->     select count(\*)

&#x20;   ->     from employees e

&#x20;   ->     where e.dept\_id = d.dept\_id

&#x20;   -> ) > 5;

+-----------+

| dept\_name |

+-----------+

| HR        |

+-----------+

1 row in set (0.00 sec)



**14.Write a subqueries for find out Max salary of employee.**



mysql> select emp\_name,salary

&#x20;   -> from employees

&#x20;   -> where salary=(select max(salary)

&#x20;   -> from employees);

+----------------+----------+

| emp\_name       | salary   |

+----------------+----------+

| akshada jadhav | 98000.00 |

+----------------+----------+

1 row in set (0.00 sec)



**15.Write a  self join query for each table.**



mysql> select

&#x20;   ->     e.emp\_name as employee\_name,

&#x20;   ->     m.emp\_name as manager\_name

&#x20;   -> from employees e

&#x20;   -> inner join employees m on e.manager\_id = m.emp\_id;

+--------------------+----------------+

| employee\_name      | manager\_name   |

+--------------------+----------------+

| rahul sharma       | akshada jadhav |

| priya patil        | priya patil    |

| amit deshmukh      | akshada jadhav |

| sneha more         | priya patil    |

| amit verma         | rahul sharma   |

| raj verma          | rahul sharma   |

| akshay jadhav      | rahul sharma   |

| raj sharma         | priya patil    |

| kiran kawade       | priya patil    |

| dhanashri ghodekar | priya patil    |

| omkar dhumane      | rahul sharma   |

| akshada jadhav     | rahul sharma   |

+--------------------+----------------+

12 rows in set (0.00 sec)

