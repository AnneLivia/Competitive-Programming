#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define TAM 10

/*
    Name: Anne Livia
    This is an algorithm that swap the adjacent elements if they are in wrong order.
    This algorithm needs one whole pass without any swap to know it is sorted.
    The above function always runs O(n^2) time even if the array is sorted.
    It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.
*/

using namespace std;

void swap_number(int *pos1, int *pos2) {
    int aux = *pos1;
    *pos1 = *pos2;
    *pos2 = aux;
}
// Bubble sort in a optimized way, since without the variable swapped, it would run all array again
void bubble_sort(int *v, int tam) {
    int swapped;
    for(int i = 0; i < tam - 1; i++) {
        swapped = 0;
        for(int j = 0; j < tam - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                swap_number(&v[j],&v[j+1]);
                swapped = 1;
            }
        }
        if(!swapped)
            break; // In case there wasn't any swap, the stop the loop
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

    bubble_sort(v,TAM);

    cout << "\n --------------------------------------\n";

    print_array(v,TAM);

    cout << "\n";
    return 0;
}
