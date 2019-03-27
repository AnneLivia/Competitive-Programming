#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
/*
    9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
4 6 2
6 7 1
6 8 6
7 8 7
*/
using namespace std;

vector<vector<int> > g;

int pings(int server) {
    vector<int>visited((int)g.size(), 0);
    vector<int>dist((int)g.size(), INF);

    dist[server] = 0;

    for (int i = 0; i < (int)g.size(); i++) {
        int minimum = -1;
        for (int j = 0; j < (int)g.size(); j++) {
            if(!visited[j]) {
                if(minimum == -1 || dist[j] < dist[minimum]) {
                    minimum = j;
                }
            }
        }

        visited[minimum] = 1;

        for (int j = 0; j < (int)g.size(); j++) {
            if(!visited[j] && g[minimum][j]) {
                int cost = dist[minimum] + g[minimum][j];
                if(cost < dist[j])
                    dist[j] = cost;
            }
        }
    }

    sort(dist.begin(), dist.end());
    return dist[(int)g.size() - 1] - dist[1];
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    g.assign(n, vector<int>(n, 0));
    while(m--) {
        cin >> u >> v >> w;
        --u; --v;
        g[u][v] = g[v][u] = w;
    }

    cin >> w;
    --w;
    cout << pings(w) << endl;
    return 0;
}
