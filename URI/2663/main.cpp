#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, s, pass, o;
    vector<int>v;

    cin >> n >> s;

    while(n--) {
        cin >> o;
        v.push_back(o);
    }

    sort(v.rbegin(),v.rend());
    pass = s;

    for (int i = s; i < (int)v.size(); i++) {
        if(v[i] == v[i - 1])
            pass++;
        else
            break;
    }

    cout << pass << endl;
    return 0;
}
