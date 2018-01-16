#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int j = 7, aux, cont = 0;
    for (int i = 1; i <= 9; i+=2)
    {
        aux = j;
        while(cont < 3) {
            cout << "I="<<i<<" J="<<aux<<endl;
            aux--;
            cont++;
        }
        cont = 0;
        j+=2;
    }
    return 0;
}
