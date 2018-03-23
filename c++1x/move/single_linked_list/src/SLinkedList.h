/*
 * SSLinkedList.h
 *
 *  Created on: Mar 7, 2018
 *      Author: dan
 */

#ifndef SLINKEDLIST_H_
#define SLINKEDLIST_H_

#include <iostream>
#include  <stdexcept>

#include <utility>

using namespace std;

#define DEBUG_ON

// Forward declarations
template<typename T> class SLinkedList;
template<typename T> void print(const SLinkedList<T> &);

template<typename U>
struct Node {
	U val;
	Node *next;
	Node(const U& a) :
			val { a }, next { nullptr } {
	}
};

template<typename T>
class SLinkedList {

	Node<T> *_head, *_tail;
	size_t _size;

	friend void print<T>(const SLinkedList<T>&);

public:
	SLinkedList();
	SLinkedList(const SLinkedList<T> &);
	SLinkedList(SLinkedList<T> &&);
	~SLinkedList();

	SLinkedList<T>& operator=(const SLinkedList<T> &);
	SLinkedList<T>& operator=(SLinkedList<T> &&);

	SLinkedList<T>& push_front(const T &);
	SLinkedList<T>& push_back(const T &);
	void pop_front();
	T& top();
	SLinkedList<T>& delete_k_th(int k = 1);

	size_t size() {
		return _size;
	}

};

///////////////////////////////////////////////
///////////////////////////////////////////////
///
/// CONSTRUCTORS & ASSIGNMENTS
///
///////////////////////////////////////////////
///////////////////////////////////////////////

template<typename T>
SLinkedList<T>::SLinkedList() :
		_head { nullptr }, _tail { nullptr }, _size { 0 } {

#ifdef DEBUG_ON
	cout << "Entering Default Constructor SLinkedList<T>::SLinkedList()"
			<< endl;

#endif

}

template<typename T>
SLinkedList<T>::SLinkedList(const SLinkedList<T> &l) :
		_head { nullptr }, _tail { nullptr }, _size { 0 } {

#ifdef DEBUG_ON
	cout
			<< "Entering Copy Constructor SLinkedList<T>::SLinkedList(const SLinkedList<T> &)"
			<< endl;
#endif

	Node<T> * cursor { l._head };

	while (cursor) {

		Node<T> *n = new Node<T> { cursor->val };

		if (!_head)
			_head = _tail = n;
		else {
			_tail->next = n;
			_tail = n;
		}

		cursor = cursor->next;
	}

	_size = l._size;

}

template<typename T>
SLinkedList<T>::SLinkedList(SLinkedList<T> &&l) :
		_head { l._head }, _tail { l._tail }, _size { l._size } {

#ifdef DEBUG_ON
	cout
			<< "Entering Move Constructor SLinkedList<T>::SLinkedList(SLinkedList<T> &&)"
			<< endl;
#endif

	l._head = l._tail = nullptr;
	l._size = 0;
}

template<typename T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T> &l) {
#ifdef DEBUG_ON
	cout
			<< "Entering Copy Assignment SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T> &)"
			<< endl;
#endif

	if (this != &l) {

		Node<T> *cursor { l._head };

		while (cursor) {

			Node<T>* n = new Node<T> { cursor->val };

			if (!_head)
				_head = _tail = n;
			else {
				_tail->next = n;
				_tail = n;
			}

			cursor = cursor->next;
		}

		_size = l._size;

	}

	return *this;

}

template<typename T>
SLinkedList<T>& SLinkedList<T>::operator=(SLinkedList<T> &&l) {

#ifdef DEBUG_ON
	cout
			<< "Entering Move Assignment SLinkedList<T>& SLinkedList<T>::operator=(SLinkedList<T> &&)"
			<< endl;
#endif

	swap(_head, l._head);
	swap(_tail, l._tail);
	swap(_size, l._size);

	return *this;
}

///////////////////////////////////////////////
///////////////////////////////////////////////
///
/// METHODS
///
///////////////////////////////////////////////
///////////////////////////////////////////////

template<typename T>
SLinkedList<T>& SLinkedList<T>::push_front(const T &val) {

	Node<T> *n = new Node<T> { val };

	if (!_head)
		_head = _tail = n;
	else {
		n->next = _head;
		_head = n;
	}

	++_size;

	return *this;
}

