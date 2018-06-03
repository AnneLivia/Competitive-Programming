#include <iostream>

using namespace std;

int main()
{
    long double i, l;
    while(cin >> l && l != 0) {
        i = l + (l - 3);
        cout.precision(6);
        cout.setf(ios::fixed);
        cout << (i - l) / l << endl;
    }
    return 0;
}
