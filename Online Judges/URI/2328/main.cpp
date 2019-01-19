#include <iostream>

using namespace std;

int main()
{
    int t, n, sum = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        sum += (n - 1);
    }
    cout << sum << endl;
    return 0;
}
