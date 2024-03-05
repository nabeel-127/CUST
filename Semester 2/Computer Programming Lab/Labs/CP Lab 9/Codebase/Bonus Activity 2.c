//#include <stdio.h>
//main()
//{
//	int X[10], Y[10], Z[20], i;
//	int *ptr1 = X, *ptr2 = Y, *ptr10 = Z;
//	for (i = 0;i < 10;i++)
//	{
//		printf("Enter the %d number for the 1st array: ", i+1);
//		scanf_s("%d", &X[i]);
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("Enter the %d number for the 2nd array: ", i + 1);
//		scanf_s("%d", &Y[i]);
//	}
//
//	for (i = 0;i < 20;i++)
//	{
//		if (i % 2 == 0)
//		{
//			*ptr10 = *ptr1;
//			ptr1++;
//		}
//		else
//		{
//			*ptr10 = *ptr2;
//			ptr2++;
//		}
//		ptr10++;
//	}
//	ptr1 = X;
//
//
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", *ptr1);
//		ptr1++;
//	}
//	ptr2 = Y;
//	printf("\n");
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", *ptr2);
//		ptr2++;
//	}
//	ptr10 = Z;
//	printf("\n");
//	for (i = 0;i < 20;i++)
//	{
//		printf("%d ", *ptr10);
//		ptr10++;
//	}
//	printf("\n");
//}