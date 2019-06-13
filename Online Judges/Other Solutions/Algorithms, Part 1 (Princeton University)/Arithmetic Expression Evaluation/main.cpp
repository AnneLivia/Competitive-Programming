#include <iostream>
#include <string>

using namespace std;

/*
    Calculating expressions, where "(" is ignored,
    any number is pushed into the stack (of numbers), any operator
    is pushed into another stack (of operators) and when get into the ")"
    it's going to be realized an operation, where it's going to be
    taken from the top of the stack that stores the operations one operator,
    to perform a calculation between two numbers popped up from the stack
    of numbers.
*/

// Creating a genetic stack (using linked List)
template <class T>
class Stack {
private:
    class Node {
    public:
        T value;
        Node *next;
        Node(T value, Node *next) : value(value), next(next) {}
    };
    Node *top;
public:
    Stack() {
        top = nullptr;
    }

    void push(T value) {
        Node *no = new Node(value, top);
        top = no;
    }

    T pop() {
        Node *poppedNode = top;
        top = top->next;
        T item = poppedNode->value;
        delete poppedNode;
        return item;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    T getTop() const {
        return top->value;
    }
};

bool isOperator(string op) {
    return (op == "+" || op == "*" || op == "/" || op == "-");
}

float calculate(float n1, float n2, string operation) {
    if(operation == "+")
        return n1 + n2;
    if(operation == "-")
        return n1 - n2;
    if(operation == "*")
        return n1 * n2;
    if(operation == "/")
        return n1 / n2;
}

int main()
{
    Stack<float>numbers; // Stack of numbers
    Stack<string>operators; // Stack of operators
    string expression; // Will store to expressions that are going to be used for the calculation
    while(cin >> expression) { // finished with EOF
        // If is a math operator, then push it into the operators stack
        if(isOperator(expression)) {
            operators.push(expression);
        } else if (expression != "(" && expression != ")") {
            // If expression is neither a operator, nor ( and ), then it's a number
            numbers.push(stof(expression)); // Pushing the expression converted to float
        } else if (expression == ")") {
            // When this condition is true, we need to perform an operation taken from the top
            // of the operators stack between two numbers taken from the top of the numbers stack
            // and then push it again to the stack of number
            float number2 = numbers.pop();
            float number1 = numbers.pop();
            float result = calculate(number1, number2, operators.pop());
            numbers.push(result);
        }
    }
    // When finished, show result
    cout << "Result: " << numbers.pop() << endl;
    return 0;
}
