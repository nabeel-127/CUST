//Bonus Activity 3

#include <stdio.h>

reverse(int X[], int Y[]);
main()
{
	int X[10], Y[10];
	for (int i = 0; i < 10; i++)
	{
		printf("Enter a number: ");
		scanf("%d", &X[i]);
	}

	for (int j = 0; j < 10; j++)
	{
		printf("%d ", X[j]);
	}

	reverse(X, Y);

	printf("\n");

	for (int k = 0; k < 10; k++)
	{
		printf("%d ", Y[k]);
	}
	printf("\n");
}

reverse(int X[], int Y[])
{
	int inverse = 0, j = 9;
	for (int i = 0; i < 10; i++)
	{
		Y[j] = X[i];
		j--;
	}
}