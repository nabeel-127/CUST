#include <stdio.h>

struct student {  
  char name[20];
  int marks;
  char grade;
};

void main() 
{
   struct student s1[10];
   int i,j;
   for(i=0;i<10;i++){
     printf(" Student Name = ");
     scanf("%s", s1[i].name);
     printf(" Student Marks = ");
     scanf("%d", &s1[i].marks); 
   }

   for(i=0;i<10;i++){
     if(s1[i].marks >= 50)
       s1[i].grade = 'P';
     else
       s1[i].grade = 'F';
   }
   for(i=0;i<10;i++){
   printf("Student Name = %s\n", s1[i].name);
   printf("Student Marks = %d\n", s1[i].marks);
   printf("Student Grade = %c\n", s1[i].grade);
   }
}
