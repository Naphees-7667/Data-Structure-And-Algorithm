/*
✅ Infix to Postfix Conversion – Pseudocode

function INFIX_TO_POSTFIX(expression):
    Initialize an empty stack called operatorStack
    Initialize an empty string called postfix

    for each character ch in expression:
        if ch is a whitespace:
            skip

        else if ch is an operand (letter or digit):
            append ch to postfix

        else if ch is '(':
            push ch to operatorStack

        else if ch is ')':
            while operatorStack is not empty and top is not '(':
                pop from operatorStack and append to postfix
            if operatorStack is not empty:
                pop '(' from operatorStack

        else if ch is an operator:
            while operatorStack is not empty AND
                  precedence(top of operatorStack) >= precedence(ch) AND
                  top of operatorStack is not '(':
                pop from operatorStack and append to postfix
            push ch to operatorStack

    while operatorStack is not empty:
        pop from operatorStack and append to postfix

    return postfix

*/

class Solution {
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3; // right-associative
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    string convertToPostfix(const string& infix) {
        stack<char> st;
        string postfix;

        for (char c : infix) {
            if (c == ' ') continue;

            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop the '('
            }
            else if (isOperator(c)) {
                // Left-associative handling: pop operators with greater or equal precedence
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    if (st.top() == '(') break;
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }

public:
    string infixToPostfix(string& s) {
        return convertToPostfix(s);
    }
};


/*
✅ Infix to Prefix Conversion

function INFIX_TO_PREFIX(expression):
    Reverse the infix expression
    Replace '(' with ')' and vice versa

    Initialize empty operatorStack
    Initialize empty postfix string

    for each character ch in reversed infix:
        if ch is operand:
            append to postfix
        else if ch is '(':
            push to operatorStack
        else if ch is ')':
            while top of operatorStack != '(':
                pop and append to postfix
            pop '('
        else if ch is operator:
            while operatorStack not empty AND
                  precedence(top) >= precedence(ch):
                pop and append to postfix
            push ch to operatorStack

    while operatorStack not empty:
        pop and append to postfix

    Reverse postfix to get prefix
    Return prefix


*/

class Solution {
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;  // Treat as left-associative here
        return 0;
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    string infixToPostfix(const string& infix) {
        stack<char> st;
        string postfix;

        for (char c : infix) {
            if (c == ' ') continue;

            if (isalnum(c)) {
                postfix += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            } else if (isOperator(c)) {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    if (st.top() == '(') break;
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        return postfix;
    }

    string reverseAndSwap(const string& s) {
        string rev;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') rev += ')';
            else if (s[i] == ')') rev += '(';
            else rev += s[i];
        }
        return rev;
    }

public:
    string infixToPrefix(string& s) {
        string reversedInfix = reverseAndSwap(s);
        string postfix = infixToPostfix(reversedInfix);
        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};