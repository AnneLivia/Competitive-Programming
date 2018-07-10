#include <iostream>
#include "stdio.h"
using namespace std;


int main()
{
    int n, x, in, out;
    in = out = 0;
    do {
        cin >> n;
    } while (n > 10000);

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x >= 10 && x <= 20)
            in +=1;
        else
            out +=1;
    }

    cout << in << " in\n";
    cout << out << " out\n";
    return 0;
}
