#include <stdio.h>

void main( void )
{
   int b[] = {10,20,30,40,50 }; 
   int *ptr = b; 
      
   printf("x = %d\n", ptr );
   printf("x = %d\n", *ptr );
   printf("x = %d\n", *++ptr );
   printf("x = %d\n", ++*ptr );
   printf("x = %d\n", *ptr++ );

}


    
   
   

