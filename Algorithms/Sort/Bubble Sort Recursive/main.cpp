#include <iostream>

using namespace std;

void swap_numbers(int *n1, int *n2) {
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

void bubbleSort_recursive(int *v, int n) {
    if(n == 1) // When the size is equal to 1, the recursion will stop
        return;
    // Do just one pass and swapping, putting the largest number inside the array to the end
    for(int i = 0; i < n; i++) {
        if(v[i] > v[i + 1])
            swap_numbers(&v[i],&v[i+1]);
    }
    bubbleSort_recursive(v,n-1); // When done that, call the function again, now with the size n - 1, since the largest number is already in the end
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
    cout << "Before bubble sort: \n";
    print(vet,10);
    bubbleSort_recursive(vet,10);
    cout << "After bubble sort: \n";
    print(vet,10);
    return 0;
}
