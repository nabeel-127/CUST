
 #include <stdio.h>    
void recursive();

int main()
{
  int n, ans;

  printf("Program Starts...\n");
  
  recursive();
   
}

/* recursive function */
void recursive()
{
  static x = 1;
  printf("Recursive Function Call = %d\n", x);
  x++;
  recursive();
}
    
