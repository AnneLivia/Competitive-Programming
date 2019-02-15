#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,pair<int,int> > > g;
vector<int>id;

int detect(int p) {
    if(p == id[p])
        return p;
    return detect(id[p]);
}

void unify(int p, int q) {
    p = detect(p);
    q = detect(q);
    id[p] = q;
}

long long int mst() {
    sort(g.begin(), g.end());
    long long int cont = 0;
    for (int i = 0; i < (int)g.size(); i++) {
        int u = g[i].second.first;
        int v = g[i].second.second;
        int w = g[i].first;
        if(detect(u) != detect(v)) {
            unify(u,v);
            cont+=w;
        }
    }
    return cont;
}

int main()
{
    int nv, ne, u, v, w;
    cin >> nv >> ne;
    id.assign(nv, 0);
    for (int i = 0; i < nv; i++)
        id[i] = i;
    while(ne--) {
        cin >> u >> v >> w;
        --u; --v;
        g.push_back({w,{u,v}});
    }
    cout << mst() << endl;
    return 0;
}
