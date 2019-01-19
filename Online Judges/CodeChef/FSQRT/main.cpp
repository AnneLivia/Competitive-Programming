#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, t;
    cin >> t;
    while(t--) {
        cin >> n;
        cout.precision(0);
        cout.setf(ios::fixed);
        cout << sqrt((double)n) << endl;
    }
    return 0;
}
