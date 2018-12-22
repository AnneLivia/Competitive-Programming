#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, nAd, vS, va, ok = 0;
    vector<vector<int>>v;
    cin >> t;
    while(t--) {
        cin >> nAd >> vS;
        v.assign(nAd, vector<int>());
        while(vS--) {
            cin >> va;
            v[va % nAd].push_back(va);
        }

        if(ok)
            cout << endl;

        for (int i = 0; i < (int)v.size(); i++) {
            cout << i << " -> ";
            for(int j = 0; j < (int)v[i].size(); j++)
                cout << v[i][j] << " -> ";
             cout << "\\\n";
        }

        ok = 1;
    }
    return 0;
}
