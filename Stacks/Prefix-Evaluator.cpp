#include <iostream>
#include <stack>
#include <cctype> // For isdigit()

using namespace std;

class PrefixEvaluator {
public:
    // Function to evaluate a prefix expression
    int evaluate(string expression) {
        stack<int> s;

        // Iterate from the rightmost character
        for (int i = expression.length() - 1; i >= 0; i--) {
            char ch = expression[i];

            if (isdigit(ch)) { // Check if ch is a digit
                s.push(ch - '0'); // Convert char to integer
            }
            else { // If it's an operator
                int val1 = s.top(); s.pop(); // Pop the first operand
                int val2 = s.top(); s.pop(); // Pop the second operand

                // Perform the operation based on the operator
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
    PrefixEvaluator evaluator;
    string expression = "-+*23*549"; // Equivalent to: ((2 * 3) + (5 * 4)) - 9
    cout << "Result of prefix expression: " << evaluator.evaluate(expression) << endl;

    return 0;
}
