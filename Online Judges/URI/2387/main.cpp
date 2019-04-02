#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, y, py = -1, cont = 0;
    vector<pair<int,int> > v;
    cin >> n;
    while(n--) {
        cin >> x >> y;
        v.push_back({y,x});
    }
    sort(v.begin(), v.end());
    for (auto i : v) {
        if(i.second >= py) {
            cont++;
            py = i.first;
        }
    }
    cout << cont << endl;
    return 0;
}
