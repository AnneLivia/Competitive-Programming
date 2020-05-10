#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y, n, m, v, away = 0;
    char c;

    cin >> n >> m;

    x = 0, y = 0;
    while(n--) {
        cin >> c >> v;
        x += (c == 'L' ? v : c == 'O' ? -v : 0);
        y += (c == 'S' ? v : c == 'N' ? -v : 0);
        if (sqrt(pow(x, 2) + pow(y, 2)) > m) {
            away = 1;
        }
    }

    cout << away << endl;
    return 0;  
}
