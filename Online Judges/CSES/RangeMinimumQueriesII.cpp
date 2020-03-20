#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int lli;

vector<lli> data, st;

inline int goleft (int n ) { return n << 1;}
inline int goright (int n ) {return (n << 1) + 1;}

void build(int n, int s, int e) {
    if (s == e) {
        st[n] = data[s];
    } else {
        int m = (s + e) >> 1;
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        st[n] = min(st[goleft(n)], st[goright(n)]);    
    }
}

void update(int n, int s, int e, int i, lli v) {
    if (s == e) {
        st[n] = v;
    } else {
        int m = (s + e) >> 1;
        if (i <= m) {
            update(goleft(n), s, m, i, v); 
        } else {
            update(goright(n), m + 1, e, i, v);
        }

        st[n] = min(st[goleft(n)], st[goright(n)]);
    }
}

lli query(int n, int s, int e, int i, int j) {
    if (s > j || e < i) 
        return 0x3F3F3F3F3F3F;
    if (i <= s && e <= j) {
        return st[n];
    }

    int m = (s + e) >> 1;
    lli ll = query(goleft(n), s, m, i, j);
    lli rr = query(goright(n), m + 1, e, i, j);

    return min(ll, rr);
}

int main() {
    int n, q;
    cin >> n >> q;
    data.assign(n, 0LL);
    st.assign(4 * n, 0LL);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    build(1, 0, n - 1);
    
    int op, a, b;
    lli v;
    while(q--) {
        cin >> op >> a;
        --a;
        if (op == 1) {
            cin >> v;
            update(1, 0, n - 1, a, v);
        } else {
            cin >> b;
            --b;
            cout << query(1, 0, n - 1, a, b) << endl;
        }
    }
    
    return 0;  
}
