//============================================================================
// Name        : copy_operaations.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <memory>
#include <string>

using namespace std;


template<class T>
class Matrix {

	string s{"*****"};

	array<int, 2> dim; // two dimensions
	T* elem; // pointer to dim[0]*dim[1] elements of type T

public:

	Matrix(int d1, int d2);// simplified (no error handling)
	Matrix(const Matrix&); // copy constructor
	Matrix& operator=(const Matrix&); // copy assignment
	Matrix(Matrix&&) = default;
	Matrix& operator=(Matrix&&) = default;
	~Matrix() { delete []elem; cout << "DESTRUCTOR CONSTRUCTOR" << endl; }

	int size() const { return dim[0] * dim[1]; }

};


template<class T>Matrix<T>::Matrix(int d1, int d2) : elem{new T[d1*d2]}
{
	dim[0] = d1; dim[1] = d2;

	cout << "NORMAL CONSTRUCTOR" << endl;
}


template<class T>Matrix<T>::Matrix(const Matrix& m) : dim{m.dim}, elem{new T[m.size()]}
{
	uninitialized_copy(m.elem,m.elem+m.size(),elem);

	cout << "COPY CONSTRUCTOR" << endl;
}



template<class T>Matrix<T>& Matrix<T>::operator=(const Matrix& m) // copy assignment
{

	cout << "COPY ASSIGMENT" << endl;

	if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
		throw runtime_error("bad size in Matrix =");

	copy(m.elem, m.elem+m.size(), elem); // copy elements

	return *this;
}


int main() {
	cout << "Starting... \n" << endl; // prints Starting...\n

	Matrix<int> m{12, 12};

	Matrix<int> n{12, 12};


	m = n;


	return 0;
}
