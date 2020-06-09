#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct data {
    int v, ind, qtd;
};
int main()
{
    int n, t, i = 0;

    cin >> n;
    vector<data>v;
    while(n--) {
        cin >> t;

        int ii = -1;

        for (int j = 0; j < (int)v.size(); j++) {
            if (v[j].v == t) {
                ii = v[j].ind;
                break;
            } else {
                ii = -1;
            }
        }

        if (ii != -1) {
            v[ii].qtd++;
        } else {
            int s = (int)v.size();
            v.push_back({t,s,1});
        }
    }

    sort(v.begin(), v.end(), [](const data& d1, const data& d2) -> bool {
         if (d1.qtd > d2.qtd)
            return true;
         else if (d1.qtd == d2.qtd) {
            if (d1.v > d2.v)
                return true;
         }
         return false;
    });

    cout << v[0].v << endl;
    return 0;
}
