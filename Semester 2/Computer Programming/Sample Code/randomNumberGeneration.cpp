/* Fig. 5.7: fig05_07.c
   Shifted, scaled integers produced by 1 + rand() % 6 */
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
   int i; 
   int number;

   for ( i = 0; i < 15; i++ ) {
  
	   /* pick random number from 1 to 10 */
	   number = 1 + rand() % 10;
      
      printf( "%d\n", number );
	        
   } 

   return 0;
} 


