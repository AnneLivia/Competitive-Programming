#include <iostream>

using namespace std;

int qtdNumber(int n) {
    if(n == 0)
        return 1;
    else
        return n + qtdNumber(n - 1);
}

int main()
{
    int n, caso = 1, cont, qtd;

    while(cin >> n) {
        cont = 0;
        qtd = qtdNumber(n);
        if(qtd == 1)
            cout << "Caso " << caso << ": " << qtd << " numero" << endl;
        else
            cout << "Caso " << caso << ": " << qtd << " numeros" << endl;

        int i = 0;
        while(i < qtd) {
            if(i != 0)
                cout << " ";
            if(i == 0 || i == 1) {
                cout << i;
            } else {
                for(int j = 0; j < i; j++) {
                    if(j != 0)
                        cout << " ";
                    cout << i;
                    qtd--;
                }
            }
            i++;
        }
        caso++;
        cout << endl;
        cout << endl; // White line
    }
    return 0;
}
