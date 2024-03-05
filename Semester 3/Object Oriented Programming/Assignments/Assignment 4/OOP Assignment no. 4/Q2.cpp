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
/* Question No.:		2.
/*==================================================================
/* I certify that I have neither given nor received unauthorized aid
/*         on this Assignment.
/*==================================================================*/

#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string name;
	int total_score;
	float batting_average;
};

class scoreBoard
{
	int actual_size, max_size;
	Node *list_array;
public:
	scoreBoard(int size)
	{
		actual_size = 0;
		max_size = size;
		list_array = new Node[size];
	}

	void addInfo(string N, int TS, float BA)
	{
		if (actual_size < max_size)
		{
			list_array[actual_size].name = N;
			list_array[actual_size].total_score = TS;
			list_array[actual_size].batting_average = BA;
			actual_size++;
		}
		else
		{
			system("cls");
			cout << "Player list is full\n";
		}
	}

	void sortPlayerList()
	{
		string tempN;
		int tempTS;
		float tempBA;
		for (int i = 1; i < max_size; i++)
		{
			for (int j = 1; j < max_size; j++)
			{
				if (list_array[j - 1].batting_average > list_array[j].batting_average)
				{
					tempBA = list_array[j - 1].batting_average;
					tempN = list_array[j - 1].name;
					tempTS = list_array[j - 1].total_score;

					list_array[j - 1].batting_average = list_array[j].batting_average;
					list_array[j - 1].name = list_array[j].name;
					list_array[j - 1].total_score = list_array[j].total_score;

					list_array[j].batting_average = tempBA;
					list_array[j].name = tempN;
					list_array[j].total_score = tempTS;
				}
			}
		}
	}



	void displayPlayerList()
	{
		for (int i = 0; i < actual_size; i++)
		{
			cout << endl;
			cout << "Player Name: " << list_array[i].name << endl;
			cout << "Total Score: " << list_array[i].total_score << endl;
			cout << "Batting Average: " << list_array[i].batting_average << endl;
		}
		cout << endl;
	}
};



void main()
{
	int size = 2;
	scoreBoard s1(size);
	string name;
	int ts;
	float ba;
	for (int i = 1; i <= size; i++)
	{
		cout << "Enter the player " << i << " name: ";
		cin >> name;
		cout << "Enter the player " << i << " total score: ";
		cin >> ts;
		cout << "Enter the player " << i << " batting average: ";
		cin >> ba;
		s1.addInfo(name, ts, ba);
	}
	s1.displayPlayerList();
	s1.sortPlayerList();
	s1.displayPlayerList();
}