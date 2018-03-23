//============================================================================
// Name        : return_type_relaxation.cpp
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
	virtual int getData() {return *p;}
	virtual ~B() { delete p; cout << "Destructor Base" << endl; }

	virtual B* clone(int x) { return new B{*p + x}; };
};


class D : public B {

	int *p;

public:

	D(int x) : B{ x / 10}, p{new int{x}} { cout << "Constructor Derived" << endl; };

	virtual void print() override;
	virtual int getData() {return *p;}
	virtual ~D() override { delete p; cout << "Destructor Derived" << endl; }

	D* clone(int x) { return new D{*p + x}; };
};




void B::print() {

	cout << "This is Base. Who are you?" << endl;
}

void D::print() {

	cout << "This is Derived. Who are you?" << endl;
}

int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	cout << endl << "0 _____________________________" << endl;

	B *b = new B{80};

	b->print();

	delete b;

	cout << endl << "1 _____________________________" << endl;

	{
		B b1{100};

		b1.print();

	}
	cout << endl << "2 _____________________________" << endl;

	D *d = new D{1000};

	d->print();

	delete d;

	cout << endl << "3 _____________________________" << endl;


	B *d1 = new D{1000};

	d1->print();

	delete d1;

	cout << endl << "4 __Return Type Relaxation Here" << endl;

	{
		B *d2 = new D{3330};

		B &tmp = *d2->clone(12);

		delete d2;

		delete &tmp;

	}

	cout << "_______________________________" << endl;
	return 0;
}
