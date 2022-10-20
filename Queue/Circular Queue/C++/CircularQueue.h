#pragma once

#define CIRCULAR_QUEUE
#ifdef CIRCULAR_QUEUE

#include<iostream>

// class template
template <class T>
class CircularQueue {
private:
	int front;
	int rear;
	int size;
	T *items;

public:
	CircularQueue(int size);
	
	void enqueue(T val);
	T dequeue();

	bool isEmpty();

	~CircularQueue();
};

// class implementation
template <class T> CircularQueue<T>::CircularQueue(int s) {
	front = -1;
	rear = -1;
	this->size = s;
	items = new T[size];

}
template <class T> void CircularQueue<T>::enqueue(T val) {
	if (front == 0 && rear == size - 1) {
		std::cout << "overflow\n";
	}
	else if (front && rear == -1) {
		front = 0;
		rear = 0;

		items[rear] = val;
	}
	else if (front != 0 && rear == size - 1) {
		rear = 0;
		items[rear] = val;
	}
	else {
		++rear;
		items[rear] = val;
	}
}

template <class T> T CircularQueue<T>::dequeue() {
	T temp = items[front];

	if (front && rear == -1) {
		std::cout << "Underflow\n";
	}
	else if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == size - 1) {
		front = 0;
	}
	else {
		temp = items[front];
		++front;
	}
	return temp;
}

template <class T> bool CircularQueue<T>::isEmpty() {
	if (rear == -1 && front == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

template <class T> CircularQueue<T>::~CircularQueue() {
	delete items;
}

#endif