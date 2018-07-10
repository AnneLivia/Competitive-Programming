#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int nFunc, nHTrabalhadas;
    float salarioPH, salarioTotal;

    cin >> nFunc;
    cin >> nHTrabalhadas;
    cin >> salarioPH;

    salarioTotal = nHTrabalhadas * salarioPH;
    cout << "NUMBER = " << nFunc << "\n";
    printf("SALARY = U$ %.2f\n",salarioTotal);

    return 0;
}
