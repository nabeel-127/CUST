#include<stdio.h>

void main()
{
	char names[4][20];
	char *days [4] = {"Monday","Tuesday","Wednesday","Thursday"};
	char months[4][20] = {"January","February","March","April"};
	int i;
		
	for(i=0;i<4;i++)
	{
		printf("Enter Names : ");
		scanf("%s",names[i]);
	}
		
	for(int i=0;i<4;i++)
	{
		printf("%s\t", names[i]);
		printf("%s\t", days[i]);
		printf("%s\n", months[i]);

	}
	
}	