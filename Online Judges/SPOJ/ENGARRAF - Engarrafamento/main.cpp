#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 999999

using namespace std;

vector<vector<int> > g;

int path(int orig, int dest) {
    vector<int>dist((int)g.size(), INF);
    vector<int>vi((int)g.size(), 0);

    dist[orig] = 0;
    for (int i = 0; i < (int)g.size(); i++) {

        int minimum = -1;
        for (int j = 0; j < (int)g.size(); j++) {
            if(!vi[j]) {
                if(minimum == -1 || dist[minimum] > dist[j]) {
                    minimum = j;
                }
            }
        }

        vi[minimum] = 1;

        for (int j = 0; j < (int)g.size(); j++) {
            if(!vi[j] && g[minimum][j]) {
                int cost = dist[minimum] + g[minimum][j];
                if(cost < dist[j]) {
                    dist[j] = cost;
                }
            }
        }
    }
    if(dist[dest] == INF)
        return -1;
    else
        return dist[dest];
}

int main() {
    int n, m, u, v, w;
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;
        g.assign(n, vector<int>(n, 0));
        while(m--) {
            cin >> u >> v >> w;
            --u; --v;
            g[u][v] = w;
        }
        cin >> u >> v;
        --u; --v;
        cout << path(u,v) << endl;
    }
    return 0;
}
