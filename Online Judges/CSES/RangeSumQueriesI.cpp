#include <iostream>
#include <vector>

using namespace std;

vector<long long int> st, data;

void build(int n, int s, int e) {
    if (s == e) {
        st[n] = data[s];
    } else {
        int m = (s + e) >> 1;
        build(2 * n, s, m);
        build(2 * n + 1, m + 1, e);
        st[n] = st[n * 2] + st[n * 2 + 1];
    }
}

long long int query(int n, int s, int e, int i, int j) {
    if (s > j || e < i) {
        return 0;
    } 

    if (i <= s && e <= j) {
        return st[n];
    }
    int m = (s + e) >> 1;

    long long int suml = query(2 * n, s, m, i, j);
    long long int sumr = query(2 * n + 1, m + 1, e, i, j);

    return suml + sumr;
}

int main() {
    int n, q, a, b;

    cin >> n >> q;
    
    data.assign(n, 0LL);
    st.assign(n * 4, 0LL);

    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    build(1, 0, n - 1);

    while(q--) {
        cin >> a >> b;
        --a; --b;
        cout << query(1, 0, n - 1, a, b) << endl;
    }
    return 0;  
}
