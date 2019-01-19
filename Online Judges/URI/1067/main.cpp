#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{
    int x;

    do {
        cin >> x;
    }while(x < 1 && x > 1000);

    for (int i = 1; i <= x; i++)
    {
        if(i % 2 != 0)
            cout << i << endl;
    }

    return 0;
}
