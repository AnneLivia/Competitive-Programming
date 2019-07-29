#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int,pair<int,int > > > g;
vector<int>id, sz;

int findd(int p) {
    if(id[p] == p)
        return p;
    return id[p] = findd(id[p]);
}

void unionn(int p, int q) {
    int idp = findd(p);
    int idq = findd(q);

    if(sz[idp] > sz[idq]) {
        swap(idp, idq);
    }

    id[idp] = idq;
    sz[idq]+=sz[idp];
}

int kruskal() {
    sort(g.begin(), g.end());
    int total = 0;
    for (int i = 0; i < (int)g.size(); i++) {
        int x = g[i].second.first;
        int y = g[i].second.second;
        if(findd(x) != findd(y)) {
            total+=g[i].first;
            unionn(x,y);
        }
    }
    return total;
}

int main()
{
    int n, m, x, y, z;
    cin >> n >> m;
    id.assign(n, 0);
    sz.assign(n, 0);
    for (int i = 0; i < n; i++) {
        id[i] = i;
    }
    while(m--) {
        cin >> x >> y >> z;
        g.push_back({z, {x, y}});
    }

    cout << kruskal() << endl;
    return 0;
}
