#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    long int t, n;

    while(true) {
        cin >> t;
        if(t == 0)
            break;
        map<int, int>m;

        while(t--) {
            cin >> n;
            if(m.find(n) != m.end()) {
                m[n]+=1;
            } else {
                m.insert(make_pair(n,1));
            }
        }

        int tam = 0;
        for(auto it = m.begin(); it != m.end(); it++) {

            if(it->second % 2 != 0) {
                if(tam != 0) {
                    cout << " ";
                }
                cout << it->first;
                tam++;
            }
        }
        cout << endl;
    }
    return 0;
}
