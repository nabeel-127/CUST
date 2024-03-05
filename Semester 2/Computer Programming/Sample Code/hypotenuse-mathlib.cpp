/* find hypotenuse  */
#include <math.h>
#include <stdio.h>    
float hypotenuse( float, float );

void main()
{
  float x, y, z;

  printf("Enter base =\n");
  scanf("%f",&x);

  printf("Enter perp =\n");
  scanf("%f",&y);
  z = hypotenuse(x,y);
  
  printf("Hypotenuse = %f\n", 
  z);
}
    
/* recursive function */

float hypotenuse( float base, float   perp)
{
  float hyp;
  hyp = sqrt( pow(base,2)+    
  pow(perp,2) ); 

  return hyp;
}
    
