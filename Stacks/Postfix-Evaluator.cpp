#include <iostream>
#include <stack>
#include <cctype> // For isdigit()

using namespace std;

class PostfixEvaluator {
public:
    // Function to evaluate a postfix expression
    int evaluate(string expression) {
        stack<int> s;

        for (char ch : expression) {
            if (isdigit(ch))//this checks if ch is is a digit or not
            {
                s.push(ch - '0'); // Convert char to integer
//converts the character to an integer by subtracting the ASCII value of '0' (which is 48) from ch
            }
            else {
                int val2 = s.top(); s.pop();
                int val1 = s.top(); s.pop();

                switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                }
            }
        }
        return s.top(); // The result is the only element left in the stack
    }
};

int main() {
    PostfixEvaluator evaluator;
    string expression = "2 3 1 * + 9 -"; // Equivalent to: (2 + (3 * 1)) - 9
    cout << "Result of postfix expression: " << evaluator.evaluate(expression) << endl;

    return 0;
}
