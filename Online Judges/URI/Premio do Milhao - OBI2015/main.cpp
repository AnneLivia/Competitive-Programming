#include <iostream>

using namespace std;

int main()
{
    int qtd, cont = 0;
    long int soma = 0, n;
    cin >> qtd;
    while(qtd--) {
        cin >> n;
        if(soma < 1000000) {
            soma+=n;
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}
