#include<stdio.h>

// defined size of queue
#define SIZE 3

// queue structure
struct queue{
    int items[SIZE];
    int front;
    int rear;
};

// initializing queue struct
struct queue q;

// inserts values into queue
void enqueue(int val){
	if (q.front == 0 && q.rear == SIZE - 1) {
		printf("overflow\n");
	}
	else if (q.front && q.rear == -1) {
		q.front = 0;
		q.rear = 0;

		q.items[q.rear] = val;
	}
	else if (q.front != 0 && q.rear == SIZE - 1) {
		q.rear = 0;
		q.items[q.rear] = val;
	}
	else {
		++q.rear;
		q.items[q.rear] = val;
	}
}

// removes values from queue
int dequeue(){
	int temp = q.items[q.front];

	if (q.front && q.rear == -1) {
		printf("underflow\n");
	}
	else if (q.front == q.rear) {
		q.front = -1;
		q.rear = -1;
	}
	else if (q.front == SIZE - 1) {
		q.front = 0;
	}
	else {
		temp = q.items[q.front];
		++q.front;
	}
	return temp;
}

int main(){
    q.front = -1;
    q.rear = -1;

    enqueue(1);
    enqueue(2);
    enqueue(3);

    // will create overflow condition
    enqueue(5);

    dequeue();
    enqueue(4);

    printf("%d \n", dequeue());
    printf("%d \n", dequeue());
    printf("%d \n", dequeue());

    // will create underflow condition
    printf("%d \n", dequeue());
}