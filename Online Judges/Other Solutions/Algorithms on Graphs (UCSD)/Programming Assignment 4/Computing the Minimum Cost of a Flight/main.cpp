#include <iostream>
#include <queue>
#include <vector>
#define INF 10000000

using namespace std;
typedef pair<int,int> pii;

int dijkstra(int source, int destination, vector<vector<pair<int,int> > >& g) {
    vector<int>dist((int)g.size(), INF);
    vector<int>vi((int)g.size(), 0);
    vector<int>path((int)g.size(), -1);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,source});
    dist[source] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;

        pq.pop();

        if(!vi[u]) {
            vi[u] = 1;
            for (int i = 0; i < (int)g[u].size(); i++) {
                int v = g[u][i].first;
                int w = g[u][i].second;

                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    path[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    if(dist[destination] == INF)
        return -1;

    int aux = destination;
    while(aux != -1) {
        cout << aux + 1 << endl;
        aux = path[aux];
    }

    return dist[destination];
}
int main()
{
    int nv, ne, u, v, w;
    cin >> nv >> ne;

    vector<vector<pair<int,int> > > g(nv, vector<pii>());
    while(ne--) {
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1,w});
    }
    cin >> u >> v;
    cout << dijkstra(u - 1,v - 1, g);
    return 0;
}
