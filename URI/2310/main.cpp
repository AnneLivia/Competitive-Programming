#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string name;
    vector<int>t,c; // t - tried, c - conquered
    double s,b,a;
    int n, p, sS = 0, sSt = 0,sB = 0, sBt = 0,sA = 0, sAt = 0;
    cin >> n;
    while(n--) {
        cin >> name;
        c.clear();
        t.clear();
        for ( int i = 0; i < 3; i++) {
            cin >> p;
            t.push_back(p);
        }

        for ( int i = 0; i < 3; i++) {
            cin >> p;
            c.push_back(p);
        }
        sS+=c[0];
        sB+=c[1];
        sA+=c[2];

        sSt+=t[0];
        sBt+=t[1];
        sAt+=t[2];
    }
    s = sS * 100.0 / sSt;
    b = sB * 100.0 / sBt;
    a = sA * 100.0 / sAt;

    cout.precision(2);
    cout.setf(ios::fixed);
    cout << "Pontos de Saque: " << s << " %.\n";
    cout << "Pontos de Bloqueio: " << b << " %.\n";
    cout << "Pontos de Ataque: " << a << " %.\n";
    return 0;
}
