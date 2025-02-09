### **Vectors in STL (Standard Template Library)**

A **vector** is a dynamic array in C++ that is part of the STL. Unlike arrays, vectors can dynamically resize themselves when elements are inserted or deleted. Vectors provide random access to elements and are a great choice when you need a sequence container that grows and shrinks as needed.

### **Characteristics of Vectors**

1.  **Dynamic Size**: Vectors automatically resize to accommodate new elements, unlike arrays with a fixed size.
    
2.  **Contiguous Memory**: Elements in a vector are stored in contiguous memory locations, allowing for efficient random access.
    
3.  **Efficient Insertion/Deletion at End**: Adding or removing elements at the end of a vector is fast (amortized O(1)).
    
4.  **Allocator Support**: Vectors manage their memory using allocators.
    
5.  **Built-In Functions**: STL provides many member functions to work with vectors easily.
    

### **Declaring a Vector**

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   #include using namespace std;  vector v1;          // Empty vector of integers  vector v2(5);       // Vector of size 5 with default values (0 for int)  vector v3(5, 10);   // Vector of size 5, initialized with value 10  vector v4{1, 2, 3}; // Vector initialized with a list of values   `

### **Commonly Used Functions in Vectors**

### **Capacity Functions**

These functions are used to query the size and capacity of a vector.

1.  **size()**:
    
    *   Returns the number of elements in the vector.
        
    *   cout << v.size(); // Prints the size of the vector
        
2.  **capacity()**:
    
    *   Returns the total capacity of the vector (the amount of memory allocated for it).
        
    *   Capacity is always greater than or equal to the size.
        
3.  **resize()**:
    
    *   Resizes the vector to contain a specified number of elements.
        
    *   v.resize(10); // Resizes the vector to contain 10 elements
        
4.  **empty()**:
    
    *   Checks whether the vector is empty.
        
    *   if (v.empty()) cout << "Vector is empty.";
        
5.  **shrink\_to\_fit()**:
    
    *   Reduces the capacity of the vector to fit its size.
        
    *   v.shrink\_to\_fit();
        

### **Modifiers**

These functions modify the content of the vector.

1.  **push\_back()**:
    
    *   Adds an element to the end of the vector.
        
    *   v.push\_back(10); // Adds 10 to the vector
        
2.  **pop\_back()**:
    
    *   Removes the last element of the vector.
        
    *   v.pop\_back(); // Removes the last element
        
3.  **insert()**:
    
    *   Inserts elements at a specified position.
        
    *   v.insert(v.begin() + 1, 20); // Inserts 20 at index 1
        
4.  **erase()**:
    
    *   Removes elements at a specified position or range.
        
    *   v.erase(v.begin() + 2); // Erases element at index 2v.erase(v.begin(), v.begin() + 3); // Erases first three elements
        
5.  **clear()**:
    
    *   Removes all elements from the vector.
        
    *   v.clear(); // Empties the vector
        
6.  **emplace\_back()**:
    
    *   Constructs and adds an element to the end of the vector (more efficient than push\_back in some cases).
        
    *   v.emplace\_back(30); // Adds 30 to the vector
        
7.  **swap()**:
    
    *   Swaps the contents of two vectors.
        
    *   v1.swap(v2); // Swaps v1 and v2
        

### **Access Functions**

These functions provide ways to access elements in the vector.

1.  **operator\[\]**:
    
    *   Provides direct access to elements.
        
    *   cout << v\[2\]; // Prints the element at index 2
        
2.  **at()**:
    
    *   Accesses elements with bounds checking (throws an exception if out of range).
        
    *   cout << v.at(2); // Prints the element at index 2
        
3.  **front()**:
    
    *   Returns a reference to the first element.
        
    *   cout << v.front(); // Prints the first element
        
4.  **back()**:
    
    *   Returns a reference to the last element.
        
    *   cout << v.back(); // Prints the last element
        

### **Iterators**

Vectors provide iterators to traverse and modify elements.

1.  **begin()** and **end()**:
    
    *   Returns an iterator to the beginning and the end of the vector, respectively.
        
    *   cppCopy codefor (auto it = v.begin(); it != v.end(); ++it) cout << \*it << " ";
        
2.  **rbegin()** and **rend()**:
    
    *   Returns reverse iterators to the beginning and end.
        
    *   cppCopy codefor (auto it = v.rbegin(); it != v.rend(); ++it) cout << \*it << " ";
        
3.  **cbegin(), cend(), crbegin(), crend()**:
    
    *   Return constant iterators that cannot modify elements.
