////Activitty 1
//#include <iostream>
//using namespace std;
//void main()
//{
//	int character = 12;
//	int *ptr = &character;
//	cout << "Address of character: \t" << &character << endl;
//	cout << "Address of ptr: \t\t" << ptr << endl;
//	cout << "Address of ptr: \t\t" << &ptr << endl;
//	cout << "Content of character: \t" << *ptr << endl;
//}


////Activity 2
//#include <iostream>
//using namespace std;
//int summation(int &a, int &b)
//{
//	int sum = 0;
//	a = a + b;
//	sum = a;
//	return sum;
//}
//void main()
//{
//	int a = 100;
//	int b = 20;
//	int c = 0;
//	c = summation(a, b);
//	cout << c << " " << a << " " << b << endl;
//}


////Activity 3
//#include <iostream>
//using namespace std;
//int arrayFunc(int *student, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << student[i] << endl;
//	}
//	return 1;
//}
//void main()
//{
//	int students[10] = { 34, 11, 98, 10, 28, 76, 45, 66, 59, 22 };
//	int *ptrStudent1, *ptrStudent2;
//	ptrStudent1 = students + 5;
//	ptrStudent2 = &students[6];
//	cout << ptrStudent1 << " " << ptrStudent2 << endl;
//	cout << *students << " " << *students + 4 << " " << *(students + 8) << endl;
//	int j = arrayFunc(students, 10);
//}


////Activity 4
//#include <iostream>
//using namespace std;
//void main()
//{
//	int st_grades[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
//	int *p_st_grades[3] = { st_grades[0], st_grades[1], st_grades[2] };
//	int **pp_st_grades = &p_st_grades[0];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cout << st_grades[i][j] << "\t";
//			cout << p_st_grades[i][j] << "\t";
//			cout << pp_st_grades[i][j] << "\t";
//		}
//		cout << "\n";
//	}
//	cout << endl;
//	for (int i = 0; i < 6; i++)
//	{
//		cout << *(*pp_st_grades + i) << "\t";
//	}
//	cout << endl;
//}


////Activity 5
//#include <iostream>
//using namespace std;
//void main()
//{
//	int *num = new int;
//	*num = 32;
//	cout << "Address of varible:\t" << &num << endl;
//	cout << "Content of variable:\t" << *num << endl;
//	delete[] num;
//}


////Activity 6
//#include <iostream>
//using namespace std;
//void main()
//{
//	int x;
//	cout << "Enter the size of the array: ";
//	cin >> x;
//	int *ptr = new int[x];
//	for (int i = 0; i < x; i++)
//	{
//		cout << "Enter the value " << (i + 1) << " of the array: ";
//		cin >> ptr[i];
//	}
//	int min = ptr[0];
//	int max = ptr[0];
//	for (int i = 0; i < x; i++)
//	{
//		min = ptr[i] < min ? ptr[i] : min;
//	}
//	cout << "Minimum number = " << max << endl;
//
//	for (int i = 0; i < x; i++)
//	{
//		max = ptr[i] > max ? ptr[i] : max;
//	}
//	cout << "Maximum number = " << max << endl;
//
//	for (int i = 0; i < x; i++)
//	{
//		delete[i] ptr;
//	}
//	delete[] ptr;
//}


