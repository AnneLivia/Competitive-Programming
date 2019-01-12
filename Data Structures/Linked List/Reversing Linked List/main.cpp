#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int value;
    Node *next;
};

class LinkedList{
private:
    Node **head;
    int numberOfNodes;
public:
    LinkedList() {
        head = (Node **)malloc(sizeof(Node *));
        *head = nullptr;
        this->numberOfNodes = 0;
    }

    LinkedList(int numberOfNodes) : numberOfNodes(numberOfNodes) {
        head = (Node **)malloc(numberOfNodes * sizeof(Node *));
        *head = nullptr;
    }

    void add_node(int value) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        if(newNode != nullptr) {
            newNode->value = value;
            newNode->next = nullptr;

            if(*head == nullptr) {
                *head = newNode;
            } else {
                Node *aux = *head;
                while(aux->next != nullptr)
                    aux = aux->next;
                aux->next = newNode;
            }
        }
    }

    void remove_node(int value) {
        Node* previous, *current = *head;

        while(current != nullptr && current->value != value) {
            previous = current;
            current = current->next;
        }

        if(current != nullptr) {
            if(current == *head) {
                *head = (*head)->next;
            } else {
                previous->next = current->next;
                free(current);
            }
        }
    }

    void showNodes() {
        Node *aux = *head;
        while(aux != nullptr) {
            cout << aux->value << " ";
            aux = aux->next;
        }
        cout << endl;
    }

    // Approach one to reverse a linked list without using extra space, etc.
    void reversing() {
        // change each next member to the previous one
        Node* previous = nullptr, *current = *head, *ahead;
        while(current != nullptr) {
            ahead = current->next; // ahead receives the next one to not lose the loop
            current->next = previous; // where current is going to point to
            previous = current; // previous now is current (pointing to null)
            current = ahead; // current is ahead
        }

        *head = previous; // Updating new head
    }

    ~LinkedList () {
        Node* aux;
        while(*head != nullptr) {
            aux = *head;
            *head = (*head)->next;
            free(aux);
            aux = nullptr;
        }
        free(head);
        head = nullptr;
    }
};

int main()
{
    LinkedList l;
    l.add_node(1);
    l.add_node(7);
    l.add_node(6);
    l.add_node(11);
    l.add_node(2);
    l.add_node(89);
    l.add_node(43);

    l.showNodes();
    l.reversing();
    l.showNodes();
    return 0;
}

