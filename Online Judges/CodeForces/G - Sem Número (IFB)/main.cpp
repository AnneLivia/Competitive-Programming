#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>v;
    int n;
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++) {
        if(v[i] != i) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
