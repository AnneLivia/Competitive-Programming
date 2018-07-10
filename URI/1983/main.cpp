#include <iostream>

using namespace std;

int main()
{
    int qtdA, nMat, nMatBig;
    float nota, maior = -1;
    cin >> qtdA;

    while (qtdA--) {
        cin >> nMat >> nota;
        if(nota >= 8.0 && nota > maior) {
            maior = nota;
            nMatBig = nMat;
        }
    }
    if(maior == -1) {
        cout << "Minimum note not reached\n";
    } else {
        cout << nMatBig << endl;
    }
    return 0;
}
