#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int t, ok = 0;
    cin >> t;
    vector<int>v(t, 0);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < t - 1; i++) {
        if(v[i - 1] > v[i] && v[i + 1] > v[i]) {
            ok = 1;
            break;
        }
    }

    if(ok)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
