#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    if (n1 * n2 > n3 * n4) {
        cout << n1 * n2 << endl;
    } else {
        cout << n3 * n4 << endl;
    }
    return 0;
}
