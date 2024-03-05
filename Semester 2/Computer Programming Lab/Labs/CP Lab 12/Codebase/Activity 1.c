//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//struct students {
//	char name[10];
//	char reg_no[10];
//	float cgpa;
//}student[10];
//FILE *fptr;
//int main()
//{
//	int i;
//	fptr = fopen("Student_Records.txt", "w");
//	for (i = 0; i < 10; i++)
//	{
//		if (fptr == NULL)
//		{
//			printf("Error. File not found\n");
//			break;
//		}
//		printf("Enter name of the student %d: ", i + 1);
//		scanf("%s", student[i].name);
//		printf("Enter the registration number of the student %d: ", i + 1);
//		scanf("%s", student[i].reg_no);
//		printf("Enter the CGPA of the student %d:", i + 1);
//		scanf("%f", &student[i].cgpa);
//		
//		fprintf(fptr, "%s\n", student[i].name);
//		fprintf(fptr, "%s\n", student[i].reg_no);
//		fprintf(fptr, "%f\n", student[i].cgpa);
//	}
//	fclose(fptr);
//}
