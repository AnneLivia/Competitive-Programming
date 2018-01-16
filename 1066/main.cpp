#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{
    int vet[5], contP, contI, contN, contPosi;
    contI = contP = contPosi = contN = 0;

    for(int i = 0; i < 5; i++) {
        cin >> vet[i];
        if(vet[i] % 2 == 0)
            contP += 1;
        else
            contI += 1;
        if(vet[i] > 0)
            contPosi +=1;
        else if(vet[i] < 0)
            contN +=1;
    }

    cout << contP << " valor(es) par(es)\n";
    cout << contI << " valor(es) impar(es)\n";
    cout << contPosi << " valor(es) positivo(s)\n";
    cout << contN << " valor(es) negativo(s)\n";
    return 0;
}
