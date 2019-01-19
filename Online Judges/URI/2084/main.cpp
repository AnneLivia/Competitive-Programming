#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, ok;
    double total = 0.0;
    vector<int>v;
    vector<double>p;
    cin >> t;
    while(t--) {
        cin >> n;
        v.push_back(n);
        total+=n;
    }

    sort(v.rbegin(),v.rend());
    for(int i = 0; i < (int)v.size(); i++)
        p.push_back((v[i]/total) * 100.0);

    ok = 1;
    if(p[0] >= 45) {
            cout << "1\n";
    } else if (p[0] >= 40) {
        for(int i = 1; i < (int)p.size(); i++) {
            if(abs(p[0] - p[i]) < 10)
                ok = 0;
        }
        if(ok)
            cout << "1\n";
        else
            cout << "2\n";
    } else {
        cout << "2\n";
    }

    return 0;
}
