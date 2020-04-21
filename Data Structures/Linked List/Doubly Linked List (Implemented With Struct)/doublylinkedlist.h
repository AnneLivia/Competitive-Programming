#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <cstdlib>

// Double Linked List is a data Structure where the Node has two pointers one to the next one and
// another to the previous one

struct Node {
    int value;
    Node *next, *previous;
};

typedef Node* Head;

// Create and destruct the DLL
Head* create();
void deleteList(Head* h);

// basic info about the list
int listSize(Head* h);
bool isEmpty(Head* h);
// there's no need to check if the list is full because we are not dealing with a static list

// Insertion operations
bool insert_front(Head *h, int value);
bool insert_back(Head *h, int value);
bool insert_sorted(Head *h, int value);

// remove operations
bool remove_pos(Head *h, int pos);
bool remove_front(Head *h);
bool remove_back(Head *h);
bool remove_value(Head *h, int value);

// access informations
int get_front(Head *h);
int get_back(Head *h);
int get_pos(Head *h, int pos);
bool find_value(Head *h, int value);

#endif // DOUBLYLINKEDLIST_H
