#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // check even or odd
    if ((n & 1) == 0 && (m & 1) == 0) {
        // both even
        cout << 1 << endl;
    } else if ((n & 1) != 0 && (m & 1) == 0) {
        cout << 0 << endl;
    } else if ((n & 1) == 0 && (m & 1) != 0) {
        cout << 0 << endl;
    } else {
        // both are odd
        cout << 1 << endl;
    }
    return 0;
}
