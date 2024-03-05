//#include <stdio.h>
//
//main()
//{
//	int matrix1[2][2], matrix2[2][2], sum = 0, result[2][2];
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			printf("Enter the %d row and %d column in matrix 1: ", i + 1, j + 1);
//			scanf("%d", &matrix1[i][j]);
//		}
//	}
//	for (int k = 0; k < 2; k++)
//	{
//		for (int l = 0; l < 2; l++)
//		{
//			printf("Enter the %d row and %d column in matrix 1: ", k + 1, l + 1);
//			scanf("%d", &matrix2[k][l]);
//		}
//		
//	}
//
//	for (int x = 0; x < 2; x++)
//	{
//		for (int y = 0; y < 2; y++)
//		{
//			sum = 0;
//			for (int z = 0; z < 2; z++)
//			{
//				sum = sum + matrix1[x][z] * matrix2[z][y];
//			}
//			result[x][y] = sum;
//		}
//	}
//	for (int m = 0; m < 2; m++)
//	{
//		for (int n = 0; n < 2; n++)
//		{
//			printf("%d ", result[m][n]);
//		}
//		printf("\n");
//	}
//
//}