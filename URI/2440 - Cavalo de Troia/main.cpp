#include <iostream>
#include <vector>
#define MAXN 50050

using namespace std;

int componente[MAXN];
vector<int>v[MAXN];

void dfs(int x) {

    for ( int i = 0; i < (int)v[x].size(); i++) {
        int p = v[x][i];
        if(componente[p] == -1) {
            componente[p] = componente[x];
            dfs(p);
        }
    }

}

int main() {

    int n, m, a, b;

    cin >> n >> m;

    for ( int i = 1; i <= n; i++) {
        componente[i] = -1;
    }

    for ( int i = 1; i <= m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int qtd = 0;

    for ( int i = 1; i <= n; i++) {
        if(componente[i] == -1) {
            qtd++;
            componente[i] = qtd;
            dfs(i);
        }
    }

    cout << qtd << endl;

    return 0;
}
