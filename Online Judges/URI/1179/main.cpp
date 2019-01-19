#include <iostream>

using namespace std;

int main()
{
    int const TAM = 5;
    int par[TAM], impar[TAM], num, contPar, contImpar;
    contImpar = contPar = 0;

    for (int i = 0 ; i < 15; i++)
    {
        cin >> num;
        if(num % 2 == 0) {
            par[contPar++] = num;
        } else {
            impar[contImpar++] = num;
        }
        if(contPar == 5) {
            for(int j = 0; j < contPar; j++)
                cout << "par["<<j<<"] = " << par[j] << endl;
            contPar = 0;
        }

         if(contImpar == 5) {
            for(int j = 0; j < contImpar; j++)
                cout << "impar["<<j<<"] = " << impar[j] << endl;
            contImpar = 0;
        }
    }
    for(int j = 0; j < contImpar; j++)
        cout << "impar["<<j<<"] = " << impar[j] << endl;
    for(int j = 0; j < contPar; j++)
        cout << "par["<<j<<"] = " << par[j] << endl;
    return 0;
}
