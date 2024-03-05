////Activity 1
//#include <iostream>
//using namespace std;
//class Area
//{
//public:
//	float area_calc(float l, float b)
//	{
//		return l * b;
//	} 
//};
//class Perimeter
//{
//public:
//	float per_calc(float l, float b)
//	{
//		return 2 * (l + b);
//	}
//};
//class Rectangle : private Area, private Perimeter
//{
//	float length, breadth;
//public:
//	Rectangle() :length(0.0), breadth(0.0)
//	{
//
//	}
//	void get_data()
//	{
//		cout << "Enter length: ";
//		cin >> length;
//		cout << "Enter Breadth: ";
//		cin >> breadth;
//	}
//	float area_calc()
//	{
//		return Area::area_calc(length, breadth);
//	}
//	float peri_calc()
//	{
//		return Perimeter::per_calc(length, breadth);
//	}
//};
//int main()
//{
//	Rectangle r;
//	r.get_data();
//	cout << "Area = " << r.area_calc() << endl;
//	cout << "Perimeter = " << r.peri_calc() << endl;
//	return 0;
//}


//Activity 2
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	string name; 
	int year_of_birth;
public:
	Person()
	{
		name = " ";
		year_of_birth = 0;
	}
	Person(string Name, int YOB)
	{
		name = Name;
		year_of_birth = YOB;
	}
};
class Employee :public Person
{
protected:
	string employeeID, joiningYear, jobTitle, courseID, courseTitle;
public:
	Employee(string eID, string jY, string jT, string cID, string cT) :Person()
	{

	}
};
class Administration :public Employee
{
public:
	Administration(string eID, string jY, string jT, string cID, string cT) :Employee(eID, jY, jT, cID, cT)
	{
		employeeID = eID;
		joiningYear = jY;
		jobTitle = jT;
		courseID = cID;
		courseTitle = cT;
	}
	void setJobTitle(string jT)
	{
		jobTitle = jT;
	}
	string getJobTitle()
	{
		return jobTitle;
	}
};
class Student :public Person
{
	string studentID, enrolledSemester;
public:
	Student(string sID, string eS, string N, int YOB) :Person(N, YOB)
	{
		studentID = sID;
		enrolledSemester = eS;
		name = N;
		year_of_birth = YOB;
	}
	void Display()
	{
		cout << "Name: " << name << endl;
		cout << "Year of birth: " << year_of_birth << endl;
		cout << "Student ID: " << studentID << endl;
		cout << "Enrolled semester: " << enrolledSemester << endl;
	}
};
class Academic :public Employee
{
public:
	Academic(string eID, string jY, string jT, string cID, string cT) :Employee(eID, jY, jT, cID, cT)
	{
		employeeID = eID;
		joiningYear = jY;
		jobTitle = jT;
		courseID = cID;
		courseTitle = cT;
	}
	void setCourseID(string cID)
	{
		courseID = cID;
	}
	void setCourseTitle(string cT)
	{
		courseTitle = cT;
	}
};

























//#include <iostream>
//using namespace std;
//template <class T>
//class Area
//{
//	T length, width;
//public:
//	Area() :length(0), width(0)
//	{
//
//	}
//	void setData(T l, T w)
//	{
//		length = l;
//		width = w;
//	}
//	T calculateArea()
//	{
//		return length * width;
//	}
//	void Display()
//	{
//		cout << "Length: " << length << endl;
//		cout << "Width: " << width << endl;
//		cout << "Area: " << calculateArea() << endl;
//	}
//};
//void main()
//{
//	Area<int> a;
//	int l, w;
//	cin >> l;
//	cin >> w;
//	a.setData(l, w);
//	a.Display();
//}