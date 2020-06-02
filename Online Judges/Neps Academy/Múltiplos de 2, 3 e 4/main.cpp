#include <iostream>

using namespace std;

int main()
{
    int t, n, t2, t3, t4;
    t2 = t3 = t4 = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        t2+= n % 2 == 0 ? 1 : 0;
        t3+= n % 3 == 0 ? 1 : 0;
        t4+= n % 4 == 0 ? 1 : 0;
    }
    cout << t2 << endl;
    cout << t3 << endl;
    cout << t4 << endl;
    return 0;
}
