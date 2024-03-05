/*=================================================================
/* CSEE1122:			Computer Programming
/*
/* Student Name :		Nabeel Ali
/*
/* Registration No.:	BEE173059
/*
/* Section No.:			II
/*
/* Assignment No.:		3
/*
/* Question No.:		1.
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/

//#include <stdio.h>
//void Multiplication(int X[3][3], int Y[3][3], int Z[3][3]);
//main()
//{
//	int i, j, k, X[3][3], Y[3][3], Z[3][3], sum;
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 3;j++)
//		{
//			printf("Enter the value of the 1st matrix: ");
//			scanf_s("%d", &X[i][j]);
//		}
//	}
//	printf("\n");
//	for (i = 0;i < 3;i++)
//	{
//		for (j = 0;j < 3;j++)
//		{
//			printf("Enter the value of the 2nd matrix: ");
//			scanf_s("%d", &Y[i][j]);
//		}
//	}
//	Multiplication(X, Y, Z);
//	for (i = 0;i < 3;i++)
//	{
//		printf("\n");
//		for (j = 0;j < 3;j++)
//		{
//			printf("%d\t", Z[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//void Multiplication(int X[3][3], int Y[3][3], int Z[3][3])
//{
//	int sum;
//	for (int row = 0;row < 3;row++)
//	{
//		for (int column = 0;column < 3;column++)
//		{
//			sum = 0;
//			for (int x = 0;x < 3;x++)
//			{
//				sum = sum + (X[row][x] * Y[x][column]);
//			}
//			Z[row][column] = sum;
//		}
//	}
//}