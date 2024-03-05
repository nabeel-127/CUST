#include <stdio.h>
#include <math.h>

struct point  
{  
  float x;
  float y;  
};

int main() 
{
   point p1, p2;
   float distance;

   printf(" Corrdinates of Point 1 = ");
   scanf("%f %f", &p1.x, &p1.y);
   printf(" Corrdinates of Point 2 = ");
   scanf("%f %f", &p2.x, &p2.y);

   distance = sqrt( pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2) );
    
   printf("Distance between two points =%f\n", distance);   
}