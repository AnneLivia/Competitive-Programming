#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, nstudents;
    vector<string>v, a;

    cin >> t;

    while(t--) {
        cin >> nstudents;
        v.assign(nstudents, " ");
        a.assign(nstudents, " ");

        for (int i = 0; i < nstudents; i++) {
            cin >> v[i];
        }

        // P - present, A - Absent, M - absent but with a doctor's note
        for (int i = 0; i < nstudents; i++) {
            cin >> a[i];
        }

        // above or equal to 75%
        int qtdP, totalClass, ok = 0;
        for (int i = 0; i < nstudents; i++) {
            qtdP = 0, totalClass = 0;
            for (int j = 0; j < (int)a[i].size(); j++) {
                if(a[i][j] != 'M')
                    totalClass++;
                if(a[i][j] == 'P')
                    qtdP++;
            }
            if((qtdP/(float)totalClass) * 100 < 75) {
                if(ok) {
                    cout << " ";
                    ok = 0;
                }
                cout << v[i];
                ok = 1;
            }
        }
        cout << endl;
    }
    return 0;
}
