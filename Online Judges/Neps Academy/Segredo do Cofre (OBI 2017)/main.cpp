#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int v[10];

    /*
    Data operator + (const Data& d) {
        Data dd;
        for (int i = 0; i < 10; i++) {
            dd.v[i] = d.v[i] + this->v[i];
        }
        return dd;
    }*/
};

vector<Data>st;
vector<int>c;

void build(int n, int s, int e) {
    if (s == e) {
        // whatever is the number, has exactly one occurrence of it and 0 of others
        st[n].v[c[s]] = 1;
    } else {
        int m = (s + e) >> 1;

        build(n * 2, s, m);
        build(n * 2 + 1, m + 1, e);

        for (int i = 0; i < 10; i++) {
            st[n].v[i] = st[2 * n].v[i] + st[2 * n + 1].v[i];
        }
    }
}

Data query(int n, int s, int e, int i, int j) {
    if (i > e || j < s) {
        return {0,0,0,0,0,0,0,0,0,0};
    }

    if (i <= s && e <= j) {
        return st[n];
    }

    int m = (s + e) >> 1;

    Data dl = query(2 * n, s, m, i, j);
    Data dr = query(2 * n + 1, m + 1, e, i, j);

    Data sum;
    for (int i = 0; i < 10; i++) {
        sum.v[i] = dl.v[i] + dr.v[i];
    }
    return sum;
}

int main()
{
    int n, m, y, x;
    cin >> n >> m;
    st.assign(4 * n, {0,0,0,0,0,0,0,0,0});
    c.assign(n, 0);
    Data get = {0};
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    build(1, 0, n - 1);

    y = 1;
    int aux;
    while(m--) {
        cin >> x;
        aux = x;
        if (y < x) {
            y++;
            swap(x, y);
        } else if (x != y) {
            y--;
        }
        --x; --y;

        Data dd = query(1, 0, n - 1, x, y);
        for (int i = 0; i < 10; i++) {
            get.v[i]+=dd.v[i];
        }

        y = aux;
    }

    for (int i = 0; i < 10; i++) {
        if (i != 0)
            cout << " ";
        cout << get.v[i];
    }
    cout << endl;

    return 0;
}
