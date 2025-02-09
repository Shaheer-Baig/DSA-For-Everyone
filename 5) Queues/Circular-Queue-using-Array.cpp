#include <iostream>

using namespace std;

class CircularQueue {
    int* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int s = 100) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear; // Queue is empty if front == rear
    }

    bool isFull() {
        return (rear + 1) % size == front; // Queue is full if rear is one step behind front in a circular manner
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
        } else {
            arr[rear] = data; // Add data to the rear of the queue
            cout << "Data " << arr[rear] << " is being added to the queue" << endl;
            rear = (rear + 1) % size; // Move rear to the next position circularly
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Dequeued: " << arr[front] << endl; // Print dequeued value
            front = (front + 1) % size; // Move front to the next position circularly
        }
    }

    void showFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "The front is: " << arr[front] << endl; // Show the value at the front of the queue
        }
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (i != rear) { // Print from front to rear in a circular way
                cout << arr[i] << " ";
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }

    ~CircularQueue() {
        delete[] arr; // Free allocated memory
    }
};

int main() {
    CircularQueue q(5); // Small size for easy testing
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.printQueue(); // Print current queue elements
    q.showFront();  // Show front of the queue
    q.dequeue();
    q.printQueue(); // Print current queue elements after dequeue
    q.enqueue(50);
    q.enqueue(60);  // This should show "Queue is Full" if reached max capacity
    q.printQueue(); // Print queue after all operations
    return 0;
}
