#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nA, nJ, n, cont;
    vector<vector<int>>v;
    while(cin >> nA >> nJ && nA && nJ) {
        v.clear();
        v.assign(nJ,vector<int>());
        for(int i = 0; i < nJ; i++) {
            for(int j = 0; j < nA; j++) {
                cin >> n;
                v[i].push_back(n);
            }
        }

        for(int i = 0; i < nA; i++) {
            cont = 0;
            for(int j = 0; j < nJ; j++) {
                if(v[j][i] == 1)
                    cont++;
            }
            if(cont == nJ) {
                cout << "yes\n";
                break;
            }
        }
        if(cont != nJ)
            cout << "no\n";
    }
    return 0;
}
