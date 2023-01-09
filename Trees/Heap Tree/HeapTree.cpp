/***************************************
    HEAP TREE
    ------------------------------
    Implementation of heap tree and
    heap sort.
    
***************************************/

#include <iostream>

using namespace std;

#define SIZE 5

// The heap body
int heap[SIZE];
int n = 5;
int root;

// Restores heap property
void minHeap()
{
    int temp1;
    for (int i = 1; i < n; ++i)
    {
        temp1 = i;
        while(temp1 != 0)
        {
            root = (temp1 -1)/2;
            if(heap[root] < heap[temp1])
            {
                int temp = heap[root];
                heap[root] = heap[temp1];
                heap[temp1] = temp;
            }
            temp1 = root;
        }
    }
}

// Deletes the value from heap
int deleteHeap()
{
    int x = heap[0];
    heap[0] = heap[n-1];
    minHeap();
    --n;

    return x;
}

// Basic structure of queue
struct queue
{
    int items[SIZE];
    int F;
    int R;
};

queue q = {{0}, -1 ,-1};

// Adds values to queue
void enqueue(int x)
{
    if(q.F == 0 && q.R == SIZE-1)
        cout << "Overflow\n";
    else if (q.F && q.R == -1)
    {
        q.F = q.R = 0;
        q.items[q.R] = x;
    }
    else if(q.R == SIZE-1 && q.F != 0)
    {
        q.R = 0;
        q.items[q.R] = x;
    }
    else
    {
        ++q.R;
        q.items[q.R] = x;
    }
}

// Removes values from queue
int dequeue()
{
    int temp = q.items[q.F];

    if (q.F && q.R == -1)
        cout << "underflow";
    else if(q.F == q.R)
        q.F = q.R = -1;
    else if(q.F == SIZE-1)
        q.F = 0;
    else
    {
        temp = q.items[q.F];
        ++q.F;
    }
    return temp;
}

int main()
{
    // Inserting values in heap
    for (int i = 0; i < SIZE; ++i)
    {
        int value;
        cout << "Enter " << i + 1 << " value to heap: ";
        cin >> value;
        heap[i] = value;
    }

    // Restoring heap property
    minHeap();

    // Prints the values of heap
    for (int i  =0; i < n; ++i)
        cout << heap[i] << " ";
    cout << endl;

    // Deletes values from heap and
    // add them to queue
    enqueue(deleteHeap());
    enqueue(deleteHeap());
    enqueue(deleteHeap());
    enqueue(deleteHeap());
    enqueue(deleteHeap());

    // Dequeue and print the values
    // also known as Heap Sort
    cout << dequeue() << " ";
    cout << dequeue() << " ";
    cout << dequeue() << " ";
    cout << dequeue() << " ";
    cout << dequeue() << " ";

    return 0;
}