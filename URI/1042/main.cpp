#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int valores[3], copia[3];
    cin >> valores[0] >> valores[1] >> valores[2];

    for (int i = 0 ; i < 3 ; i++)
    {
        copia[i] = valores[i];
    }
    int aux;
    for (int i = 0 ; i < 3 ; i++)
    {
        int j = 0;
        while(j < 3)
        {
            if(copia[j] > copia[i]){
                aux = copia[j];
                copia[j] = copia[i];
                copia[i] = aux;
            }
            j++;
        }
    }

    for (int i = 0 ; i < 3; i++)
    {
        cout << copia[i] << endl;
    }
    cout << endl;
    for (int i = 0 ; i < 3; i++)
    {
        cout << valores[i] << endl;
    }


	return 0;
}
