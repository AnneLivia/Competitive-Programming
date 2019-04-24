#include <iostream>
#include <vector>

using namespace std;

/*
    Now you decide to make sure that there are no dead
    zones in a maze, that is, that at least one exit
    is reachable from each cell. For this, you find connected
    components of the corresponding undirected graph and ensure
    that each component contains an exit cell.

    Task. Given an undirected graph with n vertices and m edges,
    compute the number of connected components in it.
*/

vector<vector<int>>g;
vector<int>vi;

void dfs(int v) {
    vi[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++) {
        if(!vi[g[v][i]])
            dfs(g[v][i]);
    }
}

int components() {
    int qtdc = 0;
    for (int i = 0; i < (int) g.size(); i++) {
        if(!vi[i] && !g[i].empty()) {
            dfs(i);
            qtdc++;
        }
    }
    return qtdc;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;

    g.assign(n, vector<int>());
    vi.assign(n, 0);

    while(m--) {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    cout << components() << endl;

    return 0;
}
