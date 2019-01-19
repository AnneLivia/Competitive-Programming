#include <iostream>

using namespace std;
template <class T>
class LinkedQueue {
private:
    class Node {
    public:
        T item; // Item of abstract type
        Node* next;
        Node(T item, Node* next) : item(item), next(next) {}
    };
    Node *first, *last;
public:

    LinkedQueue() {
        first = last = nullptr;
    }

    bool isEmpty() {
        return (first == nullptr);
    }

    // Enqueue element of T type
    void enqueue(T item) {
        Node *newNode = new Node (item, nullptr); // Adding it to the end of the queue
        if(first == nullptr)
            first = newNode;
        else
            last->next = newNode;
        last = newNode;
    }

    // dequeue element of T type (first element)
    T dequeue() {
        if (isEmpty()) {
            throw "Queue is empty";
        }

        Node *aux = first;
        first = first->next;
        if(first == nullptr) // if first is now equal to null, there was only one element
            last = first; // set last to point to null too
        T item = aux->item;
        delete aux;
        aux = nullptr;
        return item;
    }

    ~LinkedQueue() {
        Node* aux;
        while(first != nullptr) {
            aux = first;
            first = first->next;
            free(aux);
            aux = nullptr;
        }
    }
};

class StaticQueue {
private:
    string *q;
    int head, tail, capacity, numberOfItems;
public:
    StaticQueue() {
        q = new string[1];
        head = tail = numberOfItems = 0;
        capacity = 1;
    }

    void resizeArray(int newCapacity) {
        string *newArr = new string[newCapacity];
        for (int i = 0; i < numberOfItems; i++) {
            newArr[i] = q[head + i];
        }

        q = newArr;
        head = 0;
        tail = numberOfItems;
        this->capacity = newCapacity;
    }

    void enqueue(string item) {
        if(numberOfItems == this->capacity) {
            resizeArray(2 * this->capacity);
        }
        q[tail++] = item;
        if(tail > this->capacity)
            tail = 0;
        numberOfItems++;
    }

    bool isEmpty() {
        return numberOfItems == 0;
    }

    int getHead() {return this->head;}
    int getTail() {return this->tail;}
    int getCapacity() {return this->capacity;}

    string dequeue() {
        if(isEmpty()) {
            throw "Empty queue";
        }
        string item = q[head++];
        if(head == this->capacity)
            head = 0;
        numberOfItems--;

        if(numberOfItems > 0 && numberOfItems == (this->capacity / 4)) {
            this->capacity/=2;
            resizeArray(this->capacity);
        }

        return item;
    }

    int sizeQueue() const {
        return this->numberOfItems;
    }

    ~StaticQueue() {
        delete[] q;
    }
};

int main()
{
    // LinkedQueue<string>qu;
    StaticQueue qu;
    try {
        qu.enqueue("300");
        qu.enqueue("22");
        qu.enqueue("23");
        qu.enqueue("24");
        qu.enqueue("27");
        qu.enqueue("30");
        qu.enqueue("80");
        qu.enqueue("90");
        qu.enqueue("800");
        qu.enqueue("22");
        qu.enqueue("4444");

        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;

    } catch(const char* e) {
        cerr << e << endl;
    }
    return 0;
}
