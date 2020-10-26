#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if (a + b < c || a + c < b || b + c < a) {
        cout << 1 << endl;
    } else if (a < b || a < c || b < a || b < c || c < b || c < a) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;  
}
