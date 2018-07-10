#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{
    int const TAM = 100;
    double vet[TAM], num;

    cin >> num;
    vet[0] = num;
    for (int i = 1; i < TAM; i++)
    {
        vet[i] = num /= 2;
    }

    for (int i = 0; i < TAM; i++)
        printf("N[%d] = %.4f\n",i,vet[i]);
    return 0;
}
