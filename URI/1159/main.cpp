#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int x, cont = 1, sum = 0;
    cin >> x;
    while(x != 0)
    {
        while(cont <= 5) {
            if(x % 2 == 0) {
                sum = sum + x;
                cont++;
            }
            x++;
        }
        cout << sum << endl;
        sum = 0;
        cont = 1;
        cin >> x;
    }

    return 0;
}
