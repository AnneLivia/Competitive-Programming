#include <iostream>

using namespace std;

int main()
{
    int qtd, n, cont = 0;
    cin >> qtd;
    while(qtd--) {
        cin >> n;
        if(n > 1) {
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}
