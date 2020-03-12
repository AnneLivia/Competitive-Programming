#include <iostream>
#include <vector>

using namespace std;

vector<int>v, st, lazy;

// operation 1: all boxes from a to b must have k coins
// operation 2: how many coins from a to b
inline int goleft(int n) {return n << 1;}
inline int goright(int n) {return (n << 1) + 1;}

void build(int n, int s, int e) {
    if (s == e) {
        st[n] = v[s];
    } else {
        int m = (s + e) >> 1;
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        st[n] = st[goleft(n)] + st[goright(n)];
    }
}

// the idea behind lazy is to update children of some node, only if we need them later on
// and this needed is specified by the lazy array that stores the value we need to update
void update(int n, int s, int e, int i, int j, int va) {
    // check if there pending value
    if (lazy[n]) {
        st[n] = (e - s + 1) * lazy[n];
        // check if is not a leaf, if it is, then update lazy of child
        if  (s != e) {
            // has child
            lazy[goleft(n)] = lazy[n];
            lazy[goright(n)] = lazy[n];
        }

        // update was done
        lazy[n] = 0;
    }

    // continue normally
    if (s > e || s > j || e < i)
        return; // out of range
    if (i <= s && e <= j) {
        // completely in range
        // need to update e - s + 1 times, since must count that all nodes
        // represented by this specific node is going to be updated too
        st[n] = (e - s + 1) * va;

        // check if is not a leaf
        // if that's the case, lazy of child must receive value
        // in case later, there's need to use them in some query or new update
        if (s != e) {
            lazy[goleft(n)] = va;
            lazy[goright(n)] = va;
        }
        return;
    }

    // partially in range, get left and right and update node parent
    int m = (s + e) >> 1;
    update(goleft(n), s, m, i, j, va);
    update(goright(n), m + 1, e, i, j, va);

    st[n] = st[goleft(n)] + st[goright(n)];
}

// query using lazy, almost same as the update function,
// first need to check if there's pending value to update
int query(int n, int s, int e, int i, int j) {
    if (lazy[n]) {
        st[n] = (e - s + 1) * lazy[n];

        if (s != e) {
            lazy[goleft(n)] = lazy[n];
            lazy[goright(n)] = lazy[n];
        }

        lazy[n] = 0; // update was done
    }

    // check if it's out of range
    if (s > e || e < i || s > j)
        return 0;
    else if (i <= s && e <= j) {
        // inside range
        return st[n];
    } else {
        int m = (s + e) >> 1;
        // partially inside range (only some nodes are needed, call left and right)
        int l = query(goleft(n), s, m, i, j);
        int r = query(goright(n), m + 1, e, i, j);

        return l + r;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, a, b, o;
    cin >> n >> q;

    v.assign(n, 0);
    st.assign(4 * n, 0);
    lazy.assign(4 * n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    build(1, 0, n - 1);

    while(q--) {
        cin >> o >> a >> b;
        --a; --b;
        if (o == 1) {
            cin >> o;
            update(1, 0, n - 1, a, b, o);
        } else {
            cout << query(1, 0, n - 1, a, b) << endl;
        }
    }
    return 0;
}
