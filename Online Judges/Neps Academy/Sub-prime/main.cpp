#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int b, n, b1, b2, r;

    vector<int> v;

    while(cin >> b >> n && b && n) {
        v.assign(b, 0);
        bool can = true;
        for (int i = 0; i < b; i++) {
            cin >> v[i];
        }

        while(n--) {
            cin >> b1 >> b2 >> r;
            v[b1 - 1]-=r;
            v[b2 - 1]+=r;
        }

        for(int i = 0; i < (int)v.size(); i++) {
            if(v[i] < 0)
                can = false;
        }

        if(can)
            cout << "S\n";
        else
            cout << "N\n";
    }
    return 0;
}
