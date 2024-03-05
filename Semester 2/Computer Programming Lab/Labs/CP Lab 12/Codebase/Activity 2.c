//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//struct students {
//	char name[10];
//	char reg_no[10];
//	float cgpa;
//}student[10];
//FILE *fptr;
//int main()
//{
//	int i;
//	struct students student[10];
//
//	fptr = fopen("Student_Records.txt", "r");
//	for (i = 0; i < 10; i++)
//	{
//		if (fptr == NULL)
//		{
//			printf("Error. File not found\n");
//			break;
//		}
//		fscanf(fptr, "%s", student[i].name);
//		fscanf(fptr, "%s", &student[i].reg_no);
//		fscanf(fptr, "%f", &student[i].cgpa);
//		printf("Name: %s\n", student[i].name);
//		printf("Reg. no. %s\n", student[i].reg_no);
//		printf("CGPA = %f\n\n", student[i].cgpa);
//	}
//	fclose(fptr);
//}
