#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Connection {
private:
    vector<pair<int,pair<int,int> > >v;
    int sz;
    vector<int>id, ra;
public:
    Connection(int sz) {
        this->sz = sz;
        id.assign(sz, 0);
        ra.assign(sz, 0);
        for (int i = 0; i < sz; i++) {
            id[i] = i;
        }
    }

    void add_edge(int x, int y, int z) {
        v.push_back(make_pair(z,make_pair(x,y)));
    }

    bool connected(int p, int q) {
        return (detect(p) == detect(q));
    }

    int detect(int p) {
        if(p == id[p])
            return p;
        return id[p] = detect(id[p]);
    }

    void unify(int p, int q) {
        int dp = detect(p);
        int dq = detect(q);
        if(!connected(dp,dq)) {
            if(ra[dp] > ra[dq]) {
               id[dq] = dp;
               ra[dp]+=ra[dq];
            } else {
               id[dp] = dq;
               ra[dq]+=ra[dp];
            }
        }
    }

    void kruskal() {
        sort(v.begin(), v.end());
        for (int i = 0; i < (int)v.size(); i++) {
            int x = v[i].second.first;
            int y = v[i].second.second;
            if(!connected(x, y)) {
                if( y < x ) {
                    swap(x, y);
                }
                cout << x + 1 << " " << y + 1 << endl;
                unify(x,y);
            }
        }
    }
};


int main() {

    int n, m, x, y, z, t = 1;

    while(cin >> n >> m && n) {
        Connection c(n);
        while(m--) {
            cin >> x >> y >> z;
            c.add_edge(--x,--y, z);
        }
        cout << "Teste " << t++ << endl;
        c.kruskal();
        cout << endl;
    }
    return 0;
}
