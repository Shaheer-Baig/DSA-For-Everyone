#include <iostream>
using namespace std;

// Function to partition the array and return the pivot index
int partition(int arr[], int s, int e) {
    int pivot = arr[s];  // pivot element is taken as the first element

    int cnt = 0;
    for (int i = s + 1; i <= e; i++) {  // loop through the array to count elements <= pivot
        if (arr[i] <= pivot) {
            cnt++;
        }
    }

    // place the pivot at its correct position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // handling left and right parts for partitioning
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex) {
        // Increment i until we find an element greater than or equal to the pivot
        while (arr[i] < pivot) {
            i++;
        }

        // Decrement j until we find an element smaller than or equal to the pivot
        while (arr[j] > pivot) {
            j--;
        }

        // If i and j are within bounds, swap the elements
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;  // return the pivot index
}

// QuickSort function to recursively sort the array
void quickSort(int arr[], int s, int e) {
    // base case: if the array has 1 or 0 elements, it's already sorted
    if (s >= e) {
        return;
    }

    // partition the array and get the pivot index
    int p = partition(arr, s, e);

    //sort the left part of the array
    quickSort(arr, s, p - 1);

    //sort the right part of the array
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[] = { 2, 5, 1, 9, 7, 10, 31 };
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    //Output the sorted array
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
