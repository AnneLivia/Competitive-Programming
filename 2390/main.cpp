#include <iostream>

using namespace std;

int main()
{
    int q, n, tempo = 0, aux;
    cin >> q;

    for ( int i = 0; i < q; i++) {
        cin >> n;
        if(i == 0)
            tempo = 10;
        else {
            if((n - aux) > 10) // Se for maior que 10 segundos a diferen�a de chega, a pessoa n�o pega o impulso da escada rolante
                tempo+=10;
            else
                tempo += (n - aux); // Aqui a pessoa est� pegando o impulso da escada rolante.
        }
        aux = n;
    }
    cout << tempo << endl;
    return 0;
}
