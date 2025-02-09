#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int val = this->data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with Data: " << val << endl;
    }
};

// Function to print the doubly circular linked list
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to get the length of the doubly circular linked list
int getLength(Node* head) {
    if (head == NULL) {
        return 0;
    }

    int len = 0;
    Node* temp = head;
    do {
        len++;
        temp = temp->next;
    } while (temp != head);

    return len;
}

// Function to insert a node at the head of the doubly circular linked list
void insertAtHead(Node*& head, Node*& tail, int d) {
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        // Make it circular
        head->next = head;
        head->prev = head;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        temp->prev = tail;
        head->prev = temp;
        tail->next = temp;
        head = temp;
    }
}

// Function to insert a node at the tail of the doubly circular linked list
void insertAtTail(Node*& head, Node*& tail, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        // Make it circular
        head->next = head;
        head->prev = head;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        temp->prev = tail;
        tail->next = temp;
        head->prev = temp;
        tail = temp;
    }
}

// Function to insert a node at a specific position in the doubly circular linked list
void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == head) {
        insertAtTail(head, tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// Function to delete a node from the doubly circular linked list
void deleteNode(Node*& head, Node*& tail, int position) {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        if (head == tail) { // Only one node in the list
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    } else {
        Node* current = head;
        Node* previous = NULL;
        int cnt = 1;
        while (cnt < position) {
            previous = current;
            current = current->next;
            cnt++;
        }

        if (current == tail) {
            tail = previous;
        }

        previous->next = current->next;
        current->next->prev = previous;
        current->next = NULL;
        current->prev = NULL;
        delete current;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(head, tail, 20);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    insertAtHead(head, tail, 14);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    insertAtHead(head, tail, 13);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    insertAtTail(head, tail, 25);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    insertAtPosition(head, tail, 1, 101);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    insertAtPosition(head, tail, 6, 804);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(head, tail, 6);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(head, tail, 1);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(head, tail, 3);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}
