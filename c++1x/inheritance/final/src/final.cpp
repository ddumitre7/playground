//============================================================================
// Name        : final.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class B {

	int *p;

public:

	B(int x) : p{new int{x}} { cout << "Constructor Base" << endl; };

	virtual void print();
	virtual ~B() { delete p; cout << "Destructor Base" << endl; }

};


class D /*final*/ : public B {

	int *p;

public:

	D(int x) : B{ x / 10}, p{new int{x}} { cout << "Constructor Derived" << endl; };

	virtual void print() override final;
	virtual ~D() override { delete p; cout << "Destructor Derived" << endl; }

};

class DD : public D {

	int sum() { return 1000; }

	virtual void print() override { cout << "Test" << endl; } // Compilation error here

};



void B::print() {

	cout << "This is Base with value: " << *p << endl;
}

void D::print() {

	cout << "This is Derived with value: " << *p << endl;
}

int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	cout << endl << "1 _____________________________" << endl;

	B *b = new B{80};

	b->print();

	delete b;

	cout << endl << "2 _____________________________" << endl;

	{
		B b1{100};

		b1.print();

	}
	cout << endl << "3 _____________________________" << endl;

	D *d = new D{1000};

	d->print();

	delete d;

	cout << "_______________________________" << endl;
	return 0;
}
