//#include <stdio.h>
//main()
//{
//	char names[10][20];
//	int *ptr[10], i, j, counter = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("Enter the %d name: ", i+1);
//		gets(&names[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		ptr[i] = names[i];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		counter = 0;
//		for (j = 0; j < 20; j++)
//		{
//			if (names[i][j] == '\0')
//			{
//				break;
//			}
//			counter++;
//		}
//		if (counter > 5)
//		{
//			printf("%s\n", ptr[i]);
//		}
//	}
//}