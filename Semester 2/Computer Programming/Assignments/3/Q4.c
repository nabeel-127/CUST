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
//main()
//{
//	int X[6][6] = { { 0, 1, 1, 1, 1, 1 },{ 0, 0, 0, 1, 1, 1 },{ 1, 1, 0, 1, 1, 1 },{ 1, 1, 0, 1, 1, 1 },{ 1, 1, 0, 0, 0, 0 },{ 1, 1, 1, 1, 1, 0 } };
//	int Y[12][12] = { { 0, 0, 1, 1, 1, 1, 1,1,1,1,1,1 } ,{ 1,0,0,1,1,1,1,1,1,1,1,1 } ,{ 1,1,0,1,1,0,0,0,0,0,1,1 } ,{ 1,1,0,1,1,0,1,1,1,0,1,1 },{ 1,1,0,1,1,0,1,1,1,0,1,1 } ,{ 1,0,0,1,1,0,1,1,1,0,1,1 },{ 1,0,1,1,1,0,1,0,0,0,1,1 } ,{ 1,0,1,1,1,0,1,0,1,1,1,1 } ,{ 1,0,0,0,0,0,1,0,1,1,1,1 },{ 1,1,1,1,1,1,1,0,0,0,0,1 },{ 1,1,1,1,1,1,1,1,1,1,0,1 } ,{ 1,1,1,1,1,1,1,1,1,1,0,0 } };
//	int choice, row = 0, column = 0, tempR, tempC, flag, i, j, x;
//	printf("The options are:\n");
//	printf("1. 6x6\n");
//	printf("2. 12x12: ");
//	printf("Choose an option: ");
//	scanf_s("%d", &choice);
//	switch (choice)
//	{
//	case 1:
//		for (i = 0; i < 6; i++)
//		{
//			for (int j = 0; j < 6; j++)
//			{
//				printf("%d ", X[i][j]);
//			}
//			printf("\n");
//		}
//		
//		for (x = 0;x < 36;x++)
//		{
//			flag = 0;
//			printf("(%d, %d)\n", row, column);
//
//			if ((X[row][column + 1] == 0) && ((column + 1) != tempC))
//			{
//				tempR = row;
//				tempC = column;
//				column++;
//				flag = 1;
//			}
//			else if ((X[row + 1][column] == 0) && ((row + 1) != tempR))
//			{
//				tempR = row;
//				tempC = column;
//				row++;
//				flag = 1;
//			}
//			else if ((X[row][column - 1] == 0) && ((column - 1) != tempC))
//			{
//				tempR = row;
//				tempC = column;
//				column--;
//				flag = 1;
//			}
//			else if ((X[row - 1][column] == 0) && ((row - 1) != tempR))
//			{
//				tempR = row;
//				tempC = column;
//				row--;
//				flag = 1;
//			}
//			if (flag == 0)
//			{
//				break;
//			}
//		}
//		break;
//
//	case 2:
//		for (i = 0; i < 12; i++)
//		{
//			for (j = 0; j < 12; j++)
//			{
//				printf("%d ", Y[i][j]);
//			}
//			printf("\n");
//		}
//
//		for (int x = 0;x < 144;x++)
//		{
//			flag = 0;
//			printf("(%d, %d)\n", row, column);
//
//			if ((Y[row][column + 1] == 0) && ((column + 1) != tempC))
//			{
//				tempR = row;
//				tempC = column;
//				column++;
//				flag = 1;
//			}
//			else if ((Y[row + 1][column] == 0) && ((row + 1) != tempR))
//			{
//				tempR = row;
//				tempC = column;
//				row++;
//				flag = 1;
//			}
//			else if ((Y[row][column - 1] == 0) && ((column - 1) != tempC))
//			{
//				tempR = row;
//				tempC = column;
//				column--;
//				flag = 1;
//			}
//			else if ((Y[row - 1][column] == 0) && ((row - 1) != tempR))
//			{
//				tempR = row;
//				tempC = column;
//				row--;
//				flag = 1;
//			}
//			if (flag == 0)
//			{
//				break;
//			}
//		}
//		break;
//	}
//
//	
//}