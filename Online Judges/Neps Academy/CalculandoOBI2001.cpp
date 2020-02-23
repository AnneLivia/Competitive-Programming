#include <iostream>

using namespace std;

int main() {
    int m, n1, n2, res = 0, t = 1;
    char c;
    while(cin >> m && m) {
        cin >> n1;
        m--;
        cout << "Teste " << t++ << endl;
        while(m--) {
            cin >> c >> n2;
            if(c == '+') {
                n1+=n2;
            } else {
                n1-=n2;
            }
        }
        cout << n1 << "\n\n";
    }
    return 0;
}