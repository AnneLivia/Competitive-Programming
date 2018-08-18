#include <iostream>

using namespace std;

int main()
{
    double value = 0, n;
    for (int i = 0; i < 12; i++) {
        cin >> n;
        value+=n;
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << "$" << (value / 12) << endl;
    return 0;
}
