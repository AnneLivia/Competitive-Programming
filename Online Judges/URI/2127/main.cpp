#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// CIPO - 2127 URI and SPOJ
typedef pair<int,int> pii;
vector<int>id, sz;
vector<pair<int,pii>>v;

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

int main()
{
    int n, m, x, y, z, t = 1, custominimo;
    while(cin >> n >> m) {
        id.assign(n,0);
        sz.assign(n,1);
        v.clear();
        custominimo = 0;

        for (int i = 0; i < n; i++) {
            id[i] = i;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            v.push_back({z,{--x,--y}});
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < m; i++) {
            int p = v[i].second.first;
            int q = v[i].second.second;
            if(detect(p) != detect(q)) {
                unify(p, q);
                custominimo+=v[i].first;
            }
        }

        printf("Instancia %d\n%d\n\n", t++, custominimo);
    }

    return 0;
}
