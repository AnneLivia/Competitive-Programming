#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    string s;
    vector<string>si;
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        si.push_back(s);
    }

    for ( int i = 0; i < (int)si.size(); i++) {
        if((int)si[i].size() == 3) {
            if(si[i][0] == 'O' && si[i][1] == 'B' || si[i][0] == 'U' && si[i][1] == 'R')
                si[i][2] = 'I';
        }
    }

    for ( int i = 0; i < (int)si.size(); i++) {
        if(i != 0)
            cout << " ";
        cout << si[i];
    }
    cout << endl;
    return 0;
}
