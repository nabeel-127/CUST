//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//struct Book
//{
//	char title[20];
//	int pages;
//	float price;
//};
//main()
//{
//	struct Book book[3];
//	int i, max = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("Enter the title: ");
//		scanf("%s", book[i].title);
//		//fflush(stdin);
//		printf("Enter the number of pages: ");
//		scanf("%d", &book[i].pages);
//		printf("Enter the price: ");
//		scanf("%f", &book[i].price);
//		max = book[i].price > max ? i : max;
//	}
//	printf("\nThe book with the highest price is: %s,\n", book[max].title);
//	printf("which has %d pages and costs %f\n", book[max].pages, book[max].price);
//}
