#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int nf, cf, m, comp[101], cari[101], qtd = 0;
    cin >> nf >> cf >> m;

    for ( int i = 0; i < cf; i++) {
        cin >> cari[i];
    }

    for ( int i = 0; i < m; i++) {
        cin >> comp[i];
    }

    for ( int i = 0; i < cf; i++) {
        if(find(comp, comp + m, cari[i]) == comp + m)
            qtd++;
    }

    cout << qtd << endl;
    return 0;
}
