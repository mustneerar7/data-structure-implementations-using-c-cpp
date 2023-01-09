/***************************************
    INSERTION SORT
    --------------------------------
    Implementation of INSERTION sort
    algorithm.
 **************************************/
#include <iostream>

using namespace std;

void InsertionSort(int arr[], int n);
void PrintArray(int arr[], int n);


int main(){

    int arr[5] = {5,2,1,4,3};

    PrintArray(arr, 5);
    InsertionSort(arr, 5);
    PrintArray(arr, 5);

    return 0;
}

// Applies insertion sort to provided array
void InsertionSort(int arr[], int n){

    for(int i = 1; i < n; ++i){
        
        int temp = arr[i];
        int j = i - 1;

        while(j >= 0  && temp < arr[j]){
            arr[j+1] = arr[j];
            --j;
        }

        arr[j+1] = temp;
    }

}

// Prints the array
void PrintArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}