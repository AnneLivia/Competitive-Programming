#include <iostream>
#include <vector>

using namespace std;
typedef vector<char> va;
typedef vector<int> vi;

vector<va>v;
vector<vi>vis;
int cont;

void dfs(int a, int b) {

    if(a >= 0 && a < (int)v.size() && b >= 0 && b < (int)v[a].size()) {
        v[a][b] = cont;
        vis[a][b] = 1;
        if(a + 1 < (int)v.size() && v[a + 1][b] == '.' && !vis[a + 1][b]) {
            dfs(a + 1, b);
        }
        if(a - 1 >= 0 && v[a - 1][b] == '.' && !vis[a - 1][b]) {
            dfs(a - 1, b);
        }
        if(b + 1 < (int)v[a].size() && v[a][b + 1] == '.' && !vis[a][b + 1]) {
            dfs(a, b + 1);
        }
        if(b - 1 >= 0 && v[a][b - 1] == '.' && !vis[a][b - 1]) {
            dfs(a, b - 1);
        }
    }
}

int main()
{
    int n, m;
    char c;
    cin >> n >> m;

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

    cont = 0;

    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            if(!vis[i][j] && v[i][j] != 'o') {
                cont++;
                dfs(i,j);
            }
        }
    }

    cout << cont << endl;

    return 0;
}
