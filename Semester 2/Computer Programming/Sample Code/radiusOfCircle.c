/* function to compute area of a circle */
#include <stdio.h>
    
// function main
void main()
{
   const float PI = 3.14159;
   float radius, area, circum;
   printf("Entre Radius of Circle = ");
   scanf("%f", &radius); 
   area   = PI * radius * radius;
   circum = 2 * PI * radius;

   printf("Area of Circle = %f\n", area); 
   printf("Circumference of Circle = %f\n", circum);     
} /* end function main */

