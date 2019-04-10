#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

vector<vector<pair<int, int> > > graph;

void dijkstra(int start) {
    vector<int>dist((int)graph.size(), INF);
    vector<int>path((int)graph.size(), -1);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        for (int i = 0; i < (int)graph[v].size(); i++) {
            int u  = graph[v][i].first;
            int w  = graph[v][i].second;

            if(dist[u]  > dist[v] + w) {
                dist[u] = dist[v] + w;
                path[u] = v;
                pq.push({dist[u], u});
            }
        }
    }

    int aux = 0;
    vector<int>trace;
    while(aux != -1) {
        trace.push_back(aux);
        aux = path[aux];
    }

    if(dist[0] > 120) {
        cout << "It will be " << dist[0] - 120 << " minutes late. ";
    } else {
        cout << "Will not be late. ";
    }

    cout << "Travel time - " << dist[0] << " - best way - ";
    for (int i = (int)trace.size() - 1; i >= 0 ; i--) {
        if(i != (int)trace.size() - 1)
            cout << " ";
        cout << trace[i] + 1;
    }
    cout << endl;
}
int main()
{
    int cidades, estradas, v1, v2, time, start;
    while(cin >> cidades >> estradas && cidades && estradas) {
        graph.assign(cidades, vector<pair<int,int> >());
        while(estradas--) {
            cin >> v1 >> v2 >> time;
            v1--; v2--;
            graph[v1].push_back({v2, time});
            graph[v2].push_back({v1, time});
        }
        cin >> start;
        dijkstra(--start);
    }
    return 0;
}
