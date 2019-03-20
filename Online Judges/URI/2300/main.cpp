#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> >g;
vector<int>id;

int detect(int u) {
    if(id[u] == u)
        return u;
    return id[u] = detect(id[u]);
}

void unify(int p, int q) {
    p = detect(p);
    q = detect(q);

    id[p] = id[q];
}

int main()
{
    int n, m, u, v, t = 1;
    while(cin >> n >> m && n && m) {
        g.assign(n, vector<int>());
        id.assign(n, 0);
        for (int i = 0; i < n; i++)
            id[i] = i;
        int nSets = n;
        while(m--) {
            cin >> u >> v;
            if(detect(u - 1) != detect(v - 1)) {
                unify(u - 1, v - 1);
                nSets--;
            }
        }
        cout << "Teste " << t++ << endl;
        if(nSets == 1)
            cout << "normal\n";
        else
            cout << "falha\n";
        cout << endl;
    }
    return 0;
}
