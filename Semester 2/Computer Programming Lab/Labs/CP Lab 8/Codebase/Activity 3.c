//#include <stdio.h>
//char palindromic(char X[10]);
//main()
//{
//	char X[10];
//	int check;
//	printf("Enter a string: ");
//	scanf("%s", &X);
//
//	check = palindromic(X);
//	if (check == 1)
//	{
//		printf("Palindromic\n");
//	}
//	else
//	{
//		printf("NOT palindromic\n");
//	}
//}
//char palindromic(char X[10])
//{
//	int x, j, check = 0;
//	for (x = 0; x < 10; x++)
//	{
//		if (X[x] == '\0')
//		{
//			j = x - 1;
//			break;
//		}
//	}
//	for (int i = 0; i < x; i++)
//	{
//		if (X[i] != X[j])
//		{
//			check = 1;
//		}
//		j--;
//	}
//	
//	if (check == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}