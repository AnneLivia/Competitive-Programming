#include <iostream>
#include <vector>

using namespace std;

vector<int>vi;
vector<vector<int> > g;

void dfs(int v) {
    if(!vi[v]) {
        vi[v] = 1;

        for (int i = 0; i < (int)g[v].size(); i++) {
            if(!vi[g[v][i]]) {
                dfs(g[v][i]);
            }
        }
    }
}
int components() {
    vi.assign(g.size(), 0);
    int comp = 0;
    for (int i = 0; i < (int)g.size(); i++) {
        if(!vi[i]) {
            dfs(i);
            comp++;
        }
    }
    return comp;
}
int main()
{
    int nAlunos, nLista, i, j;
    cin >> nAlunos >> nLista;
    g.assign(nAlunos, vector<int>());
    while(nLista--) {
        cin >> i >> j;
        g[i - 1].push_back(j - 1);
        g[j - 1].push_back(i - 1);
    }

    cout << components() << endl;
    return 0;
}
