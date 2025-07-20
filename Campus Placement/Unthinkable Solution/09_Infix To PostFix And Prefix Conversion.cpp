/*
✅ Infix to Postfix Conversion – Pseudocode

1. Initialize an empty stack for operators
2. Initialize an empty string for postfix output

3. For each character 'ch' in the infix expression:
    a. If 'ch' is an operand:
        → Append it to postfix
    b. Else if 'ch' is '(':
        → Push it to the stack
    c. Else if 'ch' is ')':
        → While top of stack is not '(':
              → Pop from stack and append to postfix
        → Pop '(' from stack
    d. Else if 'ch' is an operator (+, -, *, /, ^):
        → While stack is not empty AND precedence of top of stack ≥ precedence of 'ch'
            AND 'ch' is not '^' (to handle right-associativity of '^'):
              → Pop from stack and append to postfix
        → Push 'ch' to stack

4. After processing all characters:
    → While stack is not empty:
        → Pop from stack and append to postfix

5. Return postfix
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3; // Right associative
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix;

    for(char c : infix) {
        if(c == ' ') continue;

        // If operand, add to output
        if(isalnum(c)) {
            postfix += c;
        }
        // If '(', push to stack
        else if(c == '(') {
            st.push(c);
        }
        // If ')', pop till '('
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        // If operator
        else if(isOperator(c)) {
            while(!st.empty() && precedence(st.top()) >= precedence(c) && c != '^') {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Main function
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

/*
✅ Infix to Prefix Conversion

Function infixToPrefix(infix):

1. Reverse the infix expression:
    a. While reversing, also:
        - Replace '(' with ')'
        - Replace ')' with '('

2. Convert the reversed expression to postfix:
    a. Initialize an empty operator stack
    b. Initialize an empty output string
    c. For each character 'ch' in reversed infix:
        i.   If 'ch' is an operand:
                 Append to output
        ii.  If 'ch' is '(':
                 Push to stack
        iii. If 'ch' is ')':
                 While top of stack ≠ '(':
                     Pop and append to output
                 Pop '(' from stack
        iv.  If 'ch' is operator:
                 While stack is not empty AND (
                     precedence(top) > precedence(ch) OR
                     precedence(top) == precedence(ch) AND ch is left-associative
                 ):
                     Pop and append to output
                 Push 'ch' to stack

    d. While stack not empty:
         Pop and append to output

3. Reverse the postfix expression → This gives the final prefix expression

4. Return the result

🧠 Important: Associativity Still Matters
+ - * / are left-associative

^ is right-associative

We must handle this properly while deciding to pop or not from the stack.

*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isLeftAssociative(char op) {
    return op != '^'; // only ^ is right-associative
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;

    for(char c : infix) {
        if(c == ' ') continue;

        if(isalnum(c)) {
            postfix += c;
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top(); st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        else if(isOperator(c)) {
            while(!st.empty() && isOperator(st.top()) &&
                 (precedence(st.top()) > precedence(c) ||
                 (precedence(st.top()) == precedence(c) && isLeftAssociative(c)))) {
                postfix += st.top(); st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top(); st.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    // Step 1: Reverse and swap parentheses
    reverse(infix.begin(), infix.end());
    for(char& c : infix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    // Step 2: Convert to postfix
    string postfix = infixToPostfix(infix);

    // Step 3: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    return 0;
    
}