#include <iostream>

using namespace std;

int main()
{
    int n, t, m = 10000000;
    cin >> n;
    while(n--) {
        cin >> t;
        if (t < m) {
            m = t;
        }
    }
    cout << m << endl;
    return 0;
}
