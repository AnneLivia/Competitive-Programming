#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int n,x, y, cont = 1, soma = 0;
    cin >> n;
    for ( int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        while(cont <= y) {
            if(x % 2 != 0) {
                soma = soma + x;
                cont++;
            }
            x +=1;
        }
        cout << soma << endl;
        cont = 1;
        soma = 0;
    }

    return 0;
}
