#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    double p, r, n;
    int q, ma, mi;
    string nome;
    vector<pair<string,double>>pl;
    vector<double>v;

    cin >> q;
    while(q--) {
        v.clear();
        r = 0.0;
        cin >> nome;
        cin >> p;
        for ( int i = 0; i < 7; i++) {
            cin >> n;
            v.push_back(n);
        }

        sort(v.begin(),v.end());
        v.pop_back();
        v.erase(v.begin(),v.begin()+1);

        for(int i = 0; i < (int)v.size(); i++) {
            r += v[i];
        }

        r*=p;

        pl.push_back(make_pair(nome,r));
    }

    cout.precision(2);
    cout.setf(ios::fixed);

    for(auto i : pl) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
