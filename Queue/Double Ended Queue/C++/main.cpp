#include <iostream>
#include "DoubleEndedQueue.h"

using namespace std;

int main(){
    DoubleEndedQueue<char> queue = DoubleEndedQueue<char>(3);

    queue.enqueueFront('A');
    queue.enqueueFront('B');
    queue.enqueueFront('C');

    // generates overflow
    queue.enqueueFront('D');

    cout << queue.dequeueBack() << endl;    
    cout << queue.dequeueBack() << endl;   
    cout << queue.dequeueBack() << endl;   

    // generates underflow
    cout << queue.dequeueBack() << endl;
}