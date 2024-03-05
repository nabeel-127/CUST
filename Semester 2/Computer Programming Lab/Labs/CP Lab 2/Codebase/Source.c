/*
//Activity 1
#include <stdio.h>
int main()
{
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	if (num % 2 == 0)
		printf("The number is even.\n");
	else
		printf("The number is odd.\n");
	
	return 0;
}
*/

/*
//Activity 2
#include <stdio.h>
int main()
{
	int a, b, c;
	printf("Enter 'a': ");
	scanf("%d", &a);
	printf("Enter 'b': ");
	scanf("%d", &b);
	printf("Enter 'c': ");
	scanf("%d", &c);
	
	if (a <= 16 && (b - c) > 6)
	{
		b = 5 + c * 2;

		if (a * b > 12)
		{
			a = 10 - c * c;
		}

	}
	else
	{
		
		if (c != b)
			c = 5 + c * 2;

		b = a * (-c);
	}
	printf("a = %d\nb = %d\nc = %d\n", a, b, c);
	return 0;
}
*/


/*
//Activity 3
#include <stdio.h>
int main()
{
	int sum, difference, product;
	float A, B, division;
	char option;
	printf("Enter the number A: ");
	scanf("%f", &A);
	printf("Enter the number B: ");
	scanf("%f", &B);
	printf("Choose an option: \n");
	printf("+ for Addition\n");
	printf("- for Subtraction\n");
	printf("* for Multiplication\n");
	printf("/ for Division\n");
	printf("You have chosen: ");
	scanf(" %c", &option);
	
	switch (option)
	{
	case '+':
		sum = A + B;
		printf("The sum is = %d\n", sum);
		break;
	case '-':
		difference = A - B;
		printf("The difference is = %d\n", difference);
		break;
	case '*':
		product = A * B;
		printf("The product is = %d\n", product);
		break;
	case '/':
		if (B == 0)
		{
			printf("Error: Dividing by zero.\n");
		}
		else
		{
			division = A / B;
			printf("The product is = %f\n", division);
		}
		break;
	default:
		printf("You have entered the wrong input.\n");
	}
	return 0;
}
*/

/*
//Activty 4
#include <stdio.h>
int main()
{
	int num1, num2, num3;
	printf("Enter the 1st number: ");
	scanf("%d", &num1);
	printf("Enter the 2nd number: ");
	scanf("%d", &num2);
	printf("Enter the 3rd number: ");
	scanf("%d", &num3);
	if (num1 < num2)
	{
		if (num1 < num3)
		{
			printf("The smallest number is = %d.\n", num1);
		}
		else
		{
			printf("The smallest number is = %d.\n", num3);
		}
	}
	else
	{
		if (num2 < num3)
		{
			printf("The smallest number is = %d.\n", num2);
		}
		else
		{
			printf("The smallest number is = %d.\n", num3);
		}
	}
	return 0;
}
*/