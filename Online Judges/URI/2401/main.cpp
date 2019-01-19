#include <iostream>

using namespace std;

int main()
{
    int n, v;
    long double r = 1;
    char c;
    cin >> n;
    while(n--) {
        cin >> v >> c;
        if(c == '/') {
            r /= v;
        } else {
            r *= v;
        }
    }

    cout.precision(0);
    cout.setf(ios::fixed);
    cout << r << endl;
    return 0;
}
