#include <stdio.h>

#define SIZE 3

// structure of queue
struct Queue{
    int items[SIZE];
    int F;
    int R;
};

// inserts value to the queue (enqueue)
void insert(struct Queue *q, int val){
    if (q->F && q->R == -1){
        q->F = 0;
        q->R = 0;

        q->items[q->R] = val;
    }
    else if (q->F == 0 && q->R == SIZE-1){
        printf("overflow\n");
    }
    else{
        ++q->R;
        q->items[q->R] = val;
    }
}

// removes value from queue (dequeue)
int remove(struct Queue *q){
    int val = q->items[q->F];

    if(q->F && q->R == -1){
        printf("underflow\n");
        return 0;
    }
    else if (q->R == q->F){
        q->F = -1;
        q->R = -1;
    }
    else{
        val = q->items[q->F];
        ++q->F;
    }
    return val;
}

int main(void){

    struct Queue queue;

    queue.F = -1;
    queue.R = -1;

    insert(&queue, 1);
    insert(&queue, 2);
    insert(&queue, 3);

    // would create overflow
    insert(&queue, 4);

    printf("%d\n", remove(&queue));
    printf("%d\n", remove(&queue));
    printf("%d\n", remove(&queue));

    // would create underflow
    printf("%d\n", remove(&queue));
}