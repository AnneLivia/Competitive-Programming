#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
vector<vi>v, vis;
int cont;

void dfs(int a, int b) {
    if(a >= 0 && a < (int) v.size() && b >= 0 && b < (int) v.size()) {
        vis[a][b] = 1;
        cont++;
        // Up
        if(a - 1 >= 0 && v[a - 1][b] >= v[a][b] && !vis[a - 1][b])
           dfs(a - 1, b);
        // Down
        if(a + 1 < (int)v.size() && v[a + 1][b] >= v[a][b] && !vis[a + 1][b])
            dfs(a + 1, b);
        // Left
        if(b - 1 >= 0 && v[a][b - 1] >= v[a][b] && !vis[a][b - 1])
            dfs(a, b - 1);
        // Right
        if(b + 1 < (int)v.size() && v[a][b + 1] >= v[a][b] && !vis[a][b + 1])
            dfs(a, b + 1);

    }
}

int main()
{


    int n, p1, p2, nc;
    cin >> n >> p1 >> p2;

    v.assign(n, vi());
    vis.assign(n, vi());

    for ( int i = 0; i < n; i++) {
        v[i].resize(n);
        vis[i].resize(n);
    }

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            cin >> nc;
            v[i][j] = nc;
        }
    }

    cont = 0;
    dfs(p1 - 1,p2 - 1);

    cout << cont << endl;
    return 0;
}
