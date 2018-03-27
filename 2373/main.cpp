#include <iostream>

using namespace std;

int main()
{
    int qtd, cont = 0, l, c;
    cin >> qtd;
    while(qtd--) {
        cin >> l >> c;
        if(l > c)
            cont+=c;
    }

    cout << cont << endl;
    return 0;
}
