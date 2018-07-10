#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int cod, qtd;
    double valor;
    cin >> cod >> qtd;
    switch(cod)
    {
        case 1  : valor = 4.00 * qtd;
                  break;
        case 2 : valor = 4.50 * qtd;
                  break;
        case 3 : valor = 5.00 * qtd;
                 break;
        case 4 : valor = 2.00 * qtd;
                 break;
        case 5 : valor = 1.50 * qtd;
                 break;
        default : break;
    }

    printf("Total: R$ %.2f\n",valor);
	return 0;
}
