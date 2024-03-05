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
/* Question No.:		2
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/

#include <stdio.h>
void main()
{
	float marks;
	printf("Enter your marks: ");
	scanf_s("%f", &marks);
	if (marks >= 90 && marks <= 100)
	{
		printf("Marks = %f\n", marks);
		printf("Grade: A\n");
		printf("GPA = 4.0\n");
	}
	else if (marks >= 82 && marks <= 100)
	{
		printf("Marks = %f\n", marks);
		printf("Grade: B\n");
		printf("GPA = 3.0\n");
	}
	else if (marks >= 65 && marks <= 100)
	{
		printf("Marks = %f\n", marks);
		printf("Grade: C\n");
		printf("GPA = 2.0\n");
	}
	else if (marks >= 45 && marks <= 100)
	{
		printf("Marks = %f\n", marks);
		printf("Grade: D\n");
		printf("GPA = 1.0\n");
	}
	else if (marks < 45 && marks >= 0 && marks <= 100)
	{
		printf("Marks = %f\n", marks);
		printf("Grade: F\n");
		printf("GPA = 0.0\n");
	}
	else
	{
		printf("You have entered the wrong value.\n");
	}
}
