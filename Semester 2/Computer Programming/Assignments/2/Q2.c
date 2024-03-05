/*=================================================================
/* CSEE1122:			Computer Programming
/*
/* Student Name :		Nabeel Ali
/*
/* Registration No.:	BEE173059
/*
/* Section No.:			II
/*
/* Assignment No.:		2
/*
/* Question No.:		2
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/


////(a)
//#include <stdio.h>
//int prime(int x);
//void main()
//{
//	int num, out;
//	printf("Enter a number: ");
//	scanf_s("%d", &num);
//	out = prime(num);
//	if (out == 1)
//	{
//		printf("TRUE\nThe number is a prime number.\n");
//	}
//	else
//	{
//		printf("FALSE\nThe number is not a prime number.\n");
//	}
//
//}
//
//int prime(int x)
//{
//	int prime = 1;
//	for (int i = 2;i <= (x / 2);i++)
//	{
//		if (x % i == 0)
//		{
//			prime = 0;
//			break;
//		}
//	}
//	if (prime == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//
////(b)
//#include <stdio.h>
//int DecimaltoBinary(int input);
//void main()
//{
//	int decimal, out;
//	printf("Enter a number in decimal system: ");
//	scanf_s("%d", &decimal);
//	out = DecimaltoBinary(decimal);
//	printf("%d\n", out);
//}
//
//int DecimaltoBinary(int input)
//{
//	int binary = 0, i = 1;
//	while (input != 0)
//	{
//
//		binary = binary + (input % 2) * i;
//		input = input / 2;
//		i = i * 10;
//	}
//	return binary;
//}
