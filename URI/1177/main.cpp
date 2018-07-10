#include <iostream>

using namespace std;

int main()
{
    int const TAM = 1000;

    int vet[TAM], num, aux = 0;
    cin >> num;
    for(int i = 0; i < TAM; i++) {
        vet[i] = aux;
        if(aux < num - 1)
            aux++;
        else
            aux = 0;
    }

    for(int i = 0; i < TAM; i++)
        cout << "N["<<i<<"] = " << vet[i] << endl;
    return 0;
}
