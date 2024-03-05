/* Using strcmp and strncmp */
#include <stdio.h>
#include <string.h>

void main( void )
{
   const char *s1 = "Computer Programming"; /* initialize char pointer */
   const char *s2 = "Computer Programming"; 
   const char *s3 = "Computer Skills"; 
 
   printf("%s%s\n%s%s\n%s%s\n\n%s%2d\n%s%2d\n%s%2d\n\n",
      "s1 = ", s1, "s2 = ", s2, "s3 = ", s3,
      "strcmp(s1, s2) = ", strcmp( s1, s2 ),
      "strcmp(s1, s3) = ", strcmp( s1, s3 ),
      "strcmp(s3, s1) = ", strcmp( s3, s1 ) );

   printf("%s%2d\n%s%2d\n%s%2d\n",
      "strncmp(s1, s3, 8) = ", strncmp( s1, s3, 8 ),
      "strncmp(s1, s3, 9) = ", strncmp( s1, s3, 9 ),
      "strncmp(s3, s1, 10) = ", strncmp( s3, s1, 10 ) );   
} 
