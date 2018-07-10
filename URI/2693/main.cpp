#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const pair<pair<int,char>,string>&a, const pair<pair<int,char>,string>&b) {
    if(a.first.first < b.first.first)
        return true;
    else if (a.first.first == b.first.first) {
        if(a.first.second < b.first.second) {
            return true;
        } else if (a.first.second == b.first.second) {
            if(a.second.compare(b.second) < 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main()
{
    int q, dis;
    string na;
    char sig;

    vector<pair<pair<int,char>,string>>v;

    while( cin >> q ) {
        v.clear();
        while(q--) {
            cin >> na >> sig >> dis;
            v.push_back(make_pair(make_pair(dis,sig),na));
        }

        sort(v.begin(),v.end(),compare);

        for(int i = 0; i < (int)v.size(); i++) {
            cout << v[i].second << endl;
        }
    }
    return 0;
}
