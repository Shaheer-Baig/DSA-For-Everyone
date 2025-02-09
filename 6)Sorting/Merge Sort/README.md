# Merge Sort

## What is Merge Sort?
Merge Sort is a **divide and conquer** sorting algorithm that recursively splits an array into smaller subarrays, sorts them, and then merges the sorted subarrays to produce the final sorted array.  

It follows these three key steps:  
1. **Divide:** Split the array into two halves until each subarray contains a single element.  
2. **Conquer:** Recursively sort the smaller subarrays.  
3. **Merge:** Combine the sorted subarrays to form a single sorted array.  

This process ensures a **consistent time complexity of O(n log n)** across all cases.

---

## How Merge Sort Works  
### Example: Sorting the array `[6, 3, 8, 5, 2, 7, 4, 1]`

### **Step 1: Divide**
Split the array into two halves:
[6, 3, 8, 5] | [2, 7, 4, 1]
Keep splitting recursively until each subarray contains a **single element**:
[6] [3] [8] [5] | [2] [7] [4] [1]
Merge further:
[3, 5, 6, 8] | [1, 2, 4, 7]
Final Merge:
[1, 2, 3, 4, 5, 6, 7, 8] (Sorted)


---

## Merge Sort Algorithm  

### **Recursive Merge Sort (C++ Implementation)**
```cpp
#include <iostream>
using namespace std;

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Recursive function to apply Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Main function to test Merge Sort
int main() {
    int arr[] = {6, 3, 8, 5, 2, 7, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
