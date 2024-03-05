////Part a
//#include <iostream>
//#include <string>
//using namespace std;
//class Rectangle
//{
//private:
//	float width, height;
//public:
//	Rectangle()
//	{
//		width = 0;
//		height = 0;
//	}
//	Rectangle(float w, float h)
//	{
//		width = w;
//		height = h;
//	}
//	float getArea()
//	{
//		return width * height;
//	}
//	float getPerimeter()
//	{
//		return (2 * width) + (2 * height);
//	}
//	
//};
//
//void main()
//{
//	Rectangle r1(5, 9);
//	Rectangle r2(5.3, 15.5);
//	Rectangle r3(0, 0);
//
//	float area, perimeter;
//	
//	area = r1.getArea();
//	cout << "Area = " << area << endl;
//	perimeter = r1.getPerimeter();
//	cout << "Perimeter = " << perimeter << endl << endl;
//
//	area = r2.getArea();
//	cout << "Area = " << area << endl;
//	perimeter = r2.getPerimeter();
//	cout << "Perimeter = " << perimeter << endl << endl;
//
//	area = r3.getArea();
//	cout << "Area = " << area << endl;
//	perimeter = r3.getPerimeter();
//	cout << "Perimeter = " << perimeter << endl << endl;
//	
//}



////Part b
//#include <iostream>
//#include <string>
//using namespace std;
//class Time
//{
//private:
//	int hours, minutes, seconds;
//public:
//	Time()
//	{
//		hours = 0;
//		minutes = 0;
//		seconds = 0;
//	}
//	Time(int h, int m, int s)
//	{
//		hours = h;
//		minutes = m;
//		seconds = s;
//	}
//	void displayTime()
//	{
//		cout << hours << ":" << minutes << ":" << seconds << endl;
//	}
//	Time addtime(Time t1)
//	{
//		Time temp;
//		temp.seconds = seconds + t1.seconds;
//		if (temp.seconds >= 60)
//		{
//			temp.seconds -= 60;
//			temp.minutes += 1;
//		}
//		temp.minutes += minutes + t1.minutes;
//		if (temp.minutes >= 60)
//		{
//			temp.minutes -= 60;
//			temp.hours += 1;
//		}
//		temp.hours += hours + t1.hours;
//		return temp;
//	}
//};
//void main()
//{
//	Time t1(1, 30, 15), t2(2, 45, 50), t3;
//	cout << "First time = ";
//	t1.displayTime();
//	cout << "Second time = ";
//	t2.displayTime();
//	t3 = t1.addtime(t2);
//	cout << "Sum = ";
//	t3.displayTime();
//}