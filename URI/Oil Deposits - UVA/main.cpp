#include <iostream>
#include <vector>

using namespace std;

typedef vector<char>va;
typedef vector<int>vi;

vector<va>v;
vector<vi>vis;

void dfs(int a, int b) {

    if(v[a][b] == '@') {
        vis[a][b] = 1;
        // Up
        if(a - 1 >= 0 && v[a - 1][b] == '@' && !vis[a - 1][b])
            dfs(a - 1, b);
        // Down
        if(a + 1 < (int)v.size() && v[a + 1][b] == '@' && !vis[a + 1][b])
            dfs(a + 1, b);
        // Left
        if(b - 1 >= 0 && v[a][b - 1] == '@' && !vis[a][b - 1])
            dfs(a, b - 1);
        // Right
        if(b + 1 < (int)v[a].size() && v[a][b + 1] == '@' && !vis[a][b + 1])
            dfs(a, b + 1);
        // DiagUp1
        if(a - 1 >= 0 && b - 1 >= 0 && v[a - 1][b - 1] == '@' && !vis[a - 1][b - 1])
            dfs(a - 1, b - 1);
        // DiagUp2
        if(a - 1 >= 0 && b + 1 < (int) v[a].size() && v[a - 1][b + 1] == '@' && !vis[a - 1][b + 1])
            dfs(a - 1, b + 1);
        // DiagDown1
        if(a + 1 < (int)v.size() && b - 1 >= 0 && v[a + 1][b - 1] == '@' && !vis[a + 1][b - 1])
            dfs(a + 1, b - 1);
        // DiagDown2
        if(a + 1 < (int)v.size() && b + 1 < (int) v[a].size() && v[a + 1][b + 1] == '@' && !vis[a + 1][b + 1])
            dfs(a + 1, b + 1);
    }
}

int main()
{
    int n, m;
    char c;

    while(true) {
        cin >> n >> m;
        if(m == 0)
            break;
        v.assign(n,va());
        vis.assign(n,vi());

        for ( int i = 0; i < n; i++) {
            v[i].resize(m);
            vis[i].resize(m);
        }

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {
                cin >> c;
                v[i][j] = c;
            }
        }

        int cont = 0;

        for ( int i = 0; i < n; i++) {
            for ( int j = 0; j < m; j++) {

                if(v[i][j] == '@' && !vis[i][j]) {
                    cont++;
                    dfs(i,j);
                }
            }
        }

        cout << cont << endl;
    }
    return 0;
}
