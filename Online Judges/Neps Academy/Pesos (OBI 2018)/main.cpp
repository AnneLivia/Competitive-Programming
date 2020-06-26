#include <iostream>

using namespace std;

int main()
{
    int n, v[100001] = {0}, can = 1;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] - v[i - 1] > 8) {
            can = 0;
            break;
        }
    }

    if (can)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
