# StaffManagment
A simple c++ Program to manage the vacation days of employees in a database. 



This program was written for an assignment for the "Programming in C++" course at the Virtuelle Hochschule Bayern.

The database is an array saved in memory during runtime and is deleted when the program ends. 



The program has the following main points:

Each employee is entitled to 30 days off per year.

Employees who have reached the age of 50 on 1 January of the current calendar year are entitled to a holiday of 32 days.



The following data of each employee is stored in the system:

Surname

First name

Date of birth

Days of holiday already taken



In addition, there is the following three subclasses, which inherit the properties from the Employee class:

HourlyEmployee:, from whom the following additional information is stored in the system:

• Hourly wage

• Hours worked


SalariedEmployee:

• Annual salary


Manager:

• Profit sharing



When the program starts, the "database" of the holiday management is empty, the data must first be entered.

The data is only be available during runtime (no permanent storage necessary!).



The program covers the following situation:

• Staff holiday management for a maximum of 500 employees (can be HourlyEmployee, SalariedEmployee, Manager)

• Creating and deleting an employee

• Entering the days on which the employee wants to take a holiday (must be possible more than once)

• Search for an employee and output of his/her data and how many remaining days of holiday he/she has

• Listing of all stored employee data


