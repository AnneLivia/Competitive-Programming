#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int t, qtd, val, vet[101];

    cin >> t;

    while(t--) {
        cin >> qtd;
        int i = 0;
        for(int j = 0; j < qtd; j++){
            cin >> val;
            if(val % 2 != 0)
                vet[i++] = val;
        }

        qtd = i;
        sort(vet, vet+i);
        i = 0;
        int j = qtd - 1;

        for (;j > i && qtd != 0; i++, j--) {
            if(i != 0)
                cout << " ";
            cout << vet[j] << " ";
            cout << vet[i];
        }
        if(qtd != 0 && qtd % 2 != 0) {
            if(qtd != 1)
                cout << " ";
            cout << vet[i] << endl;
        } else
            cout << endl;
    }
    return 0;
}
