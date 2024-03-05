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
/* Question No.:		3.
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/


//#include <iostream>
//using namespace std;
//struct Node
//{
//	int data;
//	Node *nextPtr;
//};
//class stackLinked
//{
//	Node *topPtr;
//public:
//	stackLinked(int size)
//	{
//		topPtr = NULL;
//	}
//	~stackLinked()
//	{
//		Node *temp;
//		while (1)
//		{
//			if (topPtr != NULL)
//			{
//				temp = topPtr;
//				if (topPtr->nextPtr != NULL)
//				{
//					topPtr = topPtr->nextPtr;
//				}
//				else
//				{
//					topPtr = NULL;
//				}
//				delete temp;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	void push(int data)
//	{
//		Node *newNode = new Node;
//		newNode->data = data;
//		newNode->nextPtr = topPtr;
//		topPtr = newNode;
//	}
//	int pop()
//	{
//		int data;
//		data = topPtr->data;
//		Node *temp = topPtr;
//		topPtr = topPtr->nextPtr;
//		delete temp;
//		return data;
//	}
//	int returnTop()
//	{
//		return topPtr->data;
//	}
//	bool isEmpty()
//	{
//		if (topPtr == NULL)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	int getStackSize()
//	{
//		int count = 0;
//		Node *temp = topPtr;
//		if (isEmpty())
//		{
//			return count;
//		}
//		while (1)
//		{
//			temp = temp->nextPtr;
//			count++;
//			if (temp == NULL)
//			{
//				return count;
//			}
//		}
//	}
//	void displayStack()
//	{
//		Node *temp = topPtr;
//		if (temp != NULL)
//		{
//			for (int i = 1; i <= getStackSize(); i++)
//			{
//				cout << "Value " << i << ": " << temp->data << endl;
//				temp = temp->nextPtr;
//			}
//		}
//	}
//};
//void main()
//{
//	int size = 3, data, retry = 1;
//	cout << "Enter size of list: ";
//	cin >> size;
//	stackLinked s1(size);
//	int option;
//	while (retry == 1)
//	{
//		cout << "Enter '1' to Push data\n";
//		cout << "Enter '2' to Pop data\n";
//		cout << "Enter '3' to Display Stack\n";
//		cout << "Enter '4' to Get Stack size\n";
//		cout << "Enter '5' to Exit\n";
//		cout << "Choose an option: ";
//		cin >> option;
//		system("cls");
//		switch (option)
//		{
//		case 1:
//			cout << "Enter a value: ";
//			cin >> data;
//			s1.push(data);
//			system("cls");
//			break;
//		case 2:
//			if (!s1.isEmpty())
//			{
//				cout << "Data: " << s1.pop() << endl;
//			}
//			else
//			{
//				cout << "The list is Empty\n";
//			}
//			system("pause");
//			system("cls");
//			break;
//		case 3:
//			if (!s1.isEmpty())
//			{
//				s1.displayStack();
//			}
//			else
//			{
//				cout << "The list is Empty\n";
//			}
//			system("pause");
//			system("cls");
//			break;
//		case 4:
//			cout << "Stack size: " << s1.getStackSize() << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 5:
//			retry = 0;
//			break;
//		default:
//			cout << "Invalid choice\n";
//		}
//	}
//}