#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i = 1, ok = 0;
    vector<int>v;
    cin >> n;
    v.assign(n + 1,0);
    while(n--) {
        cin >> v[i++];
    }

    sort(v.begin(),v.end());
    for (int i = 1; i < (int)v.size(); i++) {
        if(v[i] - v[i - 1] > 8)
            ok = 1;
    }

    if(ok)
        cout << "N\n";
    else
        cout << "S\n";
    return 0;
}
