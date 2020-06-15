#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    int n;
    cin >> n;
    vector<int>v(n, 0);
    vector<int>changed(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        changed[i]  = v[i];
    }

    sort(changed.begin(), changed.end());
    vector<int> ans;
    int beg = 0;
    for (int i = 0; i < n; i++) {
        if(v[i] != changed[i]) {
            ans.push_back(changed[i]);
            beg++;
        }
    }


    if(!beg)
        cout << "0";
    else {
        cout << beg << endl;
        for (int i = 0; i < beg; i++) {
            if(i != 0)
                cout << " ";
            cout << ans[i];
        }
    }
    cout << endl;
    return 0;
}
