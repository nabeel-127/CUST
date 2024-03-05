/* Using strcat and strncat */
#include <stdio.h>
#include <string.h>

void main( void )
{ 
   char s1[30] = "Computer "; 
   char s2[] = "Programming "; 
   char s3[40] = ""; /* empty */
   
   printf( "s1 = %s\ns2 = %s\n", s1, s2 );

   /* concatenate s2 to s1 */
   printf( "strcat( s1, s2 ) = %s\n", strcat( s1, s2 ) );

   printf( "strncat( s3, s2, 7 ) = %s\n", strncat( s3, s2, 7 ) );

   /* concatenate s1 to s3 */
   printf( "strcat( s3, s1 ) = %s\n", strcat( s3, s1 ) );
 
}

