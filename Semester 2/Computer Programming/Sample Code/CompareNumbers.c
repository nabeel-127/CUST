/* function to compare two numbers */
#include <stdio.h>
    
void main( void )
{
   int num1, num2; 

   printf("Enter two integers: \n" );
   scanf( "%d%d", &num1, &num2 ); 

   if (num1 == num2 ) {
      printf("%d is equal to %d\n", num1, num2 );
   }
   if (num1 < num2 ) { 
      printf("%d is less than %d\n", num1, num2 );
   }
   if (num1 > num2 ) {
      printf("%d is greater than %d\n", num1, num2 );
   }
} /* end function main */
