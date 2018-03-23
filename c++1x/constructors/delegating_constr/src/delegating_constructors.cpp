//============================================================================
// Name        : delegating_constructors.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

const int MAX{0xFFFF};

struct Bad_Val {
	Bad_Val(int x) { cout << "Wrong value: " << x << endl; }
};



class X {

	int a;
	void validate(int x) { if (0 < x && x <= MAX) a = x; else throw Bad_Val(x); }

public:

	X(int x) { validate(x); }
	X() { validate(42); }
	explicit X(string s) { int x = stoi(s); validate(x); }

	void print() { cout << "Value X: " << a << endl; }

};

class Y {

	int a;
	void validate(int y) { if (0 < y && y <= MAX) a = y; else throw Bad_Val(y); }

public:

	Y(int y) { validate(y); }
	Y() : Y{42} {}
	Y(string s) : Y{stoi(s)}{}

	void print() { cout << "Value Y: " << a << endl; }

};


int main() {
	cout << "Starting..." << endl; // prints !!!Hello World!!!

	X x1;
	x1.print();

	X x2("5432");
	x2.print();


	X x3(8123);
	x3.print();

	cout << endl;

	Y y1;
	y1.print();

	Y y2("5432");
	y2.print();


	Y y3(8123);
	y3.print();

	return 0;
}
