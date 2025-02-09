#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Check if the queue is empty
    bool IsEmpty() {
        return front == NULL;
    }

    // Push element into the queue
    void Enqueue(int d) {
        // Check if queue is empty
        if (IsEmpty()) {
            cout << "Queued the node with data: " << d << endl;
            front = rear = new Node(d);
        }
        // If the queue is not empty
        else {
            cout << "Queued the node with data: " << d << endl;
            rear->next = new Node(d);
            rear = rear->next;
        }
    }

    // Pop element from the queue
    void Dequeue() {
        // Check if queue is empty
        if (IsEmpty()) {
            cout << "Queue underflow!!" << endl;
        }
        else {
            cout << "Dequeued the node with data: " << front->data << endl;
            Node* temp = front; // Temporary pointer to hold the front node
            front = front->next; // Move front pointer to the next node
            delete temp; // Free the memory of the dequeued node
        }
    }

    // Return the data of the front node
    int start() {
        if (IsEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else {
            return front->data;
        }
    }

    // Print the entire queue
    void PrintQueue() {
        if (IsEmpty()) {
            cout << "Queue is Empty" << endl;
        }
        else {
            Node* current = front; // Start from the front node
            cout << "Queue elements: ";
            while (current != NULL) {
                cout << current->data << " "; // Print each node's data
                current = current->next; // Move to the next node
            }
            cout << endl; // Newline after printing all elements
        }
    }
};

int main() {
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);

    // Print the current queue elements
    q.PrintQueue();

    // Show the front element
    cout << "Front element: " << q.start() << endl;

    // Dequeue some elements
    q.Dequeue();
    q.PrintQueue(); // Print queue after dequeuing
    q.Dequeue();
    q.PrintQueue(); // Print queue after dequeuing again

    return 0;
}
