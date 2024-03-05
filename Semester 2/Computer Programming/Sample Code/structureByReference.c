#include <stdio.h>

struct student {  
  char name[20];
  int marks;
  char grade;
};
void findGrade ( struct student *ptrS);
void main() 
{
   struct student s1, *ptrS;
   ptrS = &s1;
   printf(" Student Name = ");
   scanf("%s", s1.name);
   printf(" Student Marks = ");
   scanf("%d", &s1.marks);

   findGrade (ptrS);

   printf("Student Name = %s\n", s1.name);
   printf("Student Marks = %d\n", s1.marks);
   printf("Student Grade = %c\n", s1.grade);
}

void findGrade ( struct student *ptrS) {
  if(ptrS->marks >= 50)
     ptrS->grade = 'P';
   else
     ptrS->grade = 'F';  
}
