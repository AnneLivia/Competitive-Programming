#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int,int> > > g;
vector<int>id, sz;

int findd(int p) {
    if(id[p] == -1)
        return p;
    return id[p] = findd(id[p]);
}

void unionn(int v, int w) {
    int idv = findd(v);
    int idw = findd(w);

    if(sz[idv] > sz[idw])
        swap(idv, idw);

    id[idv] = idw;
    sz[idw]+=sz[idv];
}

int kruskal() {
    int sum = 0;
    sort(g.begin(), g.end());

    for (int i = 0; i < (int)g.size(); i++) {
        int v = g[i].second.first;
        int w = g[i].first;
        int u = g[i].second.second;

        if(findd(v) != findd(u)) {
            sum+=w;
            unionn(v,u);
        }
    }
    return sum;
}

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    id.assign(n, -1);
    sz.assign(n, 0);
    while(m--) {
        cin >> a >> b >> c;
        g.push_back({c, {a,b}});
    }
    cout << kruskal() << endl;
    return 0;
}
