# Queues in Data Structures  

## What is a Queue?  
A **queue** is a **linear data structure** that follows the **First In, First Out (FIFO)** principle. This means that the **first element added** to the queue is the **first one to be removed**.  

A **real-world analogy** of a queue is a line of people waiting for service. The person who arrives **first** is the **first** to be served.  

---

## Key Characteristics of Queues  

- **FIFO Structure**: The element that enters first is the first to be removed.  
- **Two Primary Operations**:  
  - **Enqueue**: Adding an element to the end (rear) of the queue.  
  - **Dequeue**: Removing an element from the front of the queue.  
- **Fixed Size or Dynamic**: Queues can be implemented using **arrays** (fixed size) or **linked lists** (dynamic size).  

---

## Why Do We Use Queues?  

Queues are widely used in various computing scenarios due to their efficiency and order-preserving nature. Some common applications include:  

1. **Task Scheduling**:  
   - Operating systems use queues for scheduling tasks and processes.  
   - Jobs are executed in the order they arrive.  

2. **Data Buffering**:  
   - Used in **I/O buffers** where data is stored temporarily before processing.  
   - Example: Print spooling, where multiple print jobs wait in a queue before being printed.  

3. **Graph Traversal Algorithms**:  
   - **Breadth-First Search (BFS)** uses a queue to explore nodes level by level.  

4. **Order Preservation**:  
   - Ensures elements are processed in the same order they arrive.  
   - Used in scenarios like **call center systems** and **network request handling**.  

---

## Time Complexity of Queue Operations  

| Operation   | Time Complexity | Description |
|------------|----------------|-------------|
| **Enqueue** | `O(1)` | Adding an element to the end of the queue takes constant time. |
| **Dequeue** | `O(1)` | Removing an element from the front of the queue takes constant time. |
| **Peek/Front** | `O(1)` | Checking the element at the front of the queue takes constant time. |
| **IsEmpty** | `O(1)` | Checking if the queue is empty takes constant time. |

---

## Enqueue and Dequeue Operations Explained  

### 1. Enqueue Operation  
**Definition**: The enqueue operation adds an element to the rear (end) of the queue.  

#### Process:  
- **Check Capacity**: If using a fixed-size array, verify if the queue is full before adding a new element.  
- **Insert Element**: Add the new element at the position indicated by the rear pointer.  
- **Update Rear Pointer**: Increment the rear pointer to the next position. If using a circular queue, the pointer may wrap around to the beginning.  

#### Example Implementation (C++)  
```cpp
void enqueue(int data) {
    if (rear == size) { // Check if the queue is full
        cout << "Queue is Full" << endl;
    } else {
        arr[rear] = data; // Add data to the rear of the queue
        rear++; // Move the rear pointer forward
    }
}
