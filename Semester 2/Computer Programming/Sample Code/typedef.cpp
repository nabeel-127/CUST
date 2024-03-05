#include <stdio.h>
#include <stdlib.h>

typedef int data32bit;
typedef short data16bit;
typedef float fraction;
typedef char text;

int main()
{
	data32bit i,j;
    fraction x;
	text option;

	i=0;
	do{
		x = rand() + i;
		printf(" %d %f \n", i++, x);

		printf(" You want to continue ? ");
		scanf(" %c", &option);
	}while(option == 'y' || option == 'Y');

    return 0;
}

