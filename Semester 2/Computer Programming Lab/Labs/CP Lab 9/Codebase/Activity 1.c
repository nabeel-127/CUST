//#include <stdio.h>
//#include <stdlib.h>
//MaxMin(int X[10], int *max, int *min);
//main()
//{
//	int X[10], *ptr = X, max, min, i;
//	for (i = 0; i < 10; i++)
//	{
//		*ptr = rand();
//		ptr++;
//	}
//	ptr = X;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", *ptr++);
//	}
//	MaxMin(X, &max, &min);
//	printf("Max = %d\n", max);
//	printf("Min = %d\n", min);
//}
//MaxMin(int X[10], int *max, int *min)
//{
//	int *ptr = X, i;
//	*max = X[0];
//	*min = X[0];
//	for (i = 0; i < 10; i++)
//	{
//		*max = *ptr > *max ? *ptr : *max;
//		*min = *ptr < *min ? *ptr : *min;
//		ptr++;
//	}
//}