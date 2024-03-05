/*=================================================================
/* CSEE1122:			Computer Programming
/*
/* Student Name :		Nabeel Ali
/*
/* Registration No.:	BEE173059
/*
/* Section No.:			II
/*
/* Assignment No.:		1
/*
/* Question No.:		3
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/
/*
#include <stdio.h>
void main()
{
	do
	{
	
		int accomodation, people, days, destination, tbudget, hbudget, totalbudget, i = 0;
		char retry;
	
		printf("Enter the number of people: ");
		scanf_s("%d", &people);
		
		printf("\nEnter the number of days for the tour: ");
		scanf_s("%d", &days);
	
		printf("\nThe destinations available are: \n");
		printf("  ------------------------------------\n");
		printf(" |S# |    Destination    |   Budget   |\n");
		printf("  ------------------------------------\n");
		printf(" | 1 |   Naran Kaghan    | Rs. 8,000  |\n");
		printf(" | 2 |   Neelum Valley   | Rs. 10,000 |\n");
		printf(" | 3 |    Malam Jabba    | Rs. 9,000  |\n");
		printf(" | 4 | Shangrilla Resort | Rs. 20,000 |\n");
		printf(" | 5 |   Banjosa Lake    | Rs. 5,000  |\n");
		printf("  ------------------------------------\n");
		printf("Enter the S# of the desired destination: ");
		scanf_s("%d", &destination);
		switch (destination)
		{
		case 1:
			tbudget = 8000;
			break;
		case 2:
			tbudget = 10000;
			break;
		case 3:
			tbudget = 9000;
			break;
		case 4:
			tbudget = 20000;
			break;
		case 5:
			tbudget = 5000;
			break;
		default:
			printf("You have entered the wrong value.\n");
			i = 1;
		}
		if (i == 1)
			break;
		
		printf("\nThe available accomodations are: \n");
		printf("  -------------------------------------\n");
		printf(" |S# | Hotel Accomodation |   Budget   |\n");
		printf("  -------------------------------------\n");
		printf(" | 1 |     Five Star      | Rs. 10,000 |\n");
		printf(" | 2 |     Four Star      | Rs. 8,000  |\n");
		printf(" | 3 |     Three Star     | Rs. 5,000  |\n");
		printf(" | 4 |      Two Star      | Rs. 2,000  |\n");
		printf("  -------------------------------------\n");
		printf("Choose an accomodation: ");
		scanf_s("%d", &accomodation);
		printf("\n");
		switch (accomodation)
		{
		case 1:
			hbudget = 10000;
			break;
		case 2:
			hbudget = 8000;
			break;
		case 3:
			hbudget = 5000;
			break;
		case 4:
			hbudget = 2000;
			break;
		default:
			printf("You have entered the wrong value.\n");
			i = 1;
		}
		if (i == 1)
			break;
	
		totalbudget = tbudget * people + hbudget * days + 10000 + 2500;

		printf("The total expense of the trip will be = Rs. %d\n", totalbudget);
	
	} while (0);
}
*/