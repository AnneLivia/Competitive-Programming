#include <iostream>
#include <vector>

using namespace std;

vector<vector<int > > g;
vector<int>vi;

void dfs(int v) {
   vi[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++) {
        if(!vi[g[v][i]]) {
            dfs(g[v][i]);
        }
    }
}

int cc() {
    vi.assign((int)g.size(), 0);
    int qtd = 0;
    for (int i = 0; i < (int)g.size(); i++) {
        if(!vi[i]) {
            dfs(i);
            qtd++;
        }
    }
    return qtd;
}
int main()
{
    int n, m, a, b;
    cin >> n >> m;
    g.assign(n, vector<int>());
    while(m--) {
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << cc() << endl;
    return 0;
}
