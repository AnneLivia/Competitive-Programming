#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include <cstdlib>

/*
    Circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end.
    That is, last element of the list points to the first element.

    Some advantages of this implementation:
        We can traverse the whole list by starting from any point.
    From geeks of geeks,good advantage of this implementation and in a real usage:
    Circular lists are useful in applications to repeatedly go around the list.
    For example, when multiple applications are running on a PC, it is common for
    the operating system to put the running applications on a list and then
    to cycle through them, giving each of them a slice of time to execute,
    and then making them wait while the CPU is given to another application.
    It is convenient for the operating system to use a circular list so that
    when it reaches the end of the list it can cycle around to the front of the list.
*/

struct Node {
    int value;
    Node *next;
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

#endif // CIRCULARLINKEDLIST_H_INCLUDED
