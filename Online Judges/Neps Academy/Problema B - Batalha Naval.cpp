#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > grid(11, vector<int>(11, 0));

    int n, d, l, r, c, no = 0, nono = 0;

    cin >> n;

    while(n--) {
        cin >> d >> l >> r >> c;

        if (d == 0) {
            if (c + l - 1 > 10) {
                no = 1;

            } else {
                for (int i = c; i <= c+l-1; i++) {
                    if (grid[r][i] == 1) {
                        no = 1;
                        break;
                    }
                    grid[r][i] = 1;
                }
            }
        } else {
            if (r + l - 1 > 10) {
                no = 1;
            } else {
                for (int i = r; i <= r+l-1; i++) {
                    if (grid[i][c] == 1) {
                        no = 1;
                        break;
                    }
                    grid[i][c] = 1;
                }
            }

        }

        if (no == 1) {
            nono = 1;
        }
    }


    if (no) {
        cout << "N\n";
    } else {
        cout << "Y\n";
    }
    return 0;
}
