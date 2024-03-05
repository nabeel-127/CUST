#include <stdio.h>

void main( void )
{
   int i,j; 
   int x[2][3] = {{10,20,30},{40,50,60}}; 
   int *xptr = &x[0][0];
   
      
   for ( i = 0; i < 2; i++ ) {
	for ( j = 0; j < 3; j++ ) 
      printf( "x[][] = %d\n", x[i][j]);	
   }
      
   for ( j = 0; j < 6; j++ ) {
      printf(" x[][] = %d\n", *(xptr+j) );  
   } 
  
   for ( i = 0; i < 2; i++ ) {
	for ( j = 0; j < 3; j++ ) 
      printf( "x[][] = %d\n", *(*(x+i)+j) );	
   }

     
}

