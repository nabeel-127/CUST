/* find factorial  */

 #include <stdio.h>    
void function();

int main()
{
  function();
  function ();
  function ();
  
  return 0;  
}
    
void function() 
{ 
   int y = 0;
   static int x = 0; 
   x += 10; 
   y += 10;
   printf("X = %d, Y= %d\n", x, y ); 
}    
