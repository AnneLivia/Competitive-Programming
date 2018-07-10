#include <iostream>

using namespace std;

int main()
{
    int h1, h2, m1, m2, th1, th2;

    while(true) {
        cin >> h1 >> m1 >> h2 >> m2;
        if(h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0)
            break;
        if(h1 == 0)
            h1 = 24;
        if(h2 == 0)
            h2 = 24;

        th1 = h1 * 60 + m1;
        th2 = h2 * 60 + m2;
        if(h1 == h2 && m1 < m2)
            cout << abs(m1 - m2) << endl;
        else if (h1 == h2 && m1 < m2)
            cout << abs(th1 - 1440) + th2 << endl;
        else if(th1 > th2)
            cout << 1440 - (th1 - th2) << endl;
        else if (th1 == th2)
            cout << "1440\n";
        else
            cout << abs(th1 - th2) << endl;

    }
    return 0;
}
