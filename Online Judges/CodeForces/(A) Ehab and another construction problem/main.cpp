#include <iostream>

using namespace std;

int main()
{
    int x, ok = 0;
    cin >> x;

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            if(i % j == 0 && i * j > x && i / j < x) {
                cout << i << " " << j << endl;
                ok = 1;
                break;
            }
        }
        if(ok)
            break;
    }

    if(!ok)
        cout << "-1\n";
    return 0;
}
