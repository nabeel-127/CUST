#include <stdio.h>
void swap(int *a, int *b);

void main() {
   int q = 3;
   int r = 5;
   swap(&q, &r);
   printf("q = %d\n",q);
   printf("r = %d\n",r);
}

/* function definition */ 
void swap(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}
