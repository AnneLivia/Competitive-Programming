#include <iostream>
#include <vector>

using namespace std;

inline int left(int n) {return n << 1;}
inline int right(int n) {return (n << 1) + 1;}
inline int middle(int s, int e) {return (s + e) >> 1;}


vector<long long int> lazy, st;

void update(int n, int s, int e, int i, int j, long long int va) {
    if (lazy[n]) {
        st[n] += lazy[n] * (e - s + 1);

        if (s != e) {
            lazy[left(n)] += lazy[n];
            lazy[right(n)] += lazy[n];
        }

        lazy[n] = 0LL;
    }

    if (s > e || s > j || e < i)
        return;
    else if (i <= s && e <= j) {
        st[n] += (va * (e - s + 1));

        if (s != e) {
            lazy[left(n)]+= va;
            lazy[right(n)]+= va;
        }
        return;
    } else {
        int m = middle(s, e);
        update(left(n), s, m, i, j, va);
        update(right(n), m + 1, e, i, j, va);

        st[n] = st[left(n)] + st[right(n)];
    }
}

long long int query(int n, int s, int e, int i, int j) {
    if (lazy[n]) {
        st[n] += (lazy[n] * (e - s + 1));

        if (s != e) {
            lazy[left(n)] += lazy[n];
            lazy[right(n)] += lazy[n];
        }
        lazy[n] = 0LL;
    }

    if (s > e || s > j || e < i)
        return 0LL;
    else if (i <= s && e <= j) {
        return st[n];
    } else {
        int m = middle(s, e);

        long long int l = query(left(n), s, m, i, j);
        long long int r = query(right(n), m + 1, e, i, j);

        return l + r;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, q, op, x, y;
    long long int va;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        lazy.assign(4 * n, 0);
        st.assign(4 * n, 0);

        while(q--) {
            cin >> op >> x >> y;
            x--; y--;
            if (op == 0) {
                cin >> va;
                update(1, 0, n - 1, x, y, va);
            } else {
                cout << query(1, 0, n - 1, x, y) << endl;
            }
        }
    }
    return 0;
}
