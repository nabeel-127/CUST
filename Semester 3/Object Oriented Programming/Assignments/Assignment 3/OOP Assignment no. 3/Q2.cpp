/*=================================================================
/* CSEE1122:			OOP and Data Structure
/*
/* Student Name :		Nabeel Ali
/*
/* Registration No.:	BEE173059
/*
/* Section No.:			II
/*
/* Assignment No.:		3
/*
/* Question No.:		2.
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/


//#include <iostream>
//#include <string>
//using namespace std;
//struct Node
//{
//	string name, contactNo, email;
//	Node *nextPtr;
//	Node *previousPtr;
//};
//class addressBook
//{
//	int length;
//	Node *headPtr, *lastPtr;
//public:
//	addressBook()
//	{
//		length = 0;
//		headPtr = NULL;
//		lastPtr = NULL;
//	}
//	void addNode(string N, string cN, string E)
//	{
//		int match = 0;
//		Node *currentPtr = headPtr;
//		while (length != 0)
//		{
//			if (N == currentPtr->name || cN == currentPtr->contactNo)
//			{
//				match = 1;
//				break;
//			}
//			if (currentPtr->nextPtr == NULL)
//			{
//				break;
//			}
//			currentPtr = currentPtr->nextPtr;
//		}
//		if (match == 0)
//		{
//			Node *newNode = new Node;
//			newNode->name = N;
//			newNode->contactNo = cN;
//			newNode->email = E;
//			newNode->nextPtr = NULL;
//			if (length == 0)
//			{
//				newNode->previousPtr = headPtr;
//				headPtr = newNode;
//			}
//			else
//			{
//				lastPtr->nextPtr = newNode;
//				newNode->previousPtr = lastPtr;
//			}
//			lastPtr = newNode;
//			length++;
//		}
//		else
//		{
//			cout << "Contact already exists" << endl;
//		}
//	}
//	void deleteNode()
//	{
//		Node *currentPtr = headPtr;
//		Node *tempP, *tempN;
//		int found = 0;
//		string check;
//		if (length != 0)
//		{
//			cout << "Enter Name or Contact Number of the contact to delete: ";
//			cin >> check;
//			for (int i = 1; i <= length; i++)
//			{
//				if (check == currentPtr->name || check == currentPtr->contactNo)
//				{
//					found = 1;
//					if (length == 1)
//					{
//						headPtr = NULL;
//					}
//					else if (currentPtr->nextPtr == NULL)
//					{
//						tempP = currentPtr->previousPtr;
//						tempP->nextPtr = NULL;
//					}
//					else if (currentPtr->previousPtr == NULL)
//					{
//						tempN = currentPtr->nextPtr;
//						headPtr = tempN;
//						tempN->previousPtr = headPtr;
//					}
//					else
//					{
//						tempP = currentPtr->previousPtr;
//						tempN = currentPtr->nextPtr;
//						tempP->nextPtr = tempN;
//						tempN->previousPtr = tempP;
//					}
//					delete currentPtr;
//					length--;
//					break;
//				}
//				if (found == 0)
//				{
//					currentPtr = currentPtr->nextPtr;
//				}
//			}
//			if (found == 0)
//			{
//				cout << "Contact NOT Found" << endl;
//			}
//		}
//		else
//		{
//			cout << "List is empty\n";
//		}
//	}
//	void searchContact()
//	{
//		Node *currentPtr = headPtr;
//		int found = 0;
//		string check;
//		while (length != 0)
//		{
//			cout << "Enter Name or Contact Number to search: ";
//			cin >> check;
//			if (check == currentPtr->name || check == currentPtr->contactNo)
//			{
//				cout << "Contact Found." << endl;
//				cout << "Name: " << currentPtr->name << endl;
//				cout << "Contact Number: " << currentPtr->contactNo << endl;
//				cout << "Email: " << currentPtr->email << endl;
//				found = 1;
//			}
//			if (currentPtr->nextPtr == NULL)
//			{
//				if (found == 0)
//				{
//					cout << "Contact NOT Found" << endl;
//				}
//				break;
//			}
//			currentPtr = currentPtr->nextPtr;
//		}
//		if (length == 0)
//		{
//			cout << "List is empty" << endl;
//		}
//	}
//	void displayAll()
//	{
//		Node *currentPtr = headPtr;
//		while (length != 0)
//		{
//			cout << "Name: " << currentPtr->name << endl;
//			cout << "Contact Number: " << currentPtr->contactNo << endl;
//			cout << "Email: " << currentPtr->email << endl;
//			if (currentPtr->nextPtr == NULL)
//			{
//				break;
//			}
//			currentPtr = currentPtr->nextPtr;
//		}
//		if (length == 0)
//		{
//			cout << "List is empty\n";
//		}
//	}
//
//};
//void main()
//{
//	addressBook c1;
//	string N, cN, E, check;
//	int option, retry = 1;
//	while (retry == 1)
//	{
//	
//		cout << "Press '1' to Add a Contact\n";
//		cout << "Press '2' to Delete a Contact\n";
//		cout << "Press '3' to Search a Contact\n";
//		cout << "Press '4' to Display all Contact\n";
//		cout << "Press '5' to Exit\n";
//		cout << "Choose an option: ";
//		cin >> option;
//		system("cls");
//		switch (option)
//		{
//		case 1:
//			cout << "Enter name: ";
//			cin >> N;
//			cout << "Enter contact number: ";
//			cin >> cN;
//			cout << "Enter email: ";
//			cin >> E;
//			c1.addNode(N, cN, E);
//			system("pause");
//			system("cls");
//			break;
//		case 2:
//			c1.deleteNode();
//			system("pause");
//			system("cls");
//			break;
//		case 3:
//			c1.searchContact();
//			system("pause");
//			system("cls");
//			break;
//		case 4:
//			c1.displayAll();
//			system("pause");
//			system("cls");
//			break;
//		case 5:
//			retry = 0;
//			break;
//		default:
//			cout << "Invalid input" << endl;
//		}
//	}
//}