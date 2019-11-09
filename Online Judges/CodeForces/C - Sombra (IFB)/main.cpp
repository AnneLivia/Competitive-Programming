#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int qtd, nk, t;
    cin >>  qtd >> nk;

    vector<int>v(nk, 0);

    for (int i = 0; i < qtd; i++) {
        cin >> t;
        v[t - 1]++;
    }

    v.push_back(3);
    int qtds = 0, aux = 0;
    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i] == 0) {
            aux++;
        } else {
            if(aux != 0 && v[i - 1] == 0)
                qtds++;
            aux = 0;
        }
    }

    cout << qtds << endl;
    return 0;
}
