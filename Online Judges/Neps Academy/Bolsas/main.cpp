#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pedido {
    int tempo, entrega;
};
int main()
{
    int n;

    cin >> n;

    vector<pedido>v(n, {0,0});

    for (int i = 0; i < n; i++) {
        cin >> v[i].tempo >> v[i].entrega;
    }

    sort(v.begin(), v.end(), [](const pedido& p1, const pedido& p2){
        return p1.entrega < p2.entrega;
    });

    int a = 0, s = 0, maior = 0;
    for (int i = 0; i < n; i++) {
        a = max(0, s + v[i].tempo - v[i].entrega);
        if(a > maior) {
            maior = a;
        }

        s+=v[i].tempo;
    }

    cout << maior << endl;
    return 0;
}
