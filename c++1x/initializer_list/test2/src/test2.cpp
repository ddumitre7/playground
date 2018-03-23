//============================================================================
// Name        : test2.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

template <typename T>
struct S {

	S(size_t n) : x{n} { cout << "S(size_t n)" << endl; }

	S(initializer_list<T> l) : x{l.size()} {

		cout << "S(initializer_list<T> l)" << endl;
	}

	S(vector<T> &v) : x{v.size()} {

		cout << "S(vector<T> &v)" << endl;
	}


	S(const vector<T> &v) : x{v.size()} {

			cout << "S(const vector<T> &v)" << endl;
		}


	size_t getter_X() {return x;}


private:
	size_t x;
};

int main() {
	cout << endl << "Starting...\n" << endl; // prints Starting...\n

	cout << endl << "1)____________________________________________________" << endl;

	S<int> s{10, 20, 30};

	cout << s.getter_X() << endl;

	cout << endl << "2)____________________________________________________" << endl;

	//vector v{12, 12, 45, 45, 45};

	S<int> s1{vector<int>{12, 12, 12, 12,22 ,121, 1212}};

	cout << s1.getter_X() << endl;

	cout << endl << "3)____________________________________________________" << endl;

	vector<int> v{12, 12, 45, 45, 45};

	S<int> s2{v};

	cout << s2.getter_X() << endl;

	cout << endl << "3)____________________________________________________" << endl;


	S<int> s3{10};

	cout << s3.getter_X() << endl;


	cout << endl << "3)____________________________________________________" << endl;


	S<int> s4(10);

	cout << s4.getter_X() << endl;

	cout << endl << "____________________________________________________" << endl;

	return 0;
}
