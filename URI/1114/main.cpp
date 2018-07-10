#include <iostream>
#include "stdio.h"
using namespace std;

int main()
{

    int senha;
    cin >> senha;
    while(senha != 2002){
        cout << "Senha Invalida\n";
        cin >> senha;
    }

    cout << "Acesso Permitido\n";

    return 0;
}
