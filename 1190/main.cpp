#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char c;
    double matriz[12][12], soma = 0;
    int b = 10, cont = 0;

    cin >> c;

    for ( int i = 0 ; i < 12; i++) {
        for ( int j = 0 ; j < 12; j++) {
            cin >> matriz[i][j];
        }
    }

    for ( int i = 1; i <= 10; i++) {
        for ( int j = 11; j > b; j--) {
            soma = soma + matriz[i][j];
            cont++;
        }
        if(i < 5)
            b--;
        else if(i >= 6)
            b++;
    }


    switch (c) {
        case 'S' : printf("%.1f\n",soma);
                   break;
        case 'M' : printf("%.1f\n",soma/cont);
                   break;
    }
    return 0;
}
