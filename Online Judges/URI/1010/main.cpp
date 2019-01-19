#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    int nPeca1, qtdPeca1, nPeca2,qtdPeca2;
    double vPeca1,vPeca2;
    cin >> nPeca1 >> qtdPeca1 >> vPeca1;
    cin >> nPeca2 >> qtdPeca2 >> vPeca2;
    printf("VALOR A PAGAR: R$ %.2f\n",(qtdPeca1 * vPeca1) + (qtdPeca2 * vPeca2));
    return 0;
}
