#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nt, nq, n, maior, max_n, max_total, teste = 1;
    vector<int>v;
    cin >> nt;
    while(nt--) {
        maior = max_total = -1;
        max_n = 0;
        cin >> nq;
        while(nq--) {
            cin >> n;
            v.push_back(n);
            if(n > maior)
                maior = n;
        }
        v.push_back(-1);
        for ( int i = 0; i < (int)v.size(); i++) {
            if(v[i] == maior)
                max_n++;
            else {
                if(max_n > max_total)
                    max_total = max_n;
                max_n = 0;
            }
        }
        cout << "Caso #" << teste++ << ": " << max_total << endl;
    }

    return 0;
}
