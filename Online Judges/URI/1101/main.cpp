#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int soma = 0, m, n, aux;
    cin >> m >> n;
    while(m > 0 && n > 0){

        if (m > n)
        {
            aux = m;
            m = n;
            n = aux;
        }
        for (int i = m; i <= n; i++)
        {
            cout << i << " ";
            soma +=i;
        }
        cout << "Sum="<<soma<<"\n";
        cin >> m >> n;
        soma = 0;
    }

    return 0;
}
