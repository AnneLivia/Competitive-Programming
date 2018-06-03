#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>>vet;
    int n, m, l, c;
    l = c = 0;
    cin >> n >> m;
    vet.assign(n,vector<int>());
    for ( int i = 0; i < n; i++) {
        vet[i].resize(m);
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            cin >> vet[i][j];
        }
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            if(vet[i][j] == 42) {
                if(i - 1 >= 0 && j - 1 >= 0 &&
                   i + 1 < n && j + 1 < m &&
                   vet[i - 1][j] == 7 &&
                   vet[i - 1][j - 1] == 7 &&
                   vet[i - 1][j + 1] == 7 &&
                   vet[i + 1][j] == 7 &&
                   vet[i + 1][j - 1] == 7 &&
                   vet[i + 1][j + 1] == 7 &&
                   vet[i][j - 1] == 7 &&
                   vet[i][j + 1] == 7) {
                    l = i + 1; c = j + 1;
                    break;
                }
            }
        }
    }

    cout << l << " " << c << endl;
    return 0;
}
