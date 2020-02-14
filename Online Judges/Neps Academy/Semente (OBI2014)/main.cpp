#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int n, r, t;
    cin >> n >> r;
    vector<int>v(n, 0);
    vector<int>is;
    for (int i = 0; i < r; i++) {
        cin >> t;
        v[--t] = 1;
        is.push_back(t);
    }
    if (r == 1 && (is[0] == 0 || is[0] == n - 1)) {
        cout << n - 1 << endl;
    } else {
        t = 0;
        int can = 1, j = 0;
        vector<int>aux;
        while(can) {
            int i = is[j];
            aux.clear();
            while (j < (int)is.size()) {
                j++;
                int change = 0;
                if (v[i] == 1) {
                    if (i - 1 >= 0 && v[i - 1] == 0) {
                        v[i - 1] = 1;
                        aux.push_back(i - 1);
                    }
                    if (i + 1 < n && v[i + 1] == 0) {
                        v[i + 1] = 1;
                        change = 2;
                        aux.push_back(i + 1);
                    }

                    if (change == 2) {
                        i = j;
                    } else {
                        i = j;
                    }
                } else {
                    i = j;
                }

                i = is[j];
            }

            for (auto i : aux)
                is.push_back(i);

            t++;

            for (int i = 0; i < n; i++) {
                if (v[i] == 0) {
                    can = 0;
                    break;
                }
            }

            if (can) {
                cout << t << endl;
                break;
            }
            can = 1;
        }
    }
    return 0;
}
