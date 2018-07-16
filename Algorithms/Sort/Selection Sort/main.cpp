#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define TAM 10

using namespace std;

/*
    Name: Anne Livia

    This sort algorithm divide an array into two sub-arrays
    one, on the leftmost side, the sorted list and the other, rightmost side, the
    unsorted one. It searches for the minimum element and then swap with the leftmost element.
    It's an O(n^2) algorithm.
    Example:
    Array = {1,7,3,2,8};
    minimum = 1;
    search inside the array for an element lesser that this one
    if there is a lesser element, then:
        swap 1 with the lesser element

    And then, make min goes to the next element in the array, e.g: 7.

*/
void swap_number(int *pos1, int *pos2) {
    int aux = *pos1;
    *pos1 = *pos2;
    *pos2 = aux;
}

void selection_sort(int *v, int tam) {
    int menor;
    for ( int i = 0; i < tam - 1; i++) {
        menor = i; // getting the elements of the leftmost side
        for ( int j = i + 1; j < tam; j++) {
            if(v[menor] > v[j]) { // searching for a lesser element
                menor = j;
            }
        }
        if(menor != i) // if was found an element lesser then the one in the current i position
            swap_number(&v[menor],&v[i]); // swap the values
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

    selection_sort(v,TAM);

    cout << "\n --------------------------------------\n";

    print_array(v,TAM);

    cout << "\n";
    return 0;
}
