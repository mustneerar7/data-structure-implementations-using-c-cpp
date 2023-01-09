/***************************************
    QUICK SORT
    --------------------------------
    Implementation of quick sort
    algorithm.
 **************************************/

#include <iostream>

using namespace std;

// PROTOTYPES
void swap(int *a, int *b);
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);


int main()
{
    int arr[5] = {77, 5, 43, 56, 89};
    quickSort(arr, 0, 4);

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";

    return 0;
}

// Swaps two elements
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Partiton the provided array
int partition(int arr[], int start, int end)
{
    int a = arr[end];
    int p_index = start;

    for (int i = start; i < end; ++i)
    {
        if(arr[i] <= a)
        {
            swap(arr[i], arr[p_index]);
            ++p_index;
        }
    }
    swap(arr[p_index], arr[end]);
    return p_index;
}

// Applies quick sort to provided array
void quickSort(int arr[], int start, int end)
{
    int p_index;
    if(start >= end)
    {
        return;
    }

    p_index = partition(arr, start, end);
    quickSort(arr, start, p_index-1);
    quickSort(arr, p_index + 1, end);  
}