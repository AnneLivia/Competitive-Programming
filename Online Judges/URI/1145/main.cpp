#include <iostream>
#include "stdio.h"
#include "math.h"
using namespace std;

int main()
{

    int x,y, cont = 1;
    cin >> x >> y;

    for (int i = 1; i <= y; i++)
    {
        cout << i;
        if(cont == x) {
            cout << "\n";
            cont = 1;
        }
        else {
            cont++;
            cout << " ";
        }
    }
    return 0;
}
