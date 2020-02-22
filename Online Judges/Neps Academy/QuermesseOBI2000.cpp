#include <iostream>

using namespace std;

int main() {
    int n, v, r, t = 1;
    while(cin >> n && n) {
        cout << "Teste " << t++ << endl;
        for (int i = 1; i <= n; i++) {
            cin >> v;
            if (v == i) 
                r = v;
        }
        cout << r << "\n\n";
    }
    return 0;
}