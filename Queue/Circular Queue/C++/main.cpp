#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main() {

	CircularQueue<int> queue = CircularQueue<int>(3);

	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);

	cout << queue.dequeue();
	queue.enqueue(4);

	cout << queue.dequeue();
	cout << queue.dequeue();
	cout << queue.dequeue();

	return 0;
}