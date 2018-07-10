#include <iostream>
#define MAXN 10000
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int qtd, n[MAXN], v, i = 0, cont;
    vector<int>qt;

    cin >> qtd;
    while(i < qtd) {
        cin >> n[i];
        i++;
    }
    n[qtd] = n[qtd - 1] != 1 ? 1 : 0;
    qtd++;
    v = n[0];
    cont = 1;
    for(i = 1; i < qtd; i++) {
        if(n[i] == v) {
            cont++;
        } else {
            qt.push_back(cont);
            cont = 1;
            v = n[i];

        }
    }

    sort(qt.begin(),qt.end());
    cout << qt[qt.size() - 1] << endl;
    return 0;
}
