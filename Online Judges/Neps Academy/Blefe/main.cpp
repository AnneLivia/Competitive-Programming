#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, stop = 0;
    cin >> a >> b;
    vector<int>va(a, 0);
    vector<int>vb(b, 0);

    for (int i = 0; i < a; i++) {
        cin >> va[i];
    }

    for (int i = 0; i < b; i++) {
        cin >> vb[i];
    }

    sort(vb.begin(), vb.end());

    for (int i = 0; i < b; i++) {
        if(find(va.begin(), va.end(), vb[i]) == va.end()) {
            // if it's not in the set of a, check if is a sum
            int l = 0, r = b - 1, found = 0;
            while(l < r) {
                if(vb[l] + vb[r] == vb[i] || vb[l] + vb[l] == vb[i] || vb[r] + vb[r] == vb[i]) {
                    found = 1;
                    break;
                } else if (vb[l] + vb[r] > vb[i]) {
                    r--;
                } else {
                    l++;
                }
            }

            if(!found) {
                stop = 1;
            }
        }
        if(stop) {
            cout << vb[i] << endl;
            break;
        }
    }

    if(!stop)
        cout << "sim\n";
    return 0;
}
