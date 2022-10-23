#pragma once

#define DOUBLE_ENDED_QUEUE
#ifdef DOUBLE_ENDED_QUEUE

#include <iostream>
using namespace std;

// class template
template<class T>
class DoubleEndedQueue{
private:
    T *items;
    int size;
    int front;
    int rear;

public:
    DoubleEndedQueue(int s);
    ~DoubleEndedQueue();

    void enqueue(T val);
    T dequeue();

    void enqueueFront(T val);
    T dequeueBack();
};

// implementation
template <class T> DoubleEndedQueue<T>::DoubleEndedQueue(int s) {
	front = -1;
	rear = -1;

	this->size = s;
	items = new T[s];
}
template <class T> DoubleEndedQueue<T>::~DoubleEndedQueue() {
	delete items;
}

// inserts vales from rear
template <class T> void DoubleEndedQueue<T>::enqueue(T val) {
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

// removes values from front
template <class T> T DoubleEndedQueue<T>::dequeue() {
	T temp = items[front];

	if (front && rear == -1) {
		std::cout << "underflow\n";
        return 0;
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

//[NEW] adds values to front
template<class T> void DoubleEndedQueue<T>::enqueueFront(T val){
    if(front == rear +1){
        cout << "overflow\n";
    }
    else if(front && rear == -1){
        front = 0;
        rear = 0;

        items[front] = val;
    }
    else if(front == 0){
        front = size -1;

        items[front] = val;
    }
    else{
        --front;
        items[front] = val;
    }
}

// [NEWW] removes values ftom rear
template<class T> T DoubleEndedQueue<T>::dequeueBack(){
    T temp = items[rear];

    if (front && rear == -1){
        cout << "underflow\n";
        return 0;
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(rear == 0){
        rear = size - 1;
    }
    else{
        --rear;
    }
    return temp;
}

#endif