# Vectors in STL (Standard Template Library)

A **vector** is a dynamic array in C++ that is part of the STL. Unlike arrays, vectors can dynamically resize themselves when elements are inserted or deleted. Vectors provide random access to elements and are a great choice when you need a sequence container that grows and shrinks as needed.

---

## Characteristics of Vectors

1. **Dynamic Size**: Vectors automatically resize to accommodate new elements, unlike arrays with a fixed size.
2. **Contiguous Memory**: Elements in a vector are stored in contiguous memory locations, allowing for efficient random access.
3. **Efficient Insertion/Deletion at End**: Adding or removing elements at the end of a vector is fast (amortized `O(1)`).
4. **Allocator Support**: Vectors manage their memory using allocators.
5. **Built-In Functions**: STL provides many member functions to work with vectors easily.

---
![image](https://github.com/user-attachments/assets/3632c76e-4236-4f59-9626-2caf3d793b93)




## Declaring a Vector

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> v1;          // Empty vector of integers
vector<int> v2(5);       // Vector of size 5 with default values (0 for int)
vector<int> v3(5, 10);   // Vector of size 5, initialized with value 10
vector<int> v4{1, 2, 3}; // Vector initialized with a list of values

### Explanation:
1. **Close the previous block** using ` ``` `.
2. **Write additional Markdown text** (e.g., a new heading or explanation).
3. **Open a new code block** using ` ```cpp `.
4. **Write your new code** and close it with ` ``` `.




