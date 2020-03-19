#include <iostream>
#include <vector>

using namespace std;
typedef long long int lli;

vector<lli>st, data;

inline int goleft(int n) {return (n << 1);}
inline int goright(int n) {return (n << 1) + 1;}
inline int getmiddle(int s, int e) {return (s + e) >> 1;}

void build(int n, int s, int e) {
    if (s == e) { 
        st[n] = data[s];
    } else {
        int m = getmiddle(s, e);
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        st[n] = min(st[goleft(n)], st[goright(n)]);
    }
}

lli query(int n, int s, int e, int i, int j) {
    if (s > j || e < i)
        return 0x3f3f3f3f3f3f;
    if (i <= s && e <= j)
        return st[n];

    lli ll = query(goleft(n), s, getmiddle(s, e), i, j);
    lli dd = query(goright(n), getmiddle(s, e) + 1, e, i, j);

    return min(ll, dd);
}

int main() {
    int n, q, a, b;
    cin >> n >> q;

    data.assign(n, 0);
    st.assign(n * 4, 0);

    for (int i = 0; i < n; i++) 
        cin >> data[i];
    build(1, 0, n - 1);
    while(q--) {
        cin >> a >> b;
        --a; --b;
        cout << query(1, 0, n - 1, a, b) << endl;
    }
    return 0;  
}
