#include <iostream>
#include <vector>

using namespace std;

vector<int>a, st;

int goleft(int node) {
    return node << 1; // same as node * 2, << 1, multiply by 2
}

int goright(int node) {
    return (node << 1) + 1;
}

void build(int n, int s, int e) {
    if(s == e) {
        st[n] = a[s];
    } else {
        int m = (s + e) >> 1; // same as / 2
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        st[n] = st[goleft(n)] * st[goright(n)];
    }
}

void update(int n, int s, int e, int i, int v) {
    if(s == e) {
        st[n] = v;
        a[i] = v;
    } else {
        int m = (s + e) >> 1;
        if(i <= m)
            update(goleft(n), s, m, i, v);
        else
            update(goright(n), m + 1, e, i, v);

        st[n] = st[goleft(n)] * st[goright(n)];
    }
}

int query(int n, int s, int e, int i, int j) {
    if(s >= i && e <= j) {
        // inside range
        return st[n];
    } else if (s > j || e < i) {
        // outside, return 1
        return 1;
    }

    int m = (s+e) >> 1;

    // partially inside, return product from left and right
    int l = query(goleft(n), s, m, i, j);
    int r = query(goright(n), m + 1, e, i, j);

    return l * r;
}

int main()
{
    int n, k, i, j;
    char op;
    while(cin >> n >> k) {
        a.assign(n, 0);
        st.assign(4 * n, 0);
        for (int i = 0; i < n; i++) {
            cin >> j;
            // since this problem doesn't require the result of the
            // product, then just by changing a positive number to 1,
            // or a negative number to -1, is going to give the proper result
            a[i] = j == 0 ? 0 : j > 0 ? 1 : -1;
        }

        build(1, 0, n - 1);
        string s = "";
        while(k--) {
            cin >> op >> i >> j;
            if(op == 'C') {
                // since I'm updating the number, need to transform it to 1 or -1 here too
                j = j == 0 ? 0 : j > 0 ? 1 : -1;
                update(1, 0, n - 1, i - 1, j);
            } else {
                int r = query(1, 0, n - 1, i - 1, j - 1);
                s += (r == 0? '0' : r > 0 ? '+' : '-');
            }
        }
        cout << s << endl;
    }
    return 0;
}
