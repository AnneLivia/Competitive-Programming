#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nAtr, ncarM, ncarL, n, cm, cl, a;
    vector<vector<int>>m,l;
    vector<int>value;

    while(cin >> nAtr) {
        m.clear();
        l.clear();
        cin >> ncarM >> ncarL;
        while(ncarM--) {
            value.clear();
            for ( int i = 0; i < nAtr; i++) {
                cin >> n;
                value.push_back(n);
            }
            m.push_back(value);
        }

        while(ncarL--) {
            value.clear();
            for ( int i = 0; i < nAtr; i++) {
                cin >> n;
                value.push_back(n);
            }
            l.push_back(value);
        }

        cin >> cm >> cl >> a;
        if(m[cm - 1][a - 1] > l[cl - 1][a - 1])
            cout << "Marcos\n";
        else if (m[cm - 1][a - 1] < l[cl - 1][a - 1])
            cout << "Leonardo\n";
        else
            cout << "Empate\n";
    }
    return 0;
}
