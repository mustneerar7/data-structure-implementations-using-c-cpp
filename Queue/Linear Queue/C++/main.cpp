#include <iostream>
#include "LinearQueue.h"

using namespace std;

int main(){
    LinearQueue<int> queue = LinearQueue<int>(3);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // generates overflow
    queue.enqueue(4);

    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

    // generated underflow
    cout << queue.dequeue() << endl;

}
