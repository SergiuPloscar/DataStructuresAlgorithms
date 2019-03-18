#include <string>
#include <iostream>
#include "SMM.h"
#include "Test.h"
using namespace std;

void showEmails( SortedMultiMap smm)
{
	Iterator i{ smm };
	bool isEmpty = true;
	while (i.valid())
	{
		isEmpty = false;
		cout << "To: " << i.getCurrent()->key << endl;
		cout << i.getCurrent()->value << endl << endl;
		i.next();
	}
	if (isEmpty == true)
	{
		cout << "There are no emails to show";
		cout << endl;
	}
} 
int main()
{
	Test t;
	t.testAll();
	cout << "Welcome to the email database. Please select an option from the ones available" << endl;
	SortedMultiMap smm{ SortedMultiMap::Alphabetical };
	int op=-1;
	while (op != 0)
	{
		cout << endl;
		cout << "Press 0 to exit the program" << endl;
		cout << "Press 1 to send an email " << endl;
		cout << "Press 2 to see all emails received by an address" << endl;
		cout << "Press 3 to see all emails " << endl;
		cin >> op;
		cout << endl;
		if (op == 0)
			break;
		else if (op == 1)
		{
			cin.ignore(100, '\n');
			string k, v,empty;
			cout << "To: ";
			getline(cin, k);
			getline(cin, v);
			smm.add(k, v);
			cout << endl;
		}
		else if (op == 2)
		{
			cin.ignore(100, '\n');
			cout << "What is the address ?" << endl;
			string address;
			getline(cin, address);
			cout << endl;
			vector<string> l;
			smm.search(address, l);
			int nr = 0;
			for (auto email : l)
			{
				cout << nr << ". " << email << endl;
				nr++;
			}
			if (nr == 0)
			{
				cout << "There are no emails at this address" << endl;
			}
		}
		else if (op == 3)
		{
			showEmails(smm);
		}
		else
		{
			cout << "Please select a valid option";
		}
	} 
}