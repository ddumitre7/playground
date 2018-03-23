//============================================================================
// Name        : vtable2.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A {
public:
  int a1;
  int a2;
  virtual void a() { cout << endl << "A::a()" << endl; }
};

class B : public A {
public:
  int b1, b2;
  virtual void b() { cout << endl << "B:A::b()" << endl; }
};

class C : public A {
public:
  int c1, c2;
  virtual void c() { cout << endl << "C:A::c()" << endl; }
};

class D : public B, public C {
public:
  int d1, d2;
  virtual void d() { cout << endl << "DD:B,C::d()" << endl; }
};


class A_prime {
public:
  int a1;
  int a2;
  virtual void a() { cout << endl << "A::a()" << endl; }
  virtual ~A_prime() {}
};

class B_prime : public virtual A_prime {
public:
  int b1, b2;
  virtual void b() { cout << endl << "B:A::b()" << endl; }
  virtual ~B_prime() {}
};

class C_prime : public virtual A_prime {
public:
  int c1, c2;
  virtual void c() { cout << endl << "C:A::c()" << endl; }
  virtual ~C_prime() {}
};

class D_prime : public B_prime, public C_prime {
public:
  int d1, d2;
  virtual void d() { cout << endl << "DD:B,C::d()" << endl; }
  virtual ~D_prime() {}
};



int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n

	cout << endl << "Sizeof(A) " << sizeof(A) << endl;
	cout << endl << "Sizeof(B) " << sizeof(B) << endl;
	cout << endl << "Sizeof(C) " << sizeof(C) << endl;
	cout << endl << "Sizeof(D) " << sizeof(D) << endl;

	cout << endl << endl << "________________________________________" << endl << endl;

	cout << endl << "Sizeof(A_prime) " << sizeof(A_prime) << endl;
	cout << endl << "Sizeof(B_prime) " << sizeof(B_prime) << endl;
	cout << endl << "Sizeof(C_prime) " << sizeof(C_prime) << endl;
	cout << endl << "Sizeof(D_prime) " << sizeof(D_prime) << endl;

	cout << endl << endl << "________________________________________" << endl << endl;

	{
		// ++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/vtable2.d" -MT"src/vtable2.o" -o "src/vtable2.o" "../src/vtable2.cpp"
		//../src/vtable2.cpp: In function ‘int main()’:
		//../src/vtable2.cpp:87:16: error: ‘A’ is an ambiguous base of ‘D’
		//   A *a = new D{};

		cout << endl << "1) _ _ _ _ _ _" << endl;

		//A *a = new D{};

		//a->a();

		cout << endl << "2) _ _ _ _ _ _" << endl;

		B *b = new D{};

		b->a();

		cout << endl << "3) _ _ _ _ _ _" << endl;

		D *d = new D{};

		//d->a(); //Error - ambigous again

		d->b();
		d->c();
		d->d();
	}

		cout << endl << endl << "________________________________________" << endl << endl;

		{

		cout << endl << "1) _ _ _ _ _ _" << endl;

		A_prime *a = new D_prime{};

		a->a();

		cout << endl << "2) _ _ _ _ _ _" << endl;

		B_prime *b = new D_prime{};

		b->a();

		cout << endl << "3) _ _ _ _ _ _" << endl;

		D_prime *d = new D_prime{};

		d->a();

		d->b();
		d->c();
		d->d();

		}

		cout << endl << endl << "________________________________________" << endl << endl;







	return 0;

}
