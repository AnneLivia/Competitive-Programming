#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p, maxrow = 0;
    cin >> p >> n;
    vector<pair<int,int> > v(n, {0,0});
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first > maxrow)
            maxrow = v[i].first;
        
    }

    vector<vector<int> > kn(n+1, vector<int>(p+1, 0));
    
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < p + 1; j++) {
           int value = kn[i - 1][j];

           if (v[i - 1].first <= j) {
               int vv = kn[i - 1][j - (v[i - 1].first)] + v[i - 1].second;
               if (vv > value) {
                   value = vv;
               }
           }

            kn[i][j] = value;
        }
    }

    cout << kn[n][p] << endl;

    return 0;  
}
