# Selection Sort  

## What is Selection Sort?  
Selection Sort is a simple **comparison-based** sorting algorithm that divides the input list into two parts:  
- A **sorted sublist** (built from left to right).  
- An **unsorted sublist** (elements yet to be sorted).  

The algorithm repeatedly **selects the smallest element** from the unsorted sublist and swaps it with the first element of the unsorted part. This process continues until the list is completely sorted.  

---

## How Selection Sort Works  
The algorithm follows these steps:  
1. Start with an **unsorted list** and divide it into two parts: sorted and unsorted.  
2. Find the **smallest element** in the unsorted part.  
3. Swap this smallest element with the first element of the unsorted part.  
4. Move the boundary between sorted and unsorted sublists one step to the right.  
5. Repeat the process for the remaining unsorted elements until the entire list is sorted.  

---

## Example of Selection Sort  
Consider the following unsorted array:  
[7, 4, 10, 8, 3]

### **Pass 1**  
- Find the **smallest element** → `3`  
- Swap `3` with the first element `7`  
- New array: `[3, 4, 10, 8, 7]`  

### **Pass 2**  
- Find the smallest in `[4, 10, 8, 7]` → `4` (already in correct position)  
- No swap needed  
- New array: `[3, 4, 10, 8, 7]`  

### **Pass 3**  
- Find the smallest in `[10, 8, 7]` → `7`  
- Swap `7` with `10`  
- New array: `[3, 4, 7, 8, 10]`  

### **Pass 4**  
- Find the smallest in `[8, 10]` → `8` (already in correct position)  
- No swap needed  
- Array remains `[3, 4, 7, 8, 10]`  

Now the array is completely sorted.  

---

## Selection Sort Algorithm  
### **C++ Implementation**  
```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

