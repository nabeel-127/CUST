/* Array of pointers to functions */
#include <stdio.h>

void function1( int a );
void function2( int b );
void function3( int c );

void main( void )
{
   void (*f[ 3 ])( int ) = { function1, function2, function3 };
   int choice; 

   printf( "Enter a number between 0 and 2, 3 to end: " );
   scanf( "%d", &choice );
      
   while ( choice < 3 ) {
	         
      (*f[ choice ])( choice );

      printf( "Enter a number between 0 and 2, 3 to end: ");
      scanf( "%d", &choice );
   } 
   printf( "Program execution completed.\n" );   
} 

void function1( int a )
{
   printf( "You entered %d so function1 was called\n\n", a );
} /* end function1 */

void function2( int b )
{
   printf( "You entered %d so function2 was called\n\n", b );
} /* end function2 */

void function3( int c )
{
   printf( "You entered %d so function3 was called\n\n", c );
} /* end function3 */
