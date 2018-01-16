#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    float s = 0, i = 1, cont = 1;

    while(i <= 39) {
        s = (i / cont) + s;
        cont = cont * 2;
        i +=2;
    }

    printf("%.2f\n",s);
    return 0;
}
