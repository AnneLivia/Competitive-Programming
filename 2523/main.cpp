#include <iostream>
using namespace std;

int main()
{
    string letras, palavraFormada;
    int qtdLetras, lampada;
    while(getline(cin,letras)) {
        palavraFormada = "";
        cin >> qtdLetras;
        while(qtdLetras--) {
            cin >> lampada;
            palavraFormada += letras[lampada - 1];
        }
        cout << palavraFormada << endl;
        getchar();
    }
    return 0;
}
