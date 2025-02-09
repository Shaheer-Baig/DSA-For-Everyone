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
# Commonly Used Functions in Vectors

This document provides an overview of commonly used functions in C++ vectors, including capacity functions, modifiers, access functions, and iterators.

---

## Capacity Functions
These functions are used to query the size and capacity of a vector.

### `size()`
Returns the number of elements in the vector.

```cpp
cout << v.size();  // Prints the size of the vector
capacity()
Returns the total capacity of the vector (the amount of memory allocated for it).
Capacity is always greater than or equal to the size.

cpp
Copy
cout << v.capacity();  // Prints the capacity of the vector
resize()
Resizes the vector to contain a specified number of elements.

cpp
Copy
v.resize(10);  // Resizes the vector to contain 10 elements
empty()
Checks whether the vector is empty.

cpp
Copy
if (v.empty()) 
    cout << "Vector is empty.";
shrink_to_fit()
Reduces the capacity of the vector to fit its size.

cpp
Copy
v.shrink_to_fit();
Modifiers
These functions modify the content of the vector.

push_back()
Adds an element to the end of the vector.

cpp
Copy
v.push_back(10);  // Adds 10 to the vector
pop_back()
Removes the last element of the vector.

cpp
Copy
v.pop_back();  // Removes the last element
insert()
Inserts elements at a specified position.

cpp
Copy
v.insert(v.begin() + 1, 20);  // Inserts 20 at index 1
erase()
Removes elements at a specified position or range.

cpp
Copy
v.erase(v.begin() + 2);  // Erases element at index 2
v.erase(v.begin(), v.begin() + 3);  // Erases first three elements
clear()
Removes all elements from the vector.

cpp
Copy
v.clear();  // Empties the vector
emplace_back()
Constructs and adds an element to the end of the vector (more efficient than push_back() in some cases).

cpp
Copy
v.emplace_back(30);  // Adds 30 to the vector
swap()
Swaps the contents of two vectors.

cpp
Copy
v1.swap(v2);  // Swaps v1 and v2
Access Functions
These functions provide ways to access elements in the vector.

operator[]
Provides direct access to elements.

cpp
Copy
cout << v[2];  // Prints the element at index 2
at()
Accesses elements with bounds checking (throws an exception if out of range).

cpp
Copy
cout << v.at(2);  // Prints the element at index 2
front()
Returns a reference to the first element.

cpp
Copy
cout << v.front();  // Prints the first element
back()
Returns a reference to the last element.

cpp
Copy
cout << v.back();  // Prints the last element
Iterators in Vectors
Vectors provide iterators to traverse and modify elements.

begin() and end()
Returns an iterator to the beginning and the end of the vector, respectively.

cpp
Copy
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
rbegin() and rend()
Returns reverse iterators to the beginning and end.

cpp
Copy
for (auto it = v.rbegin(); it != v.rend(); ++it)
    cout << *it << " ";
cbegin(), cend(), crbegin(), crend()
Return constant iterators that cannot modify elements.

cpp
Copy
for (auto it = v.cbegin(); it != v.cend(); ++it)
    cout << *it << " ";  // Cannot modify elements







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




