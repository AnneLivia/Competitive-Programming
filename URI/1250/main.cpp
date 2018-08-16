#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, qt, n, gt;
    vector<int>v;
    string s;
    cin >> t;
    while(t--) {
        v.clear();
        gt = 0;
        cin >> qt;
        for (int i = 0; i < qt; i++) {
            cin >> n;
            v.push_back(n);
        }
        cin >> s;
        for(int i = 0; i < qt; i++) {
            if(v[i] <= 2 && s[i] == 'S')
                gt++;
            else if (v[i] > 2 && s[i] == 'J')
                gt++;
        }
        cout << gt << endl;
    }
    return 0;
}
