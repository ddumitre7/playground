//============================================================================
// Name        : single_linked_list.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <utility>
#include <vector>

#include "SLinkedList.h"

using namespace std;

//M myFunction1();
//pair<int, SLinkedList> myFunction1();

int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n
	cout << "-fno-elide-constructors is always ON" << endl << endl;

	cout << "0) ___________________________________" << endl << endl;

	{
		cout << endl << "MOVE CONSTRUCTOR DEMO (-fno-elide-constructors ON)"
				<< endl << endl;
		SLinkedList<int> l3 = myFunction<int>(34, 34, 44, 55, 55);

		cout << "\tThe list is (SIZE " << l3.size() << "): " << endl << "\t";

		print(l3);

		//l3.push_back(190).push_back(191).push_back(192).push_back(193);

		cout << endl;
	}

	cout << "0.1) ___________________________________" << endl << endl;

	{
		cout << endl << "MOVE CONSTRUCTOR DEMO" << endl << endl;

		myType<int> *t = new myType<int> { 99 };

		SLinkedList<int> l3 = t->myFunction();

		cout << "\tThe list is (SIZE " << l3.size() << "): " << endl << "\t";

		print(l3);

		l3.push_back(190).push_back(191).push_back(192).push_back(193);

		cout << endl;
	}

	cout << "1) ___________________________________" << endl << endl;

	{
		cout << endl << "MOVE ASSIGNMENT DEMO" << endl << endl;
		SLinkedList<int> l33;
		l33 = myFunction<int>(34, 34, 44, 55, 55);

		cout << "\tThe list is (SIZE " << l33.size() << "): " << endl << "\t";

		print(l33);

		cout << endl;
	}

	cout << "2) ___________________________________" << endl << endl;
	{
		cout << endl << "MOVE CONSTRUCTOR DEMO - I" << endl << endl;

		SLinkedList<int> l5;
		l5.push_back(1900).push_back(1910).push_back(1920).push_back(1930);

		cout << "	2.1) ___________________________________" << endl << endl;

		SLinkedList<int> l4 = move(l5);

		cout << "\tThe list l4 is (SIZE " << l4.size() << "): " << endl << "\t";

		print(l4);
		cout << endl;

		l4.push_back(8800).push_back(8810).push_back(8820).push_back(8830);

		cout << "	2.2) ___________________________________" << endl << endl;

		SLinkedList<int> l6 { l4 };

		cout << "\tThe list l6 is (SIZE " << l6.size() << "): " << endl << "\t";

		print(l6);
		cout << endl;

	}

	cout << "3) ___________________________________" << endl << endl;
	{
		cout << endl << "MOVE CONSTRUCTOR DEMO - II" << endl << endl;

		pair<int, SLinkedList<int>> m = myFunction1<int>(100);
		//pair<int, SLinkedList<int>> m = move(myFunction1<int>(100));

		cout << "m is: " << m.first << endl << endl;

		cout << "\tThe list is (SIZE " << m.second.size() << "): " << endl
				<< "\t";

		print(m.second);

		cout << endl;

	}

	cout << "4) ___________________________________" << endl << endl;
	{
		cout << endl << "MOVE CONSTRUCTOR DEMO - III" << endl << endl;
		SLinkedList<int> l7 = move(myFunction<int>());

		cout << "\tThe list is (SIZE " << l7.size() << "): " << endl << "\t";

		print(l7);
		cout << endl;
	}

	cout << "5) ___________________________________" << endl << endl;

	{
		cout << endl << "MOVE CONSTRUCTOR DEMO - IV" << endl << endl;
		SLinkedList<int> l7 { SLinkedList<int> { } };

		cout << "\tThe list is (SIZE " << l7.size() << "): " << endl << "\t";

		print(l7);

		cout << endl;

		cout << "6) ___________________________________" << endl << endl;

		{
			cout << endl << "MOVE CONSTRUCTOR DEMO - V" << endl << endl;
			//vector<SLinkedList> v;
			//v.push_back(SLinkedList{"10001"});

			vector<SLinkedList<int>> v { SLinkedList<int> { } };

			cout << "\tThe list is (SIZE " << v[0].size() << "): " << endl
					<< "\t";

			while (v[0].size()) {

				cout << v[0].top() << " ";

				v[0].pop_front();
			}

			cout << endl;
		}

		cout << "7) ___________________________________" << endl << endl;

		{
			cout << endl << "MOVE CONSTRUCTOR DEMO - VI" << endl << endl;
			SLinkedList<int> l7 { SLinkedList<int> { } };

			cout << "\tThe list is (SIZE " << l7.size() << "): " << endl
					<< "\t";

			print(l7);

			cout << endl;

		}

		cout << "________ THE END __________________________" << endl << endl;

	}

	return 0;
}

