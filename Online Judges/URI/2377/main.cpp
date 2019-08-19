#include <iostream>

using namespace std;

int main()
{
    int l, d, k, p, r;
    cin >> l >> d >> k >> p;
    if(l < d)
        cout << k * l << endl;
    else {
        r = ((l / d) * p) + (l * k);
        cout << r << endl;
    }
    return 0;
}
