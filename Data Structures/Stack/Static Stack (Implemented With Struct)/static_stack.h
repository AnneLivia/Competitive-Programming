#ifndef STATIC_STACK_H_
#define STATIC_STACK_H_
#include <cstdlib>

struct Stack {
    int *value;
    int qtd, space;
};

// Create and delete stack
Stack* create_stack(int qtd);
void delete_stack(Stack* s);

// Getting informations from stack
int stack_size(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);

// Push and Pop elements
int push(Stack* s, int n);
int pop(Stack* s);

// Get top element
int get_top(Stack *s);

#endif // STATIC_STACK_H_
