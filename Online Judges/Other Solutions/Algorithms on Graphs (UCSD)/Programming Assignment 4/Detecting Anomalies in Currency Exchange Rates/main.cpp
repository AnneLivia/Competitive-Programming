#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

bool hasNegativeCycle(int ne, vector<pair<int, pair<int,int> > >& g) {
    vector<int>dist(ne, INF);
    dist[0] = 0;
    for (int i = 0; i < ne - 1; i++) {
        for (int i = 0; i < ne; i++) {
            int u = g[i].first;
            int v = g[i].second.first;
            int w = g[i].second.second;

            if(dist[u] != INF) {
                dist[v] = min(dist[v], w + dist[u]);
            }
        }
    }

    for (int i = 0; i < ne; i++) {
        int u = g[i].first;
        int v = g[i].second.first;
        int w = g[i].second.second;

        if(dist[v] > dist[u] + w) {
            return true;
        }
    }

    return false;
}

int main()
{
    int nv, ne, u, v, w;
    cin >> nv >> ne;

    vector<pair<int, pair<int,int> > > g;
    for (int i = 0; i < ne; i++) {
        cin >> u >> v >> w;
        g.push_back({u - 1,{v - 1, w}});
    }
    cout << hasNegativeCycle(ne, g) << endl;
    return 0;
}
