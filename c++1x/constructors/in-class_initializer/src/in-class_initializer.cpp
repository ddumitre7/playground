//============================================================================
// Name        : in-class_initializer.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class A {

	int a;
	int b;

public:
	A() : a{7}, b{77} {}

	void print() { cout << "A.a: " << a << " / A.b: " << b << endl; }

};

int counter{0};

class B {

	int a{counter += 10}; // This will not be invoked
	int b;

public:
	B() : a{counter += 11}, b{77} {}

	void print() { cout << "B.a: " << a << " / B.b: " << b << endl; }

};

class C {

	int a{counter += 1000}; // This shall BE invoked
	int b;

public:
	C() : b{77} {}

	void print() { cout << "C.a: " << a << " / C.b: " << b << endl; }

};


int main() {
	cout << "Starting..." << endl; // prints Starting...

	A obj1;

	obj1.print();

	cout << "_________________________________" << endl << endl;

	B obj2;

	obj2.print();

	cout << "_________________________________" << endl << endl;

	C obj3;

	obj3.print();


	return 0;
}
