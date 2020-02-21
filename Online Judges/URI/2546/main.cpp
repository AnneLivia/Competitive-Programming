#include <iostream>
#include <vector>

using namespace std;

inline int left(int n) {return n << 1;}
inline int right(int n) {return (n << 1) + 1;}
inline int middle(int s, int e) {return (s + e) >> 1;}

struct Data {
    int id, va;
};

vector<int>v, lazy;
vector<Data> st;

void build(int n, int s, int e) {
    if (s == e) {
        st[n].va = v[s];
        st[n].id = s;
    } else {
        int m = middle(s, e);
        build(left(n),s,m);
        build(right(n),m+1,e);

        st[n] = [](const Data& d1, const Data& d2) -> Data {
            if (d1.va > d2.va)
                return d1;
            else if (d1.va == d2.va) {
                if (d1.id < d2.id)
                    return d1;
            }
            return d2;
        }(st[left(n)], st[right(n)]);
    }
}

void update(int n, int s, int e, int i, int j, int va) {
    if (lazy[n]) {
        st[n].va += lazy[n];

        if (s != e) {
            lazy[left(n)] += lazy[n];
            lazy[right(n)] += lazy[n];
        }

        lazy[n] = 0;
    }

    if (s > e || s > j || e < i)
        return;
    else if (i <= s && e <= j) {
        st[n].va += va;

        if (s != e) {
            lazy[left(n)]+= va;
            lazy[right(n)]+= va;
        }
        return;
    } else {
        int m = middle(s, e);
        update(left(n), s, m, i, j, va);
        update(right(n), m + 1, e, i, j, va);

        st[n] = [](const Data& d1, const Data& d2) -> Data {
            if (d1.va > d2.va)
                return d1;
            else if (d1.va == d2.va) {
                if (d1.id < d2.id)
                    return d1;
            }
            return d2;
        }(st[left(n)], st[right(n)]);
    }
}

Data query(int n, int s, int e, int i, int j) {
    if (lazy[n]) {
        st[n].va += lazy[n];

        if (s != e) {
            lazy[left(n)] += lazy[n];
            lazy[right(n)] += lazy[n];
        }
        lazy[n] = 0;
    }

    if (s > e || s > j || e < i)
        return {-0x3f3f3f3f, -0x3f3f3f3f};
    else if (i <= s && e <= j) {
        return st[n];
    } else {
        int m = middle(s, e);

        Data l = query(left(n), s, m, i, j);
        Data r = query(right(n), m + 1, e, i, j);

        return [](const Data& d1, const Data& d2) -> Data {
            if (d1.va > d2.va)
                return d1;
            else if (d1.va == d2.va) {
                if (d1.id < d2.id)
                    return d1;
            }
            return d2;
        }(l, r);
    }
}

ostream& operator << (ostream& out,const vector<Data>&v) {
    for (int i = 0; i < (int)v.size(); i++) {
        out << "Node: " << i << ": " << v[i].va << endl;
    }
    return out;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, x, y, t;
    char op;
    while (cin >> n >> q) {
        v.assign(n, 0);
        st.assign(n * 4, {0,0});
        lazy.assign(n * 4, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        build(1, 0, n - 1);
        while(q--) {
            cin >> op >> x >> y;
            --x; --y;
            if (op == 'A') {
                cin >> t;
                update(1, 0, n - 1, x, y, t);
            } else {
                cout << query(1, 0, n -1, x, y).id + 1 << endl;
            }
        }
    }
    return 0;
}
