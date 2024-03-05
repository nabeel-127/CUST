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
/* Question No.:		4
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/


//#include <stdio.h>
//
//int reversefunction(int x);
//
//main()
//{
//	int num, result;
//	
//	printf("Enter a number: ");
//	scanf_s("%d", &num);
//
//	result = reversefunction(num);
//	if (result == num)
//	{
//		printf("The number %d is a palindromic number.\n", num);
//	}
//	else
//	{
//		printf("The number %d is not a palindromic number.\n", num);
//	}
//}
//
//int reversefunction(int x)
//{
//	int static reverse = 0;
//	if (x < 10)
//	{
//		return (reverse + x);
//	}
//	else
//	{
//		reverse = (reverse + (x % 10)) * 10;
//		return reversefunction(x / 10);
//	}
//}
