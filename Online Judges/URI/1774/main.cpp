#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

vector<pair<int,pii>>v;
vector<int>id, sz;

int detect(int p) {
    if(p == id[p])
        return p;
    return id[p] = detect(id[p]);
}

void unify(int p, int q) {
    p = detect(p);
    q = detect(q);

    if(sz[p] > sz[q]) {
        swap(p,q);
    }

    id[p] = id[q];
    sz[q]+=sz[p];
}
int main()
{
    int r, c, p, q, t, sum = 0;
    cin >> r >> c;

    id.assign(r, 0);
    sz.assign(r, 1);

    for (int i = 0; i < r; i++) {
        id[i] = i;
    }

    for (int i = 0; i < c; i++) {
        cin >> p >> q >> t;
        v.push_back({t,{--p,--q}});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < c; i++) {

        p = v[i].second.first;
        q = v[i].second.second;

        if(detect(p) != detect(q)) {
            sum+=v[i].first;
            unify(p,q);
        }
    }

    cout << sum << endl;
    return 0;
}
