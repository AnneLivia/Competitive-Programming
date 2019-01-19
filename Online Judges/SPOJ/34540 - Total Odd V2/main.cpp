#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int n1, n2, res;
    int t;
    cin >> t;

    while(t--) {
        cin >> n1 >> n2;
        // PA formula
        if(n1 == 2) {
            res = --n2 / 2;
        } else {
            if(n1 % 2 == 0 && n2 % 2 == 0)
                n1++;
            res = ((n2 - n1) + 2) / 2;
        }
        cout << res << endl;
    }
    return 0;
}
