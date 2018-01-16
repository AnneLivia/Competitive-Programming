#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{
    int x, cont = 0;

    cin >> x;

    for (int i = x; i < x * x; i++)
    {
        if(i % 2 != 0) {
            cout << i << endl;
            cont++;
        }

        if(cont == 6) {
            break;
        }
    }
    return 0;
}
