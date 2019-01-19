#include <iostream>

using namespace std;

int main()
{
    int ia, ib, fa, fb, cont = 0;
    cin >> ia >> ib >> fa >> fb;

    if(fa == 1 && fb == 0) {
        cout << 1 << endl;
    } else if (fa == 1 && fb  == 1) {
        cout << 1 << endl;
    } else if (fa == 0 && fb == 1) {
        cout << 2 << endl;
    } else if (fa == 0 && fb == 0) {
        cout << 0 << endl;
    }
    return 0;
}
