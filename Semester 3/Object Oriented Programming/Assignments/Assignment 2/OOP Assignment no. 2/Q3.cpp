///*=================================================================
///* CSEE1122:			Computer Programming
///*
///* Student Name :		Nabeel Ali
///*
///* Registration No.:	BEE173059
///*
///* Section No.:			II
///*
///* Assignment No.:		2
///*
///* Question No.:		3.
///*==================================================================
///* I certify that I have neither given nor received unauthorized aid
///*         on this Assignment.
///*==================================================================*/
//
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//class PolarCoordinates;
//class CartCoordinates
//{
//	float x, y;
//public:
//	CartCoordinates(float x = 0, float y = 0)
//	{
//		this->x = x;
//		this->y = y;
//	}
//	void setX()
//	{
//		cin >> x;
//	}
//	void setY()
//	{
//		cin >> y;
//	}
//	void displayCart()
//	{
//		cout << "X = " << x << endl;
//		cout << "Y = " << y << endl;
//	}
//	friend CartCoordinates Convert(PolarCoordinates P);
//};
//class PolarCoordinates
//{
//	float p, angle;
//public:
//	PolarCoordinates(float p = 0, float angle = 0)
//	{
//		this->p = p;
//		this->angle = angle;
//	}
//	void setP()
//	{
//		cin >> p;
//	}
//	void setAngle()
//	{
//		cin >> angle;
//	}
//	void displayPolar()
//	{
//		cout << "Polar length = " << p << endl;
//		cout << "Angle = " << angle << endl;
//	}
//	friend CartCoordinates Convert(PolarCoordinates P);
//};
//CartCoordinates Convert(PolarCoordinates P)
//{
//	CartCoordinates C;
//	C.x = P.p * cos(P.angle);
//	C.y = P.p * sin(P.angle);
//	return C;
//}
//void main()
//{
//	CartCoordinates XY;
//	PolarCoordinates P;
//	cout << "Enter the length: ";
//	P.setP();
//	cout << "Enter the angle: ";
//	P.setAngle();
//
//	XY = Convert(P);
//	XY.displayCart();
//}
