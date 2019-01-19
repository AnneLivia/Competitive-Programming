#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, a, b, n, c, nr = 1;
    vector<pair<int,int>>v;
    vector<int>ci;
    cin >> t;

    while(t--) {
        v.clear();

        cin >> n;
        while(n--) {
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }

        cin >> c;

        ci.assign(c,0);
        int j = 0;
        while(c--) {
            cin >> a;
            for(int i = 0; i < (int)v.size(); i++) {
                if(a >= v[i].first && a <= v[i].second)
                    ci[j]++;
            }
            j++;
        }
        cout << "Case #" << nr++ << ": ";
        for(int i = 0; i < (int)ci.size(); i++) {
            cout << ci[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
