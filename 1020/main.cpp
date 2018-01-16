#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    int idadeDias, ano, meses, aux, dias;
    cin >> idadeDias;
    ano = idadeDias / 365;
    aux = idadeDias;
    while(aux >= 360)
        aux = aux - 365;
    meses = 0;
    while(aux >= 30)
    {
        meses = meses + 1;
        aux = aux - 30;
    }

    dias = (idadeDias - ((ano * 365) + (meses * 30)));
    cout << ano << " ano(s)" << endl;
    cout << meses << " mes(es)" << endl;
    cout << dias << " dia(s)" << endl;
    return 0;
}
