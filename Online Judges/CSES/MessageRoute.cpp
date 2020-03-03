#include <vector>
#include <iostream>
#include <queue>


using namespace std;
vector<vector<int> > g;
vector<int>parent;

int bfs(int from, int to) {
    vector<int>dist(to+1, -1);
    parent.assign(to+1, -1);
    queue<int>q;
    q.push(from);
    dist[from] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < (int)g[u].size(); i++) {
            if (dist[g[u][i]] == -1) {
                q.push(g[u][i]);
                dist[g[u][i]] = dist[u] + 1;
                parent[g[u][i]] = u;
            }
        }
    }
    return dist[to];
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    g.assign(n, vector<int>());
    while(m--) {
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int res = bfs(0, --n);
    if (res != -1) {
        cout << res+1 << endl;
        int aux = parent[n];
        vector<int>ans;
        ans.push_back(n+1);
        while(aux != -1) {
            ans.push_back(aux+1);
            aux = parent[aux];
        }
        for (int i = (int)ans.size() - 1; i >= 0; i--) {
            if (i != (int)ans.size() - 1)
                cout << " ";
            cout << ans[i]; 
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}