template<typename T>
SLinkedList<T>& SLinkedList<T>::push_back(const T &val) {

	Node<T> *n = new Node<T> { val };

	if (!_head)
		_head = _tail = n;
	else {
		_tail->next = n;
		_tail = n;
	}

	++_size;

	return *this;
}

template<typename T>
void SLinkedList<T>::pop_front() {

	if (_size <= 0) {

		// throw perhaps?
		return;
	}

	if (_size == 1) {

		delete _head;
		_head = _tail = nullptr;

	} else {

		Node<T> *tmp { _head };
		_head = _head->next;

		delete tmp;
	}

	--_size;

	return;
}

template<typename T>
T& SLinkedList<T>::top() {

	if (_size <= 0)
		throw range_error { "The list is empty" };

	return _head->val;
}

template<typename T>
SLinkedList<T>& SLinkedList<T>::delete_k_th(int k) {

	if ((k <= 0) || !_size || (static_cast<size_t>(k) > _size))
		return *this;

	if (k == 1) {

		SLinkedList<T> *tmp = new SLinkedList<T> { move(*this) };
		delete tmp;

	} else {

		Node<T> *cursor1 { _head }, *cursor2 { _head->next };

		int counter = 1;
		bool flag { _size % k };

		while (cursor2) {

			if (counter == k - 1) {

				cursor1->next = cursor2->next;
				delete cursor2;

				--_size;

				if (!cursor1->next)
					break;
				else {

					counter = 1;
					cursor1 = cursor1->next;
					cursor2 = cursor1->next;
				}
			} else {

				++counter;

				cursor1 = cursor1->next;
				cursor2 = cursor1->next;
			}

			if (!flag)
				_tail = cursor1;

		} // End while
	}

	return *this;
}

///////////////////////////////////////////////
///////////////////////////////////////////////
///
/// DESTRUCTOR
///
///////////////////////////////////////////////
///////////////////////////////////////////////

template<typename T>
SLinkedList<T>::~SLinkedList() {

#ifdef DEBUG_ON
	cout
			<< "Entering DE-structor SLinkedList<T>::~SLinkedList() - delete list with size: "
			<< _size << endl;
#endif

	while (_head) {

		Node<T> *tmp { _head };
		_head = _head->next;

		delete tmp;
	}

	_head = _tail = nullptr;
	_size = 0;
}

template<typename T>
void print(const SLinkedList<T> &l) {

	Node<T> *cursor { l._head };

	while (cursor) {

		cout << cursor->val << " ";
		cursor = cursor->next;

	}

	cout << endl;
}

//template <typename T>
//SLinkedList<T> myFunction(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);

template<typename T>
SLinkedList<int> myFunction(int v1 = 0, int v2 = 0, int v3 = 0, int v4 = 0,
		int v5 = 0, int v6 = 0, int v7 = 0) {

#ifdef DEBUG_ON
	cout << "\t\tIn myFunction..." << endl << endl;
#endif

	SLinkedList<int> l;

	l.push_back(v1).push_back(v2).push_back(v3).push_back(v4);

#ifdef DEBUG_ON
	cout << endl << "\t\tIn myFunction...returning with a list" << endl;
#endif

	return l;

}

template<typename T>
class myType {
	T val;

public:
	myType(T t) :
			val { t } {
	}

	virtual SLinkedList<T> myFunction() {
		SLinkedList<int> l;
		l.push_back(val);
		return l;
	}

	virtual ~myType() {
	}

};

template<typename T>
pair<int, SLinkedList<T>> myFunction1();

template<typename T>
pair<int, SLinkedList<T>> myFunction1(T t) {

#ifdef DEBUG_ON
	cout << "\t*****In myFunction1..." << endl << endl;
#endif

	SLinkedList<T> l;

	l.push_back(t + 1).push_back(t + 11).push_back(t + 12).push_back(t + 13);

#ifdef DEBUG_ON
	cout << endl << "\t*****In myFunction1...returning with a list" << endl;
#endif

	return make_pair(t, l);

}

#endif /* SLINKEDLIST_H_ */
