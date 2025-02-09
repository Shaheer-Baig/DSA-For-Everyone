#include<iostream>
using namespace std;

class Stack {
public:
	int* arr;
	int top;
	int size;


	//constructor
	Stack(int size) {
		this->size = size;//this size uper wala size and = kbad wala size jo constructor may mention hy
		arr = new int[size];
		top = -1;
	}
	void push(int element) {
		if (size - top > 1) {//size check kar rahay hy if size available hy ya nhi?
			top++;
			arr[top] = element;
			cout << element << " pushed into the stack." << endl;
		}
		else {
			cout << "Stack OverFlow!! " << endl;
		}
	}

	void pop() {
		if (top >= 0) {
			cout << arr[top] << " Popped from the stack." << endl;
			top--;


		}
		else {
			cout << "Stack UnderFlow!! " << endl;
		}

	}


	void peek() {
		if (top >= 0 && top < size) {
			cout << "The top element of stack is " << arr[top] << endl;
	
		}
		else {
			cout << "Stack is empty " << endl;
	
		}
	}

	bool IsEmpty() {
		if (top == -1) {
			cout << "Stack is empty" << endl;;
			return true;
		}
		else {
			cout << "Stack isnt empty";
			return false;
		}
	}
	bool IsFull() {
		if (top >= size-1) {
			cout << "Stack is full! ";
			return true;
		}
		else {
			cout << "Stack isnt full! ";
		}
	}
	};
	int main() {
		Stack s(5);
		s.push(10);
		s.push(20);
		s.push(30);
		s.push(40);
		s.push(50);
		s.push(60);
		s.peek();
		cout << s.IsFull() << endl;
		s.pop();
		s.pop();
		s.pop();
		s.pop();
		s.pop();
		s.pop();
		cout << s.IsFull() << endl;
		cout << s.IsEmpty() << endl;
		s.peek();
	}
