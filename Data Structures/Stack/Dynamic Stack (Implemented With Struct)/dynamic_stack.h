#ifndef DYNAMIC_STACK_H_
#define DYNAMIC_STACK_H_
#include <cstdlib>

// FILO - First in last out

struct Node {
    int num;
    Node* next;
};

typedef Node* Stack; // Stack is a pointer to node

// Creating and deleting stack
Stack* create_stack();
void delete_stack(Stack *s);

// Stack informations
int isEmpty(Stack *s);
int isFull(Stack *s); // There's not need, but just for the matter of encapsulation it will be implemented
int stack_size(Stack *s);

// Push and Pop
int push(Stack *s, int n);
int pop(Stack *s);

// Accessing top element
int get_top(Stack *s);

#endif // DYNAMIC_STACK_H_
