/* Program to find grade of student */
#include <stdio.h>
    
void main()
{
    int marks;
    char askuser;
      
    do {
       printf("Entre Marks of Student = ");
       scanf("%d", &marks);
       if(marks >= 50)
         printf("Student has Pass Grade.\n");
       else 
         printf("Student has Fail Grade.\n");
       printf("Do you want to continue (y/n) ?");
       scanf( " %c" , &askuser);
    }while (askuser == 'y' || askuser == 'Y'); 
}
