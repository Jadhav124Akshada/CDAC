**Task 1: Create Tables**

**1. Create three tables: Employees, Departments, and Projects to track employees, departments,**

**and projects, respectively.**

**o Ensure each table has a Primary Key for uniquely identifying records.**

**o Set up Foreign Key constraints to link employees to departments and projects.**

**o Use appropriate constraints (e.g., NOT NULL, UNIQUE, etc.) to maintain data**

**integrity.**

**Task 2: Insert Data (Given in excel sheet)**

**Once you have created the tables, insert the provided data into the respective tables. The data**

**contains details about employees, departments, and projects.** 





mysql> use specialForce;

Database changed

mysql> create table departments(

&#x20;   -> dept\_id int auto\_increment primary key,

&#x20;   -> dept\_name varchar(20));

Query OK, 0 rows affected (0.06 sec)



mysql> desc departments;

+-----------+-------------+------+-----+---------+----------------+

| Field     | Type        | Null | Key | Default | Extra          |

+-----------+-------------+------+-----+---------+----------------+

| dept\_id   | int         | NO   | PRI | NULL    | auto\_increment |

| dept\_name | varchar(20) | YES  |     | NULL    |                |

+-----------+-------------+------+-----+---------+----------------+

2 rows in set (0.00 sec)





mysql> insert into departments values(

&#x20;   -> 1,'IT'),

&#x20;   -> (2,'HR'),

&#x20;   -> (3,'Sales'),

&#x20;   -> (4,'Finance'),

&#x20;   -> (5,'Marketing');

Query OK, 5 rows affected (0.01 sec)

Records: 5  Duplicates: 0  Warnings: 0





mysql> select \*from departments;

+---------+-----------+

| dept\_id | dept\_name |

+---------+-----------+

|       1 | IT        |

|       2 | HR        |

|       3 | Sales     |

|       4 | Finance   |

|       5 | Marketing |

+---------+-----------+

5 rows in set (0.00 sec)



mysql> create table employees(

&#x20;   -> emp\_id int auto\_increment primary key,

&#x20;   -> first\_name varchar(20),

&#x20;   -> last\_name varchar(20),

&#x20;   -> email varchar(50) unique,

&#x20;   -> hire\_date date,

&#x20;   -> dept\_id int,

&#x20;   -> constraint fk\_departments foreign key(dept\_id) references departments(dept\_id));

Query OK, 0 rows affected (0.06 sec)



mysql> alter table employees add coloum salary int;



mysql> desc employees;

+------------+-------------+------+-----+---------+----------------+

| Field      | Type        | Null | Key | Default | Extra          |

+------------+-------------+------+-----+---------+----------------+

| emp\_id     | int         | NO   | PRI | NULL    | auto\_increment |

| first\_name | varchar(20) | YES  |     | NULL    |                |

| last\_name  | varchar(20) | YES  |     | NULL    |                |

| email      | varchar(50) | YES  | UNI | NULL    |                |

| hire\_date  | date        | YES  |     | NULL    |                |

| dept\_id    | int         | YES  | MUL | NULL    |                |

| salary     | int         | YES  |     | NULL    |                |

+------------+-------------+------+-----+---------+----------------+



mysql> insert into employees values(

&#x20;   -> 101,'ravi','sharma','ravi.sharma@specialforce.com','2017-05-15',1,55000);

Query OK, 1 row affected (0.01 sec)



mysql> insert into employees values

&#x20;   ->     (null,'neha','kapoor','neha.kapoor@specialforce.com','2019-03-23',2,48000),

&#x20;   ->     (null,'jyoti','verma','jyoti.verma@specialforce.com','2020-11-02',1,60000),

&#x20;   ->     (null,'anil','patil','anil.patil@specialforce.com','2018-09-18',3,70000),

&#x20;   ->     (null,'pooja','singh','pooja.singh@specialforce.com','2020-06-10',4,40000),

&#x20;   ->     (null,'sanjay','iyer','sanjay.iyer@specialforce.com','2018-01-22',3,75000),

&#x20;   ->     (null,'jatin','reddy','jatin.reddy@specialforce.com','2021-12-12',2,85000),

&#x20;   ->     (null,'shreya','mehta','shreya.mehta@specialforce.com','2022-04-19',5,30000),

&#x20;   ->     (null,'rajesh','gupta','rajesh.gupta@specialforce.com','2020-08-11',1,90000),

&#x20;   ->     (null,'kavita','nair','kavita.nair@specialforce.com','2021-02-07',2,50000);

Query OK, 9 rows affected (0.01 sec)



mysql> select \*from employees;

+--------+------------+-----------+-------------------------------+------------+---------+--------+

| emp\_id | first\_name | last\_name | email                         | hire\_date  | dept\_id | salary |

+--------+------------+-----------+-------------------------------+------------+---------+--------+

|    101 | ravi       | sharma    | ravi.sharma@specialforce.com  | 2017-05-15 |       1 |  55000 |

|    102 | neha       | kapoor    | neha.kapoor@specialforce.com  | 2019-03-23 |       2 |  48000 |

|    103 | jyoti      | verma     | jyoti.verma@specialforce.com  | 2020-11-02 |       1 |  60000 |

|    104 | anil       | patil     | anil.patil@specialforce.com   | 2018-09-18 |       3 |  70000 |

|    105 | pooja      | singh     | pooja.singh@specialforce.com  | 2020-06-10 |       4 |  40000 |

|    106 | sanjay     | iyer      | sanjay.iyer@specialforce.com  | 2018-01-22 |       3 |  75000 |

|    107 | jatin      | reddy     | jatin.reddy@specialforce.com  | 2021-12-12 |       2 |  85000 |

|    108 | shreya     | mehta     | shreya.mehta@specialforce.com | 2022-04-19 |       5 |  30000 |

|    109 | rajesh     | gupta     | rajesh.gupta@specialforce.com | 2020-08-11 |       1 |  90000 |

|    110 | kavita     | nair      | kavita.nair@specialforce.com  | 2021-02-07 |       2 |  50000 |

+--------+------------+-----------+-------------------------------+------------+---------+--------+

10 rows in set (0.00 sec)



mysql> insert into employees values

&#x20;   -> (null,'akshada','jadhav','akshada.jadhav@specialforce.com','2022-01-04',null,92000);

Query OK, 1 row affected (0.01 sec)



mysql> select \*from employees;

+--------+------------+-----------+---------------------------------+------------+---------+--------+

| emp\_id | first\_name | last\_name | email                           | hire\_date  | dept\_id | salary |

+--------+------------+-----------+---------------------------------+------------+---------+--------+

|    101 | ravi       | sharma    | ravi.sharma@specialforce.com    | 2017-05-15 |       1 |  55000 |

|    102 | neha       | kapoor    | neha.kapoor@specialforce.com    | 2019-03-23 |       2 |  48000 |

|    103 | jyoti      | verma     | jyoti.verma@specialforce.com    | 2020-11-02 |       1 |  60000 |

|    104 | anil       | patil     | anil.patil@specialforce.com     | 2018-09-18 |       3 |  70000 |

|    105 | pooja      | singh     | pooja.singh@specialforce.com    | 2020-06-10 |       4 |  40000 |

|    106 | sanjay     | iyer      | sanjay.iyer@specialforce.com    | 2018-01-22 |       3 |  75000 |

|    107 | jatin      | reddy     | jatin.reddy@specialforce.com    | 2021-12-12 |       2 |  85000 |

|    108 | shreya     | mehta     | shreya.mehta@specialforce.com   | 2022-04-19 |       5 |  30000 |

|    109 | rajesh     | gupta     | rajesh.gupta@specialforce.com   | 2020-08-11 |       1 |  90000 |

|    110 | kavita     | nair      | kavita.nair@specialforce.com    | 2021-02-07 |       2 |  50000 |

|    111 | akshada    | jadhav    | akshada.jadhav@specialforce.com | 2022-01-04 |    NULL |  92000 |

+--------+------------+-----------+---------------------------------+------------+---------+--------+

11 rows in set (0.00 sec)



mysql> create table project (

&#x20;   ->     project\_id int auto\_increment primary key,

&#x20;   ->     project\_name varchar(50),

&#x20;   ->     start\_date date,

&#x20;   ->     end\_date date,

&#x20;   ->     dept\_id int,

&#x20;   ->     constraint fk\_project\_departments foreign key (dept\_id) references departments(dept\_id)

&#x20;   -> );

Query OK, 0 rows affected (0.05 sec)



mysql> desc project;

+--------------+-------------+------+-----+---------+----------------+

| Field        | Type        | Null | Key | Default | Extra          |

+--------------+-------------+------+-----+---------+----------------+

| project\_id   | int         | NO   | PRI | NULL    | auto\_increment |

| project\_name | varchar(50) | YES  |     | NULL    |                |

| start\_date   | date        | YES  |     | NULL    |                |

| end\_date     | date        | YES  |     | NULL    |                |

| dept\_id      | int         | YES  | MUL | NULL    |                |

+--------------+-------------+------+-----+---------+----------------+

5 rows in set (0.02 sec)





mysql> insert into project (project\_id, project\_name, start\_date, end\_date, dept\_id) values

&#x20;   -> (201, 'Project Phoenix', '2021-01-15', '2022-07-30', 1),

&#x20;   -> (202, 'Client Onboarding', '2020-06-20', null, 3),

&#x20;   -> (203, 'Financial Overhaul', '2019-03-10', '2021-12-15', 4),

&#x20;   -> (204, 'Marketing Revamp', '2022-03-01', null, 5),

&#x20;   -> (205, 'Internal System Audit', '2023-02-15', null, 2);

Query OK, 5 rows affected (0.02 sec)

Records: 5  Duplicates: 0  Warnings: 0



mysql> select \*from project;

+------------+-----------------------+------------+------------+---------+

| project\_id | project\_name          | start\_date | end\_date   | dept\_id |

+------------+-----------------------+------------+------------+---------+

|        201 | Project Phoenix       | 2021-01-15 | 2022-07-30 |       1 |

|        202 | Client Onboarding     | 2020-06-20 | NULL       |       3 |

|        203 | Financial Overhaul    | 2019-03-10 | 2021-12-15 |       4 |

|        204 | Marketing Revamp      | 2022-03-01 | NULL       |       5 |

|        205 | Internal System Audit | 2023-02-15 | NULL       |       2 |

+------------+-----------------------+------------+------------+---------+

5 rows in set (0.00 sec)







**Query 1: Write a query to retrieve the first name, last name, and department name of all**

**employees. If an employee does not belong to any department, the department name should be**

**NULL.** 



mysql> select

&#x20;   -> e.first\_name,

&#x20;   -> e.last\_name,

&#x20;   -> d.dept\_name

&#x20;   -> from employees e

&#x20;   -> left join departments d on e.dept\_id =d.dept\_id;

+------------+-----------+-----------+

| first\_name | last\_name | dept\_name |

+------------+-----------+-----------+

| ravi       | sharma    | IT        |

| neha       | kapoor    | HR        |

| jyoti      | verma     | IT        |

| anil       | patil     | Sales     |

| pooja      | singh     | Finance   |

| sanjay     | iyer      | Sales     |

| jatin      | reddy     | HR        |

| shreya     | mehta     | Marketing |

| rajesh     | gupta     | IT        |

| kavita     | nair      | HR        |

| akshada    | jadhav    | NULL      |

+------------+-----------+-----------+

11 rows in set (0.00 sec)



**Query 2: Write a query to find all employees in the IT department who earn more than ₹50,000.** 



mysql> select \*from employees where salary >50000;

+--------+------------+-----------+---------------------------------+------------+---------+--------+

| emp\_id | first\_name | last\_name | email                           | hire\_date  | dept\_id | salary |

+--------+------------+-----------+---------------------------------+------------+---------+--------+

|    101 | ravi       | sharma    | ravi.sharma@specialforce.com    | 2017-05-15 |       1 |  55000 |

|    103 | jyoti      | verma     | jyoti.verma@specialforce.com    | 2020-11-02 |       1 |  60000 |

|    104 | anil       | patil     | anil.patil@specialforce.com     | 2018-09-18 |       3 |  70000 |

|    106 | sanjay     | iyer      | sanjay.iyer@specialforce.com    | 2018-01-22 |       3 |  75000 |

|    107 | jatin      | reddy     | jatin.reddy@specialforce.com    | 2021-12-12 |       2 |  85000 |

|    109 | rajesh     | gupta     | rajesh.gupta@specialforce.com   | 2020-08-11 |       1 |  90000 |

|    111 | akshada    | jadhav    | akshada.jadhav@specialforce.com | 2022-01-04 |    NULL |  92000 |

+--------+------------+-----------+---------------------------------+------------+---------+--------+

7 rows in set (0.00 sec)



**Query 3: Write a query to list the first name, last name, and email of all employees whose first**

**name starts with 'J' and whose email contains specialforce.com**



mysql> select \*from employees where first\_name like 'j%' and email like '%specialforce.com%';

+--------+------------+-----------+------------------------------+------------+---------+--------+

| emp\_id | first\_name | last\_name | email                        | hire\_date  | dept\_id | salary |

+--------+------------+-----------+------------------------------+------------+---------+--------+

|    103 | jyoti      | verma     | jyoti.verma@specialforce.com | 2020-11-02 |       1 |  60000 |

|    107 | jatin      | reddy     | jatin.reddy@specialforce.com | 2021-12-12 |       2 |  85000 |

+--------+------------+-----------+------------------------------+------------+---------+--------+

2 rows in set (0.00 sec)



**Query 4: Write a query to find all the distinct department names in the Departments table.** 



mysql> select distinct dept\_name from departments;

+-----------+

| dept\_name |

+-----------+

| IT        |

| HR        |

| Sales     |

| Finance   |

| Marketing |

+-----------+

5 rows in set (0.00 sec)



**Query 5: Write a query to calculate the total salary expenditure of each department.** 



mysql> select

&#x20;   -> d.dept\_name,

&#x20;   -> d.dept\_id,

&#x20;   -> sum(salary) as total\_salary

&#x20;   -> from employees e

&#x20;   -> inner join departments d on e.dept\_id=d.dept\_id

&#x20;   -> group by dept\_id;

+-----------+---------+--------------+

| dept\_name | dept\_id | total\_salary |

+-----------+---------+--------------+

| IT        |       1 |       205000 |

| HR        |       2 |       183000 |

| Sales     |       3 |       145000 |

| Finance   |       4 |        40000 |

| Marketing |       5 |        30000 |

+-----------+---------+--------------+

5 rows in set (0.01 sec)



**Query 6: Write a query to find the average salary of employees in the Finance department.** 



mysql> select avg(salary) as avg\_salary  from employees where dept\_id=4;

+------------+

| avg\_salary |

+------------+

| 40000.0000 |

+------------+

1 row in set (0.01 sec)





mysql> select

&#x20;   -> d.dept\_name,

&#x20;   -> avg(salary) as avg\_salary

&#x20;   -> from employees e

&#x20;   -> inner join departments d on e.dept\_id=d.dept\_id

&#x20;   -> where dept\_name='finance'

&#x20;   -> group by dept\_name;

+-----------+------------+

| dept\_name | avg\_salary |

+-----------+------------+

| Finance   | 40000.0000 |

+-----------+------------+

1 row in set (0.01 sec)



**Query 7: Write a query to find the minimum and maximum salaries of employees in the Sales**

**department.** 



mysql> select max(salary) as max\_salary , min(salary) as min\_salary from employees where dept\_id=3;

+------------+------------+

| max\_salary | min\_salary |

+------------+------------+

|      75000 |      70000 |

+------------+------------+

1 row in set (0.01 sec)



mysql>

mysql>  select

&#x20;   ->     d.dept\_name,

&#x20;   ->     max(salary) as max\_salary, min(salary) as min\_salary

&#x20;   ->     from employees e

&#x20;   ->     inner join departments d on e.dept\_id=d.dept\_id

&#x20;   ->      where dept\_name='sales'

&#x20;   ->      group by dept\_name;

+-----------+------------+------------+

| dept\_name | max\_salary | min\_salary |

+-----------+------------+------------+

| Sales     |      75000 |      70000 |

+-----------+------------+------------+

1 row in set (0.00 sec)



**Query 8: Write a query to count the number of employees in each department.** 



mysql> select dept\_id , count(\*) as total\_emp

&#x20;   -> from employees

&#x20;   -> group by dept\_id;

+---------+-----------+

| dept\_id | total\_emp |

+---------+-----------+

|    NULL |         1 |

|       1 |         3 |

|       2 |         3 |

|       3 |         2 |

|       4 |         1 |

|       5 |         2 |

+---------+-----------+

6 rows in set (0.00 sec)



**Query 9: Write a query to find all employees who were hired between January 1, 2018, and**

**December 31, 2020. Sort the result by hire date in ascending order.** 





mysql> select first\_name,last\_name,hire\_date

&#x20;   -> from employees

&#x20;   -> where hire\_date between '2018-01-01' and '2020-12-31'

&#x20;   -> order by hire\_date asc;

+------------+-----------+------------+

| first\_name | last\_name | hire\_date  |

+------------+-----------+------------+

| sanjay     | iyer      | 2018-01-22 |

| anil       | patil     | 2018-09-18 |

| neha       | kapoor    | 2019-03-23 |

| jatin      | sharma    | 2020-02-06 |

| pooja      | singh     | 2020-06-10 |

| rajesh     | gupta     | 2020-08-11 |

| jyoti      | verma     | 2020-11-02 |

+------------+-----------+------------+

7 rows in set (0.00 sec)



**Query 10: Write a query to list all employees who do not have an email address.** 



mysql> select \* from employees where email is null;

Empty set (0.00 sec)



**Query 11: Write a query to find all employees who work in HR, Finance, or IT departments.** 



mysql> select

&#x20;   -> e.emp\_id,

&#x20;   -> e.first\_name,

&#x20;   -> e.last\_name,

&#x20;   -> d.dept\_name

&#x20;   -> from employees e

&#x20;   -> inner join departments d on e.dept\_id =d.dept\_id

&#x20;   -> where d.dept\_name in ('HR', 'Finance', 'IT');

+--------+------------+-----------+-----------+

| emp\_id | first\_name | last\_name | dept\_name |

+--------+------------+-----------+-----------+

|    101 | ravi       | sharma    | IT        |

|    103 | jyoti      | verma     | IT        |

|    109 | rajesh     | gupta     | IT        |

|    102 | neha       | kapoor    | HR        |

|    107 | jatin      | reddy     | HR        |

|    110 | kavita     | nair      | HR        |

|    105 | pooja      | singh     | Finance   |

+--------+------------+-----------+-----------+

7 rows in set (0.00 sec)



**Query 12: Write a query to list the first name, last name, and salary of employees earning**

**between ₹30,000 and ₹70,000. Sort the results by salary in descending order.**





mysql> select first\_name, last\_name, salary

&#x20;   -> from employees

&#x20;   -> where salary between 30000 and 70000

&#x20;   -> order by salary desc;

+------------+-----------+--------+

| first\_name | last\_name | salary |

+------------+-----------+--------+

| anil       | patil     |  70000 |

| jyoti      | verma     |  60000 |

| ravi       | sharma    |  55000 |

| kavita     | nair      |  50000 |

| neha       | kapoor    |  48000 |

| pooja      | singh     |  40000 |

| shreya     | mehta     |  30000 |

+------------+-----------+--------+

7 rows in set (0.00 sec)





**Query 13: Write a query to join the Employees and Departments tables to list employees and their**

**department names. Make sure all employees are included, even if they don’t belong to any**

**department.** 



mysql> select e.first\_name, e.last\_name, d.dept\_name

&#x20;   -> from employees e

&#x20;   -> left join departments d on e.dept\_id = d.dept\_id;

+------------+-----------+-----------+

| first\_name | last\_name | dept\_name |

+------------+-----------+-----------+

| ravi       | sharma    | IT        |

| neha       | kapoor    | HR        |

| jyoti      | verma     | IT        |

| anil       | patil     | Sales     |

| pooja      | singh     | Finance   |

| sanjay     | iyer      | Sales     |

| jatin      | reddy     | HR        |

| shreya     | mehta     | Marketing |

| rajesh     | gupta     | IT        |

| kavita     | nair      | HR        |

| akshada    | jadhav    | NULL      |

| jatin      | sharma    | Marketing |

+------------+-----------+-----------+

12 rows in set (0.01 sec)





## **\*-------------------------------------------------------------------------------\***





**Task 1: Increase HR Salaries:**

**Write a query to increase the salaries of all employees in the HR department by 5%. Start a**

**transaction before applying the changes.**



mysql> update employees e

&#x20;   -> inner join departments d on e.dept\_id=d.dept\_id

&#x20;   -> set e.salary = e.salary \* 1.05

&#x20;   -> where d.dept\_name='HR';

Query OK, 3 rows affected (0.03 sec)

Rows matched: 3  Changed: 3  Warnings: 0



**Task 2: Savepoint Before Sales Increase:**

**Set a savepoint before increasing the salaries of employees in the Sales department by 3%.**



mysql> savepoint salary\_incr;

Query OK, 0 rows affected (0.02 sec)



mysql> update employees e

&#x20;   -> inner join departments d on e.dept\_id=d.dept\_id

&#x20;   -> set e.salary = e.salary \* 1.03

&#x20;   -> where d.dept\_name= 'sales';

Query OK, 2 rows affected (0.01 sec)

Rows matched: 2  Changed: 2  Warnings: 0



**Task 3: Rollback Sales Salary Increase:**

**Rollback to the savepoint created before the Sales salary increase**



mysql> rollback to salary\_incr;

Query OK, 0 rows affected (0.01 sec)



**Task 4: Commit the Transaction:**

**After rolling back the Sales increase, commit the changes made to the HR department salaries.**



mysql> commit;

Query OK, 0 rows affected (0.02 sec)





## **\*-------------------------------------------------------------------------------\***





**Query 14: Write a query to list employees who are working on projects that started after January**

**1, 2023.** 



mysql> select e.first\_name, e.last\_name, p.project\_name, p.start\_date

&#x20;   -> from employees e

&#x20;   -> inner join project p on e.dept\_id = p.dept\_id

&#x20;   -> where p.start\_date > '2023-01-01';

+------------+-----------+-----------------------+------------+

| first\_name | last\_name | project\_name          | start\_date |

+------------+-----------+-----------------------+------------+

| neha       | kapoor    | Internal System Audit | 2023-02-15 |

| jatin      | reddy     | Internal System Audit | 2023-02-15 |

| kavita     | nair      | Internal System Audit | 2023-02-15 |

+------------+-----------+-----------------------+------------+

3 rows in set (0.00 sec)



**Query 15: Write a query to list all departments, even those without any employees assigned.** 



mysql> select d.dept\_name, e.first\_name, e.last\_name

&#x20;   -> from departments d

&#x20;   -> left join employees e on d.dept\_id = e.dept\_id;

+-----------+------------+-----------+

| dept\_name | first\_name | last\_name |

+-----------+------------+-----------+

| IT        | ravi       | sharma    |

| IT        | jyoti      | verma     |

| IT        | rajesh     | gupta     |

| HR        | neha       | kapoor    |

| HR        | jatin      | reddy     |

| HR        | kavita     | nair      |

| Sales     | anil       | patil     |

| Sales     | sanjay     | iyer      |

| Finance   | pooja      | singh     |

| Marketing | shreya     | mehta     |

| Marketing | jatin      | sharma    |

| HR        | NULL       | NULL      |

+-----------+------------+-----------+

12 rows in set (0.01 sec)



**Query 16: Write a query to find the employee with the highest salary in each department.** 



mysql> select e.first\_name, e.last\_name, d.dept\_name, e.salary

&#x20;   -> from employees e

&#x20;   -> inner join departments d on e.dept\_id = d.dept\_id

&#x20;   -> where e.salary = (

&#x20;   -> select max(salary)

&#x20;   -> from employees

&#x20;   -> where dept\_id = e.dept\_id

&#x20;   -> );

+------------+-----------+-----------+--------+

| first\_name | last\_name | dept\_name | salary |

+------------+-----------+-----------+--------+

| rajesh     | gupta     | IT        |  90000 |

| jatin      | reddy     | HR        |  89250 |

| sanjay     | iyer      | Sales     |  75000 |

| pooja      | singh     | Finance   |  40000 |

| shreya     | mehta     | Marketing |  30000 |

+------------+-----------+-----------+--------+

5 rows in set (0.00 sec)





**Query 17: The company also decided to track the budget for each project. Write a query to add a**

**column budget (DECIMAL(10,2)) to the Projects table.** 





mysql> alter table project

&#x20;   -> add budget decimal(10,2);

Query OK, 0 rows affected (0.11 sec)

Records: 0  Duplicates: 0  Warnings: 0



mysql> select\* from project;

+------------+-----------------------+------------+------------+---------+--------+

| project\_id | project\_name          | start\_date | end\_date   | dept\_id | budget |

+------------+-----------------------+------------+------------+---------+--------+

|        201 | Project Phoenix       | 2021-01-15 | 2022-07-30 |       1 |   NULL |

|        202 | Client Onboarding     | 2020-06-20 | NULL       |       3 |   NULL |

|        203 | Financial Overhaul    | 2019-03-10 | 2021-12-15 |       4 |   NULL |

|        204 | Marketing Revamp      | 2022-03-01 | NULL       |       5 |   NULL |

|        205 | Internal System Audit | 2023-02-15 | NULL       |       2 |   NULL |

+------------+-----------------------+------------+------------+---------+--------+

5 rows in set (0.00 sec)



**Query 18: SpecialForce Private Limited realized they need to store the phone numbers of**

**employees. Write a query to add a new column phone\_number (VARCHAR(15)) to the Employees**

**table using the ALTER statement**



mysql> alter table employees

&#x20;   -> add phone\_number varchar(15);

Query OK, 0 rows affected (0.05 sec)

Records: 0  Duplicates: 0  Warnings: 0



mysql> select\* from employees;

+--------+------------+-----------+---------------------------------+------------+---------+--------+--------------+

| emp\_id | first\_name | last\_name | email                           | hire\_date  | dept\_id | salary | phone\_number |

+--------+------------+-----------+---------------------------------+------------+---------+--------+--------------+

|    101 | ravi       | sharma    | ravi.sharma@specialforce.com    | 2017-05-15 |       1 |  55000 | NULL         |

|    102 | neha       | kapoor    | neha.kapoor@specialforce.com    | 2019-03-23 |       2 |  50400 | NULL         |

|    103 | jyoti      | verma     | jyoti.verma@specialforce.com    | 2020-11-02 |       1 |  60000 | NULL         |

|    104 | anil       | patil     | anil.patil@specialforce.com     | 2018-09-18 |       3 |  70000 | NULL         |

|    105 | pooja      | singh     | pooja.singh@specialforce.com    | 2020-06-10 |       4 |  40000 | NULL         |

|    106 | sanjay     | iyer      | sanjay.iyer@specialforce.com    | 2018-01-22 |       3 |  75000 | NULL         |

|    107 | jatin      | reddy     | jatin.reddy@specialforce.com    | 2021-12-12 |       2 |  89250 | NULL         |

|    108 | shreya     | mehta     | shreya.mehta@specialforce.com   | 2022-04-19 |       5 |  30000 | NULL         |

|    109 | rajesh     | gupta     | rajesh.gupta@specialforce.com   | 2020-08-11 |       1 |  90000 | NULL         |

|    110 | kavita     | nair      | kavita.nair@specialforce.com    | 2021-02-07 |       2 |  52500 | NULL         |

|    111 | akshada    | jadhav    | akshada.jadhav@specialforce.com | 2022-01-04 |    NULL |  92000 | NULL         |

|    112 | jatin      | sharma    | jatin.sharma@gmail.com          | 2020-02-06 |       5 |   NULL | NULL         |

+--------+------------+-----------+---------------------------------+------------+---------+--------+--------------+

12 rows in set (0.00 sec)





**Query 19: Write a query to find the 2nd largest salary from the Employees table using:**



**. A subquery.**



mysql> select max(salary)

&#x20;   -> from employees

&#x20;   -> where salary < (select max(salary) from employees);

+-------------+

| max(salary) |

+-------------+

|       90000 |

+-------------+

1 row in set (0.00 sec)



**. The LIMIT clause.** 



mysql> select distinct salary

&#x20;   -> from employees

&#x20;   -> order by salary desc

&#x20;   -> limit 1 offset 1;

+--------+

| salary |

+--------+

|  90000 |

+--------+

1 row in set (0.02 sec)





**Query 20: Write a query to find the 3rd largest salary from the Employees table using:**

**. A subquery.**



mysql> select max(salary)

&#x20;   -> from employees

&#x20;   -> where salary < (

&#x20;   ->     select max(salary)

&#x20;   ->     from employees

&#x20;   ->     where salary < (select max(salary) from employees)

&#x20;   -> );

+-------------+

| max(salary) |

+-------------+

|       89250 |

+-------------+

1 row in set (0.01 sec)



**.The LIMIT clause.** 



mysql> select distinct salary

&#x20;   -> from employees

&#x20;   -> order by salary desc

&#x20;   -> limit 1 offset 2;

+--------+

| salary |

+--------+

|  89250 |

+--------+

1 row in set (0.00 sec)



**Query 21: Write a query to drop the Projects table.**



mysql> drop table project;

Query OK, 0 rows affected (0.06 sec)



mysql> select \*from project;

ERROR 1146 (42S02): Table 'specialforce.project' doesn't exist



**Query 22: Write a query to truncate the Employees table.**  



mysql> truncate table employees;

Query OK, 0 rows affected (0.08 sec)



mysql> select \*from employees;

Empty set (0.01 sec)



mysql> desc employees;

+--------------+-------------+------+-----+---------+----------------+

| Field        | Type        | Null | Key | Default | Extra          |

+--------------+-------------+------+-----+---------+----------------+

| emp\_id       | int         | NO   | PRI | NULL    | auto\_increment |

| first\_name   | varchar(20) | YES  |     | NULL    |                |

| last\_name    | varchar(20) | YES  |     | NULL    |                |

| email        | varchar(50) | YES  | UNI | NULL    |                |

| hire\_date    | date        | YES  |     | NULL    |                |

| dept\_id      | int         | YES  | MUL | NULL    |                |

| salary       | int         | YES  |     | NULL    |                |

| phone\_number | varchar(15) | YES  |     | NULL    |                |

+--------------+-------------+------+-----+---------+----------------+

8 rows in set (0.01 sec)

















































