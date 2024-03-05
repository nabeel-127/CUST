#include <stdio.h>
#include <string.h>
main()
{
	char names[10][50];
	for (int i = 0; i < 2; i++)
	{
		printf("Enter a name: ");
		gets(names[i]);
	}
	for (int j = 0; j < 2; j++)
	{
		puts(names[j]);
	}
}