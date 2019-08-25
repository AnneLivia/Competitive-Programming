#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int> > > g;
    int n_vertex;
public:
    Graph(int n_vertex) : n_vertex (n_vertex){
        g.assign(n_vertex, vector<pair<int,int> >());
    }

    void add_edge(int u, int v, int w) {
        this->g[u].push_back({v,w});
        this->g[v].push_back({u,w});
    }

    int dijkstra(int a, int b) {
        vector<int>dist(this->n_vertex, INF);
        priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;


        pq.push({0, a});

        while(!pq.empty()) {
            int v = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if(dist[v] == INF) {
                dist[v] = w;

                for (int i = 0; i < (int)g[v].size(); i++) {
                    int u = g[v][i].first;
                    int uw = g[v][i].second;

                    if(uw + w < dist[u]) {
                        pq.push({uw+w, u});
                    }
                }
            }
        }
        return dist[b];
    }
};

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;
    Graph g(n);
    while(m--) {
        cin >> a >> b >> w;
        g.add_edge(a - 1,b - 1,w);
    }

    cout << g.dijkstra(0, n - 1) << endl;

    return 0;
}
