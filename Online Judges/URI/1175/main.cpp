#include <iostream>

using namespace std;

int main()
{
    int const TAM = 20;

    int vet[TAM], aux;

    for(int i = 0; i < TAM; i++)
        cin >> vet[i];
    for(int i = 0, j = TAM - 1; i < TAM / 2; i++, j--) {
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }

    for(int i = 0; i < TAM; i++)
        cout << "N["<<i<<"] = " << vet[i] << endl;
    return 0;
}
