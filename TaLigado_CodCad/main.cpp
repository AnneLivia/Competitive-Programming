#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
    int n, m, t, a, b;
    bool flag;
    vector<vector<int>>v;
    cin >> n >> m;

    // And it's been initialized the vector<int> in each position
    v.assign(n + 1,vi()); // N + 1 since it's going to start from 1 to the last one. don't start with 0 here

    for ( int i = 1; i <= m; i++) {
        cin >> t >> a >> b;
        flag = false;
        if(t == 1) {
            v[a].push_back(b);
            v[b].push_back(a);
        } else {
            for ( int j = 0; j < (int)v[a].size(); j++) {
                if(v[a][j] == b) {
                    flag = 1;
                    break;
                }
            }
            cout << flag << endl;
        }
    }

    return 0;
}
