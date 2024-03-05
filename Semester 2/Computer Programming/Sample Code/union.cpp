#include <stdio.h>
#include <string.h> 

union Data { 
  int i; 
  float f; 
  char str[20]; 
}; 

void main( ) { 
   union Data data; 
   data.i = 10; 
   data.f = 310.5; 
   strcpy( data.str, "M.A.J.U"); 
   
   printf( "data.i : %d\n",data.i); 
   printf( "data.f : %f\n", data.f); 
   printf( "data.str : %s\n", data.str); 
}