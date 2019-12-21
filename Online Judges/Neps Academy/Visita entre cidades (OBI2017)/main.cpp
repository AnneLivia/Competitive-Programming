#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int,int> > > g;

int dfs(int a, int b) {
    vector<int>dist((int)g.size(), -1);
    dist[a] = 0;
    queue<int>q;
    q.push(a);
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)g[u].size(); i++) {
            int w = g[u][i].second;
            if(dist[g[u][i].first] == -1) {
                dist[g[u][i].first] = dist[u] + w;
                q.push(g[u][i].first);
            }
        }
    }
    return dist[b];
}
int main()
{
    int n, a, b, x, y, w;
    cin >> n >> a >> b;
    g.assign(n, vector<pair<int,int> >());

    --n;
    while(n--) {
        cin >> x >> y >> w;
        g[x - 1].push_back({y - 1, w});
        g[y - 1].push_back({x - 1, w});
    }

    cout << dfs(a - 1, b - 1) << endl;

    return 0;
}
