//============================================================================
// Name        : initialization_vs_assigment.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;


class X {
	const int i;
	string cl;
	string& rc;

public:

	X(int ii, string& str) : i{ii}, cl{str}, rc{str} { }

	int get_i() {return i;}
};

class Y {
	const int i;
	string cl;
	string& rc;

public:

	Y(int ii, string& str) : i{ii}, cl{str}, rc{str} { }
		// i = ii; }
		//
		// note: ‘const int Y::i’ should be initialized const int i;
		// error: assignment of read-only member ‘Y::i’

	int get_i() {return i;}
};

class Z {
	const int i;
	string cl;
	string& rc;

public:

	Z(int ii, string& str) : i{ii}, cl{str}, rc{str} {}
		//rc = str; }
		//
		// error: uninitialized reference member in ‘std::__cxx11::string& \
		// {aka class std::__cxx11::basic_string<char>&}’ [-fpermissive] \
	  	// Z(int ii, string& str) : i{ii}, cl{str} {
		//note: ‘std::__cxx11::string& Z::rc’ should be initialized string& rc;


	int get_i() {return i;}
};


int main() {
	cout << "Starting..." << endl; // prints !!!Hello World!!!

	string s{"abc"};

	X x{22, s};
	cout << "x.i = " <<  x.get_i() << endl;


	Y y{44, s};
	cout << "y.i = " <<  y.get_i() << endl;


	Z z{66, s};
	cout << "z.i = " <<  z.get_i() << endl;



	return 0;
}
