#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, d, l, r, c;

    /*
            d = 0 = horizontally
            d = 1 = vertically

            L = size of the ship

            r, c = row, and col position

            if vertical =  r + l - 1, c;
            if horizontal = r, c + l -1;

    */

    vector<vector<int> > v (10, vector<int>(10, 0));

    cin >> n;

    int ok = true;
    while(n--) {
        cin >> d >> l >> r >> c;
        if (d == 0) {
            // out of the ship
            if (l - 1 + c > 10) {
                ok = false;
            } else {
                for (int i = (c - 1); i < (c + (l - 1)); i++) {
                    if(!v[r - 1][i]) {
                        v[r - 1][i] = 1;
                    } else {
                        ok = false;
                    }
                }
            }
        } else {
             if (l - 1 + r > 10) {
                ok = false;
             } else {
                for (int i = (r - 1); i < (r + (l - 1)); i++) {
                    if(!v[i][c - 1]) {
                        v[i][c - 1] = 1;
                    } else {
                        ok = false;
                    }
                }

             }
        }

    }


    if (ok) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
