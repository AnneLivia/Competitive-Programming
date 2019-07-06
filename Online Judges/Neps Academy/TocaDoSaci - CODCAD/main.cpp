#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
vector<vi>v, vis;
int cont;

void dfs(int a, int b) {
    if(a >= 0 && a < (int) v.size() && b >= 0 && b < (int) v[a].size()) {
        vis[a][b] = 1;
        cont++;
        if(v[a][b] != 2) {
            // Down
            if(a + 1 < (int) v.size() && v[a + 1][b] == 1 && !vis[a + 1][b])
                dfs(a + 1, b);
            // Up
            if(a - 1 >= 0 && v[a - 1][b] == 1 && !vis[a - 1][b])
                dfs(a - 1, b);
            // Right
            if(b + 1 < (int) v[a].size() && v[a][b + 1] == 1 && !vis[a][b + 1])
                dfs(a, b + 1);
            // Left
            if(b - 1 >= 0 && v[a][b - 1] == 1 && !vis[a][b - 1])
                dfs(a, b - 1);
        }
    }
}

int main()
{
    int n, m, s, posI3, posJ3;

    cin >> n >> m;

    v.assign(n,vi());
    vis.assign(n,vi());

    for ( int i = 0; i < n; i++) {
        v[i].resize(m);
        vis[i].resize(m);
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            cin >> s;
            v[i][j] = s;
            if(s == 3) {
                posI3 = i;
                posJ3 = j;
            }
        }
    }

    cont = 1;
    dfs(posI3,posJ3);
    cout << cont << endl;
    return 0;
}
