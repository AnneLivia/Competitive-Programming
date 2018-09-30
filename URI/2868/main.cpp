#include <iostream>

using namespace std;

int main()
{
    char aux1, aux2;
    int n1, n2, resp, dif, qtd;
    cin >> qtd;
    while(qtd--) {
        cin >> n1 >> aux1 >> n2 >> aux2 >> resp;
        if(aux1 == '+') {
            dif = n1 + n2;
        } else if (aux1 == '-') {
            dif = n1 - n2;
        } else if (aux1 == 'x') {
            dif = n1 * n2;
        }

        dif = abs(dif - resp);
        cout << "E";
        for(int i = 0; i < dif; i++)
            cout << "r";
        cout << "ou!\n";
    }
    return 0;
}
