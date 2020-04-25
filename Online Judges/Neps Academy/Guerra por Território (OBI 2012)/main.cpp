#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>v(n, 0), suffix(n, 0), prefix(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    prefix[0] = v[0];

    suffix[0] = v[n - 1];

    for (int i = 1, j = (n - 2); i < n; i++, j--) {
        prefix[i]+=(v[i] + prefix[i - 1]);
        suffix[i]+=(v[j] + suffix[i - 1]);
    }

    int pos = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        if (prefix[i] == suffix[j] - v[i]) {
            pos = i;
            break;
        }
    }
    cout << pos + 1 << endl;

    return 0;
}
