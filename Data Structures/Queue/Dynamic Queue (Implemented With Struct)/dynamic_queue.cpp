#include "dynamic_queue.h"

// Creating queue
Queue* create_queue() {
    Queue* q = (Queue *)malloc(sizeof(Queue)); // Allocating memory
    if(q != nullptr) {
        q->first = nullptr;
        q->last = nullptr;
        q->amount = 0;
    }
    return q;
}

// Deleting queue
void delete_queue(Queue *q) {
    if(q != nullptr) { // if q exist
        Node *helper;
        while(q->first != nullptr) {
            helper = q->first;
            q->first = q->first->next;
            free(helper);
        }
        free(q);
    }
}

// Accessing information: is full
int isFull(Queue *q) {
    return false;
}

// Accessing information: is empty
int isEmpty(Queue *q) {
    if(q == nullptr || q->amount == 0)
        return true;
    return false;
}

// Accessing information: size
int size_queue(Queue *q) {
    if(q == nullptr)
        return 0;
    return q->amount;
}

// Push
int push(Queue *q, int n) {
    if(q != nullptr) {
        Node* no = (Node *)malloc(sizeof(Node));
        if(no != nullptr) {
            no->number = n;
            no->next = nullptr;
            if(q->first == nullptr) // The first element
                q->first = no;
            else {
                q->last->next = no;
            }
            q->last = no;
            q->amount++;
            return 1;
        }
    }
    return 0; // Error
}

// Pop
int pop(Queue *q) {
    if(q == nullptr || q->first == nullptr) // or q->amount == 0
        return 0;

    Node* no = q->first;
    q->first = q->first->next;
    if(q->first == nullptr) // The first element was the only one
        q->last = nullptr;  // q->last was pointing to there too.
    free(no);
    no = nullptr;
    q->amount--;
    return 1;
}

// Accessing elements
int get_front(Queue *q) {
    if(q == nullptr || q->amount == 0)
        return -1; // Error
    return q->first->number; // first element
}
