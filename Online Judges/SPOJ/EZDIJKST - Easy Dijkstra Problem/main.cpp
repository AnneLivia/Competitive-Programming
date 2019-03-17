#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

typedef vector<pair<int,int> > vpii;
vector<vpii>g;

int dijkstra(int a, int b) {
    priority_queue<pair<int,int>, vpii, greater<pair<int,int> > >pq;
    vector<int>dist(g.size(), INF);
    vector<int>vi(g.size(), 0);
    pq.push({0,a});
    dist[a] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vi[u] = 1;
        for (int i = 0; i < (int)g[u].size(); i++) {
            int v = g[u][i].second;
            int w = g[u][i].first;
            if(!vi[v]) {
                int cost = dist[u] + w;
                if(cost < dist[v]) {
                    dist[v] = cost;
                    pq.push({cost, v});
                }
            }
        }
    }
    return dist[b];
}

int main()
{
    int t, u, v, w, ve, ed;
    cin >> t;
    while(t--) {
        cin >> ve >> ed;
        g.assign(ve, vpii());
        while(ed--) {
            cin >> u >> v >> w;
            g[u - 1].push_back({w,v - 1});
        }
        cin >> u >> v;
        w = dijkstra(u - 1, v - 1);
        if(w == INF)
            cout << "NO\n";
        else
            cout << w << endl;
    }
    return 0;
}
