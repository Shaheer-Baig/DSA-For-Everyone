#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* prev;
	Node* next;

	//contructor
	Node(int d) {
		this->data = d;
		this->prev = NULL;
		this->next = NULL;

	}


	//destructor
	~Node() {
		int val = this->data;
		if (next != NULL) {
			delete next;
			next = NULL;
		}
		cout << "Memory free for node with Data: " << val << endl;
	}
};
void print(Node*& head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << endl;
}

//give length of Linked list
int getLength(Node*& head) {
	int len = 0;

	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}
	return len;

}
void insertAtHead(Node*&head,Node*& tail, int d) {
	if (head == NULL) {
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else {
		//new node creation
		Node* temp = new Node(d);
		temp->next = head;
		head->prev = temp;
		
			head = temp;
		
	}
}

void insertAtTail(Node*&head,Node*& tail, int d) {
	if (tail == NULL) {
		Node* temp = new Node(d);
		tail = temp;
		head = temp;
	}
	else {
		Node* temp = new Node(d);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}
void insetAtPosition(Node*& head, Node*& tail, int position, int d) {
	//inserting at first position
	if (position == 1) {
		insertAtHead(head,tail, d);
		return;
	}
	
	
	Node* temp = head;
	int cnt = 1;
	while (temp->next != NULL && cnt < position - 1) {
		temp = temp->next;
		cnt++;
	}
	//inserting at last position
	if (temp->next == 0) {
		insertAtTail(head,tail, d);
		return;

	}
	//creating a node to add data
	Node* nodeToInsert = new Node(d);

	nodeToInsert->next = temp->next;
	temp->next->prev = nodeToInsert;
	temp->next = nodeToInsert;
	nodeToInsert->prev = temp;
}

void deleteNode(Node*& head, int position) {
	if (position == 1) {
		Node* temp = head;
		//deleting a node from head
		
		temp->next->prev = NULL;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}
	else {
		Node* previous = head;
		Node* current = head->next;
		int count = 1;
		while (current->next != NULL && count <= position) {
			previous = current;
			current = current->next;
			count++;
		}
		current->prev = NULL;
		previous->next = current->next;
		current->next = NULL;
		delete current;
	}
}


int main() {
	Node* head = NULL;
	Node* tail = NULL;

	print(head);
	//cout << getLength(head) << endl;

	insertAtHead(head, tail, 20);
	print(head);

	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;

	insertAtHead(head, tail, 14);
	print(head);

	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;

	insertAtHead(head, tail, 13);
	print(head);

	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;

	insertAtTail(head, tail, 25);
	print(head);

	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;

	insetAtPosition(head, tail, 1, 101);
	print(head);

	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;

	insetAtPosition(head, tail, 6, 804);
	print(head);

	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;

	deleteNode(head, 6);
	print(head);
	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;


	deleteNode(head, 1);
	print(head);
	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;


	deleteNode(head, 3);
	print(head);
	cout << "Head: " << head->data << endl;;
	cout << "Tail: " << tail->data << endl;;

}
