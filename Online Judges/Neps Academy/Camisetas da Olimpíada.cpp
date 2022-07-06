#include <iostream>

using namespace std;

int main() {

    int n, x, mm = 0, pp = 0, m, p;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == 1)
            pp++;
        else
            mm++;
    }

    cin >> p >> m;

    if (p == pp && mm == m)
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
