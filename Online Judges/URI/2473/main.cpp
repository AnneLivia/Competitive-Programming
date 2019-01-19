#include <iostream>
#define TAM 6
using namespace std;

int main()
{
    int v[TAM],a[TAM], cont = 0;

    for ( int i = 0; i < TAM; i++) {
        cin >> v[i];
    }

    for ( int i = 0; i < TAM; i++) {
        cin >> a[i];
    }


    for ( int i = 0; i < TAM; i++) {
        for ( int j = 0; j < TAM; j++) {
            if(a[j] == v[i]) {
                cont++;
                break;
            }
        }
    }

    if(cont == 3)
        cout << "terno\n";
    else if (cont == 4)
        cout << "quadra\n";
    else if (cont == 5)
        cout << "quina\n";
    else if (cont == 6)
        cout << "sena\n";
    else {
        cout << "azar\n";
    }

    return 0;
}
