////Activity 1
//#include <iostream>
//using namespace std;
//void main()
//{
//	int num1 = 20;
//	int num2 = 30;
//	num2 += 30;
//	cout<<num1<<endl;
//	num1 = ++num2;
//	cout<<num1++<<endl;
//	num1 += num2--;
//	cout<<num1<<endl;
//	num1 -= num2++;
//	cout<<num1<<endl;
//	cout<<"5 times 2 is "<< (5 << 1)<<endl;
//	cout<<"20 divided by 4 is "<< (20 >> 2)<<endl;
//}

////Activity 2
//#include <iostream>
//using namespace std;
//void main()
//{
//	float a, b, c, d, e, f, result;
//	cout<<"Enter a: ";
//	cin>>a;
//	cout<<"Enter b: ";
//	cin>>b;
//	cout<<"Enter c: ";
//	cin>>c;
//	cout<<"Enter d: ";
//	cin>>d;
//	cout<<"Enter e: ";
//	cin>>e;
//	cout<<"Enter f: ";
//	cin>>f;
//	result = ((a / b) * c) + ((d + e) / f);
//	cout<<"Result = "<<result<<endl;
//}

////Acitvity 3
//#include <iostream>
//using namespace std;
//void main()
//{
//	int numbers[10] = {6, 4, -3, 4, 5, 6, 11, -8, -4, 10};
//	int index;
//	int max = 0;
//	for (index = 0;index < 10;index++)
//	{
//		if(max < numbers[index])
//		{
//			max = numbers[index];
//		}
//	}
//	cout<<max<<endl;
//}

////Acitvity 4
//#include <iostream>
//using namespace std;
//void main()
//{
//	int X[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int i = 0, min = X[0];
//	for (i = 0;i < 10;i++)
//	{
//		if(min > X[i])
//		{
//			min = X[i];
//		}
//	}
//	cout<<"Minimum = "<<min<<endl;
//}

////Acitvity 5
//#include <iostream>
//using namespace std;
//void main()
//{
//	const int size = 3;
//	int data[size][size] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//	int row, col;
//	for (row = 0;row < size;row++)
//	{
//		for(col = 0;col < size;col++)
//		{
//			cout<<data[row][col]<<" ";
//		}
//		cout<<endl;
//	}
//}

////Acitvity 6
//#include <iostream>
//using namespace std;
//void main()
//{
//	const int size = 4;
//	int array1[size][size] = { {1, 2, 3, 4}, {4, 5, 6, 7}, {6, 7, 8, 9}, {9, 10, 11, 12} };
//	int array2[size][size] = { {1, 2, 3, 4}, {4, 5, 6, 7}, {6, 7, 8, 9}, {9, 10, 11, 12} };
//	int row, col;
//	int array3[size][size];
//	for (row = 0; row < size; row++)
//	{
//		for (col = 0; col < size; col++)
//		{
//			array3[row][col] = array1[row][col] + array2[row][col];
//			cout << array3[row][col] << " ";
//
//		}
//		cout << endl;
//	}
//}



//Practice Questions

////Q1
//#include <iostream>
//using namespace std;
//void main()
//{
//	int X[4][4] = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} };
//	int Y[4][4] = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} };
//	int result[4][4];
//	int sum = 0;
//	for (int row = 0; row < 4; row++)
//	{
//		for (int column = 0; column < 4; column++)
//		{
//			for (int i = 0; i < 4; i++)
//			{
//				sum += X[row][i] + Y[i][column];
//			}
//			result[row][column] = sum;
//			sum = 0;
//		}
//	}
//	for (int row = 0; row < 4; row++)
//	{
//		for (int column = 0; column < 4; column++)
//		{
//			cout << result[row][column] << "   ";
//		}
//		cout << endl;
//	}
//}

////Q2
//#include <iostream>
//using namespace std;
//struct Time
//{
//	int hours, minutes, seconds;
//}t1;
//void main()
//{
//	cout << "Enter hours: ";
//	cin >> t1.hours;
//	cout << "Enter minutes: ";
//	cin >> t1.minutes;
//	cout << "Enter seconds: ";
//	cin >> t1.seconds;
//	long totalsecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
//	cout << "Time in seconds: " << totalsecs << endl;
//}

////Q3
//#include <iostream>
//using namespace std;
//void main()
//{
//	int X[4][4] = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1} };
//	int sum1 = 0, sum2 = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (i == j)
//			{
//				sum1 += X[i][j];
//			}
//		}
//	}
//	cout << "Sum of first diagonal = " << sum1 << endl;
//	for (int i = 0; i < 4; i++)
//	{
//		int j = 3;
//		sum2 += X[i][j];
//		j++;
//	}
//	cout << "Sum of second diagonal = " << sum2 << endl;
//}
