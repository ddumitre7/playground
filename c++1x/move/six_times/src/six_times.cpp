//============================================================================
// Name        : six_times.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class P {
public:
    string* ptr_;

    // P() : ptr_{nullptr} { cout<<"constructor empty"<<endl;  }

    P(string name) : ptr_{new string(name)} { cout<<"constructor <" << name << ">" << endl;  }
    ~P() { cout<<"destructor"<<endl; delete ptr_; }
    P(P &&pother) : ptr_{move(pother.ptr_)} {
        cout<<"move"<<endl;
        pother.ptr_ = nullptr;
    }

    P(P &pother) : ptr_{new string{*pother.ptr_}} {
            cout<<"copy"<<endl;
        }
    void print() {cout << *ptr_ << endl;}
};

int main()
{

	int j = 1;
    vector<P> ppl;
    cout << j++ << " Capacity: " << ppl.capacity() << "   Size:" << ppl.size() << endl;;
    ppl.push_back(P("Jojo1"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;;
    ppl.push_back(P("Jojo2"));
    cout << j++ << " Capacity: " << ppl.capacity()<< endl;;
    ppl.push_back(P("Jojo3"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;
    ppl.push_back(P("Jojo4"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;

    cout << " Capacity: " << ppl.capacity() << "   " << ppl.size() << endl;;
    ppl.push_back(P("Jojo5"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;;
    ppl.push_back(P("Jojo6"));
    cout << j++ << " Capacity: " << ppl.capacity()<< endl;;
    ppl.push_back(P("Jojo7"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;
    ppl.push_back(P("Jojo8"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;


    cout << " Capacity: " << ppl.capacity() << "   Size:" << ppl.size() << endl;
    ppl.push_back(P("Jojo9"));
    cout << j++ << " Capacity: " << ppl.capacity()<< endl;;
    ppl.push_back(P("Jojo10"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;
    ppl.push_back(P("Jojo11"));
    cout << j++ << " Capacity: " << ppl.capacity() << endl;


    cout<<"_________________________" << endl;
    cout << "Capacity: " << ppl.capacity() << "   Size:" << ppl.size() << endl;
 }
