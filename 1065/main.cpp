#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{
    int vet[5], contP = 0;

    for(int i = 0; i < 5; i++) {
        cin >> vet[i];
        if(vet[i] % 2 == 0)
            contP += 1;
    }

    cout << contP << " valores pares\n";
    return 0;
}
