#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    vector<int>v;
    cin >> t;
    v.assign(t+1,0);
    t--;
    while(t--) {
        cin >> n;
        v[n] = 1;
    }

    for ( int i = 1; i < (int)v.size(); i++) {
        if(!v[i])
            cout << i << endl;
    }

    return 0;
}
