//
//#include <stdio.h>
//
//int GreatestCommonDivisor(int x, int y);
//
//main()
//{
//	int num1, num2, GCD;
//	printf("Enter the first number: ");
//	scanf("%d", &num1);
//	printf("Enter the second number: ");
//	scanf("%d", &num2);
//	GCD = num1 < num2 ? num1 : num2;
//	GCD = GreatestCommonDivisor(num1, num2, GCD);
//	printf("The GCD of the given numbers are = %d\n", GCD);
//}
//
//int GreatestCommonDivisor(int x, int y, int GCD)
//{
//	if ((x % GCD == 0) && (y % GCD == 0))
//	{
//		return GCD;
//	}
//	else
//	{
//		return GreatestCommonDivisor(x, y, (GCD - 1));
//	}
//}
