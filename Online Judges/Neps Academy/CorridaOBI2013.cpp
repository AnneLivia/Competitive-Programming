#include <iostream>

using namespace std;

int main() {
    int n1, n2, d1, d2, v1, v2;
    cin >> n1 >> d1 >> v1;
    cin >> n2 >> d2 >> v2;

    if ((float)d1 / v1 < (float)d2 / v2) {
        cout << n1 << endl;
    } else {
        cout << n2 << endl;
    }
    return 0;  
}
