#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int x, a = 1, b = 0, c = 0, cont = 1;
    cin >> x;
    cout << 0 << " ";
    while(cont < x) {
        cout << a;
        c = a;
        a = a + b;
        cont +=1;
        if(cont == x)
            break;
        else
            cout << " ";
        b = c;
        cout << a;
        c = a;
        a = a + b;
        cont+=1;
        if(cont == x)
            break;
        else
            cout << " ";
        b = c;
    }
    cout << endl;

    return 0;
}
