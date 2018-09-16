#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    double n1, n2, res;
    cin >> t;
    while(t--) {
        cin >> n1 >> n2;
        res = n1 / n2;
        res = ceil(res);
        cout << res << endl;
    }
    return 0;
}
