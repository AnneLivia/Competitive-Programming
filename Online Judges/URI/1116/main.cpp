#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int n;
    float x, y;
    cin >> n;
    for (int i = 1 ; i <= n; i++)
    {
        cin >> x >> y;
        if(y == 0)
            cout << "divisao impossivel\n";
        else
            printf("%.1f\n",x / y);
    }



    return 0;
}
