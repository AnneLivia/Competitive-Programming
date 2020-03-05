#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > fk;
int n, m;

int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i-=(i&(-i))) {
        for (int j = y; j > 0; j-=(j&(-j))) {
            sum+=fk[i][j];
        }
    }
    return sum;
}

int query(int x1, int y1, int x2, int y2) {
    return (query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1));
}

void update(int x, int y, int value, int previous) {
    for (int i = x; i < n+1; i+=(i&(-i))) {
        for (int j = y; j < m+1; j+=(j&(-j))) {
            fk[i][j]-=previous;
            fk[i][j]+=value;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, q, x1, y1, x2, y2;
    vector<vector<int> > v;

    while(cin >> n >> m) {
        v.assign(n, vector<int>(m, 0));
        fk.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        // constructing FK 2d
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                update(i + 1, j + 1, v[i][j], 0);
            }
        }

        cin >> q;
        while(q--) {
            cin >> r >> x1 >> y1 >> x2 >> y2;
            if (r == 0) {
                update(x1, y1, 0, 1);
                update(x2, y2, 1, 0);
            } else {
                cout << query(x1, y1, x2, y2) << endl;
            }
        }
    }

    return 0;
}
