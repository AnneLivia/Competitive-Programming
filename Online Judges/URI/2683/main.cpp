#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef pair<int,int>pii;
vector<pair<int,pii>>v;
vector<int>id,sz;

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
    int tam = id.size(), p, q, sum = 0;
    for(int i = 0; i < tam; i++)
        id[i] = i;
    sz.assign(tam,1);

    for (int i = 0; i < (int)v.size(); i++) {
        p = v[i].second.first;
        q = v[i].second.second;

        if(detect(p) != detect(q)) {
            unify(p,q);
            sum+=v[i].first;
        }
    }

    return sum;
}

int main()
{
    int n, p, q, w;
    scanf("%d",&n);
    id.assign(n, 0);

    while(n--) {
        scanf("%d %d %d",&p,&q,&w);
        v.push_back({w,{--p,--q}});
    }

    sort(v.rbegin(), v.rend());
    printf("%d\n",kruskal());
    sort(v.begin(), v.end());
    printf("%d\n",kruskal());

    return 0;
}
