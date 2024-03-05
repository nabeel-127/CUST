#include <stdio.h>

void main()
{
   int sum , count , result;
   short p;
   float mean, da, db, dc;
   char ch;

   sum = 17;count = 5;
   da = 3.3 ; db = 4.5 ; dc = 9.9;
   ch = 'a';

   p = (short) sum; 
   result = (int)da + (int)db + (int)dc;
   mean = (float) sum / count;
   count = (int)ch;

   printf("P = %d\n", p );
   printf("Result = %d\n", result );
   printf("Mean = %f\n", mean );
   printf("Count = %d\n", count );

}