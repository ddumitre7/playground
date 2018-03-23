//============================================================================
// Name        : test1.cpp
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
int f(initializer_list<T> &&);

int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	initializer_list<int> d = {12, 12, 14, 45};

	cout << f<int>(move(d)) << endl;

	cout << d.size() << endl;

	return 0;
}

template <typename T>
int f(initializer_list<T> &&l) {

	return l.size();

}
