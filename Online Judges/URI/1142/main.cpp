#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n * 4; i++)
    {
        if(i % 4 == 0)
            cout << "PUM\n";
        else
            cout << i << " ";
    }
    return 0;
}

