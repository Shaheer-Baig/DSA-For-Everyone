#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; // Pointer to the top node

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void Push(int value) {
        Node* newNode = new Node(); // Create new node
        newNode->data = value;
        newNode->next = top; // Link the new node to the previous top
        top = newNode; // Update the top
        cout << value << " pushed into the stack." << endl;
    }

    // Pop operation
    void Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow! No elements to pop." << endl;
            return;
        }
        Node* temp = top; // Store the current top
        top = top->next; // Move top to the next node
        cout << temp->data << " popped from the stack." << endl;
        delete temp; // Free the memory
    }

    // Peek operation
    int Peek() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool IsEmpty() {
	        return top == NULL;
    }
};

int main() {
    Stack s;

    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "Top element: " << s.Peek() << endl;

    s.Pop();
    s.Pop();
    s.Pop();

    if (s.IsEmpty()) {
        cout << "Stack is empty." << endl;
    }

    return 0;
}
