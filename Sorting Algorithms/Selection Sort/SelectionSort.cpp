/***************************************
    SELECTION SORT
    --------------------------------
    Implementation of selection sort
    algorithm.
 **************************************/
#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n);
void PrintArray(int arr[], int n);


int main(){
    
    int arr[5] = {5, 2, 1, 4, 3};

    PrintArray(arr, 5);
    SelectionSort(arr, 5);
    PrintArray(arr, 5);

    return 0;
}

// Applies selection sort to provided array
void SelectionSort(int arr[], int n){
    
    for (int i = 0; i < n; ++i){

        int min = arr[i];
        int jp = i;

        for (int j = i + 1; j < n; ++j){
            if(arr[j] < min){
                min = arr[j];
                jp = j;
            }
        }
        
        arr[jp] = arr[i];
        arr[i] = min;
        
    }
}

// Prints the array
void PrintArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}