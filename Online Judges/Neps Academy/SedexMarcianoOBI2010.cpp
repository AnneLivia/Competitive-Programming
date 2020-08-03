#include <iostream>

using namespace std;

int main() {
    int l, a, p, r;
    cin >> l >> a >> p >> r;
    int d = l * l + a * a + p * p;
    if (d <= 4 * r * r)
        cout << "S\n";
    else
        cout << "N\n";
            
    return 0;  
}
