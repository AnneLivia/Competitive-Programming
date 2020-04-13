#include <iostream>

using namespace std;

int main() {
    int x, ans;
    cin >> x;
    ans = x - 9;
    if (ans < 0) {
        ans = 24-(9-x);
    }
    cout << ans << endl;
    return 0;  
}
