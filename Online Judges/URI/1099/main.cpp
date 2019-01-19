#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int n, x, y, aux, *vet;
    cin >> n;
    vet = new int[n];
    for (int i = 0; i < n; i++)
    {
        vet[i] = 0;
        cin >> x >> y;
        if(x > y)
        {
            aux = x;
            x = y;
            y = aux;
        }

        for (int j = x + 1; j < y; j++)
        {
            if(j % 2 != 0)
                vet[i] = vet[i] + j;
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << endl;
    }

    delete[] vet;
    return 0;
}
