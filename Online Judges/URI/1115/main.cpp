#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int x, y;
    cin >> x >> y;
    while(x != 0 && y != 0){
        if(x > 0 && y > 0)
            cout << "primeiro\n";
        else if(x < 0 && y > 0)
            cout << "segundo\n";
        else if(x < 0 && y < 0)
            cout << "terceiro\n";
        else if(x > 0 && y < 0)
            cout << "quarto\n";
        cin >> x >> y;
    }

    return 0;
}
