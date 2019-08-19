#include <iostream>
#include <stack>

using namespace std;

int prece(const char& op) {
    if(op == '-' || op == '+') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }

    return 0;
}

/*
    Basically this problem states that we must convert a infix expression to a
    postfix expression.

    - Steps:
        Scan the expression from left to right
        IF it's a number or letter, add it to the postfix string
        Otherwise (if it's a operator), add it to the stack, maintaining the precedence

*/
int main()
{
    int n;
    cin >> n;
    while(n--) {
        string infix, postfix = "";
        stack<char>ope;
        cin >> infix;

        // need to check infix expression from left to right
        for (int i = 0; i < (int)infix.size(); i++) {
            // if the digit is a letter or a number, just add it to the postfix expression
            if(toupper(infix[i]) >= 'A' && toupper(infix[i]) <= 'Z' ||
               infix[i] >= '0' && infix[i] <= '9') {
                postfix+=infix[i];
            } else if (infix[i] == ')') {
                // if it's the end of expression, remove all operators and insert in the postfix
                // until find a "( ";
                while(!ope.empty() && ope.top() != '(') {
                    postfix+=ope.top();
                    ope.pop();
                }
                ope.pop(); // to eliminate "("
            } else {
                // if it got here is an operator or (
                if(infix[i] == '(' || infix[i] == '^') {
                    ope.push(infix[i]); // higher precedence
                } else {
                    // not high precedence, so check if top of stack has higher precedence
                    // of the current operator, if it has, then  pop it from stack and add it to the postfix, and push
                    // the current one onto the stack.
                    while(!ope.empty() && prece(ope.top()) >= prece(infix[i])) {
                        postfix+=ope.top();
                        ope.pop();
                    }
                    // now that all operator with higher precedence than the current one was remove from
                    // stack and added on the postfix expression, and the operator to the stack
                    ope.push(infix[i]);
                }
            }
        }

        // when finish, add all remaining operators to the postfix
        while(!ope.empty()) {
            postfix+=ope.top();
            ope.pop();
        }

        cout << postfix << endl;
    }
    return 0;
}
