#include <stdio.h>

// queue size
#define SIZE 4

// base queue structure
struct queue
{
    int items[SIZE];
    int front; 
    int rear;
};

// queue declaration
struct queue q = {{0}, -1, -1};

// inserts vales from rear
void enqueue(int val){
    if (q.front == 0 && q.rear == SIZE -1){
        printf("overflow\n");
    }
    else if (q.front && q.rear == -1){
        q.front = 0;
        q.rear = 0;

        q.items[q.rear] = val;
    }
    else if (q.front !=0 && q.rear == SIZE-1){
        q.rear = 0;

        q.items[q.rear] = 0;
    }
    else{
        ++q.rear;
        q.items[q.rear] = val;
    }
}

// removes values from front
int dequeue(){
	int temp = q.items[q.front];

	if (q.front && q.front == -1) {
		printf("underflow\n");
        return 0;
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

// [NEW] inserts values from front
void enqueueFromFront(int val){

    if (q.front == q.rear + 1){
        printf("overflow\n");
    }
    else if(q.rear && q.front == -1){
        q.front = 0;
        q.rear = 0;

        q.items[q.front] = val;
    }
    else if(q.front == 0){
        q.front = SIZE -1;
        q.items[q.front] = val;
    }
    else{
        --q.front;
        q.items[q.front] = val;
    }
}

// [NEW] removes values from rear
int dequeueFromRear(){
    int temp = q.items[q.rear];

	if (q.front && q.front == -1) {
		printf("underflow\n");
        return 0;
	}
    else if (q.front == q.rear){
        q.front = -1;
        q.rear = -1;
    }
    else if (q.rear == 0){
        q.rear = SIZE -1;
    }
    else{
        --q.rear;
    }
    return temp;
}

int main(){

    enqueueFromFront(2);
    enqueueFromFront(3);
    enqueueFromFront(4);
    enqueueFromFront(5);

    // creates overflow condition
    enqueueFromFront(6);

    printf("%d\n", dequeueFromRear());
    printf("%d\n", dequeueFromRear());
    printf("%d\n", dequeueFromRear());
    printf("%d\n", dequeueFromRear());

    // creates underflow condition
    printf("%d\n", dequeueFromRear());
}