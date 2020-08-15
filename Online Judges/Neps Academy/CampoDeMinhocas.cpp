#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int maxu = 0, contl;
    for (int i = 0; i < n; i++) {
        contl = 0;
        for (int j = 0; j < m; j++) {
            contl+=v[i][j];
        }
        if (contl > maxu) {
            maxu = contl;
        }
    }
    
    for (int i = 0; i < m; i++) {
        contl = 0;
        for (int j = 0; j < n; j++) {
            contl+=v[j][i];
        }
        if (contl > maxu) {
            maxu = contl;
        }
    }

    cout << maxu << endl;

    return 0;  
}
