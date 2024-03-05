//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//struct Patient
//{
//	char name[20];
//	int ID, numberofvisits;
//};
//main()
//{
//	struct Patient patient[3];
//	int i, compare, check = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("Enter the name of patient %d: ", i + 1);
//		scanf("%s", &patient[i].name);
//		printf("Enter the ID of the patient: ");
//		scanf("%d", &patient[i].ID);
//		printf("Enter the number of visits: ");
//		scanf("%d", &patient[i].numberofvisits);
//	}
//	printf("Enter the patient ID to search: ");
//	scanf("%d", &compare);
//	for (i = 0;i < 3;i++)
//	{
//		if (compare == patient[i].ID)
//		{
//			check = 1;
//			break;
//		}
//	}
//	if (check == 1)
//	{
//		printf("Name of patient: %s\n", patient[i].name);
//		printf("Number of visits: %d\n", patient[i].numberofvisits);
//		printf("ID of the patient: %d\n", patient[i].ID);
//	}
//}