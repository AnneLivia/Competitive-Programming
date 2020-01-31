#include <iostream>

using namespace std;

int v[100001], st[512345];

inline int goleft(int n) {return n << 1;}
inline int goright(int n) {return (n << 1) + 1;}

void build(int n, int s, int e) {
    if (s == e) {
        st[n] = v[s];
    } else {
        int m = (s + e) >> 1;
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        st[n] = min(st[goleft(n)], st[goright(n)]);
    }
}

int query(int n, int s, int e, int i, int j) {
    if (s > j || e < i)
        return 0x3f3f3f3f;
    if (i <= s && e <= j)
        return st[n];

    int m = (s + e) >> 1;
    int l = query(goleft(n), s, m, i, j);
    int d = query(goright(n), m + 1, e, i, j);

    return min(l, d);
}


int main()
{
    int t, n, q, a, b, x = 1;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        build(1, 0, n - 1);
        cout << "Scenario #" << x++ << ":\n";
        while(q--) {
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
    return 0;
}
