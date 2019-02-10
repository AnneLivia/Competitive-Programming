#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > g;
vector<int> vi, cat, pre;

void dfs(int v, int contC, int& cont, int m) {
    vi[v] = 1;
    int cats = 0, leaf = 0;
    if(contC > m)
        return;
    for (int i = 0; i < (int)g[v].size(); i++) {
        if(!vi[g[v][i]]) {
            leaf++;
            pre[g[v][i]] = v;
            if(cat[g[v][i]] && !cat[pre[g[v][i]]]) {
                dfs(g[v][i], 1, cont, m);
            } else if (!cat[g[v][i]] && !cat[pre[g[v][i]]]){
                dfs(g[v][i], 0, cont, m);
            } else {
                dfs(g[v][i], contC + cat[g[v][i]], cont, m);
            }
        }
    }

    if(!leaf) { // leaf has no child
        if(contC <= m)
            cont++;
    }
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    g.assign(n, vector<int>());
    cat.assign(n, 0);
    pre.assign(n, -1);
    vi.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> cat[i];
    }

    while(--n) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    int cont = 0;
    dfs(0, cat[0], cont, m);
    cout << cont << endl;
    return 0;
}
