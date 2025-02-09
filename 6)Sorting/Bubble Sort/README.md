# Bubble Sort  

## What is Bubble Sort?  
Bubble Sort is a simple **comparison-based** sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the entire list is sorted.  

## How Bubble Sort Works  
The algorithm works by making multiple passes through the list. In each pass:  
1. It starts from the beginning and compares adjacent elements.  
2. If the first element is **greater** than the second, they are swapped.  
3. It moves to the next pair and repeats the process until the end of the list.  
4. The largest element moves (or "bubbles up") to its correct position at the end.  
5. The process is repeated for the remaining unsorted part of the list until no swaps are needed.  

---

## Example of Bubble Sort  
Consider the following unsorted array:  
[5, 3, 8, 4, 2]

### **Pass 1**  
- Compare `5` and `3` → Swap → `[3, 5, 8, 4, 2]`  
- Compare `5` and `8` → No Swap → `[3, 5, 8, 4, 2]`  
- Compare `8` and `4` → Swap → `[3, 5, 4, 8, 2]`  
- Compare `8` and `2` → Swap → `[3, 5, 4, 2, 8]`  

**Largest element `8` is now at the correct position.**  

### **Pass 2**  
- Compare `3` and `5` → No Swap → `[3, 5, 4, 2, 8]`  
- Compare `5` and `4` → Swap → `[3, 4, 5, 2, 8]`  
- Compare `5` and `2` → Swap → `[3, 4, 2, 5, 8]`  

**Largest element `5` is now in position.**  

### **Pass 3**  
- Compare `3` and `4` → No Swap → `[3, 4, 2, 5, 8]`  
- Compare `4` and `2` → Swap → `[3, 2, 4, 5, 8]`  

**Largest element `4` is now in position.**  

### **Pass 4**  
- Compare `3` and `2` → Swap → `[2, 3, 4, 5, 8]`  

Now the array is completely sorted.

---

## Bubble Sort Algorithm  
```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        bool swapped = false;  
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {  
                swap(arr[j], arr[j + 1]);  
                swapped = true;  
            }
        }
        if (!swapped) break;  // If no swaps, array is already sorted
    }
}
