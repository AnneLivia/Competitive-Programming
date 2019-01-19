#include <iostream>

using namespace std;

int main()
{
    int s, n, qTermos, opeSign;

    cin >> n;
    for ( int i = 0; i < n; i++) {
        do {
            cin >> qTermos;
        } while (n <= 0 || n > 1000);
        opeSign = 1;
        s = 0;
        for ( int j = 0; j < qTermos; j++) {
            if(opeSign == 0) {
                s = 1 - s;
                opeSign = 1;
            } else {
                s = 1 + s;
                opeSign = 0;
            }
        }
        cout << s << endl;
    }

    return 0;
}
