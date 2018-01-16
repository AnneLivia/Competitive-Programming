#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "math.h"
using namespace std;

int main() {
    float valor, aux;
    int moedas[6] = {0}, notas[6] = {0};
    do{
        scanf("%f",&valor);
    }while(valor <= 0 && valor >= 1000000.00);

	notas[0] = (int)(valor / 100);
    valor = valor - (notas[0] * 100);

    notas[1] = (int)(valor / 50);
    valor = valor - (notas[1] * 50);

    notas[2] = (int)(valor / 20);
    valor = valor - (notas[2] * 20);

    notas[3] = (int)(valor / 10);
    valor = valor - (notas[3] * 10);

    notas[4] = (int)(valor / 5);
    valor = valor - (notas[4] * 5);

    notas[5] = (int)(valor / 2);
    valor = valor - (notas[5] * 2);
    valor = valor + 0.001;

    moedas[0] = int(valor / 1);
    valor = valor - (moedas[0] * 1);

    moedas[1] = (int)(valor / 0.50);
    valor = valor - (moedas[1] * 0.50);

    moedas[2] = (int)(valor / 0.25);
    valor = valor - (moedas[2] * 0.25);

    moedas[3] = (int)(valor / 0.10);
    valor = valor - (moedas[3] * 0.10);

    moedas[4] = (int)(valor / 0.05);
    valor = valor - (moedas[4] * 0.05);

    moedas[5] = (int)(valor / 0.01);
    valor = valor - (moedas[5] * 0.01);

    cout << "NOTAS:"<< endl;
	cout << notas[0] << " nota(s) de R$ 100.00\n";
	cout << notas[1] << " nota(s) de R$ 50.00\n";
	cout << notas[2] << " nota(s) de R$ 20.00\n";
	cout << notas[3] << " nota(s) de R$ 10.00\n";
	cout << notas[4] << " nota(s) de R$ 5.00\n";
	cout << notas[5] << " nota(s) de R$ 2.00\n";
	cout << "MOEDAS:"<< endl;
	cout << moedas[0] << " moeda(s) de R$ 1.00\n";
	cout << moedas[1] << " moeda(s) de R$ 0.50\n";
	cout << moedas[2] << " moeda(s) de R$ 0.25\n";
	cout << moedas[3] << " moeda(s) de R$ 0.10\n";
	cout << moedas[4] << " moeda(s) de R$ 0.05\n";
	cout << moedas[5] << " moeda(s) de R$ 0.01\n";

	return 0;
}
