#include <iostream>

using namespace std;

int main()
{
    int qtd, n;
    cin >> qtd;
    while(qtd--) {
        cin >> n;
        if(n > 8000)
            cout << "Mais de 8000!\n";
        else
            cout << "Inseto!\n";
    }
    return 0;
}
