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
/* Question No.:		4
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/
/*
#include <stdio.h>
void main()
{
	float GST, cost = 0;
	int units, i, j, k;
	printf("Enter the electricity units(kWh): ");
	scanf_s("%d", &units);
	for (i = 1; i <= 100; i++)
	{
		if (i > units)
		{
			break;
		}
		cost = cost + 5;
	}
	for (j = i; j <= 180 && j > 100; j++)
	{
		if (j > units)
		{
			break;
		}
		cost = cost + 7;
	}
	for (k = j; k > 180 && k <= units; k++)
	{
		cost = cost + 9;
	}
	cost = cost + 35;
	GST = (5 * cost) / 100;
	cost = cost + GST;
	printf("The total cost is = %f \n", cost);
}
*/