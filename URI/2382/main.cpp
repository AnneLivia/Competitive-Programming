#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int lc,ac,pc,re;
    long double areaE, cal;
    cin >> lc >> ac >> pc >> re;
    areaE = 4 * pow(re,2.0);
    cal = pow(lc,2) + pow(ac,2) + pow(pc,2);
    if(cal <= areaE)
        cout << "S\n";
    else
        cout << "N\n";
    return 0;
}
