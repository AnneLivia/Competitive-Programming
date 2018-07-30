#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H
#include <cstdlib>

// FIFO - First in First out
struct Node {
    int number; // Store the number
    Node* next; // Pointer to the next element
};

// A data structure with descriptor node, is a type of data structure that, instead of choose an element to be the first of the list and keep your reference
// will be used a  compound structure with other members with informations about the data structure in accord with the application, such as:
// first element, last element, number of elements, mean of the elements inside the data structure, and so on.

/*
    Advantages of using a descriptor:
    When doing some application that needs to know some informations such as the size, or sum of all members, and so on, instead of transversing all the data structure
    Depending on how the a data structure is implemented, specifics nodes can be accessed directly (first, last, bigger, lesser);
*/

struct Descriptor {
    Node* first; // A pointer to the first element
    Node* last;  // A pointer to the last element
    int amount;
};

typedef Descriptor Queue;

// Creating and deleting queue

Queue* create_queue(); // Function that return a pointer Queue
void delete_queue(Queue* q);

// Accessing informations
int isFull(Queue *q); // The queue will be full only if there's no more space in the memory
int isEmpty(Queue *q);
int size_queue(Queue *q);

// Push and pop elements
int push(Queue *q, int n);
int pop(Queue *q);

// Getting the first element of the queue
int get_front(Queue *q);

#endif // DYNAMIC_QUEUE_H
