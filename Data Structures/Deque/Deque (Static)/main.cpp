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
class CircularStaticDeque {
private:
    T *_deque;
    int dSize, nElements, _front, _rear;
public:
    CircularStaticDeque(int dSize) {
        this->dSize = dSize;
        this->nElements = this->_front = this->_rear = 0;
        // Allocating memory (static implementation) fixed size
        _deque = new T[this->dSize];
    }

    // insert element at the front of the deque
    void insertFront(T p) {
        // If the deque is not full, we can insert a new value to it
        if(!this->isFull()) {
            // decrement the _front by one, if it is negative, when assign to it
            // the last acceptable position of the array
            _front--;
            if(_front < 0) {
                _front = dSize - 1;
            }

            this->_deque[_front] = p;

            // increment the number of elements
            nElements++;
        }
    }

    // insert element at the back of the deque
    void insertBack(T p) {
        // if it's not full we can add an element
        if(!this->isFull()) {
            // insert at the available position
            this->_deque[this->_rear] = p;
            // now increment the _rear position by one to get another available position
            this->_rear+=1;
            // check if the _rear is greater than the capacity of the array, if it is,
            // it must return back to the front of the array, i.e. the first index (0).
            if(this->_rear >= dSize) {
                _rear = 0;
            }
            // those instructions above is the same as:
            // this->_rear = (this->_rear + 1) % this->dSize;
            // for the above operation, it only returns 0 when it gets to the end of the deque
            // suppose dSize is 9, and _rear + 1 is 9, 9 % 9 is 0, otherwise, suppose dSize is
            // 9 and _rear + 1 is 5, 5 % 9 is 5, the remainder is the number.

            // increment the number of elements
            nElements++;
        }
    }

    // Removing element from the front of the deque
    void removeFront() {
        // we cannot remove an element from a empty deque
        if(!this->isEmpty()) {
            // increment the front by one, if it gets to end, assign to it the index 0
            this->_front = (this->_front + 1) % dSize;
            // decrement the number of elements
            this->nElements--;
        }
    }

    // Removing element from the back of the deque
    void removeBack() {
        // we cannot remove an element from a empty deque
        if(!this->isEmpty()) {
            // decrement _rear by one, if it gets a unavailable position (negative index),
            // assign to it the dSize - 1 index.
            this->_rear = this->_rear - 1 < 0 ? this->dSize - 1 : this->_rear - 1;
            // decrement the number of elements
            this->nElements--;
        }
    }

    // checking if the deque is full. i.e. if the capacity of the deque has been achieved
    bool isFull() const {
        return (this->nElements == dSize);
    }

    // checking if the deque is empty. i.e. if there isn't any element in the deque
    bool isEmpty() const {
        return (this->nElements == 0);
    }

    // return this number of elements that has been already added so far
    int getSize() const {
        return this->nElements;
    }

    // return the maximum capacity of the deque since its static
    int getCapacity() const {
        return this->dSize;
    }

    // Getting the element at the front of the deque
    T getFront() const {
        if(!this->isEmpty())
            return this->_deque[_front];

        // in case of error (like the deque is empty)
        throw "Empty Data Structure";
    }

    // Getting the element at the back of the deque
    T getRear() const {
        if(!this->isEmpty()) {
            // The rear pointer doesn't point to the last element, it points to a specific position where we can store a value
            // so, in order to get the last element of the deque, we can simply decrease the variable that keeps track of the
            // available position to insert at the end of the deque by one. But since this is a circular array, the pointer
            // could have been pointing to the first index (0) of the array, which means that, if we decrease it by one, we
            // we can get a unavailable position (negative index), that means that, the last element added to the deque is at
            // last index of the array (qSize (maximum capacity) - 1) and the variable that is referencing the end of the deque, is now
            // pointing to the first index (0), which means that, if we decrease the _rear and the result is a negative number,
            // the last value added is at the end of the array (dSize - 1), otherwise, we just assign the _rear - 1.
            int position = _rear - 1 < 0 ? dSize - 1 : _rear - 1;
            // return back element
            return this->_deque[position];
        }
        // in case of error (like the deque is empty)
        throw "Empty Data Structure";
    }

    // Destructor to deallocate the memory allocated when the object was instantiated
    ~CircularStaticDeque() {
        delete[] _deque;
    }
};


int main()
{
    try {
        CircularStaticDeque<int>dq(5);

        cout << "Before add 5 elements:\n";
        if(dq.isEmpty()) {
            cout << ">> The deque is empty\n";
        } else {
            cout << ">> The deque is not empty\n";
        }

        if(dq.isFull()) {
            cout << ">> The deque is full\n";
        } else {
            cout << ">> The deque is not full\n";
        }

        dq.insertFront(1);
        dq.insertFront(2);
        dq.insertFront(3);
        dq.insertBack(4);
        dq.insertBack(5);

        cout << "After add 5 elements to the queue:\n";
        if(dq.isEmpty()) {
            cout << ">> The deque is empty\n";
        } else {
            cout << ">> The deque is not empty\n";
        }

        if(dq.isFull()) {
            cout << ">> The deque is full\n";
        } else {
            cout << ">> The deque is not full\n";
        }
        cout << "Printing and removing elements from the deque:\n";
        // must print 3 2 1 4 5 if we remove from the front all 5 added values
        cout << dq.getFront() << endl;
        dq.removeFront();
        cout << dq.getFront() << endl;
        dq.removeFront();
        cout << dq.getFront() << endl;
        dq.removeFront();
        cout << dq.getFront() << endl;
        dq.removeFront();
        cout << dq.getFront() << endl;
        dq.removeFront();
        cout << "After all removals\n";

        if(dq.isEmpty()) {
            cout << ">> The deque is empty\n";
        } else {
            cout << ">> The deque is not empty\n";
        }
        if(dq.isFull()) {
            cout << ">> The deque is full\n";
        } else {
            cout << ">> The deque is not full\n";
        }
        cout << "Trying get an element from a empty deque:\n";
        dq.getRear();
    } catch(const char* exc) {
        cerr << exc << endl;
    }
    return 0;
}
