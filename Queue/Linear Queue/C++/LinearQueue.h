#pragma once 

#define LINEAR_QUEUE
#ifdef LINEAR_QUEUE

#include <iostream>
using namespace std;

// class template
template<class T>
class LinearQueue{
private:
    T *items;
    int size;
    int front;
    int rear;

public:
    LinearQueue(int s);
    ~LinearQueue();

    void enqueue(T val);
    T dequeue();
};

// implementation
template<class T>LinearQueue<T>::LinearQueue(int s){
    front = -1;
    rear = -1;
    items = new T[s];
    this->size = s;
}
template<class T>LinearQueue<T>::~LinearQueue(){
    delete items;
}

// inserts value to queue
template<class T> void LinearQueue<T>::enqueue(T val){
    if(front == 0 && rear == size -1){
        std::cout << "overflow\n";
    }
    else if (front && rear == -1){
        front = 0;
        rear = 0;

        items[rear] = val;
    }

    else{
        ++rear;
        items[rear] = val;
    }
}

// removes element from queue
template<class T> T LinearQueue<T>::dequeue(){
    T temp = items[front];

    if(front && rear == -1){
        std::cout << "underflow\n";
        return 0;
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        temp = items[front];
        ++front;
    }
    return temp;
}

#endif