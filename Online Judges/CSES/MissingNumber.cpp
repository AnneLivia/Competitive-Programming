#include <iostream>
#include <cstring>

using namespace std;

int sum(int va) {
    if (va == 1)
        return 1;
    return va + sum(va - 1);
}

int main() {
    int n, t, s = 0, c = 0;
    cin >> n;
    s = sum(n);

    for (int i = 0; i < n-1; i++) {
        cin >> t;
        c+=t;
    }

    cout << s - c << endl;
    
    return 0;
}