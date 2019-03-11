#include <iostream>

using namespace std;

/*
    Priority Queue is a special type of queue that generalizes the idea
    of sorting. The elements inserted in the queue has an extra data associated
    with them: their property.
    It's the value associated with that property that determines the position of an
    element in the queue, so as, which one must be the first to be removed from the queue,
    when necessary.
    Applications:
        Any problem that needs to establish a priority of access to the elements can be
        represented as a priority queue.
        Examples:
            - processor processes
            - a patient queue in a hospital
            - Dijkstra algorithm
            - interruptions manipulation
            - data compress (Huffman code)
            - arrival queue for airplanes according to fuel available
        ...
    ...
    Operations:
        create priority queue
        insert an element
        remove an element
        access the first element
        destruct the queue
        size, is full or empty, etc.

    Can be implemented using:
        dynamic linked list
        unsorted array
        sorted array
        binary heap
        etc.
    Time complexity is dependent upon the way this data structure is implemented:
        data structure        insertion      deletion
        dynamic linked list     O(N)          O(1)
        unsorted array          O(1)          O(N)
        sorted array            O(N)          O(1)
        binary heap           O(log N)      O(log N)
    ....

    Static implementation
        it utilizes an array to store elements
    disadvantages:
        it's necessary to define the size of the PQ previously
        it limits the number of elements to be added
    Advantage:
        Utilizes an array allows to use the same structure as the queue for two distinct implementation:
            sorted array
            binary heap
        We only need to modify three methods, the others are the same for both:
            insertion
            remove
            access
        ...
    ...
*/
struct Airplane {
    int id, priority;
};

/*
    A binary heap allows to simulate a binary tree complete or almost complete ( the exception is its last level)
    Each position is considered to be the parent of others two positions (left and right child)
    position i is the parent and 2 * i + 1 is the left child and 2 * i + 2 is the right child.
    Insertion: O(log n)
    Deletion: O(log n)
    In both operations it's necessary to fix and verify the heap properties violations
*/

class PQBinaryHeap {
private:
    Airplane *pq;
    int nElements, maximumCapacity;
public:
    PQBinaryHeap(int maximumCapacity) : maximumCapacity (maximumCapacity) {
        this->pq = new Airplane[maximumCapacity];
        this->nElements = 0;
    }

    // access element with highest priority (returns its id)
    int highestPriority() {
        // if the PQ is not empty, we can get an element
        if(!this->isEmpty()) {
            return this->pq[0].id; // root of the heap
        } else {
            // suppose there's no negative value in the available data
            return -1; // error
        }
    }

    void insertKey(Airplane air) {
        // if the PQ is not full, we can add an element
        if(!this->isFull()) {
            // adding it to the end of the binary heap
            this->pq[this->nElements] = air;
            // now fixing elements by shifting parent and child positions it necessary
            // where parent is accessed as (index - 1) / 2

            int index = this->nElements;
            // while index is different of 0, that is,
            while(index != 0 && this->pq[index].priority > this->pq[(index - 1) / 2].priority) {
                swap(this->pq[index], this->pq[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
            // increment number of elements
            this->nElements++;
        }
    }

    // recursive function to fix binary heap so that it can follow properties of a binary heap
    void heapify(int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int highest = index;

        // check greatest priority between index and its children (if root is smaller, move it to another position)

        if(left < this->nElements && this->pq[left].priority > this->pq[index].priority) {
            highest = left;
        }

        if(right < this->nElements && this->pq[right].priority > this->pq[highest].priority) {
            highest = right;
        }

        // if highest is different of index
        if(highest != index) {
            swap(this->pq[index], this->pq[highest]);
            this->heapify(highest);
        }
    }

    void extractKey() {
        // if the PQ is not empty, we can remove an element
        if(!this->isEmpty()) {
            // copy element from the end to the root of the array
            this->pq[0] = this->pq[this->nElements - 1];
            // decrement number of elements
            this->nElements--;
            // heapify in order to follow binary heap properties correctly
            this->heapify(0);
        }
    }

    bool isFull() const {
        return (this->nElements == this->maximumCapacity);
    }

    bool isEmpty() const {
        return (this->nElements == 0);
    }

    int getSize() const {
        return this->nElements;
    }

    // delete all elements with the destructor
    ~PQBinaryHeap() {
        delete[] pq;
    }
};
int main()
{
    PQBinaryHeap pq(5);
    pq.insertKey({12,1});
    pq.insertKey({22,44});
    pq.insertKey({32,14});
    pq.insertKey({42,17});
    pq.insertKey({88,90});


    while(!pq.isEmpty()) {
        cout << "Highest: " << pq.highestPriority() << endl;
        pq.extractKey();
    }

    cout << "Is it empty: " << pq.isEmpty() << endl;
    return 0;
}
