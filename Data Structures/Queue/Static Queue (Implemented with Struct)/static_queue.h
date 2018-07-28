#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include <cstdlib>

// FIFO - First in first out

// Last and first were created to make a circle on the queue

struct Queue {
    int first; // First index
    int last;  // Last index and also the available space for push
    int Size;  // Size of the queue
    int qtd;   // will store the amount of elements in the queue
    int *num;  // array to store numbers
};

// Create and delete function
Queue* create_queue(int qtq);
void delete_queue(Queue *q);

// Accessing information
int isFull(Queue *q);
int isEmpty(Queue *q);
int size_queue(Queue *q);

// Push and Pop
int push(Queue *q, int n);
int pop(Queue *q);

// get value
int get_front(Queue *q);

#endif // STATIC_QUEUE_H
