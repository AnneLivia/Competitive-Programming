#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<string,int>&p1,const pair<string,int>&p2) {
    if(p1.second < p2.second)
        return true;
    else if (p1.second == p2.second && p1.first > p2.first)
        return true;
    return false;
}
// Must finish
int main()
{
    string name;
    vector<pair<string,int>>v;
    int n, q, ins = 1;
    while(cin >> q) {
        v.clear();
        while(q--) {
            cin >> name >> n;
            v.push_back(make_pair(name,n));
        }

        sort(v.begin(),v.end(),compare);

        cout << "Instancia " << ins++ << endl;
        cout << v[0].first << endl << endl;
    }

    return 0;
}
