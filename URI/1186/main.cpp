#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char c;
    float matriz[12][12], soma = 0, cont = 0;

    cin >> c;

    for ( int i = 0 ; i < 12; i++) {
        for ( int j = 0 ; j < 12; j++) {
            cin >> matriz[i][j];
        }
    }
    int z = 1;
    for ( int i = 11 ; i >= 1; i--) {
        for ( int j = z; j <= 11; j++) {
            soma = soma + matriz[i][j];
            cont++;
        }
        z++;
    }


    switch (c) {
        case 's' :
        case 'S' : printf("%.1f\n",soma);
                   break;
        case 'm' :
        case 'M' : printf("%.1f\n",soma/cont);
                   break;
    }
    return 0;
}
