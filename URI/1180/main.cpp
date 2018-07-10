#include <iostream>

using namespace std;

int main()
{
    int n, *vet, menor, pos;
    cin >> n;
    vet = new int[n];
    for ( int i = 0; i < n; i++) {
        cin >> vet[i];
        if(i == 0) {
            menor = vet[0];
            pos = 0;
        }
        if(vet[i] < menor) {
            menor = vet[i];
            pos = i;
        }
    }
    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << pos << endl;

    delete[] vet;
    return 0;
}
