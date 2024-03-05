//Activity 1
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *previousPtr, *nextPtr;
};
class linkedList
{
	int length;
	Node *headPtr;
public:
	linkedList()
	{
		length = 0;
		headPtr = 0;
	}
	void insertAfter(int v1, int v2)
	{
		Node *newNode = new Node;
		newNode->data = v2;
		if (length != 0)
		{
			Node *currentPtr, *temp;
			for (int i = 1; i < v1; i++)
			{
				currentPtr = currentPtr->nextPtr;
			}
			temp = currentPtr->nextPtr;
			newNode->nextPtr = currentPtr->nextPtr;
			newNode->previousPtr = temp->previousPtr;
			currentPtr->nextPtr = newNode;
			temp->previousPtr = newNode;
		}
		else
		{
			headPtr = newNode;
			newNode->previousPtr = headPtr;
			newNode->nextPtr = NULL;
		}
	}
	void deleteFront()
	{
		if (length == 0)
		{
			cout << "List is empty.\n";
		}
		else
		{
			Node *currentPtr;
			while (currentPtr->nextPtr != NULL)
			{
				currentPtr = currentPtr->nextPtr;
			}
			Node *temp = currentPtr->previousPtr;
			temp->nextPtr = NULL;
			delete[] currentPtr;
		}
	}
	void search(int value)
	{
		
	}
};