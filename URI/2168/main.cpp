#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    vector<vector<int>>v;
    vector<vector<char>>vc;
    cin >> n;

    v.assign(n + 1,vector<int>());
    vc.assign(n,vector<char>());

    for ( int i = 0; i < n + 1; i++) {
        for ( int j = 0; j < n + 1; j++) {
            cin >> k;
            v[i].push_back(k);
        }
    }
    int qtd;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            qtd = 0;
            if(v[i][j] == 1)
                qtd++;
            if(v[i+1][j] == 1)
                qtd++;
            if(v[i][j+1] == 1)
                qtd++;
            if(v[i+1][j+1] == 1)
                qtd++;
            if(qtd >= 2)
                vc[i].push_back('S');
            else
                vc[i].push_back('U');
        }
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            cout << vc[i][j];
        }
        cout << endl;
    }


    return 0;
}
