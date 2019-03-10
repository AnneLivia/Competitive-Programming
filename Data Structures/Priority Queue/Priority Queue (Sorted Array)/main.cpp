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
    The elements here are sorted in ascending order.
    The element with highest priority is going to be inserted at the end of the array (front of the queue)
    The element with highest priority is going to be inserted at the front of the array (back of the queue)
    Insertion: O(N) (need to search for a specific point to insert)
    Deletion: O(1) (at the end of the array)
*/

// that's a max binary heap
class PQSortedArray {
private:
    Airplane *pq;
    int nElements, maximumCapacity;
public:
    PQSortedArray(int maximumCapacity) : maximumCapacity (maximumCapacity) {
        this->pq = new Airplane[maximumCapacity];
        this->nElements = 0;
    }

    // access element with highest priority (returns its id)
    int highestPriority() {
        // if the PQ is not empty
        if(!this->isEmpty()) {
            // return last element of the array (highest priority is placed there)
            return this->pq[this->nElements - 1].id;
        } else {
            return -1; // error
        }
    }

    // need to search for a place to insert element, it can be either at the front, middle or back of array
    // it depends upon its priority. in front and middle, it's necessary shift position of other elements.
    void insertKey(Airplane air) {
        // if the PQ is not full, it's allowed to insert an element
        if(!this->isFull()) {
            int index = this->nElements - 1;
            // making the comparison between the priority passed and the priority of elements in the PQ
            // if the priority of the data passed is lesser than the priority of the item in the current
            // position, we need to shift position
            while(index >= 0 && air.priority < this->pq[index].priority) {
                // moving elements one position ahead
                swap(this->pq[index], this->pq[index + 1]);
                index--;
            }
            // when it gets here, the element can be added to the index position + 1
            this->pq[index + 1] = air;
            // increment number of elements
            this->nElements++;
        }
    }

    void extractKey() {
        // if the PQ is not empty we can remove an element
        if(!this->isEmpty()) {
            // the one with highest priority in at the end
            // remove it by just decrement the number of elements
            this->nElements--;
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
    ~PQSortedArray() {
        delete[] pq;
    }
};
int main()
{
    PQSortedArray pq(5);
    pq.insertKey({12,1});
    pq.insertKey({22,44});
    pq.insertKey({32,14});
    pq.insertKey({42,17});


    while(!pq.isEmpty()) {
        cout << "Highest: " << pq.highestPriority() << endl;
        pq.extractKey();
    }

    cout << "Is it empty: " << pq.isEmpty() << endl;
    return 0;
}
