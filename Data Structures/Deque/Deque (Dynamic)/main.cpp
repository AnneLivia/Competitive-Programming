#include <iostream>
#include <cstdlib>

using namespace std;

/*
    A Deque is a data structure that generalizes the queue. It can also
    be called Double-ended queue, because it instead of add only at the end
    like the queue, it also adds a data at the end. i.e, the elements can be
    added and removed from either the front and the back. It's sometimes called
    a head-tail linked list.

    Operations on Deque:
        The following are the basics operations on a Deque:
            InsertFront(): add an item at the front of the deque
            InsertLast(): add an item at the end of the deque
            deleteFront(): delete an item from the front of the deque
            deteleLast(): delete an item from the back of the deque
            getFront(): get the first element of the deque
            getRear(): get the last element of the deque (OBS: rear is the back part of something, especially a building or a vehicle)
            isEmpty(): check if the deque is empty
            isFull(): in case we are using a static deque, we can check if it is full
    Application of a deque:
        Since deque supports both stack and queue operations, it can be used as both.
        Maritime Channel control
        Verify palindromes
        Do and undo operations on software.
        and other.
    A deck can be implemented using circular array, double linked-list, etc.
    A circular array is when returns to 0 index when reached the end.
    It's a data structure that uses a array as if it were connected end-to-end.
    Also known as circular buffer, circular queue, cyclic buffer or ring buffer.
    The idea of a circular array is that the end of the array "wraps around" to the start of the array.

    When it is a static deque, the memory space it allocated at the time of compilation
        it demands to define the maximum number of elements
        the access is sequential: the elements are contiguous in memory

        There are two approaches to implements it:
            not circular array
            circular array (more efficient).
            If it were implemented using a not circular array, when we add an element at the front
            of the deque, we would have to move all elements one position ahead. but with circular array
            there's no need to do this.
    When it is a dynamic deque, the memory is allocated at run time
        the deque grows as it adds new elements and shrinks at it removes elements.
        the access is linked: each elements can be in a distinct area in memory

        Two approaches:
            dynamic linked list
            double dynamic linked list (more efficient when removing a node at the end!)
            In a dynamic linked list to remove a node from the end we would have to run
            through all the nodes until it reaches the back.
    In both approaches we can use a descriptor node (it contains more than the pointer
    to the first element info, it contains the pointer to the end, previous, etc, it depends
    on the data structure we are implementing and which data we need to store).
    ....
*/

// type of data that is going to be stored at the deque
struct Person {
    string name;
    int age, id;
};

template <class T>
struct Data {
    T value;
    Data<T> *next, *previous;
};

template <class T>
class DynamicDeque {
private:
    // pointer by pointer because it will receive a pointer
    Data<T> *head, *tail;
    int nElements;
public:
    DynamicDeque() {
        // Allocating memory (static implementation) fixed size
        this->head = nullptr;
        this->tail = nullptr;
        this->nElements = 0;
    }

    // insert element at the front of the deque
    void insertFront(T p) {
        // allocating memory and assign initially the p value passed, and make it point to head and null
        // head, because it will pointing to whatever head was pointing to.
        Data<T> *newData = new Data<T>({p, this->head, nullptr});
        // if deque is empty make head and tail points to the element
        if(this->isEmpty()) {
            this->tail = newData;
        } else {
            // otherwise just make the member previous from the element the head points to point to the element added
            this->head->previous = newData;
        }
        // head points to the element added at the front
        this->head = newData;
        // increment number of elements
        this->nElements++;
    }

    // insert element at the back of the deque
    void insertBack(T p) {
        // allocating memory and assign initially the p value passed, and make it point to null and null
        Data<T> *newData = new Data<T>({p, nullptr, nullptr});
        // if deque is empty make head and tail points to the element
        if(this->isEmpty()) {
            this->head = newData;
        } else {
            // otherwise just make the member next from the element the tail points to point to the element added
            this->tail->next = newData;
            // and the member previous from newData to points to the elements the tail points to
            newData->previous = this->tail;
        }
        // head points to the element added at the front
        this->tail = newData;
        // increment number of elements
        this->nElements++;
    }

    // Removing element from the front of the deque
    void removeFront() {
        // we cannot remove an element from a empty deque
        if(!this->isEmpty()) {
            // get the reference of the first element
            Data<T> *aux = this->head;
            // making head points to the next element in the queue
            this->head = this->head->next;
            // checking if there was only one element, if that's the case, make tail points to null
            // or else tail will be pointing to a not allocated memory, since it was deallocated
            if(this->head == nullptr) {
                this->tail = nullptr;
            } else {
                // otherwise, make new first node point to null, since the first one was removed
                this->head->previous = nullptr;
            }
            // deallocating data
            delete aux;
            // assign it to null to avoid dangling pointer
            aux = nullptr;
            // decrement number of elements
            this->nElements--;
        }
    }

    // Removing element from the back of the deque
    void removeBack() {
        // we cannot remove an element from a empty deque
        if(!this->isEmpty()) {
            // get the reference of the last element
            Data<T> *aux = this->tail;
            // making tail points to the previous element in the queue
            this->tail = this->tail->previous;
            // checking if there was only one element, if that's the case, make head points to null
            // or else head will be pointing to a not allocated memory, since it was deallocated
            if(this->tail == nullptr) {
                this->head = nullptr;
            } else {
                // otherwise, since the new last node was pointing to the removed one,
                // now it must point to null
                this->tail->next = nullptr;
            }
            // deallocating data
            delete aux;
            // assign it to null to avoid dangling pointer
            aux = nullptr;
            // decrement number of elements
            this->nElements--;
        }
    }

    // checking if the deque is full.
    bool isFull() const {
        // the deque is going be full only if there's no more space to allocate in the heap memory
        return false;
    }

    // checking if the deque is empty. i.e. if there isn't any element in the deque
    bool isEmpty() const {
        return (this->nElements == 0);
    }

    // return this number of elements that has been already added so far
    int getSize() const {
        return this->nElements;
    }
    // Getting the element at the front of the deque
    T getFront() const {
        if(!this->isEmpty())
            return this->head->value;

        // in case of error (like the deque is empty)
        throw "Empty Data Structure";
    }

    // Getting the element at the back of the deque
    T getRear() const {
        if(!this->isEmpty()) {
            // return back element
            return this->tail->value;
        }
        // in case of error (like the deque is empty)
        throw "Empty Data Structure";
    }

    // Destructor to deallocate the memory allocated when the object was instantiated
    ~DynamicDeque() {
        Data<T> *aux;
        while(head != nullptr) {
            aux = this->head;
            this->head = this->head->next;
            delete aux;
        }
        head = nullptr;
        tail = nullptr;
    }
};


int main()
{
    try {
        DynamicDeque<char> dq;
        for (char i = 'A'; i <= 'Z'; i++) {
            dq.insertBack(i);
        }

        cout.setf(ios::boolalpha);
        cout << "Is deque empty ? " << dq.isEmpty() << endl;
        cout << "How many elements there are: " << dq.getSize() << endl;
        cout << "Elements from the front to back:\n";
        while(!dq.isEmpty()) {
            cout << dq.getFront() << endl;
            dq.removeFront();
        }
        for (char i = 'A'; i <= 'Z'; i++) {
            dq.insertBack(i);
        }
        cout << "Elements from the back to front:\n";
        while(!dq.isEmpty()) {
            cout << dq.getRear() << endl;
            dq.removeBack();
        }
        // trying access element from an empty deque
        dq.getFront();


    } catch(const char* exc) {
        cerr << exc << endl;
    }

    return 0;
}
