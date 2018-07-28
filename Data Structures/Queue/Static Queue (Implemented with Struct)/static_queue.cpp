#include "static_queue.h"

// Creating the queue
Queue* create_queue(int qtd) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q != nullptr) {
        q->Size = qtd;
        q->num = (int *)malloc(q->qtd * sizeof(int));
        if(q->num != nullptr) {
            q->first = 0;
            q->last = 0;
            q->qtd = 0;
        }
    }

    return q;
}

// Deleting queue
void delete_queue(Queue *q) {
    if(q != nullptr) {
        free(q->num);
        free(q);
    }
}

// Is full
int isFull(Queue *q) {
    if(q != nullptr && q->qtd == q->Size)
        return true;
    return false;
}

// Is empty
int isEmpty(Queue *q) {
    if(q == nullptr || q->qtd == 0)
        return true;
    return false;
}

// Size of the queue
int size_queue(Queue *q) {
    if(q != nullptr)
        return q->qtd;
    return 0;
}

// push

int push(Queue *q, int n) {
    if(q == nullptr || isFull(q))
        return 0;
    q->num[q->last] = n; // At the position available, the number will be pushed
    q->last = (q->last + 1) % q->Size; // That's the same as q-last + 1 == q->qtd, q->last = 0; That creates a circle in the queue
    q->qtd++; // Increment the number of elements
    return 1; // Everything went well
}

int pop(Queue *q) {
    if(q != nullptr && !isEmpty(q)) {
        q->first = (q->first + 1) % q->Size; // same as q->first++; if q->first == q->qtd, q->first = 0; // this makes a circle
        q->qtd--;
        return 1;
    }

    return 0;
}


// Accessing the first element

int get_front(Queue *q) {
    if(q != nullptr && !isEmpty(q))
        return q->num[q->first];
    return 0; // Error
}

