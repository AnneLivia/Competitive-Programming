#include <iostream>

using namespace std;

int main()
{
    int l1, l2, c1, c2, l, c;
    cin >> l1 >> l2 >> c1 >> c2;

    if(l1 + 1 == l2 || l1 - 1 == l2) {
        l = 3 * (l1 + l2);
    } else if (l1 == l2) {
        l = 2 * (l1 + l2);
    } else {
        l = l1 + l2;
    }

    if(c1 + 1 == c2 || c1 - 1 == c2) {
        c = 3 * (c1 + c2);
    } else if (c1 == c2) {
        c = 2 * (c1 + c2);
    } else {
        c = c1 + c2;
    }

    if(c == l) {
        cout << "empate\n";
    } else if (c > l) {
        cout << "Carolina\n";
    } else {
        cout << "Lia\n";
    }
    return 0;
}
