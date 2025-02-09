#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        //outer loop runs n-1 times
        int minVal = i;
        // Suppose karliya k min value is at ith index

        //inner loop
        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minVal])
                minVal = j;
        }
        swap(arr[minVal], arr[i]);
    }
}
 

int main() {
    int arr[] = { 94, 34, 25, 22, 22, 11, 90 }; // Array to be sorted
    int n = sizeof(arr) / sizeof(arr[0]);     // Calculate the size of the array

    selectionSort(arr, n);
    cout << "Sorted array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl; 
    return 0;
}
