#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > v;
    int n;

    cin >> n;

    v.assign(n, vector<int>());

    for (int i = 0; i < n; i++) {
        v[i].resize(n - i);
    }

    for (int i = 0; i < n; i++) {
        cin >> v[0][i];
    }

    for (int i = 1; i < n; i++) {
        for(int j = 0; j < (int)v[i].size(); j++) {
            if(v[i - 1][j] == v[i - 1][j + 1]) {
                v[i][j] = 1;
            } else {
                v[i][j] = -1;
            }
        }
    }

    if(v[n - 1][0] > 0)
        cout << "preta\n";
    else
        cout << "branca\n";
    return 0;
}
