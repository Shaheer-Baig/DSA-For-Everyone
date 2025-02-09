#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	//constructor
	Node(int d) {
		this->data = d;
		this->next = NULL;
	}

	//destructor
	~Node() {
		int value = this->data;
		//memory free
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
		cout << "Memory is free for node with data " << value << endl;
	}
};
void insertNode(Node* & tail, int element, int d) {
	//assumimg that the element is present in the list

	//if the list is empty
	if (tail == NULL) {
		Node* newNode = new Node(d);
		tail = newNode;
		newNode->next = newNode;

	}
	else {
		//non empty list
		//Assuming that the elememnt in present in the list
		Node* curr = tail;
		while (curr->data != element) {
			curr = curr->next;
		}
		Node* temp = new Node(d);
		temp->next = curr->next;
		curr->next = temp;
	}

}
void print(Node*& tail) {
	Node* temp = tail;
	if (tail == NULL) {
		cout << "List is empty "<<endl;
	}
	do {
		cout << tail->data << " ";
		tail = tail->next;

	} while (tail != temp);
	cout << endl;
}
void deleteNode(Node*&tail,int element) {

	//empty list
	if (tail == NULL) {
		cout << "List is empty , PLease Look again! " << endl;
		return;
	}
	else {
		//if the list is not empty
		//assuming that element is present in the list
		Node* prev = tail;
		Node* curr = prev->next;
		while (curr->data != element) {
			prev = curr;
			curr = curr->next;

		}
		prev->next = curr->next;

		//1 node linked list
		if (curr == prev) {
			tail = NULL;

		}
		//>=2 linked list
		if (tail == curr) {
			tail = prev;
		}
		curr->next = NULL;
		delete curr;
	}
}

int main() {
	Node* tail = NULL;
	insertNode(tail, 5, 3);
	print(tail);

	insertNode(tail, 3, 5);
	print(tail);

	insertNode(tail, 5, 7);
	print(tail);

	insertNode(tail, 3, 4);
	print(tail);

	deleteNode(tail, 3);
	print(tail);

 	
}
