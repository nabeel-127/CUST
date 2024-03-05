/*=================================================================
/* CSEE1122:			Computer Programming
/*
/* Student Name :		Nabeel Ali
/*
/* Registration No.:	BEE173059
/*
/* Section No.:			II
/*
/* Assignment No.:		2
/*
/* Question No.:		5
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/


//#include <stdio.h>
//#include <stdlib.h>
//
//DisplayGameInstructions();
//int RandomNumberGenerator(int *x, int *y, int *z);
//DecideWinner(int uservalue1, int uservalue2, int uservalue3, int randomnumber1, int randomnumber2, int randomnumber3);
//
//main()
//{
//	int num1, num2, num3, random1 = 0, random2 = 0, random3 = 0;
//	char retry;
//
//	time_t t;
//	srand((unsigned)&t);
//
//	do
//	{
//		DisplayGameInstructions();
//		
//		RandomNumberGenerator(&random1, &random2, &random3);
//		printf("\n%d\n%d\n%d\n\n", random1, random2, random3);
//
//		printf("Enter the first number: ");
//		scanf_s("%d", &num1);
//		printf("Enter the second number: ");
//		scanf_s("%d", &num2);
//		printf("Enter the third number: ");
//		scanf_s("%d", &num3);
//
//		DecideWinner(num1, num2, num3, random1, random2, random3);
//		
//		printf("Do you want to play again?\n");
//		scanf_s(" %c", &retry);
//		if ((retry != 'y') && (retry != 'Y'))
//		{
//			break;
//		}
//
//		printf("\n\n\n\n\n\n\n\n\n\n\n");
//		printf("\n\n\n\n\n\n\n\n\n\n");
//	} while (1);
//}
//
//DisplayGameInstructions()
//{
//	printf("*****************************************\n");
//	printf("*          GUESS A NUMBER GAME          *\n");
//	printf("*****************************************\n");
//	printf("HELLO USER, LETS PLAY A GAME.\n");
//	printf("YOU HAVE TO GUESS THREE NUMBERS BETWEEN 1 AND 20.\n");
//	printf("POINTS FOR EACH CORRECT GUESS ARE 100\n");
//	printf("LETS PLAY ! ! !\n");
//}
//
//int RandomNumberGenerator(int *random1, int *random2, int *random3)
//{
//	*random1 = 1 + rand() % 20;
//
//	while (1)
//	{
//		*random2 = 1 + rand() % 20;
//		if (*random2 != *random1)
//		{
//			break;
//		}
//	}
//
//	while (1)
//	{
//		*random3 = 1 + rand() % 20;
//		if ((*random3 != *random1) && (*random3 != *random2))
//		{
//			break;
//		}
//	}
//}
//
//DecideWinner(int uservalue1, int uservalue2, int uservalue3, int randomnumber1, int randomnumber2, int randomnumber3)
//{
//
//	int counter = 3, i = 0, j = 0, k = 0;
//	
//	if (uservalue1 == randomnumber1)
//	{
//		counter--;
//		i = 1;
//	}
//	else if (uservalue1 == randomnumber2)
//	{
//		counter--;
//		i = 1;
//	}
//	else if (uservalue1 == randomnumber3)
//	{
//		counter--;
//		i = 1;
//	}
//
//	if (uservalue2 == randomnumber1)
//	{
//		counter--;
//		j = 1;
//	}
//	else if (uservalue2 == randomnumber2)
//	{
//		counter--;
//		j = 1;
//	}
//	else if (uservalue2 == randomnumber3)
//	{
//		counter--;
//		j = 1;
//	}
//
//	if (uservalue3 == randomnumber1)
//	{
//		counter--;
//		k = 1;
//	}
//	else if (uservalue3 == randomnumber2)
//	{
//		counter--;
//		k = 1;
//	}
//	else if (uservalue3 == randomnumber3)
//	{
//		counter--;
//		k = 1;
//	}
//	
//	if ((i == 0) || (j == 0) || (k == 0))
//	{
//		printf("Sorry, %d out of 3 numbers are incorrect.\n", counter);
//	}
//	else
//	{
//		printf("Congratulations, You Win ! ! !\n");
//	}
//}
