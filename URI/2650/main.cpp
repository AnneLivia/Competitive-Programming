#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, cont, v;
    bool flag;
    vector<int>vn,vs;

    while(true) {
        cin >> n;
        if(n == 0)
            break;
        cont = 0;
        flag = true;

        while(flag) {
            vs.clear();
            vn.clear();
            for ( int i = 0; i < n; i++) {
                cin >> v;
                vs.push_back(v);
                vn.push_back(v);
            }
            sort(vs.begin(),vs.end());
            for ( int i = 0; i < n; i++) {
                if(vs[i] != vn[i]) {
                    flag = true;
                    break;
                } else {
                    flag = false;
                }
            }
            cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
