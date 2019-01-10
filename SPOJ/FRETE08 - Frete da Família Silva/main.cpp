#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef pair<int,int>pii;
vector<int>id, sz;
vector<pair<int,pii> >v;

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
    int coins = 0;
    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size(); i++) {
        int p = v[i].second.first;
        int q = v[i].second.second;
        if(detect(p) != detect(q)) {
          unify(p,q);
          coins+=v[i].first;
        }
    }
    return coins;
}

int main()
{
    int nColonias, nEstradas, coloniaA, coloniaB, custo;
    cin >> nColonias >> nEstradas;

    sz.assign(nColonias, 1);
    id.assign(nColonias, 0);

    for(int i = 0; i < nColonias; i++)
        id[i] = i;

    while(nEstradas--) {
        cin >> coloniaA >> coloniaB >> custo;
        v.push_back({custo, {coloniaA, coloniaB}});
    }

    cout << kruskal() << endl;

    return 0;
}
