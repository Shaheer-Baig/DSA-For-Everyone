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
![image](https://github.com/user-attachments/assets/91a1edb6-3af1-41dc-864a-1150fb74aeef)
![image](https://github.com/user-attachments/assets/06cb29a9-1222-4855-b613-6f9e7a9a457c)
![image](https://github.com/user-attachments/assets/e701d5b0-cdbc-4782-98d3-c547558e47ba)
![image](https://github.com/user-attachments/assets/0cfb1ecf-07b3-4713-81b1-59cdd1301d83)
![image](https://github.com/user-attachments/assets/beb9cd0a-657b-4f44-91c7-7d6ae05408c7)
![image](https://github.com/user-attachments/assets/f5b7eaff-39ae-4c1e-9fcd-a3e6bf7dcbc3)
![image](https://github.com/user-attachments/assets/057acb43-8c4f-44a7-8a0e-892a725261da)




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




