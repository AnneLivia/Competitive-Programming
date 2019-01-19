#include <iostream>
#include <exception>

using namespace std;

// Implementation using linked list, where we have a pointer that points to a next item
class StackOfStrings {
private:
    // Nested class (Node)
    class Node {
    public:
        string data;
        Node* next;
        Node(string data, Node* next) : data(data), next(next){}
    };
    Node *top;
public:
    StackOfStrings() {
        top = nullptr;
    }

    // Inserting an element in the stack (at the beginning of the linked list)
    void push(string data) {
        // Allocating a new node in the heap and making its next member point to the top (top of the stack)
        Node *no = new Node(data, top);
        top = no; // Top now is the new node, which is the first one
        /*
            It could be:
            Node *oldOne = top;
            top = new Node(data, oldOne);
        */
    }

    // Remove an element from the stack (from the beginning of the linked list)
    string pop() {
        Node *aux = top; // Taken reference of the first node
        string data = aux->data; // Save item to return
        top = top->next; // Top now will point to the next element
        delete aux; // Removing aux from heap
        aux = nullptr; // setting aux to nullptr, so that it's not a dangling pointer
        return data; // Return the string that was removed
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == nullptr);
    }

    ~StackOfStrings() {
        Node *aux = top;
        while(top != nullptr) {
            top = top->next;
            delete aux;
            aux = top;
        }
    }
};

// Stack with array can occur overflow and underflow
class StackWithArrayFixed {
private:
    string *arr;
    int size_arr, top;
public:
    StackWithArrayFixed(int size_arr) : size_arr(size_arr) {
        arr = new string[size_arr];
        top = 0;
    }

    // Adding an item to the stack (to add, increment top)
    void push(string item) {
        if(top == size_arr) { // Cannot add any new element, stack full
            throw "Stack Full";
            return;
        }

        // Otherwise, just add the new item at the top position and increment it
        this->arr[top++] = item;
    }

    // Removing an item from the stack (to remove, decrement top)
    string pop() {
        if(isEmpty()) { // If it's empty, than there's any element to remove
            throw "Stack Empty";
        }

        // Otherwise, just decrement top, so that the deleted element can be subscribed
        top--;
        string element = this->arr[top]; // getting removed element
        this->arr[top] = ""; // Assign it to "" empty string
        return element;
    }

    bool isEmpty() {
        return (top == 0);
    }

    ~StackWithArrayFixed() {
        delete[] arr;
    }
};

int main() {
    // StackOfStrings st;
    StackWithArrayFixed st(10);
    string data;
    // If string is equal "-", then it will pop from stack and print
    try {
        do {
            cin >> data;
            if(data.compare("-") == 0) {
                cout << st.pop() << endl;
            } else {
                st.push(data);
            }
        } while(!st.isEmpty());
    } catch(const char* e) {
        cerr << "Error: " << e << endl;
    }
    return 0;
}
