#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > g;

void bfs(int l, int p) {
    int sz = (int)g.size();
    vector<int>dist(sz, -1);
    queue<int>q;
    q.push(l);
    dist[l] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)g[u].size(); i++)
        {
            int uu = g[u][i];
            if (dist[uu] == -1) {
                dist[uu] = dist[u] + 1;
                q.push(uu);
            }
        }
    }

    for (int i = 0; i < sz; i++)
    {
        if (i != l) {
            if (dist[i] <= p && dist[i] != -1) {
                cout << i + 1 << " ";
            }
        }
    }
}

int main() {
    int c, e, l, p, a, b, t = 1;
    while(cin >> c >> e >> l >> p && c + e + l + p != 0) {
        g.assign(c, vector<int>());
        while(e--) {
            cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << "Teste " << t++ << endl;
        --l;
        bfs(l, p);
        cout << "\n\n";
    }
    return 0;  
}
