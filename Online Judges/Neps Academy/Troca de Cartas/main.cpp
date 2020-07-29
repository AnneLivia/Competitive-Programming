#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, t;
    vector<int>va, vb;
    set<int> sa, sb;
    cin >> a >> b;

    va.assign(a, 0);
    vb.assign(b, 0);

    for (int i = 0; i < a; i++) {
        cin >> va[i];
    }

    for (int i = 0; i < b; i++) {
        cin >> vb[i];
    }


     for (int i = 0; i < a; i++) {
        if(find(vb.begin(), vb.end(), va[i]) == vb.end()) {
            sa.insert(va[i]);
        }
    }

    for (int i = 0; i < b; i++) {
        if(find(va.begin(), va.end(), vb[i]) == va.end()) {
            sb.insert(vb[i]);
        }
    }

    int small = sb.size() < sa.size()? sb.size() : sa.size();
    cout << small << endl;

    return 0;
}
