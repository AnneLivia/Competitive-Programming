#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
vector<pair<int,pii>>g;
vector<int>id, sz;

int detect(int p) {
    if(p == id[p])
        return p;
    return id[p] = detect(id[p]);
}

void unify(int p, int q) {
    p = detect(p);
    q = detect(q);
    if(sz[p] > sz[q])
        swap(p,q);
    id[p] = id[q];
    sz[q]+=sz[p];
}

int kruskal() {
    int sum = 0, p, q, s = (int)id.size();
    vector<pair<int,int>>mst;
    sz.assign(s, 1);

    for(int i = 0; i < s; i++)
        id[i] = i;

    for(int i = 0; i < (int)g.size(); i++) {
        p = g[i].second.first;
        q = g[i].second.second;

        if(detect(p) != detect(q)) {
            unify(p,q);
            mst.push_back({p,q});
            sum+=g[i].first;
        }
    }
    return sum;
}

int main()
{
    int n, m, p, q, w, maximum, minimum;
    while(scanf("%d %d",&n,&m) && n != 0 && m != 0) {
        g.clear();
        id.assign(n, 0);

        maximum = maximum = 0;

        while(m--) {
            scanf("%d %d %d",&p, &q, &w);
            g.push_back({w,{--p,--q}});
        }

        sort(g.begin(), g.end());
        minimum = kruskal();
        sort(g.rbegin(), g.rend());
        maximum = kruskal();

        printf("%d\n",maximum - minimum);
    }
    return 0;
}
