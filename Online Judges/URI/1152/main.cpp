#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

vector<int>id;
vector<int>sz;
vector<pair< pii, int> >v;

int detect(int p) {
    if(id[p] == -1)
        return p;
    return id[p] = detect(id[p]);
}

void unify(int n1, int n2) {
    int r1 = detect(n1);
    int r2 = detect(n2);

    if(sz[r1] < sz[r2]) {
        id[r1] = r2;
        sz[r2]+=sz[r1];
    } else {
        id[r2] = r1;
        sz[r1]+=sz[r2];
    }
}

int main()
{
    int n, m, x, y, z;
    long long int sum, total;

    while(cin >> n >> m && m && n) {
        id.assign(n, -1);
        sz.assign(n, 1);
        total = sum = 0;
        v.clear();
        while(m--) {
            cin >> x >> y >> z;
            v.push_back(make_pair(make_pair(x,y),z));
            total+=z;
        }

        sort(v.begin(), v.end(), []( const pair<pii, int>&p1, const pair<pii, int>&p2) {
            return (p1.second < p2.second);
        });

        for (int i = 0; i < (int)v.size(); i++) {
            if(detect(v[i].first.first) != detect(v[i].first.second)){
                unify(v[i].first.first, v[i].first.second);
                sum+=v[i].second;
            }
        }

        cout << total - sum << endl;
    }
    return 0;
}
