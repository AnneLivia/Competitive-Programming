#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int,int> > > ro, fe;

vector<int>id, ra;

int findd(int p) {
    if (id[p] == p)
        return p;
    return id[p] = findd(id[p]);
}

void unify(int p, int q) {
    int idp = findd(p);
    int idq = findd(q);

    if (ra[idp] > ra[idq]) {
        id[idq] = idp;
    } else if (ra[idp] < ra[idq]) {
        id[idp] = idq;
    } else {
        id[idp] = idq;
        ra[idq]++;
    }
}

int process() {
    // sorting by cost
    sort(fe.begin(), fe.end());
    sort(ro.begin(), ro.end());
    int cost = 0;
    // ferrovias
    for (int i = 0; i < (int)fe.size(); i++) {
        pair<int, pair<int,int> > pp = fe[i];

        if(findd(pp.second.first) != findd(pp.second.second)) {
            unify(pp.second.first, pp.second.second);
            cost+=pp.first;
        }
    }

    // rodovias
    for (int i = 0; i < (int)ro.size(); i++) {
        pair<int, pair<int,int> > pp = ro[i];

        if(findd(pp.second.first) != findd(pp.second.second)) {
            unify(pp.second.first, pp.second.second);
            cost+=pp.first;
        }
    }

    return cost;
}

int main()
{
    int ci, f, r, a, b, c;

    cin >> ci >> f >> r;

    id.assign(ci + 1, 0);
    ra.assign(ci + 1, 0);

    for (int i = 1; i <= ci; i++) {
        id[i] = i;
    }

    while(f--) {
        cin >> a >> b >> c;
        fe.push_back({c, {a,b}});
        fe.push_back({c, {b,a}});
    }

    while(r--) {
        cin >> a >> b >> c;
        ro.push_back({c, {a,b}});
        ro.push_back({c, {b,a}});
    }

    cout << process() << endl;

    return 0;
}
