#include <iostream>

using namespace std;

int main() {

    int a, b, c, d, e, f, g, n;
    cin >> n >> a >> b >> c >> d >> e >> f >> g;

    int total_conj = (a - (d + e)) +
                     (b - (d + f)) + 
                     (c - (e + f)) + d + e + f + g;
    if (total_conj == n) {
        cout << "N\n";
    } else {
        cout << "S\n";
    }
    return 0;
}