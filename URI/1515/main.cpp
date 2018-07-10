#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int q, yf, y;
    string n;
    vector<pair<string,pair<int,int>>>v;
    pair<int,int>aux;
    while(1) {
        v.clear();
        cin >> q;
        if(q == 0)
            break;
        while(q--) {
            cin >> n >> yf >> y;
            aux = make_pair(yf, y);
            v.push_back(make_pair(n,aux));
        }
        int me = v[0].second.first - v[0].second.second, pos = 0;
        for ( int i = 1; i < (int)v.size(); i++) {
            if(me > v[i].second.first - v[i].second.second) {
                me = v[i].second.first - v[i].second.second;
                pos = i;
            }
        }
        cout << v[pos].first << endl;
    }
    return 0;
}
