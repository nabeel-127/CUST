/* Nested Loops*/
#include <stdio.h>
    
void main()
{
   int number = 0;
   int count, count2;

   for(count = 0; count < 4; count ++) {
      for(count2 = 0; count2 < 4; count2 ++) {      
         printf("Outer Loop count = %d, Inner Loop Count = %d\n", count, count2);
      }
	  printf("\n");
   }
   
}
