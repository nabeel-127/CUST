///*=================================================================
///* CSEE1122:			Computer Programming
///*
///* Student Name :		Nabeel Ali
///*
///* Registration No.:	BEE173059
///*
///* Section No.:			I
///*
///* Assignment No.:		4
///*
///* Question No.:		1.
///*==================================================================
///* I certify that I have neither given nor received unauthorized aid
///*         on this Assignment.
///*==================================================================*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//char GradeCalculator(int marks);
//struct Student
//{
//	char name[30];
//	char regno[20];
//	int englishmarks;
//	int algebramarks;
//	int circuitanalysismarks;
//	int cpmarks;
//};
//main()
//{
//	FILE *fptr;
//	struct Student student;
//	int grade;
//	printf("Enter the student name: ");
//	gets(student.name);
//	printf("Enter the Reg. no. of the student: ");
//	scanf("%s", student.regno);
//	printf("Enter the marks in English: ");
//	scanf("%d", &student.englishmarks);
//	printf("Enter the marks in Algebra: ");
//	scanf("%d", &student.algebramarks);
//	printf("Enter the marks in Circuit Analysis: ");
//	scanf("%d", &student.circuitanalysismarks);
//	printf("Enter the marks in CP: ");
//	scanf("%d", &student.cpmarks);
//	fptr = fopen("ResultSheet.txt", "w");
//	fprintf(fptr, "   *** International Engineering University ***   \n");
//	fprintf(fptr, "==================================================\n");
//	fprintf(fptr, "Mr. %s\t\tRegistration No. %s\n", student.name, student.regno);
//	fprintf(fptr, "==================================================\n");
//	fprintf(fptr, "Subject       Max Marks   Obtained Marks     Grade\n");
//	fprintf(fptr, "English\t\t 100\t\t %d\t\t", student.englishmarks);
//	grade = GradeCalculator(student.englishmarks);
//	fprintf(fptr, "%c\n", grade);
//	fprintf(fptr, "Linear Algebra\t 100\t\t %d\t\t", student.algebramarks);
//	grade = GradeCalculator(student.algebramarks);
//	fprintf(fptr, "%c\n", grade);
//	fprintf(fptr, "Circuit Analysis 100\t\t %d\t\t", student.circuitanalysismarks);
//	grade = GradeCalculator(student.circuitanalysismarks);
//	fprintf(fptr, "%c\n", grade);
//	fprintf(fptr, "CP\t\t 100\t\t %d\t\t", student.cpmarks);
//	grade = GradeCalculator(student.cpmarks);
//	fprintf(fptr, "%c\n", grade);
//	fprintf(fptr, "==================================================\n");
//
//}
//char GradeCalculator(int marks)
//{
//	if (marks > 100 || marks < 0)
//	{
//		return 'X';
//	}
//	else if (marks >= 90)
//	{
//		return 'A';
//	}
//	else if (marks >= 80)
//	{
//		return 'B';
//	}
//	else if (marks >= 65)
//	{
//		return 'C';
//	}
//	else if (marks >= 50)
//	{
//		return 'D';
//	}
//	else if (marks < 50)
//	{
//		return 'F';
//	}
//}
