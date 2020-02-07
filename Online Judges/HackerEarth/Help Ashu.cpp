#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int qtd_even, qtd_odd;
};

vector<long long int>v;
vector<Data>st;

inline int goleft(int n) {return n << 1;}
inline int goright(int n) {return (n << 1) + 1;}
inline int middle(int s, int e) {return (s + e) >> 1;}

void build(int n, int s, int e) {
    if (s == e) {
        Data d = {0,0};
        if ((v[s] & 1LL) == 0LL)
            d.qtd_even++;
        else
            d.qtd_odd++;
        st[n] = d;
    } else {
        int m = middle(s, e);
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        Data d;

        d.qtd_even = st[goleft(n)].qtd_even + st[goright(n)].qtd_even;
        d.qtd_odd = st[goleft(n)].qtd_odd + st[goright(n)].qtd_odd;

        st[n] = d;
    }
}

void update(int n, int s, int e, int i, long long int va) {
     if (s == e) {
        Data d = {0,0};
        if ((va & 1LL) == 0LL) {
            d.qtd_even++;
        } else {
            d.qtd_odd++;
        }
        v[i] = va;
        st[n] = d;
     }  else {
        int m = middle(s, e);

        if (i <= m)
            update(goleft(n), s, m, i, va);
        else
            update(goright(n), m + 1, e, i, va);

        Data d;

        d.qtd_even = st[goleft(n)].qtd_even + st[goright(n)].qtd_even;
        d.qtd_odd = st[goleft(n)].qtd_odd + st[goright(n)].qtd_odd;

        st[n] = d;
     }
}

int query(int n, int s, int e, int i, int j, int op) {
     if (s > j || e < i)
        return 0;
     else if (i <= s && e <= j) {
        return op == 1 ? st[n].qtd_even : st[n].qtd_odd;
     } else {
        int m = middle(s, e);

        int l = query(goleft(n), s, m, i, j, op);
        int r = query(goright(n), m + 1, e, i, j, op);

        return l + r;
     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, x, y, op;
    cin >> n;
    v.assign(n, 0);
    st.assign(4 * n, {0,0});

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    build(1, 0, n - 1);

    cin >> q;
    while(q--) {
        cin >> op >> x >> y;
        --x;
        if (op == 0) {
            // modify number in x by y;
            update(1, 0, n - 1, x, y);
        } else {
            --y;
            cout << query(1, 0, n - 1, x, y, op) << endl;
        }
    }
    return 0;
}
