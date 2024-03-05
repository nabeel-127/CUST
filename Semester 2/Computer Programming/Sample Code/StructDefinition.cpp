#include <stdio.h>

struct student 
{  
  char name[20];
  int marks;
  char grade;
};

int main() 
{
   struct student s1;

   printf(" Student Name = ");
   scanf("%s", s1.name);
   printf(" Student Marks = ");
   scanf("%d", &s1.marks);

   if(s1.marks >= 50)
	   s1.grade = 'P';
   else
	   s1.grade = 'F';

   printf("Student Name = %s\n", s1.name);
   printf("Student Marks = %d\n", s1.marks);
   printf("Student Grade = %c\n", s1.grade);
}