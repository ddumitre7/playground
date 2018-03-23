//============================================================================
// Name        : move_test.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

struct A {

    A(const A&) { std::cout << "A(const A&)" << std::endl; }
    A(A&&) { std::cout << "A(A&&)" << std::endl; }
    A() { std::cout << "A()" << std::endl; }
};

A foo(){
    return *new A;
}

A foo1(){
    return A();
}


// -fno-elide-constructors is ON

int main()
{
    A a;
    A c{foo()};
    cout << "_____" << endl;
    A d {foo1()};


}
