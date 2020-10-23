#include <iostream>

using namespace std;

int main() {
    int a, b, c, h, l;
    cin >> a >> b >> c >> h >> l;
    if (a <= l && b <= h || 
        c <= h && a <= l ||
        a <= h && b <= l ||
        c <= h && b <= l ||
        c <= l && a <= h ||
        c <= l && b <= h) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }
    return 0;  
}
