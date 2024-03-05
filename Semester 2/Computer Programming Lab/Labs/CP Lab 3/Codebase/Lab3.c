
/*
//Activity 1
#include <stdio.h>
int main()
{
	int i = 1, terms, factorial = 1;
	printf("Enter the number of factorial terms: ");
	scanf("%d", &terms);
	while (i <= terms)
	{
		factorial = factorial * i;
		i++;
	}
	printf("The factorial is = %d\n", factorial);
	return 0;
}
*/

/*
//Activity 2
#include <stdio.h>
int main()
{
	int terms, first = 0, second = 1, sum;
	printf("Enter the number of terms: ");
	scanf("%d", &terms);
	if (terms > 0)
		printf("0\n");
	if (terms > 1)
		printf("1\n");

	for (int i = 1;i <= terms - 2; i++)
	{
		sum = first + second;
		first = second;
		second = sum;
		printf("%d\n", sum);
	}
	return 0;
}
*/

/*
//Activity 3
#include <math.h>
#include <stdio.h>
void main()
{
	int i = 0;
	do
	{
		
		float perp, base, hyp, P, B, H;
		char retry;
		printf("Enter the perpendicular: ");
		scanf("%f", &perp);
		printf("Enter the base: ");
		scanf("%f", &base);

		P = pow(perp, 2);
		B = pow(base, 2);

		hyp = P + B;
		H = sqrt(hyp);

		printf("%f\n", H);

		printf("Press 'E' to exit.\nPress any other key to continue.\n");
		scanf(" %c", &retry);
		if (retry == 'E' || retry == 'e')
		{
			i = 1;
		}
		printf("\n");
	} while (i == 0);
}
*/

/*
//Activity 4
#include <stdio.h>
void main()
{
	for (int line = 1;line <= 6;line++)
	{

		for (int space = 1;space < line;space++)
		{
			printf(" ");
		}

		for (int asterisks = 6;asterisks >= line; asterisks--)
		{
			printf("*");
		}

		printf("\n");
	}
}
*/



/*
#include <stdio.h>
void main()
{

	for (int line = 1;line <= 5;line++)
	{
		for (int num = 1;num <= line;num++)
		{
			printf("%d ", num);
		}
		printf("\n");
	}
}
*/


#include <stdio.h>
void main()
{
	for (int line = 1;line <= 5;line++)
	{
		for (int space = 4;space >= line;space--)
		{
			printf("  ");
		}

		for (float asterisks = 1;asterisks <= 2 * line -1;asterisks++)
		{
			printf("* ");
			
		}


		printf("\n");
	}
}

