//============================================================================
// Name        : no_copy_constructor.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Throw_Obj1 {

	int x;

public:

	Throw_Obj1() { x = 100;}
	Throw_Obj1(const Throw_Obj1&) = default;
	//Throw_Obj1(const Throw_Obj1&) = delete; // This wouldn't compile
											//./src/no_copy_constructor.cpp:44:31:
											//error: use of deleted function
											//‘Throw_Obj1::Throw_Obj1(const Throw_Obj1&)’


};

int func(int);

int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	func(10);

	cout << "_______________________________" << endl;

	func(0);

	cout << "_______________________________" << endl;


	return 0;
}

int func(int x) {

	if (x == 0) throw Throw_Obj1();


	return 0;
}
