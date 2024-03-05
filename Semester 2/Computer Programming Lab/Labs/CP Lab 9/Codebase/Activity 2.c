//#include <stdio.h>
//main()
//{
//	int X[3][3], Y[3][3], Z[3][3], i, j, counter;
//	int *ptrX, *ptrY, *ptrZ;
//	counter = 1;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("Enter the %d value of the 1st matrix: ", counter++);
//			scanf_s("%d", &X[i][j]);
//		}
//	}
//	counter = 1;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("Enter the %d value of the 2nd matrix: ", counter++);
//			scanf_s("%d", &Y[i][j]);
//		}
//	}
//	ptrX = X;
//	ptrY = Y;
//	ptrZ = Z;
//	for (i = 0; i < 9; i++)
//	{
//		*ptrZ = *ptrX + *ptrY;
//		ptrX++;
//		ptrY++;
//		ptrZ++;
//	}
//	ptrZ = Z;
//	for (i = 0; i < 9; i++)
//	{
//		printf("\t%d", *ptrZ++);
//		if (i == 2 || i == 5)
//		{
//			printf("\n");
//		}
//	}
//	printf("\n");
//}