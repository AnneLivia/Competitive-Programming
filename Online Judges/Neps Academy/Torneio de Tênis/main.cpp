#include <iostream>

using namespace std;

int main()
{
    char c;
    int win = 0;

    for (int i = 0; i < 6; i++) {
        cin >> c;
        if (c == 'V') {
            win++;
        }
    }

    if (win >= 5 && win <= 6) {
        cout << 1 << endl;
    } else if ( win >= 3 && win <= 4 ){
        cout << 2 << endl;
    } else if ( win >= 1 && win <= 2 ){
        cout << 3 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
