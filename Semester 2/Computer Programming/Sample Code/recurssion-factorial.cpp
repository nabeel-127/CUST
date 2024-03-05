/* find factorial  */

 #include <stdio.h>    
int fact(int k);

int main()
{
  int n, ans;

  printf("Enter number =\n");
  scanf("%d",&n);

  ans = fact(n);
  
  printf("Factorial = %d\n", ans);

  return(0);
}

/* recursive function */
int fact(int k)
{
  if (k <= 1)
    return 1;
  else
    return k*fact(k-1);
}
    
