#include "doublylinkedlist.h"
#include <iostream>

using namespace std;

// Implementation of the functions

// Create and destruct the DLL
Head* create() {
    // dynamic allocation of the memory
    Head* h = (Head*) malloc(sizeof(Head));
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
        // assign the head to aux node to run through all values
        // and remove all of them
        Node *aux;
        while(*h != nullptr) {
            aux = *h;
            *h = (*h)->next;
            free(aux);
            aux = nullptr;
        }
        // then, after remove all of the data, remove head
        free(h);
    }
}

// basic info about the list
int listSize(Head* h) {
    // if list is empty or doesn't exist, size is 0
    if (h == nullptr || *h == nullptr)
        return 0;
    // aux node to transverse the list
    Node *no = *h;
    int counter = 0;
    while(no != nullptr) {
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

    // since the insertion is in front, then assign to the next member of the node
    // the value that head points to and previous is going to be null since that is going to be
    // the new head of the list
    no->next = *h;
    no->previous = nullptr;

    // makes previous element of the head points to the new element
    // if the list wasn't empty, because null can't point to a value XD
    if (*h != nullptr)
        (*h)->previous = no;

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
    // the node is going to be place at the back of the list, so assign next to null
    // since that node is going to be the last element
    no->next = nullptr;

    // first check if the empty space is the head, then update head and set previous to null
    // need to check head first, because if head is null, when try to set any previous or next, the
    // program is going to crash
    if (*h == nullptr) {
        *h = no;
        no->previous = nullptr;
    } else {
        // since the insertion is in back, need an aux node to transverse the list
        // in order to find an empty space
        Node *aux = *h;
        while(aux->next != nullptr) {
            aux = aux->next;
        }

        cout << "here\n";
        // aux is the current last element
        // make it point out to the new node and make the previous member
        // of the new node points to aux
        aux->next = no;
        no->previous = aux;
    }

    return true;
}

bool insert_sorted(Head *h, int value) {
    // function to insert value in a sorted way
    // check if list exists
    if (h == nullptr)
        return false;

    Node *no = (Node *)malloc(sizeof(Node));

    if (no == nullptr)
        return false;

    no->value = value;
    if (*h == nullptr) {
        no->next = nullptr;
        no->previous = nullptr;
        *h = no;
    } else {
        Node *previous, *aux = *h;
        while(aux != nullptr && aux->value < value) {
            previous = aux;
            aux = aux->next;
        }

        // first check if the space is the head, then update head, previous and next members
        if (aux == *h) {
            // first element with a list that is not empty
            no->next = *h;
            (*h)->previous = no;
            no->previous = nullptr;
            *h = no;
        } else {

            no->next = aux;
            previous->next = no;
            no->previous = previous;

            // update previous of aux to node, since now aux comes after it
            if(aux != nullptr)
                aux->previous = no;
        }
    }
    return true;
}

// remove operations
bool remove_pos(Head *h, int pos) {
    // can't remove from an empty list
    if (h == nullptr || *h == nullptr || pos <= 0 || pos > listSize(h))
        return false;

    Node *aux = *h;
    int counter = 1;
    while(counter < pos) {
        aux = aux->next;
        counter++;
    }

    // if it's the head, element to be removed is the first element
    if (aux == *h) {
        *h = (*h)->next;
        // if the head is not null, set previous of this "new" first node to null
        if (*h != nullptr) {
            (*h)->previous = nullptr;
        }
    } else {
        // if it's not the first element, previous of aux is not null, then
        // make it points to the next member of aux
        aux->previous->next = aux->next;
        // check if aux->next is null, if is not, make previous points to previous of aux
        if (aux->next != nullptr) {
            aux->next->previous = aux->previous;
        }
    }

    free(aux);
    aux = nullptr;
    return true;
}

bool remove_front(Head *h) {
    // can't remove from an empty list
    if (h == nullptr || *h == nullptr)
        return false;
    Node *aux = *h;
    *h = (*h)->next;
    free(aux);
    aux = nullptr;
    if (*h != nullptr)
        (*h)->previous = nullptr;
    return true;
}

bool remove_back(Head *h) {
    // can't remove from an empty list
    if (h == nullptr || *h == nullptr)
        return false;
    Node *aux = *h;
    while(aux->next != nullptr)
        aux = aux->next;

    if (aux == *h) {
        *h = nullptr;
    } else {
        aux->previous->next = nullptr;
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
    Node *previous = nullptr, *aux = *h;
    while(aux != nullptr && aux->value != value) {
        previous = aux;
        aux = aux->next;
    }

    // element was not found
    if (aux == nullptr) {
        return false;
    } else {
        // if it's not the first element, then previous is not null and its next member must be updated
        if (previous != nullptr) {
            // points to what aux next points to
            previous->next = aux->next;
            // update aux->next->previous to point to previous instead of the current aux node
            if (aux->next != nullptr)
                aux->next->previous = previous;
        } else {
            // if it got in this condition it means the first element is going to be deleted
            // head gets the next element (be it null or not)
            *h = aux->next;
            // check if *h is not null and set its previous member to null
            if (*h != nullptr) {
                (*h)->previous = nullptr;
            }
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
    while(aux->next != nullptr)
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
    while(aux != nullptr && aux->value != value) {
        aux = aux->next;
    }

    // element wasn't found
    if (aux == nullptr)
        return false;

    return true;
}
