#include <stdio.h>

struct date
{
	int date;
	int month;
	int year; 
};

struct Employee
{
   char ename[20];
   int ssn;
   float salary;
   struct date doj;
   
}emp = {"Ali",1050,20000,{22,6,2010}};

void main()
{
printf("\nEmployee Name   : %s",emp.ename);  
printf("\nEmployee SSN    : %d",emp.ssn);  
printf("\nEmployee Salary : %.2f",emp.salary);  
printf("\nEmployee DOJ    : %d/%d/%d\n", emp.doj.date,emp.doj.month,emp.doj.year);  
    
return 0;
}