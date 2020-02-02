#include <iostream>
#include <vector>

using namespace std;

vector<int>a, st;

int goleft(int n) {return n << 1;}
int goright(int n) {return (n << 1) + 1;}

void build(int n, int s, int e) {
    if (s == e)
        st[n] = a[s];
    else {
        int m = (s + e) >> 1;
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);
        st[n] = st[goleft(n)] + st[goright(n)];
    }
}

void update(int n, int s, int e, int i, int v) {
    if (s == e) {
        st[n] = v;
        a[i] = v;
    } else {
        int m = (s + e) >> 1;
        if (i <= m) {
            update(goleft(n), s, m, i, v);
        } else {
            update(goright(n), m + 1, e, i, v);
        }
        st[n] = st[goleft(n)] + st[goright(n)];
    }
}

int query(int n, int s, int e, int i, int j) {
    if (s > j || e < i)
        return 0;
    else if (i <= s && e <= j)
        return st[n];
    int m = (s + e) >> 1;
    return (query(goleft(n), s, m, i, j) +
            query(goright(n), m + 1, e, i, j));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y, t = 1;
    string op;

    while(cin >> n && n != 0) {
        a.assign(n, 0);
        st.assign(4 * n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build(1, 0, n - 1);

        if (t != 1)
            cout << "\n";
        cout << "Case " << t++ << ":" << endl;
        while(cin >> op && op != "END") {
            cin >> x >> y;
            if (op == "S") {
                update(1, 0, n - 1, --x, y);
            } else {
                cout << query(1, 0, n - 1, --x, --y) << endl;
            }
        }
    }
    return 0;
}
