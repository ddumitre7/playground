//============================================================================
// Name        : vtable.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



class Base
{
public:
    virtual void function1Base() { cout << endl << "function1Base() in Base" << endl; };
    virtual void function2Base() { cout << endl << "function2Base() in Base" << endl; };
    virtual ~Base() {}

private:

    int x{33};
    int y{33};


};

class D1: public /*virtual*/ Base
{
public:
    virtual void function1Base() { cout << endl << "function1Base() in D1" << endl; };
};

class D2: public /*virtual*/ Base
{
public:
    virtual void function2Base() { cout << endl << "function1Base() in D2" << endl; };
    virtual void function1Derived() { cout << endl << "function1Derived() in D2" << endl; };

private:
    int xx{44};
    int yy{55};
};

class DD1: public /*virtual*/ D2
{
public:
    virtual void function2Base() { cout << endl << "function1Base() in DD1" << endl; };
    virtual void function1Derived() { cout << endl << "function1Derived() in DD2" << endl; };
    virtual void function1DerivedDerived() { cout << endl << "function1DerivedDerived() in DD2" << endl; };
};





int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	cout << endl << "1) _______________________________" << endl;

	{
	D1 d1;

	Base *b;

	b = &d1;

	b->function1Base();
	}

	cout << endl << "2 )_______________________________" << endl;

	{
	Base *b1 = new D1;

	b1->function1Base();

	cout << endl << "3) _______________________________" << endl;

	Base *b2 = new D1;
	b2->function1Base();

	Base *b9 = new D2;
	b9->function1Base();


	cout << endl << "Sizeof(B) " << sizeof(*b2) << "    Sizeof(D1) " <<  sizeof(D1)  \
		 << "    Sizeof(D2) " <<  sizeof(D2) \
		 << "    Sizeof(DD1) " <<  sizeof(DD1) << endl;



	}

	cout << endl << "4 )_______________________________" << endl;

	{
	Base *b1 = new D2;

	b1->function1Base();

	D2 *d2 = new DD1;
	d2->function1Base();
	d2->function2Base();
	d2->function1Derived();


	cout << endl << "Sizeof(*b) " << sizeof(*b1) << "    Sizeof(D1) " <<  sizeof(D1)  \
		 << "    Sizeof(D2) " <<  sizeof(D2) \
		 << "    Sizeof(DD1) " <<  sizeof(DD1) << endl;



	}

	cout << endl << "5 )_______________________________" << endl;

	{
		Base *b1;

		D2 *d2 = new DD1;
		d2->function1Base();
		d2->function2Base();
		d2->function1Derived();

		cout << endl << "_ _ _ _ _ _ _" << endl;

		b1 = d2;
		b1->function1Base();
		b1->function2Base();

		cout << endl << "_ _ _ _ _ _ _" << endl;


		DD1 *d5 = new DD1;
		d5->function1DerivedDerived();

		cout << endl << "_ _ _ _ _ _ _" << endl;


		cout << endl << "Sizeof(*b) " << sizeof(*b1) << "    Sizeof(D1) " <<  sizeof(D1)  \
			 << "    Sizeof(D2) " <<  sizeof(D2) \
			 << "    Sizeof(DD1) " <<  sizeof(DD1) << endl;



	}

	cout << endl << "__________________________________" << endl;

	cout << endl << "__________________________________" << endl;
	cout << endl << "____________EPILOG________________" << endl;

	{

		class AA {
		public:
		  int a, aa;
		  virtual void v() {}
		};

		class BB : public virtual AA {
		public:
		  int b, bb;
		  virtual void w() {}
		};

		class CC : public virtual AA {
		public:
		  int c, cc;
		  virtual void x() {}
		};

		class DD : public virtual BB, public virtual CC {
		public:
		  int d, dd;
		  virtual void y() {}
		};

		cout << sizeof(AA) << endl;
		cout << sizeof(BB) << endl;
		cout << sizeof(CC) << endl;
		cout << sizeof(DD) << endl;


		cout << endl << "__________________________________" << endl;




	}

	return 0;
}
