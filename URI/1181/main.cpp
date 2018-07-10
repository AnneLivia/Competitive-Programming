#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
    int const TAM = 12;
    float matriz[TAM][TAM], operation = 0;
    int l;
    char c;
    cin >> l;
    cin >> c;

    for ( int i = 0; i < TAM ; i++)
    {
        for ( int j = 0; j < TAM ; j++)
            cin >> matriz[i][j];
    }

    switch(c) {
        case 's' :
        case 'S' : for (int i = 0; i < TAM; i++)
                   {
                        operation += matriz[l][i];
                   }
                   printf("%.1f\n",operation);
                   break;
        case 'm' :
        case 'M' : for (int i = 0; i < TAM; i++)
                   {
                        operation += matriz[l][i];
                   }
                   operation = operation / TAM;
                   printf("%.1f\n",operation);
                   break;
    }

    return 0;
}
