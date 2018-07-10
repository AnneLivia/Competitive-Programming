#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, c, sc;
    double result;
    while(cin >> n) {
        result = 0.0;
        sc = 0;
        while(n--) {
            cin  >> m >> c;
            result +=m*c;
            sc+=c;
        }
        result = result / (sc * 100);
        round(result);
        cout.precision(4);
        cout.setf(ios::fixed);
        cout << result << endl;
    }
    return 0;
}
