#include <stdio.h>
struct Book
{
	char title[20];
	int pages;
	float price;
};
union Journal
{
	char title[20];
	int pages;
	float price;
};
main()
{
	struct Book b1;
	union Journal j1;
	printf("Enter the title of the book: ");
	scanf("%s", b1.title);
	printf("Enter the number of pages in the book: ");
	scanf("%d", &b1.pages);
	printf("Enter the price of the book: ");
	scanf("%f", &b1.price);
	printf("Enter the title of the journal: ");
	scanf("%s", j1.title);
	printf("Enter the number of pages in the journal: ");
	scanf("%d", &j1.pages);
	printf("Enter the price of the journal: ");
	scanf("%f", &j1.price);
	printf("\nSize of book: %d\n", sizeof(b1));
	printf("Size of journal: %d\n", sizeof(j1));
	printf("\n\n");
	printf("Title of book: %s\n", b1.title);
	printf("Number of pages in the book: %d\n", b1.pages);
	printf("Price of the book: %f\n", b1.price);
	printf("\n");
	printf("Title of journal: %s\n", j1.title);
	printf("Number of pages in the journal: %d\n", j1.pages);
	printf("Price of the journal: %f\n", j1.price);
}