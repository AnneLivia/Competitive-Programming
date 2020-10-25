#include <iostream>
#include <vector>
using namespace std;

ostream& operator << (ostream& out, const vector<int>& v) {
    for (auto i : v) {
        out << i << " ";
    }
    return out;
}

int main() {
    int a, n, m, ii, r, p;
    cin >> n >> m;
    vector<int>s(n, 0), c;

    cin >> ii >> r;
    s[ii-1] = 1; // infectado
    for (int i = 0; i < m; i++) {
        int atLeastOneInfected = 0;
        cin >> a;
        while(a--) {
            cin >> p;
            if (i < r-1)
                continue;
            if (s[p-1])
               atLeastOneInfected = 1;
            c.push_back(p);
        }
        for (int i = 0; i < (int)c.size(); i++) {
            if (atLeastOneInfected)
                s[c[i]-1] = 1;
        }
        c.clear();
    }

    int cont = 0;
    for (int i = 0; i < n; i++) {
        cont+=s[i];
    }

    cout << cont << endl;

    return 0;
}
