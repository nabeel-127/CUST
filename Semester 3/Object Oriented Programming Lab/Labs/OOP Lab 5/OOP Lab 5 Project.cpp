////Activity 1
//#include <iostream>
//using namespace std;
//class Vehicle
//{
//	static int count;
//public:
//	Vehicle() 
//	{
//
//	}
//	void incrementCount()
//	{
//		count++;
//	}
//	int getCount()
//	{
//		return count;
//	}
//};
//int Vehicle :: count = 0;
//void main()
//{
//	Vehicle v1, v2, v3;
//	v1.incrementCount();
//	cout << "Count is " << v2.getCount() << endl;
//	v3.incrementCount();
//	cout << "Count is " << v1.getCount() << endl;
//}


////Activity 2
//#include <iostream>
//using namespace std;
//class Math
//{
//	int num1, num2;
//	static int count;
//	const double PI;
//public:
//	Math() :PI(3.14159)
//	{
//
//	}
//	Math(int n1, int n2) :PI(3.14159), num1(n1), num2(n2)
//	{
//
//	}
//	void setNum1()
//	{
//		cin >> num1;
//	}
//	int getNum1()
//	{
//		return num1;
//	}
//	void setNum2()
//	{
//		cin >> num2;
//	}
//	int getNum2()
//	{
//		return num2;
//	}
//	void setCount()
//	{
//		cin >> count;
//	}
//	int getCount()
//	{
//		return count;
//	}
//	double getPI()
//	{
//		return PI;
//	}
//};
//void main()
//{
//	Math m1, m2, m3;
//	cout << "Enter 1st num1: ";
//	m1.setNum1();
//	cout << "Enter 2nd num1: ";
//	m2.setNum1();
//	cout << "Enter 3rd num1: ";
//	m3.setNum1();
//	cout << "Enter 1st num2: ";
//	m1.setNum2();
//	cout << "Enter 2nd num2: ";
//	m2.setNum2();
//	cout << "Enter 3rd num2: ";
//	m3.setNum2();
//	cout << endl;
//
//	cout << "1st num1: " << m1.getNum1() << endl;
//	cout << "2nd num1: " << m2.getNum1() << endl;
//	cout << "3rd num1: " << m3.getNum1() << endl;
//	cout << "1st num2: " << m1.getNum2() << endl;
//	cout << "2nd num2: " << m2.getNum2() << endl;
//	cout << "3rd num2: " << m3.getNum2() << endl;
//
//	cout << m1.getPI() << endl;
//
//}


////Activity 3
//#include <iostream>
//using namespace std;
//class printData
//{
//	int num1, num2;
//public:
//	int sum(int a, int b)
//	{
//		return a + b;
//	}
//	int sum(int a, int b, int c)
//	{
//		return a + b + c;
//	}
//};
//void main()
//{
//	printData pd;
//	cout << "Sum = " << pd.sum(5, 3) << endl;
//	cout << "Sum = " << pd.sum(9, 2, 5) << endl;
//}


////Activity 4
//#include <iostream>
//using namespace std;
//class printData
//{
//	int num1, num2;
//public:
//	int sum()
//	{
//		return num1 + num2;
//	}
//	int sum(int a, int b)
//	{
//		return a + b;
//	}
//	int sum(int a, int b, int c)
//	{
//		return a + b + c;
//	}
//	void setNum1()
//	{
//		cin >> num1;
//	}
//	void setNum2()
//	{
//		cin >> num2;
//	}
//
//};
//void main()
//{
//	printData pd, pd1;
//	cout << "Enter num1: ";
//	pd1.setNum1();
//	cout << "Enter num2: ";
//	pd1.setNum2();
//	cout << "Sum = " << pd1.sum() << endl;
//	cout << "Sum = " << pd.sum(5, 3) << endl;
//	cout << "Sum = " << pd.sum(9, 2, 5) << endl;
//}


////Activity 5
//#include <iostream>
//using namespace std;
//class Counter
//{
//	int x;
//public:
//	Counter() :x(0)
//	{
//
//	}
//	int getX()
//	{
//		return x;
//	}
//	int operator++()
//	{
//		return ++x;
//	}
//	int operator--()
//	{
//		return --x;
//	}
//	int operator++(int)
//	{
//		return x++;
//	}
//	int operator--(int)
//	{
//		return x--;
//	}
//	void operator=(int x)
//	{
//		this->x = x;
//	}
//};
//void main()
//{
//	Counter c1, c2;
//	cout << "C1: " << c1.getX() << endl;
//	cout << "C2: " << c2.getX() << endl;
//	cout << "C1: " << ++c1 << endl;
//	cout << "C2: " << ++c2 << endl;
//	cout << "C2: " << c2++ << endl;
//	c2 = ++c1;
//	cout << "After copying: " << endl;
//	cout << "C2: " << c2.getX() << endl;
//	c1 = c2++;
//	cout << "C2: " << c2.getX() << endl;
//}


////Activity 6
//#include <iostream>
//using namespace std;
//class Temp
//{
//	int x;
//public:
//	Temp(int X) :x(X)
//	{
//
//	}
//	int operator+(Temp X)
//	{
//		return x + X.x;
//	}
//};
//void main()
//{
//	Temp a(1), b(2);
//	int result = a + b;
//	cout << "Result = " << result << endl;
//}


//Practice Questions

////Question 1
////NOT SURE ABOUT THIS! This question was worded so fkin bad, I did what I thought was ok...
//#include <iostream>
//using namespace std;
//class Math
//{
//	int num1, num2;
//public:
//	Math() :num1(0), num2(0)
//	{
//
//	}
//	Math(int a, int b) :num1(a), num2(b)
//	{
//
//	}
//	int calculateSum() const
//	{
//		int sum = num1 + num2;
//		return sum;
//	}
//};
//void main()
//{
//	const Math A(1, 2), B(3, 4);
//	cout << A.calculateSum() << endl;
//	cout << B.calculateSum() << endl;
//}


////Question 2
//#include <iostream>
//using namespace std;
//class Temp
//{
//	int x;
//public:
//	Temp() :x(0)
//	{
//
//	}
//	Temp(int X) :x(X)
//	{
//
//	}
//	int operator>(Temp X)
//	{
//		return x + X.x;
//	}
//	int operator-(Temp X)
//	{
//		return x - X.x;
//	}
//	bool operator<=(Temp X)
//	{
//		return x <= X.x ? true : false;
//	}
//	int getX()
//	{
//		return x;
//	}
//};
//void main()
//{
//	Temp t1(1), t2(2), t3;
//	t3 = t1 > t2;
//	cout << "Sum: " << t3.getX() << endl;
//	t3 = t1 - t2;
//	cout << "Difference: " << t3.getX() << endl;
//	if (t1 <= t2)
//	{
//		cout << "T1 is smaller" << endl;
//	}
//	else
//	{
//		cout << "T2 is smaller" << endl;
//	}
//}