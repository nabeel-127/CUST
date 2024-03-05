
#include <stdio.h>

void main( void )
{
   char string1[] = "Computer Programming"; 
   char string2[ 20 ]; 
   int i; 

   printf("Enter your Name: ");
   scanf( "%s", string2 ); 

   printf("String1 is: %s\nstring2 is: %s\n",string1, string2 );
   printf("String2 with spaces :\n");
   i = 0; 
   while ( string2[ i ] != '\0') {
      printf("%c ", string2[ i ] );
	  i++;
   }       
   printf("\n");
} 



