#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int n[10], value;

    cin >> value;

    n[0] = value;
    for(int i = 1; i < 10; i++)
        n[i] = n[i-1] + n[i-1];

    for(int i = 0; i < 10; i++)
    {
        cout << "N["<<i<<"] = " << n[i] << endl;
    }


    return 0;
}
