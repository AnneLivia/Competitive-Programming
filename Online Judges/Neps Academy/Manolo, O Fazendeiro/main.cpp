#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, t, l1, l2, c1, c2, to = 0;
    cin >> n;

    vector<vector<int> > v(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    cin >> t;

    while(t--) {
        cin >> l1 >> c1 >> l2 >> c2;
        for (int i = l1; i <= l2; i++) {
            for (int j = c1; j <= c2; j++) {
               to+=v[i][j];
               v[i][j] = 0;
            }
        }
    }
    cout << to << endl;
    return 0;
}
