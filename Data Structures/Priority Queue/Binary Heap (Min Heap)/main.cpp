#include <iostream>

using namespace std;

/*
    A binary heap is a complete binary tree (all levels are completely) this
    allow the binary heap to be store in a array.
    A binary heap can be divide into min heap and max heap, where:
        min heap: the key at the root is minimum among all keys that belongs to the heap
        max heap: the key at the root is maximum among all keys that belongs to the heap
    A binary heap is often represented as an array where the root is the index 0.
    The specify the parent, left and right child, the following formulas are applied:
        >> (i - 1) / 2: get the parent of a node
        >> (2 * i) + 1: get the left child of a node
        >> (2 * i) + 2: get the right child of a node
    The traversal method use to achieve Array representation is Level Order
    Example:
           10
         /   \
        4     8
      /  \   / \
     3   2  7  5
    Printing in level order here, would be: 10,4,8,3,2,7,5

    Applications:
        >> HeapSort
        >> priority queue
        >> Dijkstra's Algorithm, Prim's algorithm, etc.
        >> many others.
    Operations:
        getMinimum(): get the element from a min heap; O(1)
        extractMinimum(): remove the minimum from a min heap; O(log n)
        decreaseKey(): decreases value of key; O(log n);
        /
            If the decreases key value of a node is greater than the parent
            of the node, then we don't need to do anything. Otherwise, we need
            to traverse up to fix the violated heap property.
        /
        insert(): insert a new key; O(log n);
        /
            We add a new key at the end of the tree. IF new key is greater than
            its parent, then we don't need to do anything. Otherwise, we need
            to traverse up to fix the violated heap property.
        /
        delete(): delete a key; O(log n);
        /
            We replace the key to be deleted with minimum infinite by calling decreaseKey().
            After decreaseKey(), the minus infinite value must reach root, so we call extractMin()
            to remove the key.
        /
*/

// min heap: root is minimum
class MinHeap {
private:
    int *minHeap, nElements, maximumCapacity;
public:
    MinHeap(int maximumCapacity) : maximumCapacity (maximumCapacity) {
        this->nElements = 0;
        // creating array with maximumCapacity size
        this->minHeap = new int[this->maximumCapacity];
    }

    // insert a new key to the heap
    void insertKey(int value) {
        // if it's full, we cannot add any other element
        if(!this->isFull()) {
            // insert element at the end
            this->minHeap[this->nElements] = value;
            // fix the min heap in case of violation
            int index = this->nElements;
            // while the index is different of 0, i.e. it's not the first element added at the heap
            // and the element from the parent of the this added node is greater than it. we swap them
            // child and parent. to access parent position, we do (i - 1) / 2
            while(index != 0 && this->minHeap[((index - 1) / 2)] > this->minHeap[index]) {
                // swap them
                swap(this->minHeap[((index - 1)/ 2)], this->minHeap[index]);
                // now index is at its parent position was
                index = (index - 1) / 2;
            }
            this->nElements++;
        }
    }

    bool isFull() const {
        return (this->nElements == maximumCapacity);
    }

    bool isEmpty() const {
        return (this->nElements == 0);
    }

    // remove key from heap at index passed through parameter
    void deleteKey(int index) {
        // first decrease value to make it the minimum one, so that it can be the first one in the heap
        this->decreaseKey(index, INT_MIN);
        // now extract minimum from heap which is at the root
        this->extractMinimum();
    }

    // extract minimum node from the heap which is the root
    int extractMinimum() {
        // if the element heap is empty
        if(this->isEmpty())
            return -1;

        // get the minimum value from root
        int root = this->minHeap[0];

        // decrease the number of elements
        this->nElements--;

        // if it's not empty, fix heap
        if(this->nElements != 0){
            // make index 0 receives the last element
            this->minHeap[0] = this->minHeap[this->nElements];
            // Rearrange the heap to maintain its property from index 0
            this->heapify(0);
        }
        // return extracted root
        return root;
    }

    // this method is used to update a value (decreasing) from a specific position index
    void decreaseKey(int index, int newValue) {
        // update value at the index position
        this->minHeap[index] = newValue;
        // fix binary heap in case of violation
        while(index != 0 && this->minHeap[((index - 1)/2)] > this->minHeap[index]) {
            swap(this->minHeap[((index - 1)/2)], this->minHeap[index]);
            index = (index - 1) / 2;
        }
    }

    // get the minimum element which is at the root, index 0
    int getMinimum() const {
        return this->minHeap[0];
    }

    // get the number of elements
    int getNumberOfElements() const {
        return this->nElements;
    }

    // Heapify function: Rearrange a heap to maintain the heap property,
    // that is, the key of the root node is more extreme (greater or less)
    // than or equal to the keys of its children. If the root node's key is
    // not more extreme, swap it with the most extreme child key, then recursively
    // heapify that child's subtree. The child subtrees must be heaps to start.
    void heapify(int index) {
        // that's a recursive function
        // We need to compare the value at the index with its children, left and right
        int leftChild =  (index * 2) + 1;
        int rightChild = (index * 2) + 2;
        int smallest = index; // it's going to store the smallest one to change with the index
        // check if the leftChild is less than or equal to the number of elements,
        // i.e. we haven't reached the end of the heap and the maximum capacity
        // and if the leftChild is less than its parent (index), we assign it as the smallest one
        if(leftChild < this->nElements && this->minHeap[leftChild] < this->minHeap[index]) {
            smallest = leftChild;
        }

        // checking now if the rightChild is smaller than the leftChild, or in case, the left child wasn't
        // smaller, check the right and index.
        if(rightChild < this->nElements && this->minHeap[rightChild] < this->minHeap[smallest]) {
            smallest = rightChild;
        }

        // if the smallest element is different from the index swap the elements at index and smallest position and
        // call function again recursively. otherwise, the binary heap is already fixed
        if(smallest != index) {
            swap(this->minHeap[smallest], this->minHeap[index]);
            this->heapify(smallest);
        }
    }

    ~MinHeap() {
        // deallocating
        delete[] this->minHeap;
    }
};
int main()
{
    MinHeap mp(10);
    mp.insertKey(75);
    mp.insertKey(63);
    mp.insertKey(36);
    mp.insertKey(15);
    mp.insertKey(21);
    mp.insertKey(72);
    mp.insertKey(70);
    mp.insertKey(12);
    mp.insertKey(18);
    mp.insertKey(65);

    while(!mp.isEmpty()) {
        cout << "Min: " << mp.extractMinimum() << endl;
    }

    mp.insertKey(1);
    mp.insertKey(2);
    mp.insertKey(3);
    cout << "Min element: " << mp.getMinimum() << endl;
    cout << "Number of elements: " << mp.getNumberOfElements() << endl;
    mp.decreaseKey(2, -88);
    cout << "Min element: " << mp.getMinimum() << endl;
    cout << "Number of elements: " << mp.getNumberOfElements() << endl;
    mp.deleteKey(2);
    while(!mp.isEmpty()) {
        cout << "Min: " << mp.extractMinimum() << endl;
    }
    return 0;
}
