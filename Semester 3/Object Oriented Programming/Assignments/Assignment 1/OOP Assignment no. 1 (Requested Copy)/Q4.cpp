////Part a
//#include <iostream>
//#include <string>
//using namespace std;
//class rectangle
//{
//private:
//	float w, h;
//public:
//	rectangle()
//	{
//		w = 0;
//		h = 0;
//	}
//	rectangle(float w, float h)
//	{
//		this->w = w;
//		this->h = h;
//	}
//	float getArea()
//	{
//		return w * h;
//	}
//	float getPerimeter()
//	{
//		return (w + w) + (h + h);
//	}
//	
//};
//int main()
//{
//	float area, perimeter;
//	rectangle r1(5, 9);
//	rectangle r2(5.3, 15.5);
//	rectangle r3(0, 0);
//	area = r1.getArea();
//	cout << "area " << area << endl;
//	perimeter = r1.getPerimeter();
//	cout << "perimeter " << perimeter << endl << endl;
//	area = r2.getArea();
//	cout << "area " << area << endl;
//	perimeter = r2.getPerimeter();
//	cout << "perimeter " << perimeter << endl << endl;
//	area = r3.getArea();
//	cout << "area" << area << endl;
//	perimeter = r3.getPerimeter();
//	cout << "perimeter " << perimeter << endl << endl;
//}


//
////Part b
//#include <iostream>
//#include <string>
//using namespace std;
//class time
//{
//private:
//	int h, m, s;
//public:
//	time()
//	{
//		h = 0;
//		m = 0;
//		s = 0;
//	}
//	time(int h, int m, int s)
//	{
//		this->h = h;
//		this->m = m;
//		this->s = s;
//	}
//	void displaytime()
//	{
//		cout << h << ":" << m << ":" << s << endl;
//	}
//	time addtime(time t1)
//	{
//		time temp;
//		temp.s = s + t1.s;
//		if (temp.s >= 60)
//		{
//			temp.s -= 60;
//			temp.m++;
//		}
//		temp.m += m + t1.m;
//		if (temp.m >= 60)
//		{
//			temp.m -= 60;
//			temp.h++;
//		}
//		temp.h += h + t1.h;
//		return temp;
//	}
//};
//void main()
//{
//	time t1(1, 30, 15), t2(2, 45, 50), t3;
//
//	t1.displaytime();
//
//	t2.displaytime();
//	t3 = t1.addtime(t2);
//
//	t3.displaytime();
//}