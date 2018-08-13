#include <iostream>

using namespace std;

int main()
{
    int t, n, x, y;
    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        for(int i = 1; i < n; i++) {
            if((i % x == 0) && !(i % y == 0)) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
