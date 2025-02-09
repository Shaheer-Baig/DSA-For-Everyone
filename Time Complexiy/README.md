# Understanding Time Complexity

## **What is Time Complexity?**
Time Complexity is a measure of the computational time an algorithm takes to complete based on input size `n`. It helps determine how an algorithm scales as the input grows.  

The **Big O notation** (e.g., `O(n)`, `O(log n)`) describes time complexity, typically focusing on the worst-case scenario unless otherwise stated.

---

## **Types of Time Complexity**

| Complexity  | Name          | Description |
|------------|--------------|---------------------------------------------|
| `O(1)`     | Constant      | Execution time remains constant, irrespective of input size. |
| `O(log n)` | Logarithmic   | Execution time increases logarithmically as input size grows. |
| `O(n)`     | Linear        | Execution time scales directly with input size. |
| `O(n log n)` | Linearithmic | Execution time grows slightly faster than linear. |
| `O(n^2)`   | Quadratic     | Execution time scales quadratically with input size. |
| `O(2^n)`   | Exponential   | Execution time doubles for each additional input. |
| `O(n!)`    | Factorial     | Execution time grows factorially, making it infeasible for large inputs. |

---

## **Detailed Explanation of Time Complexities**

### **1. Constant Time Complexity - `O(1)`**
An algorithm with `O(1)` complexity runs in the same amount of time, regardless of the input size. This is the most efficient time complexity.

#### **Example: Accessing an array element**
```cpp
int getFirstElement(int arr[]) {
    return arr[0]; // Always takes constant time
}
