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

---

### **2. Logarithmic Time Complexity - `O(log n)`**
An algorithm with `O(log n)` complexity reduces the problem size in each step, often seen in divide-and-conquer algorithms like binary search.

#### **Example: Binary Search**

---

### **3. Linear Time Complexity - `O(n)`**
An `O(n)` algorithm processes each element exactly once.

#### **Example: Finding Maximum**

---

### **4. Linearithmic Time Complexity - `O(n log n)`**
Sorting algorithms like Merge Sort and Quick Sort often have this complexity.

#### **Example: Merge Sort**


---

### **5. Quadratic Time Complexity - `O(n^2)`**
Bubble Sort and other nested loop algorithms exhibit `O(n^2)` complexity.

#### **Example: Bubble Sort**

---
### **6. Exponential Time Complexity - O(2^n)**

An O(2^n) algorithm's execution time doubles with each additional input. This complexity is seen in recursive solutions like the Fibonacci sequence.

#### **Example: Recursive Fibonacci Calculation**
---

### **7. Factorial Time Complexity - `O(n!)`**
An `O(n!)` algorithm's execution time grows factorially, making it infeasible for large inputs. This is seen in problems like the Traveling Salesman Problem (TSP).

#### **Example: Generating All Permutations**

