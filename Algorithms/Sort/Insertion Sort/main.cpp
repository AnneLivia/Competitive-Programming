#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define TAM 10

/*
    Name: Anne Livia
    This is an algorithm that works in the exactly way that we sort playing card
    The function runs in the worst case O(n^2).
    Algorithmic Paradigm: Incremental Approach.
    Uses: Insertion sort is used when number of elements is small. It can also be
    useful when input array is almost sorted, only few elements are misplaced in complete big array.
    We can create a binary insertion sort, where, according to the website geeks for geeks:
    We can use binary search to reduce the number of comparisons in normal insertion sort.
    Binary Insertion Sort find use binary search to find the proper location to insert the selected
    item at each iteration. In normal insertion, sort it takes O(i) (at ith iteration) in worst case.
    we can reduce it to O(log i) by using binary search. The algorithm as a whole still has a running
    worst case running time of O(n2) because of the series of swaps required for each insertion. Refer this for implementation.

    Example:
    7 8 9 3 2 1
    7 8 9 3 2 1 -> first pass
    7 8 9 3 2 1 -> second pass var pos = 0
    3 2 7 8 9 1 -> third pass var pos = 1
    1 3 2 7 8 9 -> fourth pass var pos = 0

*/

using namespace std;

/*
    Geeks for geeks implementation:

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

    // Move elements of arr[0..i-1], that are
    // greater than key, to one position ahead
    // of their current position

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
*/

void insertion_sort(int *v, int tam) {
    int pos, aux;
    for ( int i = 1; i < tam; i++) {
        pos = i;
        for ( int j = i - 1; j >= 0; j--) {
            if(v[i] < v[j])
                pos = j;
        }
        aux = v[i];
        if(pos != i) {
            for(int j = i; j > pos; j--) {
                v[j] = v[j - 1];
            }
            v[pos] = aux;
        }
    }

}

void print_array(int *v, int tam) {
    for ( int i = 0; i < tam; i++) {
        cout << " " << v[i];
    }
}

int main()
{
    srand(time(NULL));
    int v[TAM];
    for ( int i = 0; i < TAM; i++) {
        v[i] = 1 + rand() % 1000;
    }

    print_array(v,TAM);

    insertion_sort(v,TAM);

    cout << "\n --------------------------------------\n";

    print_array(v,TAM);
    return 0;
}
