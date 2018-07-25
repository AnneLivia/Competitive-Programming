#include "dynamic_stack.h"

// FILO - First in last out

// Creating stack
Stack* create_stack() {
    Stack *s = (Stack *)malloc(sizeof(Stack)); // Allocating memory to the stack
    if(s != nullptr) {
        *s = nullptr; // head points to null
    }
    return s; // This function returns a pointer to a pointer to node (As if the Stack is the head)
}

// Deleting stack
void delete_stack(Stack *s) {
    if(s != nullptr) { // If the stack exist
        Node *helper;
        while((*s) != nullptr) {
            helper = *s; // Helper will receive the head
            *s = (*s)->next; // Head will receive the next
            free(helper); // Free helper
        }
        free(s); // When finished, free s
        // Good practice
        s = nullptr;
        helper = nullptr;
    }
}

// Getting the size of the stack
int stack_size(Stack *s) {
    if(s != nullptr) { // If the stack exist
        int qtd = 0; // will store the size
        Node *helper = *s; // variable that is going to transverse the stack
        while(helper != nullptr) { // while there is next element
            qtd++; // increment the size
            helper = helper->next; // receives the next element
        }
        return qtd; // return size
    }
    return -1; // error
}

// Checking if the stack is full
int isFull(Stack *s) {
    return false;
}

// Checking if the stack is empty
int isEmpty(Stack *s) {
    if(s == nullptr || *s == nullptr) // if the pointer to stack is null or the head is null
        return true;
    return false;
}

// Push value in the stack
int push(Stack *s, int n) {
    if(s != nullptr) { // if the stack exist
        // Creating node
        Node *helper = (Node *)malloc(sizeof(Node));
        if(helper != nullptr) { // If everything went well
            helper->num = n;
            helper->next = *s; // helper->next will point to where *s (head) points to. if its the first element then, it will point to null, else, will point to some element
            *s = helper; // Head start to points to this new element
            return 1; // Everything went well
        }
    }
    return 0; // error
}

// Pop value in the stack
int pop(Stack *s) {
    if(s != nullptr && !isEmpty(s)) { // If the stack exist and is not empty
        Node* helper = *s; // Helper will receive the first element
        *s = (*s)->next;  // Head now points to the next element
        free(helper); // Free helper

        helper = nullptr;

        return 1; // everything went well
    }
    return 0; // Error
}

// Get element from top of the stack
int get_top(Stack *s) {
    if(s != nullptr && !isEmpty(s)) { // if the stack is not empty, there's element
        return (*s)->num; // Getting element from top
    }
    return -1; // Error
}
