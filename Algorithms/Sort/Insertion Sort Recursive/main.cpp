#include <iostream>

using namespace std;

void insertionSort_recursive(int *v, int n) {
    if(n <= 1)
        return;

    insertionSort_recursive(v,n-1); // This is going to create a stack of calls in the memory until it find the size equals to 1, and then it will return to all the calls

    // In each call will be done this
    int last = v[n - 1]; // Getting the last element, since the number returned is one greater then the position, then it must be decreased by one
    int j = n - 2; // Insertion sorts works by checking if the element is lesser then the before ones, because of that, j start by n - 1

    // while j is greater equal than 0 and the value in the "last" position is lesser than the current value in position j
    // it will move the elements to one position ahead of the array
    while(j >= 0 && last < v[j]) {
        v[j + 1] = v[j]; // Moving element
        j--;
    }

    v[j + 1] = last; // position j + 1 is going to receive the last element

    // Now this call to the function ends, and goes to the other in the stack
}

void print(int *v, int n) {
    for ( int i = 0; i < n; i++) {
        cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    int vet[10] = {1,6,4,3,24,4,6,5,3,0};
    cout << "Before insertion sort: \n";
    print(vet,10);
    insertionSort_recursive(vet,10);
    cout << "After insertion sort: \n";
    print(vet,10);
    return 0;
}
