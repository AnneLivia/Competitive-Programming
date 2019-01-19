#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char c;
    int col;
    float matriz[12][12], soma = 0;

    cin >> col;
    cin >> c;

    for ( int i = 0 ; i < 12; i++) {
        for ( int j = 0 ; j < 12; j++) {
            cin >> matriz[i][j];
        }
    }

    for ( int i = 0 ; i < 12; i++)
        soma = soma + matriz[i][col];

    switch (c) {
        case 's' :
        case 'S' : printf("%.1f\n",soma);
                   break;
        case 'm' :
        case 'M' : printf("%.1f\n",soma/12);
                   break;
    }
    return 0;
}
