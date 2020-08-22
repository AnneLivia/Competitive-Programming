#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x;
    double total = 1.0;
    char c;  
    cin >> n;  
    while(n--) {
        cin >> x >> c;
        if (c == '*') {
            total*=x;
        } else {
            total/=x;
        }
    }
    cout.precision(0);
    cout.setf(ios::fixed);
    cout << total << endl;
    return 0;  
}
