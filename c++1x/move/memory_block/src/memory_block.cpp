//============================================================================
// Name        : memory_block.cpp
// Author      : Dan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "MemoryBlock.h"

using namespace std;

int main() {
	cout << "Starting...\n" << endl; // prints Starting...\n


	// Create a vector object and add a few elements to it.
	vector<MemoryBlock> v(10);
	cout << "1) ________________" << endl;

	v.push_back(MemoryBlock{25});

	cout << "2) ________________" << endl;

	v.push_back(MemoryBlock{75});

	cout << "3) ________________" << endl;

	// Insert a new element into the second position of the vector.
	v.insert(v.begin() + 2, MemoryBlock{50});

	cout << "4) ________________" << endl;

	return 0;
}
