#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, qtA, numM, n;
    vector<int>v;
    cin >> t;

    while(t--) {
        v.clear();
        cin >> qtA >> numM;

        while(qtA--) {
            cin >> n;
            v.push_back(n);
        }

        int achou = 0, i, pos = 0, closer = abs(v[0] - numM);
        for ( i = 0; i < (int)v.size(); i++) {
            if(v[i] == numM) {
                achou = true;
                break;
            }
            if(abs((v[i] - numM)) < closer) {
                closer = abs(v[i] - numM);
                pos = i;
            }
        }
        if(achou) {
            cout << i + 1 << endl;
        } else {
            cout << pos + 1 << endl;
        }
    }
    return 0;
}
