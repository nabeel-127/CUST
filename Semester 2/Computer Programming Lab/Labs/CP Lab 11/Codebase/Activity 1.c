//#include <stdio.h>
//
//struct Date
//{
//	int day, month, year;
//};
//struct Employee
//{
//	char name[20];
//	float salary;
//	struct Date dob;
//};
//
//main()
//{
//	struct Employee e1[3];
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("Enter the name of employee: ");
//		scanf("%s", e1[i].name);
//		printf("Enter the salary: ");
//		scanf("%f", &e1[i].salary);
//		printf("Enter the DOB: \n");
//		printf("Day: ");
//		scanf("%d", &e1[i].dob.day);
//		printf("Month: ");
//		scanf("%d", &e1[i].dob.month);
//		printf("Year: ");
//		scanf("%d", &e1[i].dob.year);
//		
//	}
//	printf("\n");
//	for (i = 0; i < 3; i++)
//	{
//		if (e1[i].dob.year == 1995)
//		{
//			printf("Name: %s\n", e1[i].name);
//			printf("Salary: %f\n", e1[i].salary);
//			printf("DOB: %d-%d-%d\n", e1[i].dob.day, e1[i].dob.month, e1[i].dob.year);
//		}
//	}
//}