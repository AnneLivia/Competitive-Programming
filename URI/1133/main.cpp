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

    for (int i = x + 1; i < y; i++)
    {
        if(i % 5 == 2 || i % 5 == 3)
        {
            cout << i << endl;
        }
    }
    return 0;
}
