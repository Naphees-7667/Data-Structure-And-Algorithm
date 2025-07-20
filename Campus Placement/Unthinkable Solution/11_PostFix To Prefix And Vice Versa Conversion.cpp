/*
✅ Postfix to Prefix – Algorithm / Pseudocode

Function postfixToPrefix(postfix):
    1. Initialize an empty stack of strings

    2. For each character 'ch' in postfix (left to right):
        a. If 'ch' is an operand:
            → Push 'ch' as string to stack
        b. If 'ch' is an operator:
            → Pop operand2 from stack
            → Pop operand1 from stack
            → Combine into prefix: (op + operand1 + operand2)
            → Push the result back to stack

    3. After traversal, stack will contain final prefix expression

    4. Return the top of the stack

    Example - ab+cd-*  
    1. a → push
    2. b → push
    3. + → pop a, b → +ab → push
    4. c → push
    5. d → push
    6. - → pop c, d → -cd → push
    7. * → pop +ab, -cd → *+ab-cd → push
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string postfixToPrefix(const string& postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            string expr = c + operand1 + operand2;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string prefix = postfixToPrefix(postfix);
    cout << "Prefix: " << prefix << endl;

    return 0;
}

/*
✅ Prefix to Postfix – Algorithm / Pseudocode

🔁 Strategy:
We traverse the prefix expression from right to left, use a stack, and for every operator we:

pop two operands,

combine them in postfix format,

push the result back to the stack.

Function prefixToPostfix(prefix):
1. Initialize an empty stack of strings

2. Traverse prefix expression from **right to left**:
    a. If character is operand:
        → Push it as a string onto the stack
    b. If character is operator:
        → Pop operand1 from stack
        → Pop operand2 from stack
        → Combine: operand1 + operand2 + operator
        → Push result back to stack

3. Final postfix expression is at top of stack

4. Return top of stack

Example - *+ab-cd

→ d → push
→ c → push
→ - → pop c, d → cd- → push
→ b → push
→ a → push
→ + → pop a, b → ab+ → push
→ * → pop ab+, cd- → ab+cd-* → push

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string prefixToPostfix(const string& prefix) {
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
            string expr = operand1 + operand2 + c;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix: " << postfix << endl;

    return 0;
    
}