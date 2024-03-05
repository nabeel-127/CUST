//#include <iostream>
//#include <string>
//using namespace std;
//struct student
//{
//	string name;
//	int marks;
//	char grade;
//};
//void main()
//{
//	float avg, sum = 0;
//	int x = 20;
//	student *ptr = new student[x];
//	for (int i = 0; i < x; i++)
//	{
//		cout << "Enter the name: ";
//		cin >> ptr[i].name;
//		cout << "Enter your marks: ";
//		cin >> ptr[i].marks;
//		if (ptr[i].marks >= 90)
//			ptr[i].grade = 'A';
//		else if (ptr[i].marks >= 80)
//			ptr[i].grade = 'B';
//		else if (ptr[i].marks >= 65)
//			ptr[i].grade = 'C';
//		else if (ptr[i].marks >= 50)
//			ptr[i].grade = 'D';
//		else if (ptr[i].marks < 80)
//			ptr[i].grade = 'F';
//	}
//	for (int i = 0; i < x; i++)
//	{
//		cout << endl << "Name of student = " << ptr[i].name << endl;
//		cout << "Marks of student = " << ptr[i].marks << endl;
//		cout << "Grade of student = " << ptr[i].grade << endl << endl;
//	}
//	for (int i = 0; i < x; i++)
//	{
//		sum = sum + ptr[i].marks;
//	}
//	avg = sum / x;
//	cout << "Class average = " << avg << endl;
//	delete[] ptr;
//}