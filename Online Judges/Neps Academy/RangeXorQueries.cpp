#include <iostream>
#include <vector>

using namespace std;
typedef long long int lli;

vector<lli>st,data;
inline int goleft(int n) {return n << 1;}
inline int goright(int n) {return (n << 1) + 1;}

void build(int n, int s, int e) {
    if (s == e) {
        st[n] = data[s];
    } else {
        int m = (s + e) >> 1;
        build(goleft(n), s, m);
        build(goright(n), m + 1, e);

        st[n] = st[goleft(n)] ^ st[goright(n)];
    }
}

lli query(int n, int s, int e, int a, int b) {
    if (s > b || e < a) {
        return 0LL;
    }

    if (a <= s && e <= b) {
        return st[n];
    }

    int m = (s + e) >> 1;
    lli l = query(goleft(n), s, m, a, b);
    lli d = query(goright(n), m + 1, e, a, b);

    return l ^ d;
}

int main() {
    int n, q, a, b;

    cin >> n >> q;

    data.assign(n, 0LL);
    st.assign(4 * n, 0LL);

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    build(1, 0, n - 1);

    while(q--) {
        cin >> a >> b;
        cout << query(1, 0, n - 1, --a, --b) << endl;
    }
    return 0;  
}
