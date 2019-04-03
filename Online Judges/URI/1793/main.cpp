#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t, n, cont, prev;
    while(cin >> t && t) {
        prev = 0; cont = 0;
        while(t--) {
            cin >> n;
            int diff = abs(n - prev);
            if(prev == 0 || diff >= 10) {
                cont+=10;
            } else {
                cont+=diff;
            }
            prev = n;
        }
        cout << cont << endl;
    }
    return 0;
}
