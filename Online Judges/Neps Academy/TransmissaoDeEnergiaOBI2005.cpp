#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > g;
vector<int>vi;

void dfs_aux(int n) {
    vi[n] = 1;
    for (int i = 0; i < (int)g[n].size(); i++)
    {
        if (!vi[g[n][i]]) {
            dfs_aux(g[n][i]);
        }
    }
}

bool dfs(const int& sz) {
    vi.assign(sz, 0);
    int qtd = 0;
    for (int i = 0; i < sz; i++) {
        if (!vi[i]) {
            dfs_aux(i);
            qtd++;
        } 
    }
    return (qtd == 1); 
}

int main() {
    int e, l, a, b, t = 1;
    while(cin >> e >> l && l && e) {
        g.assign(e, vector<int>());
        while(l--) {
            cin >> a >> b;
            --a, --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        cout << "Teste " << t++ << endl;
        if (!dfs(e)) {
            cout << "falha\n\n";
        } else {
            cout << "normal\n\n";
        }
    }
    return 0;  
}
