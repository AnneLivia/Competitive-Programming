#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000
using namespace std;

vector<vector<pair<int,int> > > g;
vector<int>vi;

int dij(int st) {
    vector<int>dist((int)g.size(), INF);
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
    sort(dist.begin(), dist.end());

    return dist[(int)dist.size() - 1] - dist[1];
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    vi.assign(n, 0);
    g.assign(n, vector<pair<int,int> >());
    while(m--) {
        cin >> a >> b >> c;
        g[a - 1].push_back({b - 1,c});
        g[b - 1].push_back({a - 1,c});
    }
    cin >> a;
    cout << dij(a - 1) << endl;
    return 0;
}
