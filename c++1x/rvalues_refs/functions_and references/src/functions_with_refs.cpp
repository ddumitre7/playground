//============================================================================
// Name        : functions_with_refs.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void f(string &str, int n);
void f(const string &str, int n);
void f(string &&str, int n);

void f(string &str, int n) {

	cout << "void f(string &str)" << endl;

	transform(str.begin(), str.end(),str.begin(), ::toupper);

	cout << str << endl;

	if (n == 1) f(str, 0);

	return;

}

void f(const string &str, int n) {

	cout << "void f(const string &str)" << endl;

	//transform(str.begin(), str.end(),str.begin(), ::toupper);

	cout << str << endl;

	if (n == 1) f(str, 0);

	return;

}

void f(string &&str, int n) {

	cout << "void f(string &&str)" << endl;

	transform(str.begin(), str.end(),str.begin(), ::toupper);

	cout << str << endl;

	if (n == 1) f(str, 0);

	return;

}




int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	string s1 = {"Meri"};

	f(s1, 1);

	const string s2{"Dan"};

	f(s2, 1);

	string &&s3{"John"};
	f(s3, 1);

	string s4{"Raul"};
	string s5{"Helen"};
	f(s4 + s5, 1);

	return 0;




}
