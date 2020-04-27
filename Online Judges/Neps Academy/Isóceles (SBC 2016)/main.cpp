#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, h = 0;
    cin >> n;
    vector<int>v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        if (v[i - 1] >= v[i] && i + 1 < n && v[i + 1] < v[i] && v[i - 1] == v[i + 1]) {
            if (v[i] > h)
                h = v[i];
        } else if (v[i - 1] == 1 && v[i] == 1 && v[i + 1] == 1 && i + 1 < n) {
                h = 1;
        }
    }
    cout << h << endl;
    return 0;
}
