#include <iostream>
#include "stdio.h"
using namespace std;


int main()
{
    int n;

    do {
        cin >> n;
    }while ( n > 10000);

    for (int i = 1; i < 10000; i++)
    {
        if(i % n == 2) {
            cout << i << endl;
        }
    }

    return 0;
}
