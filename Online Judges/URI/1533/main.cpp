#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, num;
    vector<pair<int,int>>v;
    while(cin >> n && n) {
        v.clear();
        for(int i = 0; i < n; i++) {
            cin >> num;
            v.push_back(make_pair(num,i+1));
        }
        sort(v.rbegin(),v.rend());

        cout << v[1].second << endl;
    }
    return 0;
}
