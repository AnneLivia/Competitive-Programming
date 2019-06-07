#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
typedef vector<int>vi;

int shortestPathBFS(vector<vi>g, int u, int v) {
//    u--; v--;
    queue<int>q;
    vector<int>layer(g.size(), -1);
    vector<int>previous(g.size(), -1);
    layer[u] = 0;
    q.push(u);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < (int)g[u].size(); i++) {
            if(layer[g[u][i]] == -1) {
                q.push(g[u][i]);
                previous[g[u][i]] = u;
                layer[g[u][i]] = layer[u] + 1;
            }
        }
    }
    return layer[v];
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    vector<vi>g(n, vi());
    while(m--) {
        cin >> u >> v;
      //  u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> u >> v; // shortest path between u and v (minimum number of flight segments)
    cout << shortestPathBFS(g, u, v) << endl;
    return 0;
}
