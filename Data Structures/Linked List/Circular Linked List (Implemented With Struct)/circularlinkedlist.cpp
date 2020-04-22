#include "circularlinkedlist.h"
#include <iostream>

using namespace std;

// Implementation of the functions

// Create and destruct the CLL
Head* create() {
    // dynamic allocation of the memory
    Head *h = (Head *) malloc(sizeof(Head));
    // if allocation is successful
    if (h != nullptr) {
        // assign to head the value null, because the list is empty yet
        *h = nullptr;
    }

    return h;
}

void deleteList(Head* h) {
    // first check if the list exists
    if (h != nullptr) {
        // check if it's not null the first value, that means there's at least one element
        // and I can with that get the next element without error
        if (*h != nullptr) {
            // control it's going to be used to help the change
            Node *aux = (*h)->next, *control;
            while(aux != *h) {
                control = aux->next;
                free(aux);
                aux = control;
            }
            free(*h);
            *h = nullptr;
        }
        // then, after remove all of the data, remove head
        free(h);
        h = nullptr;
    }
}

// basic info about the list
int listSize(Head* h) {
    // if list is empty or doesn't exist, size is 0
    if (h == nullptr || *h == nullptr)
        return 0;
    // aux node to transverse the list
    // while next element is different of head, loop
    Node *no = *h;
    int counter = 1;
    while(no->next != *h) {
        counter++;
        no = no->next;
    }
    return counter;
}

bool isEmpty(Head* h) {
    // is list doesn't exist or head points to null, list is empty
    return (h == nullptr || *h == nullptr);
}


// Insertion operations
bool insert_front(Head *h, int value) {

    // check if list exists
    if (h == nullptr)
        return false;

    // allocating new node
    Node *no = (Node *)malloc(sizeof(Node));

    // if error had occurred, notify
    if (no == nullptr)
        return false;

    // if it got here, assign values and populate the list
    no->value = value;

    // if the list is empty, makes next node member points to itself
    if (*h == nullptr) {
        no->next = no;
    } else {
        // next points to what head was pointing to
        no->next = *h;

        Node *aux = *h;
        // try to find last element to change the node where its next member is pointing to
        while(aux->next != *h) {
            aux = aux->next;
        }
        // found last element, make it points to the new first element of the list
        aux->next = no;
    }

    // update head
    *h = no;
    return true;
}

bool insert_back(Head *h, int value) {

    // check if list exists
    if (h == nullptr)
        return false;

    // allocating new node
    Node *no = (Node *)malloc(sizeof(Node));

    // if error had occurred, notify
    if (no == nullptr)
        return false;

    // if it got here, assign values and populate the list
    no->value = value;

    // if it's the first element, make next points to itself and update head
    if (*h == nullptr) {
        no->next = no;
        *h = no;
    } else {
        // since that node is going to be the last element, the next member is going to point to the first one
        no->next = *h;
        // first I need to get the current last node to make its next member points to the new added node
        Node *aux = *h;
        while(aux->next != *h) {
            aux = aux->next;
        }

        // aux is the current last element
        aux->next = no;
    }

    return true;
}

bool insert_sorted(Head *h, int value) {
    // function to insert value in a sorted way
    // check if list exists
    if (h == nullptr)
        return false;

    // allocating new node
    Node *no = (Node *)malloc(sizeof(Node));

    // if error had occurred, notify
    if (no == nullptr)
        return false;

    // if it got here, assign values and populate the list
    no->value = value;

    // need first to check if it's empty, because when try to access aux->next it's going to crash if that's the case
    if (*h == nullptr) {
        no->next = no;
        *h = no;
    } else {
        // since the insertion can be at any place, need an aux node to transverse the list
        // in order to find the right place to insert the node
        Node *previous, *aux = *h;
        while(aux->next != *h && aux->value < value) {
            previous = aux;
            aux = aux->next;
        }

        // first check if the space is the head, then update head
        if ((*h)->value > value) {
            no->next = *h;
            // find last node to update its next member
            Node *auxx = *h;
            while (auxx->next != *h)
                auxx = auxx->next;

            auxx->next = no;
            *h = no;
        } else {
            // if it's not the head then update previous and next elements of the node aux
            // first check if the space is to be inserted at the last position
            if (aux->next == *h && aux->value < value) {
                aux->next = no;
                no->next = *h;
            } else {
                previous->next = no;
                no->next = aux;
            }
        }
    }
    return true;
}

