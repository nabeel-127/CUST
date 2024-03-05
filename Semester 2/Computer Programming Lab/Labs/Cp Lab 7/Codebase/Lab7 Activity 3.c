//#include <stdio.h>
//Transpose(int matrix[3][3], int transpose[3][3]);
//main()
//{
//	int matrix[3][3], transpose[3][3];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("Enter a number for the %d row and %d column: ", i + 1, j + 1);
//			scanf("%d", &matrix[i][j]);
//		}
//	}
//
//	Transpose(matrix, transpose);
//
//	for (int x = 0; x < 3; x++)
//	{
//		for (int y = 0; y < 3; y++)
//		{
//			printf("%d ", transpose[x][y]);
//		}
//		printf("\n");
//	}
//}
//
//Transpose(int matrix[3][3], int transpose[3][3])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			transpose[j][i] = matrix[i][j];
//		}
//	}
//}