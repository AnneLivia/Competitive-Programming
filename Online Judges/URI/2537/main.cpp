#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > fk;
inline int lsb(int n) {return n&(-n);}

void update(int x, int y, int value) {
    for (int i = x; i < n+1; i+=lsb(i)) {
        for (int j = y; j < n+1; j+=lsb(j)) {
            fk[i][j]+=value;
        }
    }
}

int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i-=lsb(i)) {
        for (int j = y; j > 0; j-=lsb(j)) {
            sum+=fk[i][j];
        }
    }
    return sum;
}

int query(int x1, int y1, int x2, int y2) {
    return (query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1-1, y1-1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2;
    vector<vector<int> > g;
    while(cin >> n >> m) {
        g.assign(n, vector<int>(n, 0));
        fk.assign(n+1,vector<int>(n+1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                update(i+1, j+1, g[i][j]);
            }
        }

        while(m--) {
            cin >> x1 >> y1;
            update(x1, y1, 1);
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1, y1, x2, y2) << endl;
        }

    }
    return 0;
}
