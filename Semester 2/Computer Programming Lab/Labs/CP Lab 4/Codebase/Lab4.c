/*
//Activity 1
#include <stdio.h>

void pattern(int y, int x);

void main()
{
	int rows, columns;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("Enter the number of columns: ");
	scanf("%d", &columns);
	pattern(rows, columns);
}

void pattern(int y, int x)
{
	for (int line = 1; line <= y; line++)
	{
		for (int asterisks = 1; asterisks <= x; asterisks++)
		{
			printf("*");
		}
		printf("\n");
	}
}
*/



/*
//Activity 2
#include <stdio.h>

void menu();
float addition(float a, float b); 
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);

void main()
{
	float num1, num2, out;
	int option;
	char retry;
	do
	{
		printf("Enter the first number: ");
		scanf("%f", &num1);
		printf("Enter the second number: ");
		scanf("%f", &num2);
		printf("\n");
		menu();
		printf("\n");
		printf("Choose an option: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			out = addition(num1, num2);
			printf("The answer is = %f\n", out);
			break;
		case 2:
			out = subtraction(num1, num2);
			printf("The answer is = %f\n", out);
			break;
		case 3:
			out = multiplication(num1, num2);
			printf("The answer is = %f\n", out);
			break;
		case 4:
			out = division(num1, num2);
			printf("The answer is = %f\n", out);
			break;
		default:
			printf("You have entered the wrong value.\n");
		}
		
		printf("Press 'Y' to try agin the program, or any other key to exit: ");
		scanf(" %c", &retry);
		if (retry != 'Y' && retry != 'y')
		{
			break;
		}
		
		printf("\n\n\n");
	} while (1);
	

}

void menu()
{
	printf("The available operations are: \n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
}
float addition(float a, float b)
{
	float result;
	result = a + b;
	return result;
}
float subtraction(float a, float b)
{
	float result;
	result = a - b;
	return result;
}
float multiplication(float a, float b)
{
	float result;
	result = a * b;
	return result;
}
float division(float a, float b)
{
	float result;
	result = a / b;
	return result;
}
*/



/*
//Activity 3
#include <stdio.h>

int YofX(int X, int Y);

void main()
{
	int base, power, out;
	printf("Enter the base value: ");
	scanf("%d", &base);
	printf("Enter the power value: ");
	scanf("%d", &power);
	out = YofX(base, power);
	printf("The answer is = %d\n", out);
}

int YofX(int X, int Y)
{
	int result = 1;
	for (int counter = 1; counter <= Y; counter++)
	{
		result = result * X;
	}
	return result;
}
*/




//Activity 4
#include <stdio.h>

int LCM(int a, int b);

void main()
{
	int num1, num2, out;
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);
	out = LCM(num1, num2);
	printf("The LCM of the given numbers is = %d\n", out);

}

int LCM(int a, int b)
{
	int i;
	i = a > b ? a : b;
	while (1)
	{
		if ((i % a == 0) && (i % b == 0))
		{
			break;
		}
		i++;
	}
	return i;
}


/*
//Bonus Activity 1
#include <stdio.h>
int DecimaltoBinary(int input);
void main()
{
	int decimal, out;
	printf("Enter a number in decimal system: ");
	scanf("%d", &decimal);
	out = DecimaltoBinary(decimal);
	printf("%d\n", out);
}

int DecimaltoBinary(int input)
{
	int binary = 0, i = 1;
	while (input != 0)
	{

		binary = binary + (input % 2) * i;
		input = input / 2;
		i = i * 10;
	}
	return binary;
}
*/



/*
//Bonus Activity 2
#include <stdio.h>
int palindromic(int x);
void main()
{
	int num, out;
	printf("Enter a number: ");
	scanf("%d", &num);
	out = palindromic(num);
	if (out == 1)
	{
		printf("TRUE\nThe number is palindromic.\n");
	}
	else
	{
		printf("FALSE\nThe number is not palindromic.\n");
	}

}

int palindromic(int x)
{
	int store, reverse = 0, num, result;
	store = x;
	while (x > 0)
	{
		num = x % 10;
		x = x / 10;
		reverse = reverse * 10 + num;

	}

	return (reverse == store);
}
*/



/*
//Bonus Activity 3
#include <stdio.h>
#include <math.h>

float distance(int x1, int x2, int y1, int y2);

main()
{
	float D;
	int x1, x2, y1, y2;
	printf("Enter the x1 coordinate: ");
	scanf("%d", &x1);
	printf("Enter the x2 coordinate: ");
	scanf("%d", &x2);
	printf("Enter the y1 coordinate: ");
	scanf("%d", &y1);
	printf("Enter the y2 coordinate: ");
	scanf("%d", &y2);
	D = distance(x1, x2, y1, y2);
	printf("The distance is = %f\n", D);
}

float distance(int x1, int x2, int y1, int y2)
{
	float D;
	int x, y;
	x = x2 - x1;
	y = y2 - y1;
	D = sqrt(pow(x, 2) + pow(y, 2));
	return D;
}
*/



/*
#include <stdio.h>

int YofX(int x, int y);

main()
{
	int base, power, out;
	printf("Enter the base: ");
	scanf("%d", &base);
	printf("Enter the power: ");
	scanf("%d", &power);
	out = YofX(base, power);
	printf("The result is = %d\n", out);
}

int YofX(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	else
	{
		return (x * YofX(x, y - 1));
	}
}
*/