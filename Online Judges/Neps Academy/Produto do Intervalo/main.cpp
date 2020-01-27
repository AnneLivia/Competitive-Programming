#include <iostream>
#include <vector>

using namespace std;

vector<long long int>st, a;

const long long int M = 1000000007; // (10^9 + 7)

void build(int node, int start, int endd) {
    if(start == endd) {
        st[node] = a[start];
    } else {
        int midd = (start + endd) >> 1;
        int left = node * 2;
        int right = node * 2 + 1;

        build(left, start, midd);
        build(right, midd + 1, endd);

        st[node] = (st[left] * st[right]) % M; // same as ((p1 % M) * (pr % M) % M)
    }
}

void update(int node, int start, int endd, int i, long long int value) {
    if(start == endd) {
        st[node] = value;
        a[i] = value;
    } else {
        int midd = (start + endd) >> 1;

        int left = node * 2;
        int right = node * 2 + 1;

        if(i <= midd) {
            update(left, start, midd, i, value);
        } else {
            update(right, midd + 1, endd, i, value);
        }

        // update intermediate nodes
        st[node] = (st[left] * st[right]) % M; // same as ((p1 % M) * (pr % M) % M)
    }
}

long long int query(int node, int start, int endd, int i, int j) {
    // check if range represented by this current node
    // is outside the range i..j, inside or partially inside
    if(start > j || endd < i) {
        // outside range
        return 1;
    }

    if (i <= start && endd <= j) {
        // inside range
        return st[node];
    }

    // partially inside
    int midd = (start + endd) >> 1;

    int left = node * 2;
    int right = node * 2 + 1;

    long long int pl = query(left, start, midd, i, j);
    long long int pr = query(right, midd + 1, endd, i, j);

    return (pl * pr) % M; // same as ((p1 % M) * (pr % M) % M)
}

ostream& operator << (ostream& out, const vector<long long int>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        out << "(" << i + 1 << ") -> " << v[i] << "\n";
    }
    return out;
}

int main() {

    int n, k, i, j;
    long long int v;
    char op;
    while(cin >> n >> k) {
        a.assign(n, 0);
        if (n & (n - 1) == 0) // power of two
            st.assign(n * 2, 0);
        else
            st.assign(n * 4, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        build(1, 0, n - 1);

        string ans = "";

        while(k--) {
            //cout << "\n\nInitial vector\n: " << a << endl;
            //cout << "ST vector: " << st << endl << endl;
            cin >> op >> i;
            i--;
            if(op == 'C') {
                cin >> v;
                update(1, 0, n - 1, i, v);
            } else {
                cin >> j;
                j--;
                long long int r = query(1,0, n - 1, i, j) % M;
                if(r > 0)
                    ans+="+";
                else if (r < 0)
                    ans+="-";
                else
                    ans+="0";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
