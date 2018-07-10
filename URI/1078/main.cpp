#include <iostream>
#include "stdio.h"
using namespace std;


int main()
{
    int n;

    do {
        cin >> n;
    }while ( n <= 2 && n >= 1000);

    for (int i = 1; i <= 10; i++)
    {
        cout << i << " x " << n << " = " << i * n << endl;
    }

    return 0;
}
