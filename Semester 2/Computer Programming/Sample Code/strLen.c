/* Using strlen */
#include <stdio.h>
#include <string.h>

void main( void )
{
   char *string1 = "abcdefghijklmnopqrstuvwxyz";
   char *string2 = "Pakistan";
   char *string3 = "CUST";
    
printf("%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n%s\"%s\"%s%lu\n",
      "The length of ", string1, " is ", (unsigned int) strlen( string1 ),
      "The length of ", string2, " is ", (unsigned int) strlen( string2 ),
      "The length of ", string3, " is ", (unsigned int) strlen( string3 ) );   
} 
