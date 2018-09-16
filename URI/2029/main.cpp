#include <iostream>

using namespace std;

int main()
{
    double d, v, h;
    cout.precision(2);
    cout.setf(ios::fixed);
    while(cin >> v >> d) {
        h = (v/(3.14 * ((d/2) * (d/2))));
        cout << "ALTURA = " << h << endl;
        cout << "AREA = " << ((3.14 * ((d/2) * (d/2)))) << endl;
    }
    return 0;
}
