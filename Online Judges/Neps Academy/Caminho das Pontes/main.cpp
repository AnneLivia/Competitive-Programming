#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000
using namespace std;

vector<vector<pair<int,int> > > g;
vector<int>vi;

int dij(int st, int go) {
    vector<int>dist((int)g.size(), INF);
    vector<int>vi((int)g.size(), 0);
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    pq.push({0, st});

    while(!pq.empty()) {
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if(!vi[v]) {
            vi[v] = 1;
            dist[v] = w;

            for (int i = 0; i < (int)g[v].size(); i++) {
                int u = g[v][i].first;
                int uw = g[v][i].second;

                if(uw + w < dist[u]) {
                    dist[u] = uw + w;


                    pq.push({uw+w, u});
                }
            }
        }
    }
    return dist[go];
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    vi.assign(n + 2, 0);
    g.assign(n + 2, vector<pair<int,int> >());
    while(m--) {
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    cout << dij(0, n + 1) << endl;
    return 0;
}
