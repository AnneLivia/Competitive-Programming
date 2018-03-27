#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, q, c;
    vector<int>p;
    while(cin >> n >> q) {
        p.clear();
        while(n--) {
            cin >> c;
            p.push_back(c);
        }
        sort(p.begin(),p.end(),greater<int>());
        while(q--) {
            cin >> c;
            cout << p[c - 1] << endl;
        }
    }
    return 0;
}
