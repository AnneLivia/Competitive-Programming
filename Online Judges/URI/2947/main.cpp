#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nQ, nA, maximum = 0;
    cin >> nQ;
    vector<char>unf(nQ, ' ');

    for (int i = 0; i < nQ; i++) {
        cin >> unf[i];
    }

    cin >> nA;
    vector<string> friUnf(nA, "");

    for (int i = 0; i < nA; i++) {
        cin >> friUnf[i];
    }

    vector<int>alf;

    for (int i = 0; i < nQ; i++) {
        alf.assign(26, 0);
        for(int j = 0; j < nA; j++) {
            int letterNumber = friUnf[j][i] - 'A';
            if(friUnf[j][i] != unf[i]) {
                alf[letterNumber]++;
            }
        }
        sort(alf.rbegin(), alf.rend());
        maximum+=alf[0];
    }

    cout << maximum << endl;
    return 0;
}
