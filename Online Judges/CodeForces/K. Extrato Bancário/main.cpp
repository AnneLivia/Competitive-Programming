#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct a {
    string nome;
    int ind;
    float per, po;
};

int main()
{
    vector<a>aa = {
        {"alimentacao", 0, 0.00, 0.00},
        {"despesas", 1, 0.00, 0.00},
        {"geral", 2, 0.00, 0.00},
        {"transporte", 3, 0.00, 0.00}
    };

    int t;
    string assf;
    float total = 0, gas;
    cin >> t;

    while(t--) {
        cin >> gas >> assf;
        total+=gas;
        int i = 0;
        find_if(aa.begin(), aa.end(), [&](a& aaa) -> int{
            if(assf == aaa.nome) {
                i = aaa.ind;
            }
        });
        aa[i].per+=gas;
    }

    cout.precision(2);
    cout.setf(ios::fixed);
    for(int i = 0; i < 4; i++) {
        cout << aa[i].nome << " " << aa[i].per << " " << (aa[i].per * 100) / total << endl;
    }
    return 0;
}
