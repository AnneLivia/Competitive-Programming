#include <iostream>

using namespace std;

// Grow and shrink array
// When push an element, increase size of array by 1
// When pop an element, decrease size of array by 1
// Too expensive (need to copy all items to a new array), (inserting first N items takes time proportional to N^2/2
// Ensures that array resizing happens infrequently
// How to grow array?
// If array is full, create new array of twice the size, and copy items

class ResizingArray {
private:
    string *s;
    int index, capacity;
public:
    ResizingArray() {
        s = new string[1]; // Starting with size 1
        capacity = 1;
        index = 0;
    }

    string& operator[](const int& index) {
        return this->s[index];
    }

    void push(string item) {
        if(index == this->capacity) { // If index is equal to the size of the array, now its time to grow array
            resizeArray(2 * this->capacity); // Doubling size;
        }
        s[index++] = item;
    }

    void resizeArray(int newCapacity) {
        string *aux = new string[newCapacity]; // new array double size
        for (int i = 0; i < this->capacity; i++) {
            aux[i] = s[i]; // Copying all elements to aux array
        }

        s = aux; // passing aux to s array
        this->capacity = newCapacity;
    }

    // Shrink array (when array is one-quarter full, make it to be halve size
    string pop() {
        if(index > 0) {
            string item = s[--index];
            s[index] = "";
            if(index > 0 && index == (this->capacity/4)) { // If array is not empty and its index is equal to a quarter of the capacity
                this->capacity = this->capacity / 2;
                resizeArray(this->capacity); // resize it to a halve size
            }
            return item;
            // Array is between 25% and 100%
        }
        return "";
    }

    int arraySize() {
        return this->index;
    }

    int getCapacity() {
        return this->capacity;
    }

    void clear_array() {
        for(int i = 0; i < this->capacity; i++)
            s[i] = "";
        index = 0;
        this->capacity = 1;
        resizeArray(1);
    }

    ~ResizingArray() {
        delete[] s;
    }

    friend ostream& operator << (ostream& stream, ResizingArray& ra);
};

ostream& operator << (ostream& stream, ResizingArray& ra) {
    for (int i = 0; i < ra.capacity; i++) {
        if (i != 0)
            cout << " ";
        stream << ra[i];
    }
    return stream;
}

int main()
{
    ResizingArray ra;
    string op;
    while(cin >> op) {
        if(op == "-")
            ra.pop();
        else
            ra.push(op);

        cout << "Size of array: " << ra.arraySize() << endl;
        cout << "Capacity of array: " << ra.getCapacity() << endl;
        cout << "All element: ";
        cout << ra << endl;
    }

    ra.clear_array();
    cout << "Size of array: " << ra.arraySize() << endl;
    cout << "Capacity of array: " << ra.getCapacity() << endl;
    cout << ra << endl;

    return 0;
}
