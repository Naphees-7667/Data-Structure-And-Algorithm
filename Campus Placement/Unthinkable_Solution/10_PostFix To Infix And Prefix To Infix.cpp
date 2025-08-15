/*
✅ Postfix to Infix – Algorithm / Pseudocode

Function postfixToInfix(postfix):
    1. Initialize an empty stack of strings

    2. For each character 'ch' in postfix:
        a. If 'ch' is an operand:
            → Push 'ch' as a string to the stack
        b. If 'ch' is an operator:
            → Pop two operands from the stack:
                operand2 = top element; pop
                operand1 = next top element; pop
            → Form a new infix expression: "(operand1 op operand2)"
            → Push this new expression back to the stack

    3. After loop, the stack should have one element → the final infix expression

    4. Return the top of the stack

--------------------------------------------------------------------------------

    Example - ab+cde+**  

    1. a → push
    2. b → push
    3. + → pop a, b → (a + b) → push
    4. c → push
    5. d → push
    6. e → push
    7. + → pop d, e → (d + e) → push
    8. * → pop c, (d + e) → (c * (d + e)) → push
    9. * → pop (a + b), (c * (d + e)) → ((a + b) * (c * (d + e))) → push
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToInfix(const string& postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c)); // push operand as string
        }
        else if (isOperator(c)) {
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            string expr = "(" + operand1 + c + operand2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix: " << infix << endl;

    return 0;
}

/*
✅ Prefix to Infix Conversion

Function prefixToInfix(prefix):
    1. Initialize an empty stack of strings

    2. Traverse the prefix expression from **right to left**:
        a. If current character is an operand:
            → Push it as a string onto the stack
        b. If current character is an operator:
            → Pop two operands from the stack:
                operand1 = top element; pop
                operand2 = next top element; pop
            → Form new expression: "(operand1 op operand2)"
            → Push this new expression back to the stack

    3. After traversal, the stack will contain the final infix expression

    4. Return the top of the stack

    Example - *+ab-cd

    → d → push
    → c → push
    → - → pop c, d → (c - d) → push
    → b → push
    → a → push
    → + → pop a, b → (a + b) → push
    → * → pop (a + b), (c - d) → ((a + b) * (c - d)) → push

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToInfix(const string& prefix) {
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            string operand1 = st.top(); st.pop();
            string operand2 = st.top(); st.pop();
            string expr = "(" + operand1 + c + operand2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    string infix = prefixToInfix(prefix);
    cout << "Infix: " << infix << endl;

    return 0;
}