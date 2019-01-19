#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int n, maior, ja = 0;
    vector<string>v;
    string aux;
    while(cin >> n && n) {
        v.clear();
        maior = 0;
        if(ja >= 1)
            cout << endl;
        while(n--) {
            cin >> aux;
            v.push_back(aux);
            if(maior < (int)aux.size())
                maior = (int)aux.size();
        }
        for(int i = 0; i < (int)v.size(); i++) {
            cout << setw(maior) << right << v[i] << endl;
        }
        ja++;
    }
    return 0;
}
