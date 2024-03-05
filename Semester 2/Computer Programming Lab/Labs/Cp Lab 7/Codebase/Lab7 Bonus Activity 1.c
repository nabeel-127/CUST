//#include <stdio.h>
//main()
//{
//	int matrix[3][3], check = 1;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("Enter a number for the %d row and %d column: ", i + 1, j + 1);
//			scanf("%d", &matrix[i][j]);
//		}
//	}
//	for (int k = 0; k < 3; k++)
//	{
//		for (int l = 0; l < 3; l++)
//		{
//			if (k == l)
//			{
//				if (matrix[k][l] == 0)
//				{
//					check = 0;
//				}
//			}
//			else if (k < l)
//			{
//				if (matrix[k][l] != 0)
//				{
//					check = 0;
//				}
//			}
//			else if (k > l)
//			{
//				if (matrix[k][l] == 0)
//				{
//					check = 0;
//				}
//			}
//		}
//	}
//	if (check == 0)
//	{
//		printf("The matrix is NOT a lower triangular matrix.\n");
//	}
//	else
//	{
//		printf("The matrix is a lower triangular matrix.\n");
//	}
//}