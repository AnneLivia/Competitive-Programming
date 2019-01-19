#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
    float n1,n2, opt;
    while (true) {
        while(true) {
            cin >> n1;
            if(n1 < 0 || n1 > 10)
                cout << "nota invalida\n";
            else
                break;
        }

        while(true) {
            cin >> n2;
            if(n2 < 0 || n2 > 10)
                cout << "nota invalida\n";
            else
                break;
        }

        printf("media = %.2f\n",(n1 + n2) / 2);
        do {
            cout << "novo calculo (1-sim 2-nao)\n";
            cin >> opt;
        }while(opt < 1 || opt > 2);

        if(opt == 2) {
            break;
        }
    }

    return 0;
}
