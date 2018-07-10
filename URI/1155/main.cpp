#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    float s = 0, cont = 1;
    while(cont <= 100)
    {
        s = 1/cont + s;
        cont = cont + 1;
    }

    printf("%.2f\n",s);
    return 0;
}
