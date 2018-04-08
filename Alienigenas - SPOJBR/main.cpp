#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int q, n;
    string md;
    vector<char>d;
    set<string>w;
    while(true) {
        d.clear();
        w.clear();
        cin >> q;
        if(!q)
            break;

        while(q--) {
            d.clear();
            cin >> md;
            for(int i = 0; i < md.size(); i++) {
                d.push_back(md[i]);
            }
            sort(d.begin(),d.end());
            md = "";
            for ( int i = 0; i < d.size(); i++) {
                md+=d[i];
            }

            w.insert(md);
        }

        cout << (int)w.size() << endl;
    }
    return 0;
}
