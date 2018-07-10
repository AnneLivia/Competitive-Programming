#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    char nome[100];
    double salarioFixo, valorVendas;
    scanf(" %[^\n]",nome);
    cin >> salarioFixo;
    cin >> valorVendas;

    valorVendas = valorVendas * 0.15;
    salarioFixo = salarioFixo+valorVendas;
    printf("TOTAL = R$ %.2f\n",salarioFixo);
    return 0;
}
