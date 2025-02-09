# Quick Sort

## What is Quick Sort?
Quick Sort is a **divide and conquer** sorting algorithm that selects a **pivot element**, partitions the array around the pivot, and recursively sorts the left and right subarrays.

It follows these three steps:
1. **Choose a Pivot:** Select an element from the array (e.g., first, last, middle, or randomly).
2. **Partitioning:** Rearrange elements so that:
   - Elements **less than** the pivot move to the left.
   - Elements **greater than** the pivot move to the right.
3. **Recursively Sort:** Apply Quick Sort to the left and right partitions.

Unlike Merge Sort, Quick Sort is **in-place** and generally performs better on average.

---

## How Quick Sort Works  
### Example: Sorting `[8, 4, 7, 3, 5, 2]`

### **Step 1: Choose a Pivot**
Let’s pick the last element as the pivot (`2`).
Pivot = 2 [8, 4, 7, 3, 5, 2]


### **Step 2: Partitioning**
- Move elements smaller than the pivot to the left.
- Move elements greater than the pivot to the right.

After partitioning:
[2, 4, 7, 3, 5, 8] (Pivot placed correctly)

Now, apply Quick Sort **recursively** to `[4, 7, 3, 5]` and `[8]`.

### **Step 3: Recursively Sorting Left & Right**
- **Sorting `[4, 7, 3, 5]`:**
  - Pivot = `5`
  - Partition: `[3, 4, 5, 7]`
  - Recursively sort `[3, 4]` and `[7]`.

- **Sorting `[8]`** (Already sorted)

Final sorted array:
[2, 3, 4, 5, 7, 8]

---

## Quick Sort Algorithm  

### **Recursive Quick Sort (C++ Implementation)**
```cpp
// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Move smaller elements to the left
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1;
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Main function to test Quick Sort
int main() {
    int arr[] = {8, 4, 7, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}


