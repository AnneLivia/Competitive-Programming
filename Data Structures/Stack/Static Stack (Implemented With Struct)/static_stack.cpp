#include "static_stack.h"

// FILO - First in Last out

// Creating stack
Stack* create_stack(int qtd) {
    Stack* s = (Stack *)malloc(sizeof(Stack)); // Allocating memory space for the stack
    if(s != nullptr) { // In case everything went okay
        s->qtd = qtd; // size of the array
        s->value = (int *)malloc(qtd * sizeof(int));  // Allocating space for the stack array of size QTD
        if(s->value != nullptr) { // in case everything went okay
            s->space = 0;  // space available to insert element
        }
    }
    return s; // return the stack allocated in the memory
}

// Delete Stack
void delete_stack(Stack *s) {
    if(s != nullptr) { // If the stack exist
        free(s->value);  // free the array of values
        free(s); // free the stack
        s = nullptr; // stacks now points to null
    }
}

// Getting size of the stack
int stack_size(Stack *s) {
    if(s != nullptr) {
        return s->space; // If the stack exist, return its size represented by the QTD structure member
    }
    return -1; // Return -1 in case the stack does not exist
}

// Checking if it's empty
int isEmpty(Stack *s) {
    if(s == nullptr || s->space == 0) { // If the stack doesn't exist or the QTD member is equal to 0, the stack is empty
        return true;
    } else {
        return false;
    }
}

// Check if the stack is full
int isFull(Stack *s) {
    if(s != nullptr && s->space == s->qtd) // If the stack is different of null, that is, if exist and the space is equal to total, it's full
        return true;
    return false;
}

// Push element
int push(Stack *s, int n) {
    if(s != nullptr && !isFull(s)) { // if the stack exist and it's not full
        s->value[s->space++] = n; // Store in the space available the value n;
    } else {
        return -1; // Error
    }

    return 1; // Everything went well
}

// Pop element
int pop(Stack *s) {
    if(s != nullptr && !isEmpty(s)) { // If the stack exist and is not empty
        s->space--; // decrease by one the space member
    } else {
        return -1; // Error
    }

    return 1; // everything went well
}

int get_top(Stack *s) {
    if(s != nullptr && !isEmpty(s)) // If the stack exist and it's not empty
        return s->value[s->space - 1]; // return the value
    return -1; // Error
}
