/*=================================================================
/* CSEE2132:			OOP and Data Structures
/*
/* Student Name :		Nabeel Ali
/*
/* Registration No.:	BEE173059
/*
/* Section No.:			II
/*
/* Assignment No.:		4
/*
/* Question No.:		3.
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/

//#include <iostream>
//using namespace std;
//
//template <class T>
//struct Node {
//	T data;
//	Node<T> *nextPtr;
//};
//
//template <class T>
//class QueueLinkedList
//{
//	int length;
//	Node<T> *frontPtr;
//	Node<T> *rearPtr;
//public:
//	QueueLinkedList()
//	{
//		length = 0;
//		frontPtr = rearPtr = NULL;
//	}
//	~QueueLinkedList()
//	{
//		Node<T> *currentPtr = rearPtr;
//		for (int i = 1; i < length; i++)
//		{
//			currentPtr = rearPtr->nextPtr;
//			delete rearPtr;
//			rearPtr = currentPtr;
//		}
//	}
//
//	//void InitializeQueue();
//	
//	bool IsEmpty()
//	{
//		if (length == 0)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	void Enqueue(T data)
//	{
//		Node<T> *newNode = new Node<T>;
//		newNode->data = data;
//		newNode->nextPtr = rearPtr;
//		if (frontPtr == NULL && rearPtr == NULL)
//		{
//			
//			frontPtr = newNode;
//		}
//		rearPtr = newNode;
//		length++;
//	}
//
//	T Dequeue()
//	{
//		T temp = frontPtr->data;
//		Node<T> *currentPtr = rearPtr;
//		for (int i = 1; i < length - 1; i++)
//		{
//			currentPtr = currentPtr->nextPtr;
//		}
//		delete frontPtr;
//		frontPtr = currentPtr;
//		length--;
//		return temp;
//	}
//	int getSize()
//	{
//		return length;
//	}
//
//	T getFront()
//	{
//		return frontPtr->data;
//	}
//	
//	T getRear()
//	{
//		return rearPtr->data;
//	}
//
//	void displayQueue()
//	{
//		Node<T> *currentPtr = rearPtr;
//		for (int i = 1; i <= length; i++)
//		{
//			cout << "Data " << i << ": " << currentPtr->data << endl;
//			currentPtr = currentPtr->nextPtr;
//		}
//	}
//};////////void main()//{
//	QueueLinkedList<float> q1;//	float data;////	for (int i = 1; i <= 3; i++)//	{//		cout << "Enter the value " << i << ": ";//		cin >> data;//		q1.Enqueue(data);//	}//	cout << "\nThe dequeued data is: " << q1.Dequeue() << endl;//	cout << endl;//	q1.displayQueue();//	cout << "\nThe stack size is: " << q1.getSize() << endl;//}