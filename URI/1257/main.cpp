#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int hash_comp, t, l;
    string s;
    vector<string>v;
    cin >> t;
    while(t--) {
        hash_comp = 0;
        v.clear();
        cin >> l;
        while(l--) {
            cin >> s;
            v.push_back(s);
        }

        for(int i = 0; i < (int)v.size(); i++) {
            for(int j = 0; j < (int)v[i].size(); j++) {
                hash_comp+= (((int)v[i][j] - 65) + i + j);
            }
        }

        cout << hash_comp << endl;
    }
    return 0;
}
