#include<iostream>
#include<stack>

using namespace std;

class ParenthesisChecker {
public:
	bool isBalanced(string expression) {
		stack<char> s;
		for (int i = 0; i < expression.length(); i++) { // 1. Fix `expression.length` to `expression.length()`
			char ch = expression[i]; //ch holds the current charactor

			// If opening bracket, push onto the stack
			if (ch == '(' || ch == '{' || ch == '[') {
				s.push(ch);
			}
			else {
				// Check if stack is empty before popping
				if (!s.empty()) {
					char top = s.top();
					if ((ch == ')' && top == '(') ||
						(ch == '}' && top == '{') ||
						(ch == ']' && top == '[')) {
						s.pop();
					}
					else {
						return false; // Unmatched closing bracket
					}
				}
				else {
					// Stack is empty and we encountered a closing bracket
					return false;
				}
			}
		}

		return s.empty();
	}
};

int main() {
	ParenthesisChecker checker;
	string expression = "{[()]}"; // balanced example

	// 4. Fix missing parentheses in `if` condition
	if (checker.isBalanced(expression)) {
		cout << "The expression is balanced HEHE 0__0" << endl;
	}
	else {
		cout << "The expression is not balanced awww" << endl;
	}
	return 0;
}
