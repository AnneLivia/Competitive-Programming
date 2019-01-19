#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int,int>,int> >v;
vector<int>id;

int detect(int el) {
    if(id[el] == -1)
        return el;
    return id[el] = detect(id[el]);
}

void unify(int v1, int v2) {
    id[detect(v1)] = detect(v2);
}

int main()
{
    int m, n, w, v1, v2, sum;
    while(cin >> m >> n && m != 0 && n != 0) {
        id.assign(m,-1);
        v.clear();
        sum = 0;
        while(n--) {
            cin >> v1 >> v2 >> w;
            v.push_back(make_pair(make_pair(v1, v2), w));
        }

        sort(v.begin(), v.end(),
        [](const pair<pair<int,int>,int>& p1, const pair<pair<int,int>,int>& p2) -> bool {
            return (p1.second < p2.second);
        });

        for (int i = 0; i < (int)v.size(); i++) {
            if(detect(v[i].first.first) != detect(v[i].first.second)) {
                sum+=v[i].second;
                unify(v[i].first.first, v[i].first.second);
            }
        }

        cout << sum << endl;
    }
    return 0;
}
