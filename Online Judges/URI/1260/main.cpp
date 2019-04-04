#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
    int n, total = 0, c;
    string s;
    map<string, float>m;
    cin >> n;
    getline(cin, s);
    cin.ignore();

    while(n--) {
        if(total != 0)
            cout << endl;
        m.clear();
        total = 0;
        while(getline(cin, s) && s != "") {
            if(m.find(s) == m.end()) {
                m.insert(make_pair(s,1));
            } else {
                m.at(s)++;
            }
            total++;
        }

        cout.precision(4);
        cout.setf(ios::fixed);
        for(auto i : m) {
            cout << i.first << " " << ((float)i.second/total) * 100 << endl;
        }

    }
    return 0;
}
