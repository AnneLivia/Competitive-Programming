#include <iostream>

using namespace std;

void swap_numbers(int *n1, int *n2) {
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

// Basically in the selection sort, the minimum elements are going to be inserted at the leftmost side of the array
void selectionSort_recursive(int *v, int n, int start) {
    if(start == n - 1) // When the start is equal to the total of element in the array, then the recursion will stop.
        return;

    int minimum = start; // Assuming the minimum element is the first one.

    // Do just one pass and search for an element lesser than the first one
    for(int i = start + 1; i < n; i++) { // Start from start + 1 since the first element is already in the variable minimum
        if(v[minimum] > v[i])
            minimum = i;
    }
    // After check
    if(start != minimum)
        swap_numbers(&v[start],&v[minimum]);
    selectionSort_recursive(v,n,start + 1); // When done that, call the function again, now with the start + 1, since the minimum number is already in the beginning of the array
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
    cout << "Before Selection sort: \n";
    print(vet,10);
    selectionSort_recursive(vet,10,0);
    cout << "After Selection sort: \n";
    print(vet,10);
    return 0;
}
