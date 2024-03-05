#include <iostream>
#include<conio.h>
#include <fstream>
#include <string>
using namespace std;
int bookslength = 0;
int bookclength = 0;

struct book {
	string bookname;
	string bookauthor;
	float bookprice;
	int bookid;
	int bookcid;
	char chbookname[30];
	book *next;
	book *prev;
};
struct student1 {
	string name;
	int regno;
	string department;
	string bookissuedname1;
	string bookissuedname2;
	int sbi;
	char chstudentname[30];
	char chbookissuedname1[30];
	char chbookissuedname2[30];
	float fine;
	int noofbooksissued;
	int issuedate;
	int receiveddate;


	string bookname;
	int noofbooksisd;
	book bs1;
	student1 *next;
	student1 *prev;
};
struct bookcategory {
	string bcategory;
	int categoryid;
	book b1;
	bookcategory *next;
	bookcategory *prev;
	book *bhead;
	book *blast;
};
class book1 {
protected:
	book* head;
	book* last;
	int noofbooks;
public:
	book1()
	{
		head = NULL;
		last = NULL;
		noofbooks = 0;
	}

	void insertbook(string booka, string bookauthor, int price, int bookid1)
	{

		book* newbook = new book;
		noofbooks++;
		bookslength++;
		cout << "enter bookname again without space\n";
		cin >> newbook->chbookname;
		newbook->bookname = booka;
		newbook->bookauthor = bookauthor;
		newbook->bookprice = price;
		newbook->bookid = bookid1;
		newbook->next = NULL;
		newbook->prev = NULL;
		if (head == NULL)
		{
			head = newbook;
			last = newbook;
		}
		else
		{
			last->next = newbook;
			newbook->prev = last;
			last = newbook;
		}
	}
	void insertbookf(string booka, string bookauthor, int price, int bookid1)
	{

		book* newbook = new book;
		noofbooks++;
		bookslength++;

		newbook->bookname = booka;
		newbook->bookauthor = bookauthor;
		newbook->bookprice = price;
		newbook->bookid = bookid1;
		newbook->next = NULL;
		newbook->prev = NULL;


		if (head == NULL)
		{
			head = newbook;
			last = newbook;
		}
		else
		{
			last->next = newbook;
			newbook->prev = last;
			last = newbook;
		}
	}
	void editbook()
	{

		int idbook = 0;
		cout << "Enter id of book to edit"<<endl;
		cin >> idbook;
		book *current = searchbook();
		cout << "enter new name"<<endl;
		cin >> current->bookname;
		cout << "enter new author"<<endl;
		cin >> current->bookauthor;
		cout << "enter(int) new price"<<endl;
		cin >> current->bookid;
		cout << "enter(int) new id"<<endl;
		cin >> current->bookid;


	}
	int sgetbookn()
	{
		int bid = 0;
		cout << "enter bookid to check its numbers in library\n";
		cin >> bid;
		int count = 0;
		book *current = head;
		for (int i = 0; i <= noofbooks; i++)
		{
			if (current->bookid == bid)
			{
				count = count + 1;
				current = current->next;
			}
			else
			{
				current = current->next;
			}
		}
		return count;
	}

	int  searchbookid(int idbook)
	{
		int idsearched = 0;
		book *current = head;
		while (current != NULL)
		{
			if (current->bookid == idbook)
			{
				idsearched = current->bookid;
				return idsearched;
				break;
			}
			else
			{
				current = current->next;
			}

		}
		return NULL;



	}
	void addcopyofbook()
	{
		int id ;
		cout << "enter id of book to add it copies"<<endl;
		cin >> id;
		book *current = head;
		int number = 0;
		int i;
		cout << "Enter number of copies you want to add"<<endl;
		cin >> number;
		for (i = 0; i<number; i++)
		{
			if (current->bookid == id)
			{

				book* newbook = new book;
				noofbooks++;
				bookslength++;


				newbook->bookname = current->bookname;
				newbook->bookauthor = current->bookauthor;
				newbook->bookprice = current->bookprice;
				newbook->bookid = current->bookid;
				newbook->next = NULL;
				newbook->prev = NULL;

				last->next = newbook;
				newbook->prev = last;
				newbook->next = NULL;
				last = newbook;


			}

			else
			{
				current = current->next;

			}


		}



	}


	void similaritysearchbook(char bookname1[30])
	{
		int n = 0;
		book *current = head;
		cout << "enter the number of alphabets (int) you want to compare for similrity search\n";
		cin >> n;
		int compare = -10;
		while (current != NULL)
		{

			compare = strncmp(current->chbookname, bookname1, n);
			if (compare == 0)
			{
				cout << "data matched with\n" << current->bookname << endl;
				current = current->next;

			}
			else
			{
				current = current->next;
			}


		}

	}


	book* searchbook()
	{
		int idbook = 0;
		cout << "enter the(int) id of book\n";
		cin >> idbook;
		book *current = head;
		while (current != NULL)
		{
			if (current->bookid == idbook)
			{
				return current;
				break;
			}
			else
			{
				current = current->next;
			}

		}
		return NULL;



	}

	int getbookn()
	{
		int bid = 0;
		cout << "enter bookid(int)to check its numbers in library\n";
		cin >> bid;
		int count = 0;
		book *current = head;
		for (int i = 0; current != NULL; i++)
		{
			if (current->bookid == bid)
			{
				count = count + 1;
				current = current->next;
			}
			else
			{
				current = current->next;
			}
		}
		return count;
	}

	int gettotalbookn()
	{

		return noofbooks;
	}
	void displaybook()
	{
		book*current = head;
		if (noofbooks == 0)
		{

			cout << "list is empty\n";
		}
		else if (noofbooks == 1)
		{
			cout << "book name: \t";
			cout << current->bookname << endl;
			cout << "author name: \t";
			cout << current->bookauthor << endl;
			cout << "book price:\t";
			cout << current->bookprice << endl;
			cout << "book id:\t";
			cout << current->bookid << endl;
		}
		else
		{
			while (current != NULL)
			{
				cout << "book name: \t";
				cout << current->bookname << endl;
				cout << "author name: \t";
				cout << current->bookauthor << endl;
				cout << "book price:\t";
				cout << current->bookprice << endl;
				cout << "book id:\t";
				cout << current->bookid << endl;
				current = current->next;
			}
		}
		cout << "the total number of books are\t" << noofbooks << endl;
	}
	int searchbookindex(string value)
	{
		book *n = new book;
		n = head;
		for (int i = 0; n != NULL; i++)
		{
			if (n->bookname == value)
			{
				return i;
			}
			else
			{
				n = n->next;
			}
		}
		return -1;
	}

