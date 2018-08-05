#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m, t;
    vector<int>v;
    cin >> n >> m;
    v.assign(n,0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> t;
            v[i]+=t;
        }
    }

    int maior = 0;
    for (int i = 1; i < n; i++) {
        if(v[maior] > v[i])
            maior = i;
    }
    cout << maior + 1 << endl;
    return 0;
}
