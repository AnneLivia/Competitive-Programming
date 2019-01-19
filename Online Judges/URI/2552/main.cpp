#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>vi;
int main()
{
    int n, m, cont;
    vector<vi>v;
    vector<vi>vg;
    while(cin >> n >> m) {
        v.clear();
        v.assign(n,vi());
        vg.assign(n,vi());
        for ( int i = 0; i < n; i++) {
            v[i].resize(m);
            vg[i].resize(m);
        }

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cont = 0;
                if(v[i][j] == 1) {
                    vg[i][j] = 9;
                } else {
                    if(i - 1 >= 0 && v[i - 1][j] == 1) {
                        cont++;
                    }

                    if (i + 1 < n && v[i + 1][j] == 1) {
                        cont++;
                    }

                    if (j - 1 >= 0 && v[i][j - 1] == 1) {
                        cont++;
                    }

                    if (j + 1 < m && v[i][j + 1] == 1) {
                        cont++;
                    }
                    vg[i][j] = cont;
                }
            }
        }

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cout << vg[i][j];
            }
            cout << endl;
        }


    }
    return 0;
}