	int booksearch(string k)
	{
		book *n = new book;
		n = head;
		for (int i = 0; n != NULL; i++)
		{

			if (n->bookname == k) {
				return i;
			}
			else
			{
				n = n->next;
			}
		}
		return -1;
	}



	void deletebook()
	{
		int bookid1 = 0;
		cout << "enter book id(int) to delete\n";
		cin >> bookid1;
		book *current = head;
		if (head == NULL)
		{
			cout << "list is empty";
		}
		else if (head->bookid == bookid1 && noofbooks == 1)
		{
			head->next = NULL;
			delete head;
			noofbooks--;
			bookslength--;


		}

		else if (head->bookid == bookid1 && noofbooks>1)
		{

			book *temp = head;
			head = head->next;
			head->prev = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			noofbooks--;
			bookslength--;

		}
		else if (last->bookid == bookid1 && noofbooks>1)
		{

			book *temp = last;
			last = last->prev;
			last->next = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			noofbooks--;
			bookslength--;

		}

		else
		{
			while (current != NULL)
			{
				if (current->bookid == bookid1)
				{
					break;
				}
				else if (current->bookid != bookid1)
				{

					cout << "you have deleted the book that donot exist\n";
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}
		if (current->bookid == bookid1) {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			delete current;
			noofbooks--;
			bookslength--;
		}

	}
	void savebook()
	{
		ofstream file("D:\\bookfilelms.txt");
		book *temp = head;
		book *temp2 = NULL;
		while (temp != NULL)
		{
			file << "bookstart\n";
			file << temp->bookname << "\n";
			file << temp->bookauthor << "\n";
			file << temp->bookprice << "\n";
			file << temp->bookid << "\n";
			file << "bookend\n";
			temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
		file.close();

	}
	void loadbook()
	{
		ifstream file("D:\\bookfilelms.txt");
		if (!file)
		{
			cout << "File is empty" << endl;

		}
		else
		{
			while (!file.eof())
			{
				string hint1;
				string bn;
				string ba;
				int bp;
				int bi;
				string hint2;
				file >> hint1;
				if (hint1 == "bookstart")
				{
					file >> bn;
					file >> ba;
					file >> bp;
					file >> bi;
					file >> hint2;
					if (bn != "")
					{
						if (ba != "")
						{
							if (hint2 == "bookend")
							{
								insertbookf(bn, ba, bp, bi);

							}
						}
					}
				}
			}
		}
	}


};
class book1;
class bookc
{
protected:
	bookcategory *head;
	bookcategory *last;
	bookcategory *bookhead;
	bookcategory *booklast;
	int noofc;
	int noofbooksc;

public:
	book1 *b;
	bookc()
	{
		head = NULL;
		last = NULL;
		bookhead = NULL;
		booklast = NULL;
		noofc = 0;
		noofbooksc = 0;
	}

	void insertbookcategory(string bookc, int idbookc)
	{

		bookcategory *newbookc = new bookcategory;
		noofc++;
		newbookc->bcategory = bookc;
		newbookc->categoryid = idbookc;
		newbookc->b1.bookcid = idbookc;
		newbookc->next = NULL;
		newbookc->prev = NULL;
		newbookc->bhead = NULL;
		newbookc->blast = NULL;
		if (head == NULL)
		{
			head = newbookc;
			last = newbookc;

		}
		else
		{
			last->next = newbookc;
			newbookc->prev = last;
			last = newbookc;
		}

	}

	void insertbookinbc(int cid)
	{
		bookcategory *current = head;
		while (current != NULL)
		{
			if (current->categoryid == cid)
			{
				break;
			}
			else
			{
				current = current->next;
			}
		}
		if (current->categoryid == cid) {
			book* newbook = new book;
			noofbooksc++;
			bookclength++;
			string booka;
			string bookauthor;
			float price = 0;
			int bookid1;
			cout << "Enter the name of book";
			cin >> booka;
			cout << "Enter the name of author of book";
			cin >> bookauthor;
			cout << "Enter the(int) price of book";
			cin >> price;
			cout << "Enter (int)the id of book";
			cin >> bookid1;
			newbook->bookname = booka;
			newbook->bookauthor = bookauthor;
			newbook->bookprice = price;
			newbook->bookid = bookid1;
			newbook->bookcid = cid;
			newbook->next = NULL;
			newbook->prev = NULL;
			if (current->bhead == NULL)
			{
				current->bhead = newbook;
				current->blast = newbook;
			}
			else
			{
				current->blast->next = newbook;
				newbook->prev = current->blast;
				current->blast = newbook;
			}
		}
	}
	void addcopyofbookinbc()
	{
		int idbc = 0;
		int idb = 0;
		cout << "enter id of bookcategory to add copies in it\n";
		cin >> idbc;
		cout << "enter id of book you want to copy\n";
		cin >> idb;
		bookcategory *current = searchbookcategory(idbc);
		int number = 0;
		int i;
		cout << "Enter number of copies you want to add\n";
		cin >> number;
		book *temp = current->bhead;
		for (i = 0; i<number; i++)
		{
			if (temp->bookid == idb)
			{

				book* newbook = new book;
				noofbooksc++;
				bookclength++;
				newbook->bookname = temp->bookname;
				newbook->bookauthor = temp->bookauthor;
				newbook->bookprice = temp->bookprice;
				newbook->bookid = temp->bookid;
				newbook->bookcid = temp->bookcid;
				newbook->next = NULL;
				newbook->prev = NULL;

				if (current->bhead == NULL)
				{
					current->bhead = newbook;
					current->blast = newbook;
				}
				else
				{
					current->blast->next = newbook;
					newbook->prev = current->blast;
					current->blast = newbook;

				}


			}

			else
			{
				cout << "the id of book donot match the records\n";
				break;
			}


		}



	}


	void editbookinbookcategory()
	{
		int idbookc = 0;
		int idb = 0;
		cout << "Enter id (int)of book category to edit\t";
		cin >> idbookc;
		cout << "Enter id (int)of book  to edit\t";
		cin >> idb;
		bookcategory *current = searchbookcategory(idbookc);
		book *temp = current->bhead;
		if (temp->bookid == idb)
		{
			cout << "enter new name\t";
			cin >> temp->bookname;
			cout << "enter new author\t";
			cin >> temp->bookauthor;
			cout << "enter new price\t";
			cin >> temp->bookid;
			cout << "enter new id\t";
			cin >> temp->bookid;
		}
		else
		{
			cout << "the id of book donot match the records\n";

		}


	}


	void displaybookinbookcategory()
	{
		int bookc = 0;
		cout << "enter the category(int) to display books\n";
		cin >> bookc;
		bookcategory *current = searchbookcategory(bookc);
		if (current->bhead == NULL)
		{
			cout << "list is empty\n";
		}
		else
		{
			while (current->bhead != NULL)
			{
				cout << "the name  of the book is\n";
				cout << current->bhead->bookname << endl;
				cout << "the name of the author of the book is\n";
				cout << current->bhead->bookauthor << endl;
				cout << "the id  of the book is\n";
				cout << current->bhead->bookid << endl;
				cout << "the price of the book is\n";
				cout << current->bhead->bookprice << endl;
				cout << "the category id of the book is\n";
				cout << current->bhead->bookcid << endl;
				current->bhead = current->bhead->next;

			}
		}

	}

	bookcategory* searchbookcategory(int idbookc)
	{
		bookcategory *current = head;
		while (current != NULL)
		{
			if (current->categoryid == idbookc)
			{
				return current;
				break;
			}
			else
			{
				current = current->next;
			}

		}
		return NULL;



	}
	int  searchbookidinbookcategory(int idbookc, int idb)
	{
		int idsearched = 0;
		bookcategory *current = searchbookcategory(idbookc);
		book *temp = current->bhead;
		while (temp != NULL)
		{
			if (temp->bookid == idb)
			{
				idsearched = temp->bookid;
				return idsearched;
				break;

			}
			else
			{
				temp = temp->next;
			}

		}

		return -1;

	}
	void editbookcategory(int idbookc)
	{
		bookcategory *current = searchbookcategory(idbookc);
		cout << "enter the new name of the category\n";
		cin >> current->bcategory;

		cout << "enter the new id of the category\n";
		cin >> current->categoryid;


	}

	int searchbookcategory1(int idbookc)
	{
		bookcategory *current = head;
		while (current != NULL)
		{
			if (current->categoryid == idbookc)
			{
				return idbookc;
				break;
			}
			else
			{
				current = current->next;
			}

		}
		return 0;



	}

	void searchbookinbookcategory()
	{
		int idbookc = 0;
		int idb = 0;
		cout << "enter the id of book category to search\n";
		cin >> idbookc;
		cout << "enter the id of book to search\n";
		cin >> idb;
		bookcategory *current = searchbookcategory(idbookc);
		book *temp = current->bhead;
		while (temp != NULL)
		{
			if (temp->bookid == idb)
			{
				cout << "book found in search\n";
				cout << "bookname:\t" << temp->bookname << endl;
				cout << "authorname:\t" << temp->bookauthor << endl;
				cout << "bookprice:\t" << temp->bookprice << endl;
				cout << "bookid:\t" << temp->bookid << endl;
				temp = temp->next;
			}
			else
			{
				temp = temp->next;
			}

		}
	}

	int getbookcategoryid(int idc)
	{
		int id1 = 0;
		bookcategory *current = head;
		while (current != NULL)
		{
			if (current->categoryid == idc)
			{
				id1 = idc;
				cout << idc << endl;
				return id1;
			}
			else
			{
				current = current->next;

			}

		}
		return -1;
	}

	void displaybookcategory()
	{
		bookcategory *current = head;
		if (noofc == 1)
		{
			cout << "the name of the category of the book is\n";
			cout << head->bcategory << endl;
			cout << "the id of the category of the book is\n";
			cout << head->categoryid << endl;

		}
		else
		{
			while (current != NULL)
			{
				cout << "the name of the category of the book is\n";
				cout << current->bcategory << endl;
				cout << "the id of the category of the book is\n";
				cout << current->categoryid << endl;
				current = current->next;
			}
		}
	}
	void deletebookcategory(int idbookc)
	{
		bookcategory *current = head;
		if (head == NULL)
		{
			cout << "list is empty";
		}
		else if (head->categoryid == idbookc && noofc == 1)
		{
			head->next = NULL;
			delete head;
			noofc--;
		}
		else if (head->categoryid == idbookc && noofc>1)
		{
			bookcategory *temp = head;
			head = head->next;
			head->prev = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			noofc--;
		}
		else if (last->categoryid == idbookc && noofc>1)
		{

			bookcategory *temp = last;
			last = last->prev;
			last->next = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			noofc--;
		}
		else
		{
			while (current != NULL)
			{
				if (current->categoryid == idbookc)
				{
					break;
				}
				else if (current->categoryid != idbookc)
				{

					cout << "you have deleted the book that donot exist\n";
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}
		if (current->categoryid == idbookc) {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			delete current;
			noofc--;
		}

	}


	void deletebookinbc()
	{

		int idbc = 0;
		int idb = 0;
		cout << "enter id of bookcategory\n";
		cin >> idbc;
		cout << "enter id of book\n";
		cin >> idb;
		bookcategory *current = searchbookcategory(idbc);
		book *temp = current->bhead;
		if (temp == NULL)
		{
			cout << "list is empty";
		}
		else
		{

			if (temp->bookid == idb && noofbooksc == 1)
			{
				cout << "hie\n";
				temp->next = NULL;
				delete temp;
				noofbooksc--;


			}

			else if (temp->bookid == idb && noofbooksc>1)
			{
				book *temp1 = current->bhead;
				temp = temp->next;
				temp->prev = NULL;
				temp1->next = NULL;
				temp1->prev = NULL;
				delete temp1;
				noofbooksc--;


			}
		}

	}
	void savebookcategory()
	{
		ofstream file("D:\\bookcategory.txt");
		bookcategory *temp = head;
		bookcategory *temp2 = NULL;
		while (temp != NULL)
		{
			file << "bookcategorystart\n";
			file << temp->bcategory << "\n";
			file << temp->categoryid << "\n";

			file << "bookcategoryend\n";
			temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
		file.close();

	}
	void loadbookcategory()
	{
		ifstream file("D:\\bookcategory.txt");
		if (!file)
		{
			cout << "File is empty" << endl;

		}
		else
		{
			while (!file.eof())
			{
				string hint1;
				string bn;
				int bp;
				string hint2;
				file >> hint1;
				if (hint1 == "bookcategorystart")
				{
					file >> bn;
					file >> bp;
					file >> hint2;
					if (bn != "")
					{
						if (hint2 == "bookcategoryend")
						{
							insertbookcategory(bn, bp);

						}

					}
				}
			}
		}
	}

};

class student :public book1
{
private:
	student1 *head;
	student1 *last;
	book *bhead;
	int noofstudents;
	int noofbis;
public:
	student()
	{
		head = NULL;
		last = NULL;
		bhead = NULL;
		noofstudents = 0;
		noofbis = 0;
	}

	void registernewstudent()
	{
		student1 *newstudent = new student1;
		noofstudents++;

		cout << "Enter  name" << endl;
		cin >> newstudent->name;
		cout << "enter name again without space\n";
		cin >> newstudent->chstudentname;
		cout << "Enter(int) reg no " << endl;
		cin >> newstudent->regno;
		cout << "Enter name of department" << endl;
		cin >> newstudent->department;

		newstudent->bookissuedname1 = "nill";
		newstudent->bookissuedname2 = "nill";
		newstudent->fine = 0;
		newstudent->noofbooksissued = 0;
		newstudent->issuedate = 0;
		newstudent->receiveddate = 0;
		newstudent->noofbooksisd = 0;
		newstudent->next = NULL;
		newstudent->prev = NULL;
		if (head == NULL)
		{
			head = newstudent;
			last = newstudent;
		}
		else
		{
			last->next = newstudent;
			newstudent->prev = last;
			last = newstudent;
		}

	}

	void registernewstudentf(string name, string dept, int regno)
	{
		student1 *newstudent = new student1;
		noofstudents++;


		newstudent->name = name;

		newstudent->regno = regno;

		newstudent->department = dept;
		newstudent->bookissuedname1 = "nill";
		newstudent->bookissuedname2 = "nill";
		newstudent->fine = 0;
		newstudent->noofbooksissued = 0;
		newstudent->issuedate = 0;
		newstudent->receiveddate = 0;
		newstudent->noofbooksisd = 0;
		newstudent->next = NULL;
		newstudent->prev = NULL;
		if (head == NULL)
		{
			head = newstudent;
			last = newstudent;
		}
		else
		{
			last->next = newstudent;
			newstudent->prev = last;
			last = newstudent;
		}

	}
	void similaritysearchstudent(char bookname1[30])
	{
		int n = 0;
		student1 *current = head;
		cout << "enter the number of alphabets you want to compare for similrity search\n";
		cin >> n;


		int compare = -10;
		while (current != NULL)
		{

			compare = strncmp(current->chstudentname, bookname1, n);
			if (compare == 0)
			{
				cout << "data matched with\n" << current->name << endl;
				current = current->next;

			}
			else
			{
				current = current->next;
			}


		}

	}

	student1* searchstudent(int reg)
	{
		student1 *current = head;
		while (current != NULL)
		{
			if (current->regno == reg)
			{
				cout << "student serarched\n";
				cout << "name:";
				cout << current->name << endl;
				return current;
				break;
			}
			else
			{
				current = current->next;
			}

		}
		return NULL;
	}

	void editstudent()
	{
		int reg = 0;


		cout << "Enter regno(int) of student to edit\t";
		cin >> reg;
		student1 *current = searchstudent(reg);
		cout << "enter new name\t";
		cin >> current->name;
		cout << "enter (int)new regno\t";
		cin >> current->regno;
		cout << "enter new department\t";
		cin >> current->department;
		cout << "change the book issue date\t";
		cin >> current->issuedate;
		cout << "change the book received date\t";
		cin >> current->receiveddate;
		cout << "change the fine \t";
		cin >> current->fine;



	}
	int sgetbookn1()
	{
		int bid = 0;
		cout << "enter bookid to check its numbers in library\n";
		cin >> bid;
		int count = 0;
		book *current = bhead;
		while (current != NULL)
		{
			if (current->bookid == bid)
			{
				count = count + 1;
				cout << "count incremented\n";
				current = current->next;
			}
			else
			{
				current = current->next;
			}
		}
		return count;
	}
	void issuegeneralbook(int reg, int bid, string bname, char arr[30], int idknown)
	{
		student1 * current = head;


		while (current != NULL)
		{
			if (current->regno == reg)
			{
				break;
			}
			else
			{
				current = current->next;

			}

		}
		if (current->regno == reg)
		{
			if (current->fine>0)
			{
				cout << "you already have fine so book cannot be issued\n";

			}
			else
			{
				cout << "you have no fine\n";
				int idsearched = 0;
				idsearched = idknown;
				cout << idsearched;
				if (idsearched == bid)
				{
					int n = 0;
					n = bookslength;

					if (n <= 1)
					{
						cout << "there is no or only one book so it cant be issued\n";
					}
					else
					{
						if (current->noofbooksisd == 3)
						{
							cout << "you already have 3 books issued so book cannot be issued\n";
						}

						else
						{
							int isd = 0;
							if (current->noofbooksissued == 0)
							{
								current->bookissuedname1 = bname;
								current->chbookissuedname1[30] = arr[30];
								noofbis++;
								current->noofbooksissued++;
								cout << "enter the issue date of book\n";
								cin >> isd;
								current->issuedate = isd;
								current->receiveddate = isd + 3;
								cout << "book issued successfully\n";
							}
							else if (current->noofbooksissued == 1)
							{
								current->bookissuedname2 = bname;
								current->chbookissuedname2[30] = arr[30];
								noofbis++;
								current->noofbooksissued++;
								cout << "enter the issue date of book\n";
								cin >> isd;
								current->issuedate = isd;
								current->receiveddate = isd + 3;
								cout << "book issued successfully\n";
							}
							else
							{
								cout << "student already have two books so books cannot be issued\n";

							}
						}
					}
				}
				else
				{
					cout << "book you entered doesnot exist\n";
				}
			}
		}
		else
		{
			cout << "the entered regno is not registered in library\n";
		}

	}
	void issuecategorybook(int reg, int bid, string bname, char arr[30], int idknown)
	{
		student1 * current = head;


		while (current != NULL)
		{
			if (current->regno == reg)
			{
				break;
			}
			else
			{
				current = current->next;

			}

		}
		if (current->regno == reg)
		{
			if (current->fine>0)
			{
				cout << "you already have fine so book cannot be issued\n";

			}
			else
			{
				cout << "you have no fine\n";
				int idsearched = 0;
				idsearched = idknown;
				cout << idsearched;
				if (idsearched == bid)
				{
					int n = 0;
					n = bookclength;

					if (n <= 1)
					{
						cout << "there is no or only one book so it cant be issued\n";
					}
					else
					{
						if (current->noofbooksisd == 2)
						{
							cout << "you already have 2 books issued so book cannot be issued\n";
						}
						else
						{
							int isd = 0;
							if (current->noofbooksissued == 0)
							{
								current->bookissuedname1 = bname;
								current->chbookissuedname1[30] = arr[30];
								noofbis++;
								current->noofbooksissued++;
								cout << "enter the issue date of book\n";
								cin >> isd;
								current->issuedate = isd;
								current->receiveddate = isd + 3;
								cout << "book issued successfully\n";
							}
							else if (current->noofbooksissued == 1)
							{
								current->bookissuedname2 = bname;
								current->chbookissuedname2[30] = arr[30];
								noofbis++;
								current->noofbooksissued++;
								cout << "enter the issue date of book\n";
								cin >> isd;
								current->issuedate = isd;
								current->receiveddate = isd + 3;
								cout << "book issued successfully\n";
							}
							else
							{
								cout << "student already have two books so books cannot be issued\n";

							}



						}
					}




				}
				else
				{
					cout << "book you entered doesnot exist\n";
				}


			}
		}
		else
		{
			cout << "the entered regno is not registered in library\n";
		}

	}
	int searchreg(int s)
	{
		student1 * u = head;
		for (int i = 0; u != NULL; i++)
		{
			if (u->regno == s)
			{
				return i;
			}
			else
			{
				u = u->next;
			}
		}
		return -1;
	}
	void receivebook()
	{
		student1 *u = head;
		student1 *temp;
		student1 *temp2;
		int reg1 = 0;
		string bn = "nill";
		cout << "enter (int)the regno\n";
		cin >> reg1;
		cout << "enter the bookname to return\n";
		cin >> bn;
		if (head == NULL)
		{
			cout << "No student registered" << endl;

		}
		else if (noofstudents == 1 && u->regno == reg1 && u->bookissuedname1 == bn)
		{
			int bookid = 0;
			int b = 0;

			cout << "enter the book returned date1\n";
			cin >> b;
			u->receiveddate = b;
			int h = u->issuedate;
			int max = b - h;
			if (max>3) {
				int fine1 = 0;
				fine1 = (max - 3) * 20;
				cout << "RS" << fine1;
				cout << "is fined for late submittion of ";
				cout << max - 3 << "days" << endl;
				u->fine = fine1;

			}
			cout << "Book is succesfully submitted" << endl;
			u->bookissuedname1 = "nill";

			u->noofbooksissued--;
			noofbis--;

		}

		else if (noofstudents == 1 && u->regno == reg1 && u->bookissuedname2 == bn)
		{
			int bookid = 0;
			int b = 0;

			cout << "enter the book returned date\n";
			cin >> b;
			u->receiveddate = b;
			int h = u->issuedate;
			int max = b - h;
			if (max>3) {
				int fine1 = 0;
				fine1 = (max - 3) * 20;
				cout << "RS" << fine1;
				cout << "is fined for late submittion of ";
				cout << max - 3 << "days" << endl;
				u->fine = fine1;

			}
			cout << "Book is succesfully submitted" << endl;
			u->bookissuedname2 = "nill";

			u->noofbooksissued--;
			noofbis--;

		}
		else {

			while (u != NULL)
			{
				if (u->regno == reg1)
				{
					break;
				}
				else
				{
					u = u->next;

				}

			}

			int max;
			int b = 0;;
			cout << "enter the book returned date\n";
			cin >> b;
			u->receiveddate = b;
			max = (u->issuedate) - (u->receiveddate);
			if (max>3) {
				int fine1 = 0;
				fine1 = (max - 3) * 20;
				cout << "RS" << fine1;
				cout << "is fined for late submittion of ";
				cout << max - 3 << "days" << endl;
				u->fine = fine1;
			}
			if (u->bookissuedname1 == bn)
			{

				cout << "Book is succesfully submitted" << endl;
				u->bookissuedname1 = "nill";

				u->noofbooksissued--;
				noofbis--;
			}
			else if (u->bookissuedname2 == bn)
			{

				cout << "Book is succesfully submitted" << endl;
				u->bookissuedname2 = "nill";

				u->noofbooksissued--;
				noofbis--;
			}

		}

	}


	void receivefine()
	{
		int reg1;
		cout << "enter the regno\n";
		cin >> reg1;
		student1 *current = head;
		current = searchstudent(reg1);
		int fine1;
		cout << "enter the fine to deopsit\n";
		cin >> fine1;
		current->fine = (current->fine - fine1);
		cout << "fine" << fine1;
		cout << "submitted successfuly";


	}
	void display()
	{

		if (noofstudents == 0)
		{
			cout << "No students are registered" << endl;
		}
		else
		{
			student1* n = head;

			for (int i = 0; i<noofstudents; i++)
			{
				cout << "name:\t ";
				cout << n->name << endl;
				cout << "Reg no of student:\t ";
				cout << n->regno << endl;
				cout << "Department name:\t";
				cout << n->department << endl << endl;
				cout << "Date of issue:\t";
				cout << n->issuedate << endl;
				cout << "Date to receive:\t";
				cout << n->receiveddate << endl;
				cout << "total fine:\t";
				cout << n->fine << endl;

				n = n->next;
			}
			student1* n1 = head;
			cout << "total students \t" << noofstudents << endl;
			for (int i = 0; i<noofstudents; i++)
			{
				cout << "name:\t ";
				cout << n1->name << endl;
				n1 = n1->next;
			}
		}
	}

	void displayissuedbooks()
	{
		if (noofbis == 0)
		{
			cout << "No books are issued" << endl;
		}
		else
		{
			student1 *n = head;
			cout << "list of total book issued:\n";
			while (n != NULL)
			{

				if (n->noofbooksissued == 1 && n->bookissuedname1 != "nill")
				{
					cout << n->bookissuedname1 << endl;
					cout << "issued by\t" << n->name << endl;

				}
				else if (n->noofbooksissued == 1 && n->bookissuedname2 != "nill")
				{
					cout << n->bookissuedname2 << endl;
					cout << "issued by\t" << n->name << endl;
				}
				else if (n->noofbooksissued == 2)
				{
					cout << n->bookissuedname1 << endl;
					cout << n->bookissuedname2 << endl;
					cout << "issued by\t" << n->name << endl;
				}
				else
				{
					cout << "no books issued\n";
					break;
				}
				n = n->next;


			}

			cout << "total books issued are \t" << noofbis << endl;

		}



	}

	void similaritysearchbookissued(char bookname1[30])
	{
		int n = 0;
		student1 *current = head;
		cout << "enter the number of alphabets you want to compare for similrity search\n";
		cin >> n;


		int compare = -10;
		while (current != NULL)
		{

			compare = strncmp(current->chstudentname, bookname1, n);
			if (compare == 0)
			{
				cout << "data matched with\n" << current->bookissuedname1 << endl;
				current = current->next;

			}
			else
			{
				current = current->next;
			}


		}

	}
	void dropstudent()
	{
		int reg1 = 0;
		cout << "enter the regno(int) of student to drop\n";
		cin >> reg1;
		student1 *current = head;
		cout << "student searching before dropping\n";
		current = searchstudent(reg1);
		if (current == NULL)
		{
			cout << "no student registered\n";

		}
		else if (current->noofbooksisd == 0 && current->fine == 0)
		{
			if (noofstudents == 1)
			{
				head->next = NULL;
				delete head;
				noofstudents--;


			}

			else if (head->regno == reg1 && noofstudents>1)
			{

				student1 *temp = current;
				head = head->next;
				head->prev = NULL;
				temp->next = NULL;
				temp->prev = NULL;
				delete temp;
				noofstudents--;

			}
			else if (last->regno == reg1 && noofstudents>1)
			{

				student1 *temp = last;
				last = last->prev;
				last->next = NULL;
				temp->next = NULL;
				temp->prev = NULL;
				delete temp;
				noofstudents--;

			}
			else
			{
				current->next->prev = current->prev;
				current->prev->next = current->next;
				delete current;
				noofstudents--;

			}

		}

		else
		{
			cout << "student cannot be dropped.He has a book issued or fine dew\n";
		}


	}


	void deletestudent()
	{
		int reg = 0;
		cout << "enter regno to delete\n";
		cin >> reg;
		student1 *current = head;
		if (head == NULL)
		{
			cout << "no student registered\n";
		}
		else if (head->regno == reg && noofstudents == 1)
		{
			head->next = NULL;
			delete head;
			noofstudents--;


		}

		else if (head->regno == reg && noofstudents>1)
		{

			student1 *temp = head;
			head = head->next;
			head->prev = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			noofstudents--;

		}
		else if (last->regno == reg && noofstudents>1)
		{

			student1 *temp = last;
			last = last->prev;
			last->next = NULL;
			temp->next = NULL;
			temp->prev = NULL;
			delete temp;
			noofstudents--;

		}

		else
		{
			while (current != NULL)
			{
				if (current->regno == reg)
				{
					break;
				}
				else if (current->regno != reg)
				{

					cout << "you have deleted the student that donot exist\n";
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}
		if (current->regno == reg) {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			delete current;
			noofstudents--;
		}

	}

	void savestudent()
	{
		ofstream file("D:\\bookfilelms1.txt");
		student1 *temp = head;
		student1 *temp2 = NULL;
		while (temp != NULL)
		{
			file << "studentstart\n";
			file << temp->name << "\n";
			file << temp->department << "\n";
			file << temp->regno << "\n";
			file << "studentend\n";
			temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
		file.close();

	}
	void loadstudent()
	{
		ifstream file("D:\\bookfilelms1.txt");
		if (!file)
		{
			cout << "File is empty" << endl;

		}
		else
		{
			while (!file.eof())
			{
				string hint1;
				string bn;
				string ba;
				int bp;
				string hint2;
				file >> hint1;
				if (hint1 == "studentstart")
				{
					file >> bn;
					file >> ba;
					file >> bp;
					file >> hint2;
					if (bn != "")
					{
						if (ba != "")
						{
							if (hint2 == "studentend")
							{
								registernewstudentf(bn, ba, bp);

							}
						}
					}
				}
			}
		}
	}

};


class manager : public student, public book1, public bookc
{
private:


public:
	manager()
	{

	}
	void insertbookm(string booka, string bookauthor, int price, int bookid1)
	{
		book1::insertbook(booka, bookauthor, price, bookid1);
	}

	void insertbookfm(string booka, string bookauthor, int price, int bookid1)
	{
		book1::insertbookf(booka, bookauthor, price, bookid1);
	}
	void editbookm()
	{
		book1::editbook();
	}
	int searchbookidm(int idbook)
	{
		return book1::searchbookid(idbook);
	}

	void addcopyofbookm()
	{
		book1::addcopyofbook();

	}
	void searchbookm()
	{
		book1::searchbook();


	}
	int getbooknm()
	{
		return book1::getbookn();
	}
	void similaritysearchbookm(char bookname1[30])
	{
		book1::similaritysearchbook(bookname1);
	}
	int gettotalbookn()
	{
		return book1::gettotalbookn();

	}
	void displaybookm()
	{
		book1::displaybook();

	}
	void deletebookm()
	{
		book1::deletebook();
	}
	void savebookm()
	{
		book1::savebook();
	}
	void loadbookm()
	{
		book1::loadbook();

	}
	void insertbookcategorym(string bookc, int idc)
	{
		bookc::insertbookcategory(bookc, idc);
	}
	void insertbookinbcm(int cid)
	{
		bookc::insertbookinbc(cid);

	}
	int  searchbookidinbookcategorym(int idbookc, int idb)
	{
		return bookc::searchbookidinbookcategory(idbookc, idb);
	}
	void addcopyofbookinbcm()
	{
		bookc::addcopyofbookinbc();

	}
	void editbookinbookcategorym()
	{
		bookc::editbookinbookcategory();
	}
	void displaybookinbookcategorym() {
		bookc::displaybookinbookcategory();
	}
	bookcategory* searchbookcategorym(int idbookc)
	{
		return bookc::searchbookcategory(idbookc);

	}
	void editbookcategorym(int idbookc)
	{
		bookc::editbookcategory(idbookc);
	}
	void searchbookinbookcategorym()
	{
		bookc::searchbookinbookcategory();
	}
	void displaybookcategorym()
	{
		bookc::displaybookcategory();
	}

	void deletebookcategorym(int idbookc)
	{
		bookc::deletebookcategory(idbookc);
	}
	void savebookcategorym()
	{
		bookc::savebookcategory();
	}
	void loadbookcategorym()
	{
		bookc::loadbookcategory();

	}
	void registernewstudentm()
	{
		student::registernewstudent();

	}
	void registernewstudentmf(string n, string dept, int reg)
	{
		student::registernewstudentf(n, dept, reg);

	}
	void similaritysearchstudentm(char bookname1[30])
	{
		student::similaritysearchstudent(bookname1);
	}
	void editstudentm()
	{
		student::editstudent();
	}
	int sgetbooknm()
	{
		return student::sgetbookn();
	}
	void searchstudentm(int reg)
	{
		student::searchstudent(reg);

	}
	void displaym()
	{
		student::display();

	}

	void issuegeneralbookm(int reg, int bid, string bname, char arr[30], int idknown)
	{
		student::issuegeneralbook(reg, bid, bname, arr, idknown);

	}
	void savestudentm()
	{
		student::savestudent();
	}
	void loadstudentm()
	{
		student::loadstudent();

	}

	void issuecategorybookm(int reg, int bid, string bname, char arr[30], int idknown)
	{
		student::issuecategorybook(reg, bid, bname, arr, idknown);

	}
	void receivebookm()
	{
		student::receivebook();
	}
	void similaritysearchbookissuedm(char bookname1[30])
	{
		student::similaritysearchbookissued(bookname1);
	}
	void receivefinem()
	{
		student::receivefine();
	}
	void displayissuedbooksm()
	{
		student::displayissuedbooks();
	}
	void dropstudentm()
	{
		student::dropstudent();
	}
	void deletestudentm()
	{
		student::deletestudent();
	}

};


book1 b1;
student s;


manager m1;
bookc b2;
void generalbookmenu()
{
	char choice = 0;
	do
	{
		cout << "Welcome to the general books menu" << endl;
		cout << "Press 1 to enter new book in library\n";
		cout << "Press 2 to display books\n";
		cout << "Press 3 to add copies of books\n";
		cout << "Press 4 to delete books\n";
		cout << "Press 5 to edit book\n";
		cout << "Press 6 to check the number of books in library\n";
		cout << "Press 7 for similarity search\n";
		cout << "Press 8 to exit\n";

		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{

			string booka;
			string bookauthor;
			float price = 0;
			int bookid1;
			cout << "Enter name of book\t";
			cin >> booka;
			cout << "Enter name of book author\t";
			cin >> bookauthor;
			cout << "Enter (int)book price\t";
			cin >> price;
			cout << "Enter(int) book id\t";
			cin >> bookid1;
			m1.insertbookm(booka, bookauthor, price, bookid1);
			break;
		}

		case 2:
		{   m1.loadbookm();
		m1.displaybookm();
		break;
		}
		case 3:
		{
			m1.addcopyofbookm();
			break;
		}
		case 4:
		{
			int id = 0;

			m1.deletebookm();
			break;

		}
		case 5:
		{
			m1.editbookm();
			break;

		}
		case 6:
		{
			int n = 0;
			cout << "the number are" << b1.getbookn() << endl;
			n = m1.getbooknm();
			break;


		}
		case 7:
		{
			char name1[30] = { "nill" };
			cout << "enter the attribute for similaity serach\n";
			cin >> name1;
			m1.similaritysearchbookm(name1);

		}

		case 8:
		{
			break;

		}
		default:
		{
			cout << "you have entered wrong option\n";
		}

		}
		cout << "Do you want to exit general bookmenu(Y/N)\n";
		cin >> choice;
	} while (choice == 'N' || choice == 'n');
}
void categorybookmenu()
{
	char choice = 0;
	do
	{
		cout << "Welcome to the category books menu" << endl;
		cout << "Press 1 to enter new bookcategory in library\n";
		cout << "Press 2 to enter new book in category in library\n";
		cout << "Press 3 to display bookscategory\n";
		cout << "Press 4 to display books with category\n";
		cout << "Press 5 to edit category\n";
		cout << "Press 6 to edit book in category\n";
		cout << "Press 7 to add copies of books with category\n";
		cout << "Press 8 to delete category\n";
		cout << "Press 9 for similarity search\n";
		cout << "Press 10 to search a book\n";
		cout << "Press 11 to exit\n";

		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			string bookc = "nill";
			int idbookc = 0;
			cout << "Enter the name of book category\n";
			cin >> bookc;
			cout << "Enter the id(int) of book category\n";
			cin >> idbookc;
			m1.insertbookcategorym(bookc, idbookc);
			break;
		}

		case 2:
		{  // m1.loadbookm();

			int id = 0;
			cout << "enter the(int) bookcategory id\n";
			cin >> id;
			m1.insertbookinbcm(id);
			break;
		}
		case 3:
		{
			m1.loadbookcategorym();
			m1.displaybookcategorym();
			break;
		}
		case 4:
		{

			m1.displaybookinbookcategorym();
			break;
		}
		case 5:
		{
			int id = 0;
			cout << "enter the (int)bookcategory id\n";
			cin >> id;
			m1.editbookcategorym(id);
			break;


		}

		case 6:
		{

			m1.editbookinbookcategorym();
			break;


		}
		case 7:
		{
			m1.addcopyofbookinbcm();
			break;

		}
		case 8:
		{
			int id = 0;
			cout << "enter the (int)bookcategory id\n";
			cin >> id;
			m1.deletebookcategorym(id);
			break;

		}

		case 9:
		{
			char name1[30] = { "nill" };
			cout << "enter the attribute for similaity serach\n";
			cin >> name1;
			m1.similaritysearchbookm(name1);

		}
		case 10:
		{
			m1.searchbookinbookcategorym();
			break;

		}

		case 11:
		{


			break;

		}
		default:
		{
			cout << "you have entered wrong option\n";
		}


		}
		cout << "Do you want to exit category bookmenu(Y/N)\n";
		cin >> choice;
	} while (choice == 'N' || choice == 'n');
}
void studentregistrationmenu()
{
	char choice = 0;
	do
	{
		cout << "Welcome to student registration menu" << endl;
		cout << "Press 1 to register new student in library\n";
		cout << "Press 2 to display registered students\n";
		cout << "Press 3 to drop student\n";
		cout << "Press 4 to delete student\n";
		cout << "Press 5 to edit student\n";
		cout << "Press 6 to search student\n";
		cout << "Press 7 for similarity search\n";
		cout << "Press 8 to exit\n";

		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			// m1.registernewstudentm();
			string name = "nill";
			string dep = "nill";
			int reg = 0;
			cout << "enter name\n";
			cin >> name;
			cout << "enter dept\n";
			cin >> dep;
			cout << "enter reg\n";
			cin >> reg;
			m1.loadstudentm();
			m1.registernewstudentf(name, dep, reg);
			break;
		}

		case 2:
		{  // m1.loadbookm();
			m1.loadstudentm();
			m1.displaym();
			break;
		}
		case 3:
		{
			m1.dropstudentm();
			break;
		}
		case 4:
		{

			m1.deletestudentm();
			break;

		}
		case 5:
		{
			m1.editstudentm();
			break;

		}
		case 6:
		{
			int reg = 0;
			cout << "enter the (int)student regno to search\n";
			cin >> reg;
			m1.searchstudentm(reg);
			break;
		}
		case 7:
		{
			char name1[30] = { "nill" };
			cout << "enter the attribute for similaity serach\n";
			cin >> name1;
			m1.similaritysearchstudentm(name1);

		}
		case 8:
		{


			break;

		}
		default:
		{
			cout << "you have entered wrong option\n";
		}


		}
		cout << "Do you want to exit student registration menu(Y/N)\n";
		cin >> choice;
	} while (choice == 'N' || choice == 'n');
}
void bookissueandmanagementmenu()
{
	char choice = 0;
	do
	{
		cout << "Welcome to book issue and management menu" << endl;
		cout << "Press 1 to issue generalbook \n";
		cout << "Press 2 to issue categorybook \n";
		cout << "Press 3 to receive book\n";
		cout << "Press 4 to receive fine\n";
		cout << "Press 5 to display all issued books\n";
		cout << "Press 6 for similarity search\n";
		cout << "Press 7 to exit\n";
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			string bname1 = "nill";
			char arr1[30] = { "nill" };
			int bsearched1 = 0;
			int reg1 = 0;
			int bid1 = 0;
			cout << "enter (int)student regno\t";
			cin >> reg1;
			cout << "Enter(int) the book id to issue\n";
			cin >> bid1;
			cout << "Enter the book name to issue\n";
			cin >> bname1;
			cout << "Enter book name again withoutspace\n";
			cin >> arr1;
			bsearched1 = m1.searchbookidm(bid1);

			m1.issuegeneralbookm(reg1, bid1, bname1, arr1, bsearched1);
			break;
		}

		case 2:
		{
			string bname1 = "nill";
			char arr1[30] = { "nill" };
			int bsearched1 = 0;
			int reg1 = 0;
			int bid1 = 0;
			int bcid1 = 0;
			cout << "enter(int) student regno\t";
			cin >> reg1;
			cout << "Enter(int) the book category\n";
			cin >> bcid1;
			cout << "Enter the (int)book id to issue\n";
			cin >> bid1;
			cout << "Enter the book name to issue\n";
			cin >> bname1;
			cout << "Enter book name again withoutspace\n";
			cin >> arr1;
			bsearched1 = m1.searchbookidinbookcategorym(bcid1, bid1);
			cout << bsearched1 << endl;
			m1.issuecategorybookm(reg1, bid1, bname1, arr1, bsearched1);
			break;
		}

		case 3:
		{
			m1.receivebookm();
			break;
		}
		case 4:
		{
			m1.receivefinem();
			break;
		}
		case 5:
		{

			m1.displayissuedbooksm();
			break;

		}
		case 6:
		{
			char name1[30] = { "nill" };
			cout << "enter the attribute for similaity serach\n";
			cin >> name1;
			m1.similaritysearchbookissuedm(name1);

			break;

		}
		case 7:
		{

			break;

		}

		default:
		{
			cout << "you have entered wrong option\n";
		}





		}
		cout << "Do you want to exit bookissue and management menu(Y/N)\n";
		cin >> choice;
	} while (choice == 'N' || choice == 'n');
}



int main()
{  //bookc b5;
   // b5.insertbookcategory();
   // b5.insertbookinbc(123);
   // b5.insertbookinbc(123);

   //b5.deletebookinbc();
   //b5.displaybookinbookcategory();
   //b5.displaybookinbookcategory();
	char username[10] = { "library" };
	int userpassword = 12345;
	int count = 0;
	char usern[10] = { "nill" };
	int id ;
	int compare = -1;
	for (int i = 0; i<3; i++)
	{
		cout << "Enter the username of the manager" << endl;
		cin >> usern;
		compare = strcmp(username, usern);
		if (compare == 0)
		{
			cout << "user name verified\n\n";
			cout << "now enter the userpassword of the manager\n" << endl;
			cin >> id;
			if (userpassword == id)
			{
				cout << "Log in successful\n";
				count = 5;
				break;
			}
			else
			{
				if (i <= 1)
				{
					cout << "try again\n";
				}
				else
				{
					cout << "Sorry only 3 wrong tries are allowed\n";
				}
			}

		}
		else
		{

			if (i <= 1)
			{
				cout << "you have entered wrong username\n";
				cout << "try again\n";
			}
			else
			{
				cout << "you have entered wrong username\n";
				cout << "Sorry only 3 wrong tries are allowed\n";
			}

		}




	}

	if (count == 5)
	{
		cout << "\n\t\t\tWelcome To Library Managment System\n\n\n";

		int option;

		do {
			cout << "press 1 to enter menu of general books(without categories)\n";
			cout << "press 2 to enter menu of books with categories\n";
			cout << "Press 3 to enter student registration menu\n";
			cout << "Press 4 to enter bookissue and management menu\n";
			cout << "Press 5 to exit\n";
			cin >> option;
			switch (option)
			{
			case 1:
			{
				generalbookmenu();


				break;
			}
			case 2:
			{
				categorybookmenu();

				break;
			}
			case 3:
			{
				studentregistrationmenu();


				break;
			}
			case 4:
			{
				bookissueandmanagementmenu();


				break; }

			}
		} while (option != 5);
		m1.savebookm();
		m1.savestudentm();
		m1.savebookcategorym();
		return 0;
	}
}
