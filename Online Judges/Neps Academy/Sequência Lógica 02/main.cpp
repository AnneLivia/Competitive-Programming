#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 1, t = 0;
    for (int i = 0; i <= 61; i++) {
        cout << "a = " << a << " <-> b = " << b << endl;

        if (a == 0) {
            a++;
        } else {
            t++;
        }

        if ((t == 0 && (a - 1) == 0) || t == 2) {
            b-=2;
        } else {
            b+=4;
        }

        if (t >= 2) {
            t = 0;
            a++;
        }
    }
    return 0;
}
