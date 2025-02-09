#include <iostream>

using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int size;

public:
    Queue() {
        size = 100;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear; // Check if the queue is empty
    }

    void enqueue(int data) {
        if (rear == size) // Check if the queue is full
            cout << "Queue is Full" << endl;
        else {
            arr[rear] = data; // Add data to the rear of the queue
            cout << "Data " << arr[rear] << " is being added in the queue" << endl;
            rear++;
        }
    }

    void dequeue() { // Changed to void
        if (isEmpty()) {
            cout << "Queue is Empty" << endl; // Handle empty queue case
        }
        else {
            cout << "Dequeued: " << arr[front] << endl; // Print dequeued value
            
            front++; // Move front pointer forward
            if (front == rear) { // Reset pointers if queue becomes empty
                front = 0;
                rear = 0;
            }
        }
    }

    void showFront() {
        if (isEmpty())
            cout << "Queue is Empty" << endl;
        else {
            cout << "The front is: " << arr[front] << endl; // Show the value at the front of the queue
        }
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl; // If the queue is empty, print a message
        }
        else {
            cout << "Queue elements: ";
            for (int i = front; i < rear; i++) { // Loop through elements from front to rear
                cout << arr[i] << " "; // Print each element
            }
            cout << endl; // Newline after printing all elements
        }
    }

    ~Queue() {
        delete[] arr; // Free allocated memory
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.printQueue(); // Print current queue elements
    q.showFront();  // Show front of the queue
    q.dequeue();
    q.printQueue(); // Print current queue elements after dequeue
    q.dequeue();
    q.dequeue(); // Testing dequeue on empty queue
    q.printQueue(); // Print queue after all dequeues
    return 0;
}
