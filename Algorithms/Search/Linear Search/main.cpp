#include <iostream>
#include <ctime>
#include <cstdlib>
#define TAM 10

/*
    Name: Anne Livia
    Linear search is one of the most simple search algorithm
    it checks if one specific value is equals to any value inside the array by
    comparing one by one until it finds, in case the element its not there, it will run through
    all the array, because of that this has a complexity of O(n).

*/

using namespace std;

int linear_search(int *v, int tam, int n) {
    for ( int i = 0; i < tam; i++) {
        if(n == v[i])
            return i; // Return the pos of the element
    }
    return -1; // Returning -1 in case the value its not in the array

}

void print_array(int *v, int tam) {
    for ( int i = 0; i < tam; i++) {
        cout << " " << v[i];
    }
}

int main()
{
    srand(time(NULL));
    int v[TAM], n, pos;
    for ( int i = 0; i < TAM; i++) {
        v[i] = 1 + rand() % 1000;
    }

    print_array(v,TAM);

    cout << "\n Search for a value: ";
    cin >> n;

    pos = linear_search(v,TAM,n);

    if(pos != -1)
        cout << "\n The value " << n << " is in the " << pos + 1 << " position\n";
    else
        cout << "\n The value " << n << " was not found.\n";

    return 0;
}
