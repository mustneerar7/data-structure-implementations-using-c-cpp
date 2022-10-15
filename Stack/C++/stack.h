#pragma once

#ifndef STACKCLASS
#define STACKCLASS

#include <iostream>

// class template 
template <class T>
class StackClass {
private:
	int top;
	T *nodes;
	int size;

public:
	StackClass(int size);

	bool isEmpty();
	void push(T val);

	T pop();
	T getTop();

	~StackClass();
};

// class implementation
template <class T> StackClass<T>::StackClass(int size)
{
	top = -1;
	this->size = size;
	nodes = new T[size];
};

template <class T> void StackClass<T>::push(T val) {
	if (top ==  this->size - 1) {
		std::cout << "Stack overflow\n";
	}
	else {
		++top;
		nodes[top] = val;
	}
}

template <class T> T StackClass<T>::pop() {
	if (top == -1) {
		std::cout << "Stack underflow\n";
	}
	else {
		T temp = nodes[top];
		--top;
		return temp;
	}
}

template <class T> bool StackClass<T>::isEmpty() {
	if (top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

template <class T> T StackClass<T>::getTop() {
	return nodes[top];
}

template <class T> StackClass<T>::~StackClass() {
	delete nodes;
}

#endif
