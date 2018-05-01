#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    vector<string>si;
    int n;
    while(cin >> n) {
        si.clear();
        while(n--) {
            cin >> s;
            si.push_back(s);
        }
        sort(si.begin(),si.end());
        for ( int i = 0; i < (int)si.size(); i++) {
            cout << si[i] << endl;
        }
    }
    return 0;
}
