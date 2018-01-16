#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    float i = 0, j = 1;
    int aux, cont = 0;
    do{
        cont = 0;
        while(cont < 3) {
            cout << "I=" << i << " J=" << j << endl;
            j+=1;
            cont++;
        }

        i+=0.2;
        j = 1 + i;
    }while(i <= 2.1);
    return 0;
}