////Activity 7
//#include <iostream>
//using namespace std;
//int Determinant(int **A)
//{
//	int det;
//	det = A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1])) - A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0])) + A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0]));
//	return det;
//}
//void Transpose(int **A)
//{
//	int **T = new int*[3];
//	for (int i = 0; i < 3; i++)
//	{
//		T[i] = new int[3];
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			T[j][i] = A[i][j];
//		}
//	}	
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			A[i][j] = T[i][j];
//		}
//	}
//}
//void main()
//{
//	int det, T;
//
//	int **ptr = new int*[3];
//
//	for (int i = 0; i < 3; i++)
//	{
//		ptr[i] = new int[3];
//	}
//	ptr[0][0] = 1;
//	ptr[0][1] = 3;
//	ptr[0][2] = 2;
//	ptr[1][0] = 1;
//	ptr[1][1] = 4;
//	ptr[1][2] = 1;
//	ptr[2][0] = 2;
//	ptr[2][1] = 3;
//	ptr[2][2] = 2;
//	//ptr = { {1,3,2},{1,4,1},{2,3,2}};
//	det = Determinant(ptr);
//	cout << "Determinant = " << det << endl;
//	
//	Transpose(ptr);
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << ptr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		delete[i] ptr;
//	}
//	delete[] ptr;
//}



//Practice Questions

////Q1
//#include <iostream>
//#include <string>
//using namespace std;
//int checkPalindrome(char arr1[10]);
//void main()
//{
//	int check;
//	char arr[10];
//	cout << "Enter the value for the array: ";
//	cin >> arr;
//	check = checkPalindrome(arr);
//	if (check == 0)
//		cout << "The given array is NOT palindromic\n";
//	else
//		cout << "The given array is palindromic\n";
//}
//int checkPalindrome(char arr1[10])
//{
//	char arr2[10];
//	int i, j, k, match = 1, nullvalue;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr1[i] == '\0')
//			break;
//	}
//	nullvalue = i;
//	i--;
//	j = 0;
//	while (i >= 0)
//	{
//		arr2[j] = arr1[i];
//		i--;
//		j++;
//	}
//	for (k = 0; k < nullvalue; k++)
//	{
//		if (arr2[k] != arr1[k])
//		{
//			match = 0;
//			break;
//		}
//	}
//	if (match == 0)
//		return 0;
//	else
//		return 1;
//}

////Q2
//#include <iostream>
//using namespace std;
//void main()
//{
//	int size, retry, fact;
//	float sum = 0, avg;
//	do
//	{
//		retry = 0;
//		cout << "Enter the size of the array between 1 and 20: ";
//		cin >> size;
//		if (size < 1 || size > 20)
//		{
//			system("cls");
//			cout << "Size out of range. Try again\n";
//			retry = 1;
//		}
//	} while (retry == 1);
//	
//	int *ptr = new int[size];
//
//	for (int i = 0; i < size; i++)
//	{
//		do
//		{
//			retry = 0;
//			cout << "Enter a value in the array between 0 and 12: ";
//			cin >> ptr[i];
//			if (ptr[i] < 0 || ptr[i] > 12)
//			{
//				system("cls");
//				cout << "Value out of range. Try again\n";
//				retry = 1;
//			}
//		} while (retry == 1);
//	}
//	for (int i = 0; i < size; i++)
//	{
//		sum = sum + ptr[i];
//	}
//	avg = sum / size;
//	cout << "Average = " << avg << endl << endl;
//	for (int i = 0; i < size; i++)
//	{
//		fact = 1;
//		for (int j = 1; j <= ptr[i]; j++)
//		{
//			fact = fact * j;
//		}
//		cout << "Factorial = " << fact << endl;
//	}
//	delete[] ptr;
//}

////Q3
//#include <iostream>
//using namespace std;
//void main()
//{
//	int row = 3, column = 3, sum = 0;
//	int **ptr = new int*[row];
//	for (int i = 0; i < row; i++)
//	{
//		ptr[i] = new int[column];
//	}
//	ptr[0][0] = 1;
//	ptr[0][1] = 2;
//	ptr[0][2] = 3;
//	ptr[1][0] = 4;
//	ptr[1][1] = 5;
//	ptr[1][2] = 6;
//	ptr[2][0] = 7;
//	ptr[2][1] = 8;
//	ptr[2][2] = 9;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < column; j++)
//		{
//			sum += ptr[i][j];
//		}
//	}
//	cout << "Sum = " << sum;
//	delete[] ptr;
//}
