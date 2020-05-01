#include <iostream>
#include <algorithm>

using namespace std;

struct data {
    int id, qtd;
};

int main()
{
    data v[13] ={0,0};
    int n, t;
    cin >> n;

    for (int i = 1; i <= 12; i++) {
        v[i].id = i; v[i].qtd = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> t;
        v[t].qtd++;
    }

    sort(v, v + 13, [](const data& d1, const data& d2) -> bool {
        if (d1.qtd > d2.qtd)
            return true;
        else if (d1.qtd == d2.qtd) {
            if (d1.id < d2.id)
                return true;
        }
        return false;
    });

    cout << v[0].id;
    for (int i = 1; i <= 12; i++) {
        if(v[i].qtd == v[i - 1].qtd)
            cout << " " << v[i].id;
        else
            break;
    }
    cout << endl;
    return 0;
}
