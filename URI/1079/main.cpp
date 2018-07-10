#include <iostream>
#include "stdio.h"
using namespace std;


int main()
{
    int n;
    float value[3];

    cin >> n;
    float *vet = new float[n];

    for ( int i = 0; i < n; i++)
    {
        cin >> value[0] >> value[1] >> value[2];
        vet[i] = ((value[0] * 2) + (value[1] * 3) + (value[2] * 5)) / (2 + 3 + 5);
    }

    for (int i = 0 ; i < n ; i++)
    {
        printf("%.1f\n",vet[i]);
    }

    delete[] vet;




    return 0;
}
