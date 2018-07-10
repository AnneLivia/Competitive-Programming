#include <iostream>

using namespace std;

int main()
{
    long long int rafa, beto, carlos;
    int teste, x, y;
    cin >> teste;
    while(teste--) {
        cin >> x >> y;
        rafa = ((3 * x) * (3 * x)) + (y * y);
        beto = (2*(x * x)) + ((5 * y) * (5 * y));
        carlos = (-100 * x) + (y * y * y);

        if(rafa > beto && rafa > carlos)
            cout << "Rafael ganhou\n";
        else if (beto > rafa && beto > carlos)
            cout << "Beto ganhou\n";
        else if (carlos > rafa && carlos > beto)
            cout << "Carlos ganhou\n";
    }
    return 0;
}
