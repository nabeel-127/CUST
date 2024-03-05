///*=================================================================
///* CSEE112020:			Computer Programming
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
//
//struct Book 
//{
//	char title[30];
//	int pages;
//	float price;
//}book[20];
//FILE *fptr;
//
//SaveBookData();
//ReadBookData();
//
//main()
//{
//	int i, counter = 0;
//	for (i = 0;i < 20;i++)
//	{
//		printf("Enter the title of the book: ");
//		scanf("%s", book[i].title);
//		printf("Enter the number of pages in the book: ");
//		scanf("%d", &book[i].pages);
//		printf("Enter the price of the book: ");
//		scanf("%f", &book[i].price);
//		if (book[i].price > 500)
//		{
//			counter++;
//		}
//	}
//	SaveBookData();
//	ReadBookData();
//	printf("\n");
//	for (i = 0;i < 20;i++)
//	{
//		printf("%s\n", book[i].title);
//		printf("%d\n", book[i].pages);
//		printf("%f\n\n", book[i].price);
//	}
//	printf("%d books have a price greater than Rs. 500\n", counter);
//}
//
//SaveBookData()
//{
//	int i;
//	fptr = fopen("Books.txt", "w");
//	for (i = 0;i < 20;i++)
//	{
//		fprintf(fptr, "%s\n", book[i].title);
//		fprintf(fptr, "%d\n", book[i].pages);
//		fprintf(fptr, "%f\n", book[i].price);
//	}
//	fclose(fptr);
//}
//
//ReadBookData()
//{
//	int i;
//	fptr = fopen("Books.txt", "r");
//	for (i = 0;i < 20;i++)
//	{
//		fscanf(fptr, "%s", book[i].title);
//		fscanf(fptr, "%d", &book[i].pages);
//		fscanf(fptr, "%f", &book[i].price);
//	}
//	fclose(fptr);
//}