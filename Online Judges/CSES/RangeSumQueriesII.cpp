#include <iostream>
#include <vector>

using namespace std;
typedef long long int lli;

vector<lli>data, st;

void build(int n, int s, int e) {
    if (s == e) {
        st[n] = data[s];
    } else {
        int m = (s + e) >> 1;
        build(2 * n, s, m);
        build(2 * n + 1, m + 1, e);

        st[n] = st[2 * n] + st[2 * n + 1];
    }
}

void update(int n, int s, int e, int i, lli v) {
    if (s == e) {
        st[n] = v; 
    } else {
        int m = (s + e) >> 1;
        if (i <= m)
            update(2 * n, s, m, i, v);
        else
            update(2 * n + 1, m + 1, e, i, v);

        st[n] = st[2 * n] + st[2 * n + 1]; 
    }
}

lli query(int n, int s, int e, int i, int j) {
    if (s > j || e < i)
        return 0LL;
    if (i <= s && e <= j) 
        return st[n];
    int m = (s + e) >> 1;
    lli ll = query(2 * n, s, m, i, j);
    lli dd = query(2 * n + 1, m + 1, e, i, j);
    return ll + dd;
}

int main() {
    int n, q, op, a, b;
    lli va;

    cin >> n >> q;
    data.assign(n + 1, 0);
    st.assign(4 * (n + 1), 0);
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    
    build(1, 0, n + 1);

    while(q--) {
        cin >> op >> a;
        if (op == 1) {
            cin >> va;
            update(1, 0, n + 1, a, va);
        } else {
            cin >> b;
            cout << query(1, 0, n + 1, a, b) << endl;
        }
    }
    return 0;  
}