// remove operations
bool remove_pos(Head *h, int pos) {
    // can't remove from an empty list
    if (h == nullptr || *h == nullptr || pos <= 0 || pos > listSize(h))
        return false;

    Node *aux = *h, *previous;
    int counter = 1;
    while(counter < pos) {
        previous = aux;
        aux = aux->next;
        counter++;
    }

    // if it's the head, element to be removed is the first element
    if (aux == *h) {
        // there's only one element
        if ((*h)->next == *h)
            *h = nullptr;
        else {
            // makes head points to next element and update last node of the list to point to the new first element
            Node *auxx = *h;
            while(auxx->next != *h)
                auxx = auxx->next;
            auxx->next = (*h)->next;
        }
    } else {
        // if it's not the first element, previous must point to aux->next (can be head or not)
        previous->next = aux->next;
    }

    free(aux);
    aux = nullptr;
    return true;
}

bool remove_front(Head *h) {
    // can't remove from an empty list
    if (h == nullptr || *h == nullptr)
        return false;

    // there's only one element
    if ((*h)->next == *h) {
        free(*h);
        *h = nullptr;
    } else {

        Node *aux = *h, *pre = *h;
        // need to find last element
        while(aux->next != *h) {
            aux = aux->next;
        }

        (*h) = (*h)->next;
        aux->next = *h;
        // eliminating the first element
        free(pre);
        pre = nullptr;
    }

    return true;
}

bool remove_back(Head *h) {
    // can't remove from an empty list
    if (h == nullptr || *h == nullptr)
        return false;
    Node *aux = *h, *previous;
    while(aux->next != *h) {
        previous = aux;
        aux = aux->next;
    }

    // element at the back is the first element
    if (aux == *h) {
        *h = nullptr;
    } else {
        // it's note the  first element and there's more than one element, so update previous of last point to what last next points to
        previous->next = aux->next;
    }
    free(aux);
    aux = nullptr;
    return true;
}

bool remove_value(Head *h, int value) {
    // can't remove from an empty list
    if (h == nullptr || *h == nullptr)
        return false;
    // transverse the list to find value
    Node *previous, *aux = *h;
    while(aux->next != *h && aux->value != value) {
        previous = aux;
        aux = aux->next;
    }

    // element was not found
    if (aux->value != value) {
        return false;
    } else {
        // check if it's the head and if it has only one element or not
        if (aux == (*h)) {
            // only one element
            if ((*h)->next == *h) {
                *h = nullptr;
            } else {
                // more than one element
                *h = (*h)->next;
                // need to update last member
                Node *auxx = *h;
                while(auxx->next != aux) {
                    auxx = auxx->next;
                }

                auxx->next = *h;
            }
        } else {
            // if it's not the first element, update previous to point to what aux is point to
            previous->next = aux->next;
        }
    }
    free(aux);
    aux = nullptr;
    return true;
}

// access informations
int get_front(Head *h) {
    // if list is empty or doesn't exist return some error value
    if (h == nullptr || *h == nullptr)
        return 0x3F3F3F3F;

    // otherwise return the value of the head
    return (*h)->value;
}

int get_back(Head *h) {
    // if list is empty or doesn't exist return some error value
    if (h == nullptr || *h == nullptr)
        return 0x3F3F3F3F;

    // transverse the list to find last element
    Node *aux = *h;
    while(aux->next != *h)
        aux = aux->next;

    return aux->value;
}

int get_pos(Head *h, int pos) {

    // if list is empty or doesn't exist return some error value
    // if position is greater than the size of the list return error value too

    if (h == nullptr || *h == nullptr || pos > listSize(h) || pos <= 0)
        return 0x3F3F3F3F;

    int pos_aux = 1;
    // transverse the list to find element
    Node *aux = *h;
    while(pos_aux < pos) {
        aux = aux->next;
        pos_aux++;
    }

    return aux->value;

}

bool find_value(Head *h, int value) {
    // if list is empty or doesn't exist return some error value
    if (h == nullptr || *h == nullptr)
        return false;

    // transverse the list to find value
    Node *aux = *h;
    while(aux->next != *h && aux->value != value) {
        aux = aux->next;
    }

    // element wasn't found
    if (aux->value != value)
        return false;

    return true;
}
