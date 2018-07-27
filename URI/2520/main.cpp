#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, m, poscolPok, posliPok, poscolSas, posliSas;
    vector<vector<int>>v;
    while(cin >> n >> m) {
        v.clear();
        v.assign(n,vector<int>());
        for ( int i = 0; i < n; i++) {
            v[i].resize(m);
        }

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cin >> v[i][j];
                if(v[i][j] == 2) {
                    poscolPok = j;
                    posliPok = i;
                } else if (v[i][j] == 1) {
                    poscolSas = j;
                    posliSas = i;
                }
            }
        }

        cout << abs(poscolPok - poscolSas) + abs(posliPok - posliSas) << endl;

    }
    return 0;
}
