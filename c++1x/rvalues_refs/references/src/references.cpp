//============================================================================
// Name        : references.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string f() {

	string str = "john";

	transform(str.begin(), str.end(),str.begin(), ::toupper);

	return str;

}

int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	string var = "Abcdefgh";

	cout << "The string is " << f() << endl;

	/*
	string &r_str{f()}; // Compilation error
	cout << "The string is" << r_str << endl;
	 */


	const string &cr_str{f()}; // Compilation error
	cout << "The string is " << cr_str << endl;

	/*
	string &r1{"Mary"}; // Compilation error
	cout << "The string is" << r1 << endl;
	*/

	const string &r1{"Mary"};
	cout << "The string is " << r1 << endl;

	cout << "_____________________________" << endl;

	string &&rr1{f()};
	cout << "The string is " << rr1 << endl;

	/*
	string &&rr2{var}; // Compilation error
	cout << "The string is " << rr2 << endl;
	*/

	string &&rr3{"Chicago"};
	cout << "The string is " << rr3 << endl;

	const string &cr1{"Lyon"};
	cout << "The string is " << cr1 << endl;





	return 0;
}
