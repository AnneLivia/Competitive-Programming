#include <iostream>

using namespace std;

int main()
{
    int q, p, tp = 0;
    cin >> p >> q;
    while(q--) {
        cin >> tp;
        p += tp;
        if(p > 100)
            p = 100;
        else if (p < 0)
            p = 0;
    }
    cout << p <<  endl;
    return 0;
}
