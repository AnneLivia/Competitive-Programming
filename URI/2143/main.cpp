#include <iostream>

using namespace std;

int main()
{
    int t, n;
    while(cin >> t && t) {
        while(t--) {
            cin >> n;
            if(n % 2 == 0) {
                cout << ((n - 2) * 2) + 2 << endl;
            } else {
                cout << ((n - 2) * 2) + 3 << endl;
            }
        }
    }
    return 0;
}
