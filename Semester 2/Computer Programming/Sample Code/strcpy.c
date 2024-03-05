/* Using strcpy and strncpy */
#include <stdio.h>
#include <string.h>

void main( void )
{ 
   char x[] = "CP Spring-2015"; 
   char y[ 25 ]; 
   char z[ 15 ]; 
   
   /* copy contents of x into y */
   printf( "%s%s\n%s%s\n", 
      "The string in array x is: ", x, "The string in array y is: ", strcpy( y, x ) );

    /* copy first 9 characters of x into z. */
   strncpy( z, x, 9 ); 
   z[ 9 ] = '\0'; /* terminate string in z */

   printf( "The string in array z is: %s\n", z );   
}

