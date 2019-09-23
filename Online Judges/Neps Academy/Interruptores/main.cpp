#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, l, a;
    cin >> n >> m;
    vector<vector<int> > inte (n, vector<int>());
    vector<int> asc (m, 0);
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> a;
        asc[a - 1] = 1;
    }

    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        while(t--) {
            cin >> a;
            inte[i].push_back(a - 1);
        }
    }

    int i = 0, ok = 0, total = 0;
    while(true) {
        int cont = 0, iqual = 0;
        total++;
        for (int k = 0; k < (int)inte[i].size(); k++) {
            asc[inte[i][k]] = !asc[inte[i][k]];
        }
        for (int k = 0; k < (int)asc.size(); k++) {
            if(!asc[k]) {
                cont++;
            }
        }

        if(cont == m) {
            ok = 1;
            break;
        } else if ((m - cont) == l && i == (int)inte.size() - 1) {
            ok = 0;
            break;
        }

        i++;
        if(i >= n)
            i = 0;

    }

    if(ok) {
        cout << total << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
