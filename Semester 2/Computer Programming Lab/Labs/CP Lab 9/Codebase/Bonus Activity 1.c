//#include <stdio.h>
//main()
//{
//	int X[5], Y[5], Z[5], i, j;
//	int *ptr1[3] = { X, Y, Z }, **ptr2;
//	for (i = 0;i < 5;i++)
//	{
//		printf("Enter the %d number for the 1st array: ", i+1);
//		scanf_s("%d", &X[i]);
//	}
//	for (i = 0;i < 5;i++)
//	{
//		printf("Enter the %d number for the 2nd array: ", i+1);
//		scanf_s("%d", &Y[i]);
//	}
//	for (i = 0;i < 5;i++)
//	{
//		printf("Enter the %d number for the 3rd array: ", i+1);
//		scanf_s("%d", &Z[i]);
//	}
//	for (i = 0;i < 5;i++)
//	{
//		ptr2 = &ptr1[i];
//		for (j = 0;j < 5;j++)
//		{
//			
//			printf("%d ", **ptr2++);
//		}
//		
//	}
//}