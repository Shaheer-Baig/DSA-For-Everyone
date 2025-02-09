#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i =1 ; i < n ; i++) {
        // Outer Loop runs n-1 times
        for (int j = 0; j < n - i ; j++) { 
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); //Swapping
            }
        }
    }
}

int main() {
    int arr[] = { 94, 34, 25, 22, 22, 11, 90 }; // Array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]);     // Calculate the size of the array

    bubbleSort(arr, n);
    cout << "Sorted array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl; 
    return 0;
}
