#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int x, y, aux;
    cin >> x >> y;
    if(x > y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    aux = 0;
    for (int i = x; i <= y; i++)
    {
        if(i % 13 != 0)
        {
            aux += i;
        }
    }
    cout << aux << "\n";

    return 0;
}
