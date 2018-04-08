#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>v,d,c;
    int n, isc = 0,isd = 0;
    for(int i = 0; i < 5; i++) {
        cin >> n;
        v.push_back(n);
        c.push_back(n);
        d.push_back(n);
    }

    sort(c.begin(),c.end());
    sort(d.rbegin(),d.rend());

    for ( int i = 0; i < (int)v.size(); i++) {
        if(v[i] == c[i])
            isc++;
        if(v[i] == d[i])
            isd++;
    }

    if(isc == (int)v.size())
        cout << "C\n";
    else if (isd == (int)v.size())
        cout << "D\n";
    else
        cout << "N\n";

    return 0;
}
