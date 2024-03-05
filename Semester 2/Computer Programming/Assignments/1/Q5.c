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
/* Question No.:		5
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/
/*
#include <stdio.h>
int main()
{
	float v, s, t, decimalvalueH, decimalvalueM;
	int num, hour, min, sec;
	printf("Enter the velocity in km/h: ");
	scanf_s("%f", &v);
	printf("Enter the distance in km: ");
	scanf_s("%f", &s);
	t = s / v;
	hour = t;
	
	decimalvalueH = t - hour;
	min = decimalvalueH * 60;
	
	decimalvalueM = decimalvalueH * 60;
	sec = (decimalvalueM - min) * 60;
	
	printf(" %d : %d : %d \n\n", hour, min, sec);
	return 0;
}
*/