#include <iostream>

using namespace std;

int main()
{
    int h1, m1, h2, m2, hh;

    while(cin >> h1 >> m1 >> h2 >> m2) {
        if (h1+h2+m1+m2 == 0)
            break;

        h1 = h1 == 0 ? 24 : h1;
        h2 = h2 == 0 ? 24 : h2;

        if (h2 < h1 || (h1 == h2 && m2 < m1)) {
            h2+=24;
        }

        hh = abs(h2 - h1);

        cout << ((60 * hh) - m1) + m2 << endl;
    }
    return 0;
}
