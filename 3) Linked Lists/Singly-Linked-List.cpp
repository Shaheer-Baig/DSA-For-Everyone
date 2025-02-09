
//Creation
#include<iostream>
using namespace std;
class Node { //class created
public:
	int data;
	Node* next;//node* name ka ptr hy
	//jo next node ko point karay ga;

	Node(int value) {    //contructor banaya 
		this->data = value;
		this->next = nullptr;
	}
	// Destructor banaya
	//isko abhi start may nhi perhna verna confuse ho jow gy jub node remove karnay ki bar ay tub dekhna
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
//function 1 dekhnay say pehlay main may chalay jana and dekhlena k waha head and tail kesay bany hy uskay bad yaha ana 
void insertAtHead(Node* &head, int d) { 
	//new node creation
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
}
void insertAtTail(Node*& tail, int d) {
	// new node created
	Node* temp = new Node(d);
	tail->next = temp;
	tail = tail->next;

}
void insetAtMiddle(Node* &head,Node* &tail,int location, int d) {
	//inserting at first position
	if (location == 1) {
		insertAtHead(head, d);
		return;
	};
	
	Node* current = head;

	int count = 1;
	while (current->next != NULL && count < location - 1) {
		current = current->next;
		count++;
	}
	//inserting at last position
	if (current->next == 0) {
		insertAtTail(tail, d);
		return;

	}
	//creating a node to add data
	Node* temp = new Node(d);
	temp->next = current->next;
	current->next = temp;

}
void print(Node*& head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << endl;
}

void deleteNode(Node*& head, int location) {
	if (location == 1) {
		Node* temp = head;
		//deleting a node from head
		head = head->next;
		temp->next=NULL;
		delete temp;
	}
	else {
		Node* previous = head;
		Node* current = head->next;
		int count = 1;
		while (current->next != NULL && count <= location) {
			previous = current;
			current = current->next;
			count++;
		}
		previous->next = current->next;
		current->next = NULL;
		delete current;
	}
}
int getLength(Node*& head) {
	int len = 0;

	Node* temp = head;
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}
	return len;
}

// Function to reverse the linked list
void reverseLinkedList(Node*& head) {
	Node* prev = NULL;
	Node* current = head;
	Node* next = NULL;

	while (current != NULL) {
		next = current->next;  // Store the next node
		current->next = prev;  // Reverse the current node's pointer
		prev = current;   // Move the `prev` pointer one step ahead
		current = next; // Move the `current` pointer one step ahead
	}
	head = prev;  // Update the head to the new front of the list
}
//searching for a specific value
bool search(Node* head, int value) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == value) {
			return true; 
		}
		temp = temp->next;
	}
	return false;
}


	int main() {
	Node* node1 = new Node(10);//pehla node banaya hy and usmay value 10 bhej di
	//cout << node1->data<<endl;
	//cout << node1->next;
	Node* head = node1; //ab jub node ek hy hain to humnay isko hy head bana diya and isko hy tail bana diya;
	Node* tail = node1;
	print(head);
	insertAtTail(tail, 12);
	print(head);//print ka ek function banaya jo nodes ko print karay ga uper hy dekho 
	//agar new node add karna hy head per to
	insertAtTail(tail, 15);
	print(head);

	insetAtMiddle(head,tail, 3, 22);
	print(head);
	insertAtHead(head, 31);
	print(head);
	insertAtTail(tail, 1);
	print(head);
	cout << "head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;


	cout<<"The number of elements in the linked list are : " << getLength(head) << endl;

	reverseLinkedList(head);
	cout << "Reversed linked list: "<<endl;
	print(head);

	int num = 31;
	if (search(head, num)) {
		cout << "Value: " << num << endl;
		cout << "We Found the value yuhuuuu!!!!" << endl;
	}
	else {
		cout << "Search value not found buuuuu :(" << endl;
	}
	return 0;

}
