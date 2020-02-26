#include <iostream>
#include <vector>

using namespace std;

int x, y, p;
vector<vector<int> > fk;

void update(int ii, int jj, int value) {
    for (int i = ii; i < x+1; i+=i&(-i)) {
        for (int j = jj; j < y+1; j+=j&(-j)) {
            fk[i][j]+=(value*p);
        }
    }
}

int query(int ii, int jj) {
    int sum = 0;
    for (int i = ii; i > 0; i-=i&(-i)) {
        for (int j = jj; j > 0; j-=j&(-j)) {
            sum+=fk[i][j];
        }
    }
    return sum;
}

int query(int x1, int y1, int x2, int y2) {
    return (query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char a;
    int x1, y1, x2, y2, op, va;
    while(cin >> x >> y >> p && x && y && p) {
        fk.assign(x+1, vector<int>(y+1, 0));
        cin >> op;
        while(op--) {
            cin >> a;
            if (a == 'A') {
                cin >> va >> x1 >> y1;
                ++x1; ++y1;
                update(x1, y1, va);
            } else {
                cin >> x1 >> y1 >> x2 >> y2;
                x1++; y1++; x2++; y2++;
                if (y2 < y1)
                    swap(y1, y2);
                if (x2 < x1)
                    swap(x1,x2);
                cout << query(x1, y1, x2, y2) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
