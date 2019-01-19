#include <iostream>
#include <cstring>

using namespace std;

int dp(const int *m, const int *tp, const int &t, const int& maxp);

int main()
{
    int t, maxp;
    int m[31], tp[31]; // Minutes and number of pizzas

    while(cin >> t && t) {

        cin >> maxp;

        for(int i = 1; i <= t; i++) {
            cin >> m[i] >> tp[i];
        }

        cout << dp(m, tp, t, maxp) << " min." << endl;
    }
    return 0;
}

int dp(const int *m, const int *tp, const int &t, const int& maxp) {
    int tab[t + 1][maxp + 1];


    for(int i = 0; i < maxp + 1; i++)
        tab[0][i] = 0;
    for(int i = 0; i < t + 1; i++)
        tab[i][0] = 0;

    for (int i = 1; i < t + 1; i++) {
        for(int j = 1; j < maxp + 1; j++) {
            int vAA = tab[i - 1][j];
            if(tp[i] <= j) {
                int vAL = tab[i - 1][j - tp[i]] + m[i];
                tab[i][j] = (vAL > vAA) ? vAL : vAA;
            } else {
                tab[i][j] = vAA;
            }
        }
    }

    return tab[t][maxp];
}
