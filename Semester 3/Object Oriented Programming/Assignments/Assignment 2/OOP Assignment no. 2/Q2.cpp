/*=================================================================
/* CSEE1122:			Computer Programming
/*
/* Student Name :		Nabeel Ali
/*
/* Registration No.:	BEE173059
/*
/* Section No.:			II
/*
/* Assignment No.:		2
/*
/* Question No.:		2.
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/

//#include<iostream>
//#include<string>
//using namespace std;
//class item
//{
//protected:
//	string title;
//	float price;
//public:
//	item(string T, float PR)
//	{
//		title = T;
//		price = PR;
//	}
//	void display()
//	{
//		cout << "Title: " << title;
//		cout << "Price: " << price;
//	}
//};
//class Book :public item
//{
//	string author, publisher;
//	int pages;
//public:
//	Book(string T, float PR, string A, string PU, int PA) :item(T, PR)
//	{
//		author = A;
//		publisher = PU;
//		pages = PA;
//
//	}
//	void display()
//	{
//		cout << "Title of book: " << title << endl;
//		cout << "Price of book: " << price << endl;
//		cout << "Author of book: " << author << endl;
//		cout << "Pulisher of book: " << publisher << endl;
//		cout << "Pages in book: " << pages << endl << endl;
//	}
//
//};
//class Newspaper :public item
//{
//	string editor, publisher, date;
//public:
//	Newspaper(string T, float PR, string E, string PU, string D) :item(T, PR)
//	{
//		editor = E;
//		publisher = PU;
//		date = D;
//	}
//	void display()
//	{
//		cout << "Title of newspaper: " << title << endl;
//		cout << "Price of newspaper: " << price << endl;
//		cout << "Editor of newspaper: " << editor << endl;
//		cout << "Publisher of newspaper: " << publisher << endl;
//		cout << "Date newspaper was publised on: " << date << endl << endl;
//	}
//};
//void main()
//{
//	int pages;
//	float priceB, priceN;
//	string titleB, author, publisherB;
//	string editor, publisherN, date, titleN;
//
//	cout << "Enter title of book: ";
//	getline(cin, titleB);
//	cout << "Enter Author of book: ";
//	getline(cin, author);
//	cout << "Enter publisher of book: ";
//	getline(cin, publisherB);
//	cout << "Enter title of newspaper: ";
//	getline(cin, titleN);
//	cout << "Enter the newspaper Editor's name: ";
//	getline(cin, editor);
//	cout << "Enter newspaper Publisher's name: ";
//	getline(cin, publisherN);
//	cout << "Enter the date newspaper was published on: ";
//	getline(cin, date);
//	cout << "Enter price of newspaper: ";
//	cin >> priceN;
//	cout << "Enter price of book: ";
//	cin >> priceB;
//	cout << "Enter pages in the book: ";
//	cin >> pages;
//	cout << endl;
//	Book book(titleB, priceB, author, publisherB, pages);
//	Newspaper newspaper(titleN, priceN, editor, publisherN, date);
//	book.display();
//	newspaper.display();
//}
