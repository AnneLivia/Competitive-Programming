#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int m, n;
    cin >> m >> n;
    while(m != n){
        if(m > n)
            cout << "Decrescente\n";
        else
            cout << "Crescente\n";
        cin >> m >> n;
    }

    return 0;
}
