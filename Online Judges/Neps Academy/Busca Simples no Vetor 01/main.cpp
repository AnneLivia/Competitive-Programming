#include <iostream>

using namespace std;

int main()
{
    int n[10], x, f = 0;
    for (int i = 0; i < 10; i++) {
        cin >> n[i];
    }
    cin >> x;
    for (int i = 0; i < 10; i++) {
        if (x == n[i]) {
            cout << "SIM\n";
            f = 1;
            break;
        }
    }
    if (!f)
        cout << "NAO\n";

    return 0;
}
