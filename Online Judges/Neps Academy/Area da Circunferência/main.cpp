#include <iostream>

using namespace std;

int main()
{
    int r;
    cin >> r;
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << (2 * 3.1416 * r * r) / 2 << endl;
    return 0;
}
