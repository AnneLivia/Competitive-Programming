#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int n, fat = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fat = fat * i;
    }
    cout << fat << endl;
    return 0;
}
