#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > g;

int bfs(int a, int b) {
    vector<int>dist((int)g.size(), -1);
    queue<int>q;
    q.push(a);
    dist[a] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)g[u].size(); i++) {
            if(dist[g[u][i]] == -1) {
                dist[g[u][i]] = dist[u] + 1;
                q.push(g[u][i]);
            }
        }
    }
    return dist[b];
}

int main()
{
    int n, a, b, x, y;
    cin >>  n >> a >> b;

    g.assign(n, vector<int>());

    n--;

    while(n--) {
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    cout << bfs(a - 1, b - 1) << endl;

    return 0;
}
