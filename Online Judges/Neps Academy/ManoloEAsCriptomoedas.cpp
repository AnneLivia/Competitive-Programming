#include <iostream>

using namespace std;

int main() {
    int n;
    float t, val = 100;
    cin >> n;    
    cin >> t;
    val*=t;
    n--;
    while(n--) {
        cin >> t;
    }
    cout.precision(2);
    cout.setf(ios::fixed);
    cout << (100 * t) - val << endl;
    return 0;  
}
